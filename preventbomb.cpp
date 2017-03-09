#include <sys/resource.h>
#include <sys/time.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <unistd.h>

using namespace std;

int main(int argn, char * args[]) {

    struct rlimit rl;

    getrlimit(RLIMIT_NPROC, &rl);

    rl.rlim_cur = atoi(args[1]);

    setrlimit(RLIMIT_NPROC, &rl);

    pid_t pid = 0;
    while (true) {

        if (pid == -1) {
                if (errno == EAGAIN) {
                        return 0;
                }
        }

        pid = fork();

        if (pid == 0) {
                sleep(1);
        } else if (pid > 0) {
        }

    }

    return 0;
}

