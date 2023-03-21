#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    char data[64];
    struct NODE *next;
} NODE;

NODE *g_pHead = NULL;

void printAllElements()
{
    printf("printAllElements() : ");
    for (NODE *pTmp = g_pHead; pTmp != NULL; pTmp = pTmp->next)
        printf("[%p] %s, next[%p] / ", pTmp, pTmp->data, pTmp->next);
    putchar('\n');
}

int addHead(char *data) 
{
    NODE *pNode = malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE)); // 메모리를 0으로 초기화. 안해도 되지만 하는 것을 추천.
    strcpy(pNode->data, data);
    if (g_pHead != NULL)
        pNode->next = g_pHead;
    g_pHead = pNode;
    return 1;   // 요소 추가 성공 여부를 판단하기 위해서 반환한다.
}

void delete(char *data)
{
    NODE *pTmp = g_pHead;
    NODE *pPrev = NULL;
    while (pTmp != NULL)
    {
        if (strcmp(pTmp->data, data) == 0)
        {
            if (pPrev == NULL)  // pTmp가 헤드인 경우
                g_pHead = pTmp->next;
            else
                pPrev->next = pTmp->next;
            free(pTmp);
        }
        pPrev = pTmp;
        pTmp = pTmp->next;
    }
}

void deleteAll()
{
    NODE *pTmp = g_pHead;
    NODE *pDelete = NULL;
    while (pTmp != NULL)
    {
        pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s\n", pDelete, pDelete->data);
        free(pDelete);
    }
    g_pHead = NULL;
}

int find(char *data)
{
    for (NODE *pTmp = g_pHead; pTmp != NULL; pTmp = pTmp->next)
        if (strcmp(pTmp->data, data) == 0) return 1;
    return 0;
}

void before()
{
    printAllElements();
    deleteAll();
    printf("\n");
}

int main(int argc, char const *argv[])
{   
    printf("printAllElements() : 요소가 없을 경우 아무것도 출력되지 않는다.\n");
    before();

    printf("addHead() : A를 추가하고 A가 출력되야 한다.\n");
    addHead("A");
    before();

    printf("addHead() : 이미 A가 추가된 리스트에 B를 추가하고 BA가 출력되야 한다.\n");
    addHead("A");
    addHead("B");
    before();

    printf("deleteAll() : 모든 노드를 삭제한다. 아무것도 출력되지 않는다.\n");
    addHead("A");
    addHead("B");
    deleteAll();
    before();

    printf("delete() : 빈 배열에서 노드 삭제시 아무일도 일어나지 않는다. 아무것도 출력되지 않는다.\n");
    delete("A");
    before();

    printf("delete() : A 노드만 포함된 리스트에서 A 노드를 삭제한다. 아무것도 출력되지 않는다.\n");
    addHead("A");
    delete("A");
    before();

    printf("delete() : AB 노드가 포함된 리스트에서 A 노드를 삭제한다. B가 출력된다.\n");
    addHead("B");
    addHead("A");
    delete("A");
    before();

    printf("delete() : AB 노드가 포함된 리스트에서 B 노드를 삭제한다. A가 출력된다.\n");
    addHead("B");
    addHead("A");
    delete("B");
    before();

    printf("delete() : ABC 노드가 포함된 리스트에서 B 노드를 삭제한다. AC가 출력된다.\n");
    addHead("C");
    addHead("B");
    addHead("A");
    delete("B");
    before();

    printf("delete() : delete를 한 리스트에 다시 A를 추가한다. A가 출력된다.\n");
    addHead("A");
    delete("A");
    addHead("A");
    before();

    printf("find() : 빈 리스트의 요소를 찾는 경우 0이 출력된다.\n");
    printf("result : %d\n\n", find("A"));

    printf("find() : A가 들어있는 리스트에서 A를 찾는 경우 1이 출력된다.\n");
    addHead("A");
    printf("result : %d\n", find("A"));
    before();

    printf("find() : A가 들어있는 리스트에서 B를 찾는 경우 0이 출력된다.\n");
    addHead("A");
    printf("result : %d\n", find("B"));
    before();

    return 0;
}
