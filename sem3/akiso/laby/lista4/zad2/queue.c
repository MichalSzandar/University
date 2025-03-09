#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//program that tests if signals are queued
//send SIGUSR1 multiple times to the process with given PID

int main()
{
    int pid;
    printf("Enter the PID of the process: ");
    scanf("%d", &pid);
    // send SIGUSR1 multiple times
    for (int i = 0; i < 5; i++)
    {
        printf("Sending SIGUSR1 to the process with PID: %d\n", pid);
        kill(pid, SIGUSR1);
    }
}
