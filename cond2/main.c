// gcc -o main main.c -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <sys/poll.h>
#include <sys/file.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <sys/wait.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;
int fuel = 0;

void *fuel_filling(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel = fuel + 30;
        printf("Fillig Fuell is now %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40)
    {
        printf("Car is waiting for fuel\n");
        pthread_cond_wait(&condFuel, &mutexFuel);
    }
    fuel = fuel - 40;
    printf("Car is now %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
    return NULL;
}

// gcc -o main main.c -lpthread

int main()
{
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);
    pthread_t th[6];
    for (int i = 0; i < 6; i++)
    {
        if (i == 4 || i == 5)
        {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
            {
                printf("Error creating thread\n");
                exit(1);
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0)
            {
                printf("Error creating thread\n");
                exit(1);
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            printf("Error joining thread\n");
            exit(1);
        }
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}