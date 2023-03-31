// #pragma once

typedef struct NODE
{
    char data[64];
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
int insertHead(LIST *list, char *data);
int insertTail(LIST *list, char *data);
NODE *find(LIST *list, char *data);
int delete(LIST *list, char *data);
void deleteAll(LIST *list);
void printAllElements(LIST *list);