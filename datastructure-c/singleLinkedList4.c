#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sigleLinkedList3에서 더미 노드를 추가

typedef struct NODE
{
    char data[64];
    struct NODE *next;
} NODE;

NODE g_pHead = {0};

int isEmpty()
{
    return g_pHead.next == NULL ? 1 : 0;
}

int insertHead(char *data) 
{
    NODE *pNode = malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE)); // 메모리를 0으로 초기화. 안해도 되지만 하는 것을 추천.
    strcpy(pNode->data, data);
    if (isEmpty() == 0)
        pNode->next = g_pHead.next;
    g_pHead.next = pNode;
    return 1;   // 요소 추가 성공 여부를 판단하기 위해서 반환한다.
}

int insertTail(char *data) 
{
    NODE *pNode = malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE)); // 메모리를 0으로 초기화. 안해도 되지만 하는 것을 추천.
    strcpy(pNode->data, data);

    NODE *pTmp = &g_pHead;
    while (pTmp->next != NULL)
        pTmp = pTmp->next;
    pTmp->next = pNode;
    return 1;   // 요소 추가 성공 여부를 판단하기 위해서 반환한다.
}

int find(char *data)
{
    for (NODE *pTmp = g_pHead.next; pTmp != NULL; pTmp = pTmp->next)
        if (strcmp(pTmp->data, data) == 0) return 1;
    return 0;
}

void deleteAll()
{
    NODE *pTmp = g_pHead.next;
    NODE *pDelete = NULL;
    while (pTmp != NULL)
    {
        pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s\n", pDelete, pDelete->data);
        free(pDelete);
    }
    g_pHead.next = NULL;
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    printf("isEmpty() : 리스트가 비어있는 경우. 1을 반환한다.\n");
    printf("isEmpty() : %d\n\n", isEmpty());
    
    printf("isEmpty() : 리스트에 요소가있는 경우. 0을 반환한다.\n");
    insertHead("A");
    printf("isEmpty() : %d\n", isEmpty());
    deleteAll();
    
    printf("insertHead() : 리스트 처음에 AB를 추가한다. BA가 출력된다.\n");
    insertHead("A");
    insertHead("B");
    deleteAll();

    printf("insertTail() : 리스트 마지막에 AB를 추가한다. AB가 출력된다.\n");
    insertTail("A");
    insertTail("B");
    deleteAll();

    printf("find() : 빈 리스트의 요소를 찾는 경우 0이 출력된다.\n");
    printf("result : %d\n\n", find("A"));

    printf("find() : A가 들어있는 리스트에서 A를 찾는 경우 1이 출력된다.\n");
    insertHead("A");
    printf("result : %d\n", find("A"));
    deleteAll();

    printf("find() : A가 들어있는 리스트에서 B를 찾는 경우 0이 출력된다.\n");
    insertHead("A");
    printf("result : %d\n", find("B"));
    deleteAll();
    
    return 0;
}
