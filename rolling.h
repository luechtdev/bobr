#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    size_t capacity;
    size_t index;
    char** content;
} RollingQ;

RollingQ* rq_new (size_t qsize) {
    // Allocate the rolling queue
    RollingQ* q = malloc(sizeof(RollingQ));
    q->capacity = qsize;
    q->index = 0;

    // Allocate the pointer array
    char** content = calloc(qsize, sizeof(char*));
    q->content = content;

    return q;
}

void rq_push_s (RollingQ* q, const char* msg, size_t size) {
    if (q->index < q->capacity) {
        q->content[q->index] = calloc(size, sizeof(char));
        memcpy(q->content[q->index], msg, size);
    }
}

void rq_pushf (RollingQ* q, const char* fmt, ...) {

}

void rq_printf (RollingQ* q, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void rq_close (RollingQ* q) {
    for (char** msg = q->content; msg < &q->content[q->capacity]; q++)
        free(msg);
    free(q);
}
