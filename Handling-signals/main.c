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

void handle_sigtstp(int sig)
{
    printf("Stop not allowen\n");
}

void handle_sigcont(int sig)
{
    printf("Input number: ");
}

int main(int argc, char *argv[])
{
    struct sigaction sa;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCONT, &sa, NULL);



    // dont use this func for portable resons
    // signal(SIGTSTP, &handle_sigtstp);


    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result %d * 5 = %d\n", x, x * 5);

    return 0;
}
