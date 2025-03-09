#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//program that tests if you can kill init process
//init process is the first process that is started by the kernel
//it has PID 1
//it is the parent of all processes
//it is the only process that is not a child of any other process
//it is the only process that is not killed when it receives SIGKILL signal

int main() {
    printf("Proba wyslania SIGKILL (PID 1)...\n");

    if (kill(1, SIGKILL) == -1) {
        perror("kill");
        printf("Nie mozna zabic procesu.\n");
    } else {
        printf("SIGKILl wyslano do init.\n");
    }

    return 0;
}
