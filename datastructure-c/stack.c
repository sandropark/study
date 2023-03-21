#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int value;
    struct NODE *next;
} NODE;

NODE *stack = NULL;

void push(int value);
void print();
int pop();

int main(void)
{
    push(1);
    push(2);
    push(3);

    print();

    printf("Pop() : %d\n", pop());
    printf("Pop() : %d\n", pop());
    printf("Pop() : %d\n", pop());
    printf("Pop() : %d\n", pop());
    return 0;
}

void push(int value)
{
    NODE *pTmp = malloc(sizeof(NODE));
    pTmp->value = value;
    pTmp->next = stack;
    stack = pTmp;
}

int pop()
{
    if (stack == NULL) return 0;
    NODE *pDelete = stack;
    int result = pDelete->value;
    stack = stack->next;
    free(pDelete);
    return result;
}

void print()
{
    NODE *pTmp = stack;
    if (pTmp != NULL)
    {
        printf("%d", pTmp->value);
        pTmp = pTmp->next;
    }
    while (pTmp != NULL)
    {
        printf(",%d", pTmp->value);
        pTmp = pTmp->next;
    }
    printf("\n");
}