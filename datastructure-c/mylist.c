void initList(LIST *list, const char *(*pFunc)(void *))
{
    list->pHead = malloc(sizeof(NODE));
    list->pTail = malloc(sizeof(NODE));
    memset(list->pHead, 0, sizeof(NODE));
    memset(list->pTail, 0, sizeof(NODE));
    list->pHead->next = list->pTail;
    list->pTail->prev = list->pHead;
    list->size = 0;
    list->getKey = pFunc;
}

void clear(LIST *list)
{
    NODE *pHead = list->pHead;
    NODE *pTail = list->pTail;

    NODE *pTmp = pHead->next;
    NODE *pDelete = NULL;
    while (pTmp != pTail)
    {
        pDelete = pTmp;
        pTmp = pTmp->next;
        free(pDelete->pData);
        free(pDelete);
    }
    pHead->next = pTail;
    pTail->prev = pHead;
    list->size = 0;
}

NODE *createNode(void *data)    // 생성자
{
    NODE *pNew = malloc(sizeof(NODE));
    memset(pNew, 0, sizeof(NODE));
    pNew->pData = data;
    return pNew;
}

int insertBefore(LIST *list, NODE *pNext, NODE *pNew)
{

    if (pNext == list->pHead) return 0;
    NODE *pPrev = pNext->prev;

    pNew->prev = pPrev;
    pNew->next = pNext;

    pNext->prev = pNew;
    pPrev->next = pNew;
    list->size++;
    return 1;
}

int insertAfter(LIST *list, NODE *pPrev, NODE *pNew)
{
    if (pPrev == list->pTail) return 0;
    NODE *pNext = pPrev->next;

    pNew->prev = pPrev;
    pNew->next = pNext;

    pNext->prev = pNew;
    pPrev->next = pNew;
    list->size++;
    return 1;
}

int insertHead(LIST *list, void *pData)
{
    return insertAfter(list, list->pHead, createNode(pData));
}

int insertTail(LIST *list, void *pData)
{
    return insertBefore(list, list->pTail, createNode(pData));
}

NODE *findNodeByKey(LIST *list, const char *key)
{
    NODE *pHead = list->pHead;
    NODE *pTail = list->pTail;
    for (NODE *pTmp = pHead->next; pTmp != pTail; pTmp = pTmp->next)
        if (strcmp(list->getKey(pTmp->pData), key) == 0) return pTmp;
    return NULL;
}

void deleteByKey(LIST *list, const char *key)
{
    NODE *pDelete = findNodeByKey(list, key);

    NODE *pNext = pDelete->next;
    NODE *pPrev = pDelete->prev;

    pNext->prev = pPrev;
    pPrev->next = pNext;

    free(pDelete->pData);
    free(pDelete);
    list->size--;
}