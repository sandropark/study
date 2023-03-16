#include <stdio.h>
#include <stdlib.h>

void extend(int *list);

int main(int argc, char const *argv[])
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL) return 1;

    for (int i = 0; i < 3; i++)
        list[i] = i + 1;

    // int *tmp = malloc(4 * sizeof(int));
    // if (tmp == NULL) return 1;

    // for (int i = 0; i < 3; i++)
    //     tmp[i] = list[i];
    // tmp[3] = 4;
    // free(list);
    // list = tmp;

    // int *tmp = realloc(list, 4 * sizeof(int));
    // if (tmp == NULL) return 1;
    // tmp[3] = 4;

    extend(list);

    for (int i = 0; i < 4; i++)
        printf("%i", list[i]);
    printf("\n");

    return 0;
}

void extend(int *list)
{
    int *tmp = realloc(list, 4 * sizeof(int));
    tmp[3] = 4;
}