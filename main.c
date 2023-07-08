//
// Created by Jannus on 05.07.2023.
//

#pragma execution_character_set("utf-8")

#include <unistd.h>
#include <time.h>
#include <Windows.h>

#include "ansi.h"
#include "rolling.c"

int main(int argc, char** argv) {

    SetConsoleOutputCP(CP_UTF8);

    RollingQ* rq = rq_new(3);


    struct timespec sleepTime = {
        .tv_sec = 0,            // Seconds
        .tv_nsec = 10000000     // Nanoseconds (10ms)
    };

    for (int i = 0; i < 1000; ++i) {
        rq_pushf(rq, "Hello %d", i);
        nanosleep(&sleepTime, NULL);
    }

    rq_free(rq);

}