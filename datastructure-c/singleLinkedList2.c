#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    char data[64];
    struct NODE *next;
} NODE;

NODE *g_pHead = NULL;

void printList(void);
int insertNewNode(char *data);

int main(int argc, char const *argv[])
{
    insertNewNode("sandro1");
    printList();
    insertNewNode("sandro2");
    printList();
    insertNewNode("sandro3");
    printList();
    return 0;
}

int insertNewNode(char *data)
{
    NODE *pNode = malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE)); // 메모리 초기화

    strcpy(pNode->data, data);

    if (g_pHead == NULL)
    {
        g_pHead = pNode;
        return 0;
    } 
    
    // 새로 생성한 노드를 헤드로 만들기
    // pNode->next = g_pHead;
    // g_pHead = pNode;

    // 새로 생성한 노드를 테일로 만들기
    NODE *tmp = g_pHead;
    NODE *tmpNext = g_pHead->next;

    while (tmp != NULL)
    {
        if (tmpNext == NULL)
        {
            tmp->next = pNode;
            return 0;
        }
        tmp = tmpNext;
        tmpNext = tmp->next;        
    }
    
    return 1;
}

void printList(void)
{
    for (NODE *pTmp = g_pHead; pTmp != NULL; pTmp = pTmp->next)
        printf("[%p] %s, next[%p]\n", pTmp, pTmp->data, pTmp->next);
    putchar('\n');
}

