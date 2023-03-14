#include <stdio.h>
#include "cs50.h"
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *file = fopen("phonebook.csv", "a");

    char *name = get_string("Name : ");
    char *number = get_string("Number : ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
    return 0;
}
