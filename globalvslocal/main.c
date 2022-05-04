// gcc -o main main.c -lm ; ./main
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int x;
void g1();
void f1(){
    int x = 15;
    x = 15;
    g1();
    // printf("value of x is %d\n", x);
}

void g1(){
    // int x = 20;
    printf("value of x is %d\n", x);
}

int main(int argc, char *argv[]){
    f1();
    return 0;
}