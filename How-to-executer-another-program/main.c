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
// windows <process.h>

// gcc main.c -o main

int main(int argc, char *argv[])
{

    // execl("ping", "ping", "google.com",NULL); will work only if you know the path to ping program
    // execlp("ping", "ping", "google.com", NULL);
    execlp("ping2", "ping", "google.com", NULL);
    int err = errno;
    printf("err: %d", err);
    return 0;
}