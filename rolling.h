#pragma once

typedef struct {
    size_t capacity;
    size_t index;
    char** content;
} RollingQ;

/**
 * Create new rolling queue
 * @param qsize Size of the queue
 * @return new RQ on the heap
 */
RollingQ* rq_new (size_t qsize);

void rq_wall     (RollingQ*);

void rq_pushf    (RollingQ*, const char* fmt, ...);
void rq_pushln_s (RollingQ*, const char* msg, size_t size);
void rq_pushln   (RollingQ*, const char* msg);

void rq_printf   (RollingQ*, const char* fmt, ...);
void rq_free    (RollingQ *q);
