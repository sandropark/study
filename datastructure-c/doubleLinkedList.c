#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *prev;
    char *data;
    struct NODE *next;
} NODE;

NODE *g_pHead = NULL;
NODE *g_pTail = NULL;

int isEmpty()
{
    if (g_pHead == NULL && g_pTail == NULL)
        return 1;
    return 0;
}
void insertHead(char *data)
{
    NODE *pTmp = malloc(sizeof(NODE));
    pTmp->data = data;
    if (isEmpty())
    {
        g_pHead = pTmp;
        g_pTail = pTmp;
        return;
    }
    g_pHead->prev = pTmp;
    pTmp->next = g_pHead;
    g_pHead = pTmp;
}
void insertTail(char *data)
{
    NODE *pTmp = malloc(sizeof(NODE));
    pTmp->data = data;
    if (isEmpty())
    {
        g_pHead = pTmp;
        g_pTail = pTmp;
        return;
    }
    g_pTail->next = pTmp;
    pTmp->prev = g_pTail;
    g_pTail = pTmp;
}
void print()
{
    NODE *pTmp = g_pHead;
    while (pTmp != NULL)
    {
        printf("%s\n", pTmp->data);
        pTmp = pTmp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    insertHead("sandro1");
    insertHead("sandro2");
    insertHead("sandro3");

    print();

    insertTail("sandro1");
    insertTail("sandro2");
    insertTail("sandro3");

    print();
    return 0;
}
