// gcc -o main main.c  ; ./main


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    char str[] = "Les's break this string into pieces";
    // string token
    strtok(str, " ");
    return 0;


}