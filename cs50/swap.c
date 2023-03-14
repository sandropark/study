#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);

int main(int argc, char const *argv[])
{
    int x = 1;
    int y = 2;

    printf("x=%i, y=%i\n", x, y);
    swap(&x, &y);
    printf("x=%i, y=%i\n", x, y);

    return 0;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}