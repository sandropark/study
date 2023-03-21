#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int value;
    struct NODE *next;
} NODE;

NODE *queue = NULL;

void put(int value)
{
    NODE *pTmp = malloc(sizeof(NODE));
    pTmp->value = value;
    NODE *pTmpQueue = queue;
    if (pTmpQueue == NULL)
    {
        queue = pTmp;
        return;
    }
    while (pTmpQueue->next != NULL)
        pTmpQueue = pTmpQueue->next;
    pTmpQueue->next = pTmp;
}

int get()
{
    NODE *pDelete = queue;
    int result = pDelete->value;
    queue = queue->next;
    free(pDelete);
    return result;
}

void print()
{
    NODE *pTmp = queue;
    printf("print() : ");
    while (pTmp != NULL)
    {
        printf("%d", pTmp->value);
        pTmp = pTmp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    put(1);
    put(2);
    put(3);

    print();

    printf("get() : %d\n", get());
    print();
    printf("get() : %d\n", get());
    print();
    printf("get() : %d\n", get());
    print();
    return 0;
}

