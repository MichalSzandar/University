#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// program to handle SIGUSR1 signals
// it counts how many signals it received

volatile int signal_count = 0;

void signal_handler(int signo) {
    ++signal_count;
    printf("Received SIGUSR1, count: %d\n", signal_count);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Program is running, PID: %d\n", getpid());
    printf("Send multiple SIGUSR1 signals to this process.\n");

    while (1) {
        pause();
    }

    return 0;
}
