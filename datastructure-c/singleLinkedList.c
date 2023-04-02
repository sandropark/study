#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "singleLinkedList.h"

void initList(LIST *list)
{
    list->pHead = malloc(sizeof(NODE));
    memset(list->pHead, 0, sizeof(NODE));
    list->size = 0;
}

int isEmpty(LIST *list)
{
    return list->size == 0 ? 1 : 0;
}

NODE *createNode(void *data)
{
    NODE *pNode = malloc(sizeof(NODE));
    memset(pNode, 0, sizeof(NODE));
    pNode->pData = data;
    return pNode;
}

int insertHead(LIST *list, void *data) 
{
    NODE *pNew = createNode(data);

    if (isEmpty(list))
        list->pTail = pNew;
    else
        pNew->next = list->pHead->next;
    list->pHead->next = pNew;
    list->size++;
    return 1;
}

int insertTail(LIST *list, void *data) 
{
    NODE *pNew = createNode(data);

    if (isEmpty(list))
        list->pHead->next = pNew;
    else 
        list->pTail->next = pNew;
    list->pTail = pNew;
    list->size++;
    return 1;   // 요소 추가 성공 여부를 판단하기 위해서 반환한다.
}

// NODE *find(LIST *list, void *data) // 리스트에 해당 데이터가 있다면 해당 데이터를 가진 노드의 이전 노드의 주소를 반환한다. 
// {
//     NODE *pPrev = list->pHead;
//     NODE *pTmp = list->pHead->next;
//     while (pTmp != NULL)
//     {
//         if (strcmp(pTmp->data, data) == 0) 
//         {
//             printf("find = [%p, %s]\n", pPrev, pPrev->data);
//             return pPrev;
//         }
//         pPrev = pPrev->next;
//         pTmp = pTmp->next;
//     }
//     return NULL;
// }

// int delete(LIST *list, char *data)
// {
//     NODE *pPrev = find(list, data);
//     if (pPrev != NULL)
//     {
//         NODE *pDelete = pPrev->next;
//         NODE *pTail = list->pTail;
//         pPrev->next = pDelete->next;
//         if (pTail == pDelete) pTail = NULL;
//         free(pDelete);
//         list->size--;
//         return 1;
//     }
//     return 0;    
// }