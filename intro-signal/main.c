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

// gcc main.c -o main

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == -1)
    {
        return 1;
    }
    if (pid == 0)
    {
        while (1)
        {
            printf("Some text\n");
            usleep(50000);
        }
    }
    else
    {
        sleep(1);
        kill(pid, SIGKILL);
        wait(NULL);
    }

    return 0;
}