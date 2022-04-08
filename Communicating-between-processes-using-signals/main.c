#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>

// gcc main.c -o main ; ./main
 int x;
void handle_sigtstp(int sig)
{
    printf("Stop not allowen\n");
}

void handle_sigcont(int sig)
{
    printf("Input number: ");
}

void handle_sigusr1(int sig)
{
    if (x == 0)
    {
        printf("\n(Hint)remember that multiplication is repetetaive addition\n");
    }
}

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        return 1;
    }
    if (pid == 0)
    {
        // Child
        sleep(5);
        kill(getppid(), SIGUSR1);
    }
    else
    {
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1, &sa, NULL);
        // Parent process
       
        printf("What is the result of 3 x 5: ");
        scanf("%d", &x);
        if (x == 15)
        {
            printf("Right\n");
        }
        else
        {
            printf("Wrong\n");
        }
        wait(NULL);
    }

    return 0;
}
