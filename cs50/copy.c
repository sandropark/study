#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *deep_copy(char *s);

int main(void)
{
    char *s = "emmma";
    char *t = deep_copy(s);

    *t -= 32;

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
}

char *deep_copy(char *s)
{
    char *t = malloc(strlen(s) + 1);
    for (int i = 0, n = strlen(s) + 1; i < n; i++)
        t[i] = s[i];
    return t;
}