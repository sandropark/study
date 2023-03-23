#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USER
{
    char name[64];
    char phone[64];
} USER;

const char *getKeyFromUser(void *pData)
{
    return ((USER *)pData)->name;
}

typedef struct NODE
{
    // 관리 대상 자료
    void *pData;

    // 맴버 함수 포인터
    const char *(*getKey)(void *);

    // 자료구조
    struct NODE *prev;
    struct NODE *next;
} NODE;

NODE *g_pHead, *g_pTail;
int g_size;

void initList()
{
    g_pHead = malloc(sizeof(NODE));
    g_pTail = malloc(sizeof(NODE));
    memset(g_pHead, 0, sizeof(NODE));
    memset(g_pTail, 0, sizeof(NODE));
    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
    g_size = 0;
}

void validateNode(NODE *pNode)
{
    printf("ValidateNode : prev=[%11p] tmp=[%p] data=[%s] next=[%p]\n", pNode->prev, pNode, pNode->getKey(pNode->pData), pNode->next);
}

void clear()
{
    NODE *pTmp = g_pHead->next;
    NODE *pDelete = NULL;
    while (pTmp != g_pTail)
    {
        pDelete = pTmp;
        pTmp = pTmp->next;
        free(pDelete->pData);
        free(pDelete);
    }
    g_pHead->next = g_pTail;
    g_pTail->prev = g_pHead;
    g_size = 0;
}

void validate(int expectedSize)
{
    printf("Size : 예상 %d 실제 %d\n", expectedSize, g_size);
    for (NODE *pTmp = g_pHead; pTmp != NULL; pTmp = pTmp->next)
    {
        if (pTmp == g_pHead)
            printf("HEAD=[%p] next=[%p]\n", pTmp, pTmp->next);
        else if (pTmp == g_pTail)
            printf("TAIL=[%p] prev=[%p]\n", pTmp, pTmp->prev);
        else
            printf("prev=[%11p] tmp=[%p] data=[%s] next=[%11p]\n", pTmp->prev, pTmp, pTmp->getKey(pTmp->pData),  pTmp->next);
    }
    putchar('\n');
    clear();
}

NODE *createNode(void *data, const char *(*pFunc)(void *))
{
    NODE *pNew = malloc(sizeof(NODE));
    memset(pNew, 0, sizeof(NODE));
    pNew->pData = data;
    pNew->getKey = pFunc;
    return pNew;
}

USER *createUser(char *name, char *phone)
{
    USER *pNew = malloc(sizeof(USER));
    strcpy(pNew->name, name);
    strcpy(pNew->phone, phone);
    return pNew;
}

int insertBefore(NODE *pNext, NODE *pNew)
{
    if (pNext == g_pHead) return 0;
    NODE *pPrev = pNext->prev;

    pNew->prev = pPrev;
    pNew->next = pNext;

    pNext->prev = pNew;
    pPrev->next = pNew;
    g_size++;
    return 1;
}

int insertAfter(NODE *pPrev, NODE *pNew)
{
    if (pPrev == g_pTail) return 0;
    NODE *pNext = pPrev->next;

    pNew->prev = pPrev;
    pNew->next = pNext;

    pNext->prev = pNew;
    pPrev->next = pNew;
    g_size++;
    return 1;
}

int insertHead(void *pData, const char *(*pFunc)(void *))
{
    insertAfter(g_pHead, createNode(pData, pFunc));
    return 1;
}

int insertTail(void *pData, const char *(*pFunc)(void *))
{
    insertBefore(g_pTail, createNode(pData, pFunc));
    return 1;
}

NODE *findNodeByKey(const char *key)
{
    for (NODE *pTmp = g_pHead->next; pTmp != g_pTail; pTmp = pTmp->next)
        if (strcmp(pTmp->getKey(pTmp->pData), key) == 0) return pTmp;
    return NULL;
}

void deleteByKey(const char *key)
{
    NODE *pDelete = findNodeByKey(key);

    NODE *pNext = pDelete->next;
    NODE *pPrev = pDelete->prev;

    pNext->prev = pPrev;
    pPrev->next = pNext;

    free(pDelete->pData);
    free(pDelete);
    g_size--;
}

int main(int argc, char const *argv[])
{
    initList();

    printf("insertBefore() : g_pHead의 앞에는 노드를 추가할 수 없다. 0을 반환한다.\n");
    printf("StatusCode = %d\n\n", insertBefore(g_pHead, malloc(sizeof(NODE))));

    printf("insertAfter() : g_pTail의 뒤에는 노드를 추가할 수 없다. 0을 반환한다.\n");
    printf("StatusCode = %d\n\n", insertAfter(g_pTail, malloc(sizeof(NODE))));

    printf("insertHead() : 가장 앞에 데이터를 추가한다.\n");
    insertHead(createUser("B", "010-1234-1234"), getKeyFromUser);
    insertHead(createUser("A", "010-1234-1234"), getKeyFromUser);
    validate(2);

    printf("insertTail() : 가장 뒤에 데이터를 추가한다.\n");
    insertTail(createUser("A", "010-1234-1234"), getKeyFromUser);
    insertTail(createUser("B", "010-1234-1234"), getKeyFromUser);
    validate(2);

    printf("findNodeByKey() : 이름이 A인 노드를 반환한다.\n");
    insertTail(createUser("A", "010-1234-1234"), getKeyFromUser);
    insertTail(createUser("B", "010-1234-1234"), getKeyFromUser);
    validateNode(findNodeByKey("A"));
    clear();
    putchar('\n');
    
    printf("deleteByKey() : 이름이 A인 노드를 삭제한다.\n");
    insertTail(createUser("A", "010-1234-1234"), getKeyFromUser);
    insertTail(createUser("B", "010-1234-1234"), getKeyFromUser);
    deleteByKey("A");
    validate(1);

    return 0;
}

