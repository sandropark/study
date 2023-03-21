#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    char data[64];
    struct NODE *next;
} NODE;

NODE *g_pHead = NULL;
NODE *g_pTail = NULL;

void printList(void);
int insertNewNode(char *data);
void releaseList(void);
void deleteNode(char *target);
int findNode(char *target);

int main(int argc, char const *argv[])
{
    insertNewNode("sandro1");
    printList();
    insertNewNode("sandro2");
    printList();
    insertNewNode("sandro3");
    printList();

    printf("sandro1 : %i\n", findNode("sandro1"));
    printf("sandro2 : %i\n", findNode("sandro2"));
    printf("sandro3 : %i\n\n", findNode("sandro3"));

    deleteNode("sandro2");
    printList();
    deleteNode("sandro1");
    printList();
    deleteNode("sandro3");
    printList();

    releaseList();

    insertNewNode("sandro1");
    printList();
    insertNewNode("sandro2");
    printList();
    insertNewNode("sandro3");
    printList();

    releaseList();
    return 0;
}

int findNode(char *target)
{
    NODE *pTmp = g_pHead;
    while(pTmp != NULL)
    {
        if (strcmp(pTmp->data, target) == 0) return 1;
        pTmp = pTmp->next;
    }
    return 0;
}

void deleteNode(char *target)
{   
    NODE *pPrev = NULL;
    NODE *pTmp = g_pHead;
    while (pTmp != NULL)
    {
        if (strcmp(pTmp->data, target) == 0)
        {
            printf("Found : %s\n", pTmp->data);
            if (pPrev == NULL)  // 해당 데이터가 헤드인경우
                g_pHead = g_pHead->next;
            else
                pPrev->next = pTmp->next;
            if (pTmp == g_pTail)
                g_pTail = 0;
            free(pTmp);
            return;
        }
        pPrev = pTmp;
        pTmp = pTmp->next;
    }
}

void releaseList(void)  // 리스트의 모든 요소를 삭제(free)한다.
{
    // 반복문을 돌면서 요소를 하나씩 삭제한다.
    NODE *pTmp = g_pHead;
    if (pTmp == NULL) return;
    NODE *pDelete = pTmp;   // 현재 포인터를 임시 포인터에 저장한다. 현재 포인터를 먼저 지우면 다음 노드를 가르키는 포인터를 잃기 때문이다.
    while (pDelete != NULL)
    {
        pTmp = pTmp->next;      // 현재 포인터를 다음으로 옮긴다. 
        printf("Delete: [%p] %s\n", pDelete, pDelete->data);
        free(pDelete); 
        pDelete = pTmp;
    }
    g_pHead = 0;
    g_pTail = 0;
}

int insertNewNode(char *data)
{
    NODE *pNode = malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE)); // 메모리 초기화

    strcpy(pNode->data, data);

    if (g_pHead == NULL)
        g_pHead = pNode;
    else
        g_pTail->next = pNode;
    g_pTail = pNode;
    
    return 1;
}

void printList(void)
{
    for (NODE *pTmp = g_pHead; pTmp != NULL; pTmp = pTmp->next)
        printf("[%p] %s, next[%p]\n", pTmp, pTmp->data, pTmp->next);
    putchar('\n');
}

