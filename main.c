//
// Created by Jannus on 05.07.2023.
//

#include <unistd.h>

#include "ansi.h"
#include "rolling.h"

int main(int argc, char** argv) {

    RollingQ* rq = rq_new(3);

    rq_push_s(rq, "Hello1", 6);
    rq_push_s(rq, "Hello2", 6);
    sleep(1);
    rq_push_s(rq, "Hello3", 6);
    sleep(1);
    rq_push_s(rq, "Hello4", 6);
    sleep(1);
    rq_push_s(rq, "Hello5", 6);

    rq_close(rq);

}