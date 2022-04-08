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
        // child process
        execlp("ping", "ping", "-c", "3", "google.com", NULL);
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("\nSuccess!\n");
        printf("\nSome post processing goes here!!\n");
    }

    return 0;
}