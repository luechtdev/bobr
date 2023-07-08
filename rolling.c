#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

#include "rolling.h"
#include "box.h"
#include "ansi.h"

RollingQ* rq_new (size_t qsize) {
    // Allocate the rolling queue
    RollingQ* q = malloc(sizeof(RollingQ));
    q->capacity = qsize;
    q->index = 0;

    // Allocate the pointer array
    q->content = calloc(qsize, sizeof(char*));;

    fprintf(stdout, ANSI_SCI_CLS);

    return q;
}

void rq_advance (RollingQ* q) {
    free(q->content[0]);
    for (size_t i = 0; i < q->capacity - 1; ++i)
        q->content[i] = q->content[i+1];
}

void rq_wall (RollingQ* q) {
    for (size_t i = 0; i < q->index && i < q->capacity; ++i) {
        fprintf(stdout, ANSI_SCI_CUU "" ANSI_SCI_EL "" ANSI_SCI_CHA);
    }
    for (size_t i = 0; i < q->index && i < q->capacity; ++i) {
        fprintf(stdout, "%s\n", q->content[i]);
    }
}

void rq_wall_box (RollingQ* q, const char* title) {
    if (q->index) {
        fprintf(stdout, ANSI_SCI_CUU "" ANSI_SCI_EL "" ANSI_SCI_CHA);
        fprintf(stdout, ANSI_SCI_CUU "" ANSI_SCI_EL "" ANSI_SCI_CHA);
    }
    for (ssize_t i = 0; i < q->index && i < q->capacity; ++i) {
        fprintf(stdout, ANSI_SCI_CUU "" ANSI_SCI_EL "" ANSI_SCI_CHA);
    }
    fprintf(stdout, BOX_DDR "" BOX_DH "" BOX_VS_LD " %s " BOX_VS_RD "" BOX_DH "" BOX_DH "" BOX_VS_LD " %zd \n", title, q->index);
    for (size_t i = 0; i < q->index && i < q->capacity; ++i) {
        fprintf(stdout, BOX_DV " %s\n", q->content[i]);
    }
    fprintf(stdout, BOX_DUR "\n");
}

void rq_pushln_s (RollingQ* q, const char* msg, size_t size) {
    size_t target = q->index;

    if (q->index >= q->capacity) {
        rq_advance(q);
        target = q->capacity - 1;
    }

    q->content[target] = calloc(size + 1, sizeof(char));
    memcpy(q->content[target], msg, size);

    q->index++;
    rq_wall_box(q, "Dings");
}

inline void rq_pushln (RollingQ* q, const char* msg) {
    rq_pushln_s(q, msg, strlen(msg));
}


void rq_pushf (RollingQ* q, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    // Get the size of the message
    ssize_t buffer_size = vsnprintf(NULL, 0, fmt, args);

    if (buffer_size < 0) {
        va_end(args);
        return;
    }

    char* msg_buffer = calloc(buffer_size + 1, sizeof(char));
    vsnprintf(msg_buffer, buffer_size + 1, fmt, args);

    rq_pushln_s(q, msg_buffer, buffer_size);

    va_end(args);
}

void rq_free (RollingQ* q) {
    for (char** msg = q->content; msg < &q->content[q->capacity]; ++msg)
        free(*msg);
    free(q);
}