#include "stdio.h"
#include "stdlib.h"

long long add(int a, int b)
{
    return a + b;
}

long long mul(int a, int b)
{
    return a * b;
}

void exec(long long (*func)(int, int))
{
    printf("%lld\n", func(5, 6));
}

int main(int argc, char *argv[])
{
    long long (*func)(int, int);
    func = &mul;
    printf("%lld\n", func(5, 6));
    func = &add;
    printf("%lld\n", add(5, 6));
    exec(&mul);
    exec(&add);

    return 0;
}