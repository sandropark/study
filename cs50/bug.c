#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;

    y = x;

    *y = 13;
    return 0;
}
