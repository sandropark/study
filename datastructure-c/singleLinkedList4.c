#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sigleLinkedList3에서 더미 노드를 추가
// Stack과 Queue 구현

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

NODE *find(char *data) // 리스트에 해당 데이터가 있다면 해당 데이터를 가진 노드의 이전 노드의 주소를 반환한다. 
{
    NODE *pPrev = &g_pHead;
    NODE *pTmp = g_pHead.next;
    while (pTmp != NULL)
    {
        if (strcmp(pTmp->data, data) == 0) return pPrev;
        pPrev = pPrev->next;
        pTmp = pTmp->next;
    }
    return 0;
}

int delete(char *data)
{
    NODE *pPrev = find(data);
    if (pPrev != NULL)
    {
        NODE *pDelete = pPrev->next;
        pPrev->next = pDelete->next;
        printf("Delete() : %s\n", pDelete->data);
        free(pDelete);
        return 1;
    }
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

void push(char *data)
{
    insertHead(data);
}

int pop(NODE *pPopNode) // 가장 처음 노드를 삭제하고 외부에서 삭제한 데이터를 사용할 수 있게 매개변수에 메모리를 복사한다.
{
    if (isEmpty()) return 0;

    NODE *pDelete = g_pHead.next;
    memcpy(pPopNode, pDelete, sizeof(NODE));
    g_pHead.next = pDelete->next;   // 다음 데이터로
    printf("Pop() : %s\n", pDelete->data);
    free(pDelete);                  // 삭제
    return 1;
}

void printAllElements()
{
    printf("printAllElements() : ");
    for (NODE *pTmp = g_pHead.next; pTmp != NULL; pTmp = pTmp->next)
        printf("[%p] %s, next[%p] / ", pTmp, pTmp->data, pTmp->next);
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    printf("isEmpty() : 리스트가 비어있는 경우. 1을 반환한다.\n");
    if (isEmpty()) printf("1\n\n");
    
    
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
    printf("result : %p\n\n", find("A"));

    printf("find() : A가 들어있는 리스트에서 A를 찾는 경우 A 노드의 이전 노드의 주소가 출력된다.\n");
    insertHead("A");
    printf("result : %p\n", find("A"));
    deleteAll();

    printf("find() : A가 들어있는 리스트에서 B를 찾는 경우 0이 출력된다.\n");
    insertHead("A");
    printf("result : %p\n", find("B"));
    deleteAll();

    printf("delete() : 비어있는 리스트에서 A를 삭제한다. 0이 출력된다.\n");
    printf("Delete Result : %d\n\n", delete("A"));

    printf("delete() : A가 들어있는 리스트에서 A를 삭제한다. 1이 출력된다.\n");
    insertHead("A");
    printf("Delete Result : %d\n", delete("A"));
    deleteAll();

    // Stack
    printf("Stack : ABC를 순서대로 push()한다. CBA가 출력된다.\n");
    push("A");
    push("B");
    push("C");
    printAllElements();
    deleteAll();

    printf("Stack : 빈 Stack에 Pop()한다. 0이 출력된다.\n");
    NODE tmp = {0};
    printf("Pop() : %d\n\n", pop(&tmp));
    
    printf("Stack : CBA가 들어있는 Stack에 Pop()을 하면 CBA 순서대로 꺼내진다.\n");
    push("A");
    push("B");
    push("C");
    pop(&tmp);
    pop(&tmp);
    pop(&tmp);

    return 0;
}
