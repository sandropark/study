// #pragma once

typedef struct NODE
{
    void *pData;
    struct NODE *next;
} NODE;

typedef struct LIST
{
    NODE *pHead;
    NODE *pTail;
    int size;
} LIST;

void initList(LIST *list);
int isEmpty(LIST *list);
int insertHead(LIST *list, void *data);
int insertTail(LIST *list, void *data);
NODE *find(LIST *list, void *data);
int delete(LIST *list, void *data);
void deleteAll(LIST *list);
void printAllElements(LIST *list);