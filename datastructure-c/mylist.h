// #pragma once // 인클루드가 중복되는 경우 한 번만 적용.

typedef struct NODE
{
    void *pData;  // 관리 대상 자료

    // 자료구조
    struct NODE *prev;
    struct NODE *next;
} NODE;

typedef struct LIST
{
    NODE *pHead;
    NODE *pTail;
    int    size;

    // 맴버 함수 포인터
    const char *(*getKey)(void *);
} LIST;

void initList(LIST *list, const char *(*pFunc)(void *));
void clear(LIST *list);
NODE *createNode(void *data);
int insertBefore(LIST *list, NODE *pNext, NODE *pNew);
int insertAfter(LIST *list, NODE *pPrev, NODE *pNew);
int insertHead(LIST *list, void *pData);
int insertTail(LIST *list, void *pData);
NODE *findNodeByKey(LIST *list, const char *key);
void deleteByKey(LIST *list, const char *key);