#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include<string.h>
#include<stdlib.h>

void signal_handler(int signo) {
    printf("Received signal: %d\n", signo);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    int rc;

    // Obsługa wszystkich sygnałów
    for (int i = 1; i < NSIG; ++i) {
        rc = sigaction(i, &sa, NULL);
  
        if (rc == -1) {
            fprintf(stderr, "Unable to register handler for signal %d (%s)\n", i, strsignal(i));
        }
        else {
            printf("handler registered for signal %d (%s)\n", i, strsignal(i));
        }
    }

    return 0;
}
