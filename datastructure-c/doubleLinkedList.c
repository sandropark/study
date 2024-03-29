#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    const char *data;

    struct NODE *prev;
    struct NODE *next;
} NODE;

NODE *g_pHead, *g_pTail;
int g_size;

void insertAfter(NODE *pPrev, const char *data);
void insertBefore(NODE *pNext, const char *data);

int isEmpty()
{
    return g_size == 0;
}

void initList()
{
    g_pHead = malloc(sizeof(NODE));
    g_pTail = malloc(sizeof(NODE));
    g_size = 0;
    memset(g_pHead, 0, sizeof(NODE));
    memset(g_pTail, 0, sizeof(NODE));
    g_pHead->data = "HAED";
    g_pTail->data = "TAIL";
    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
}

NODE *createNode(const char *data)
{
    NODE *pNewNode = malloc(sizeof(NODE));
    memset(pNewNode, 0, sizeof(NODE));
    pNewNode->data = data;
    return pNewNode;
}

int insertHead(const char *data)
{
    insertAfter(g_pHead, data);
    return 1;
}

int insertTail(const char *data)
{
    insertBefore(g_pTail, data);
    return 1;
}

void print(const int expectedSize)
{
    printf("Size : 예상 %d, 실제 %d\n", expectedSize, g_size);
    for (NODE *pTmp = g_pHead; pTmp != NULL; pTmp = pTmp->next)
        printf("prev:[%11p], tmp:[%p], data:%6s, next:[%11p]\n", pTmp->prev, pTmp, pTmp->data, pTmp->next);
    printf("\n");
}

void deleteAll()
{
    NODE *pTmp = g_pHead->next;
    NODE *pDelete = NULL;
    while (pTmp != NULL)
    {
        if (pTmp == g_pTail) break;
        pDelete = pTmp;
        pTmp = pTmp->next;
        free(pDelete);
    }
    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
    g_size = 0;
}

NODE *find(const char *data)
{
    for (NODE *pTmp = g_pHead->next; pTmp != g_pTail; pTmp = pTmp->next)
        if (strcmp(pTmp->data, data) == 0) return pTmp;
    return NULL;
}

int delete(const char *data)
{   
    NODE *pDelete = find(data);
    if (pDelete == NULL) return 0;
    NODE *pPrev = pDelete->prev;
    NODE *pNext = pDelete->next;
    pPrev->next = pNext;
    pNext->prev = pPrev;
    free(pDelete);
    return --g_size;
}

void insertBefore(NODE *pNext, const char *data)
{
    NODE *pNewNode = createNode(data);
    pNewNode->prev = pNext->prev;
    pNewNode->next = pNext;
    pNext->prev->next = pNewNode;
    pNext->prev = pNewNode;
    g_size++;
}

void insertAfter(NODE *pPrev, const char *data)
{
    NODE *pNewNode = createNode(data);
    pNewNode->prev = pPrev;
    pNewNode->next = pPrev->next;
    pPrev->next->prev = pNewNode;
    pPrev->next = pNewNode;
    g_size++;
}

int insertAt(int idx, char *data)
{   
    int i = 0;
    for (NODE *pTmp = g_pHead->next; pTmp != g_pTail; pTmp = pTmp->next)
    {
        if (i == idx) {
            insertBefore(pTmp, data);
            return i;
        } 
        i++;
    }
    insertTail(data);
    return i;
}

NODE *getAt(int idx)
{
    if (idx >= g_size) return NULL;
    if (idx == g_size-1) return g_pTail->prev;

    NODE *pTmp = g_pHead;
    for (int i = 0; i < idx; i++)
        pTmp = pTmp->next;
    return pTmp->next;
}

int main(int argc, char const *argv[])
{   
    printf("initList() : 전역변수에 메모리 할당 및 초기화.\n");
    initList();
    print(0);

    printf("isEmpty() : 리스트가 비어있는 경우. 1을 반환한다.\n");
    printf("%s : 예상 %d, 실제 %d\n", "isEmpty", 1, isEmpty());
    putchar('\n');

    printf("insertHead() : 리스트 맨 앞에 A를 추가한다.\n");
    insertHead("A");
    print(1);

    printf("insertHead() : A가 든 리스트 맨 앞에 B를 추가한다. BA 순서대로 저장\n");
    insertHead("B");
    print(2);

    printf("deleteAll() : 리스트의 모든 요소를 삭제한다.\n");
    deleteAll();
    print(0);

    printf("insertTail() : 리스트 맨 뒤에 A를 추가한다.\n");
    insertTail("A");
    print(1);

    printf("insertTail() : A가 든 리스트 맨 뒤에 B를 추가한다. AB 순서대로 저장\n");
    insertTail("B");
    print(2);

    printf("delete() : ABC가 든 리스트에서 B를 삭제한다. AC가 남는다.\n");
    insertTail("C");
    delete("B");
    print(2);

    printf("delete() : AC가 든 리스트에서 A를 삭제한다. C만 남는다.\n");
    delete("A");
    print(1);

    printf("delete() : C가 든 리스트에서 C를 삭제한다. 빈 리스트가 된다.\n");
    delete("C");
    print(0);

    printf("delete() : 빈 리스트에 데이터 삭제시 아무일도 일어나지 않는다.\n");
    delete("C");
    print(0);

    printf("insertAt() : 빈 리스트에 인덱스 0으로 A를 추가한다. A가 출력된다.\n");
    insertAt(0, "A");
    print(1);
    deleteAll();

    printf("insertAt() : 유요하지 않은 인덱스의 경우 리스트 마지막에 데이터를 추가한다. A가 출력된다.\n");
    printf("%d\n", insertAt(1, "A"));
    print(1);
    deleteAll();

    printf("insertAt() : A가 든 리스트에 인덱스 1로 B를 추가하는 경우 AB가 출력된다.\n");
    insertAt(0, "A");
    insertAt(1, "B");
    print(2);
    deleteAll();

    printf("insertAt() : AC가 든 리스트에 인덱스 1로 B를 추가하는 경우 ABC가 출력된다.\n");
    insertAt(0, "A");
    insertAt(1, "B");
    insertAt(2, "C");
    print(3);
    deleteAll();

    printf("getAt() : ABC가 든 리스트에 인덱스 0로 조회할 시 A의 주소를 반환한다.\n");
    insertAt(0, "A");
    insertAt(1, "B");
    insertAt(1, "C");
    printf("getAt() : 예상 %p, 실제 %p\n\n", g_pHead->next, getAt(0));

    printf("getAt() : ABC가 든 리스트에 인덱스 2로 조회할 시 C의 주소를 반환한다.\n");
    printf("getAt() : 예상 %p, 실제 %p\n\n", g_pTail->prev, getAt(2));

    printf("getAt() : ABC가 든 리스트에 인덱스 1로 조회할 시 B의 주소를 반환한다.\n");
    printf("getAt() : 예상 %p, 실제 %p\n\n", g_pTail->prev->prev, getAt(1));

    printf("getAt() : ABC가 든 리스트에 범위를 넘어서는 인덱스로 조회할 시 NULL을 반환한다.\n");
    printf("getAt() : 예상 %p, 실제 %p\n\n", NULL, getAt(10));

    return 0;
}
