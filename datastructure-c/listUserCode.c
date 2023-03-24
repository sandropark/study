#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mylist.h"
#include "mylist.c"

typedef struct USER
{
    char name[64];
    char phone[64];
} USER;

const char *getNameFromUser(void *pUser)
{
    return ((USER *)pUser)->name;
}

USER *createUser(char *name, char *phone)   // 생성자
{
    USER *pNew = malloc(sizeof(USER));
    strcpy(pNew->name, name);
    strcpy(pNew->phone, phone);
    return pNew;
}

void validateNode(LIST *list, NODE *pNode)
{
    if (pNode == NULL) return;
    USER *pUser = pNode->pData;
    printf("ValidateNode : prev=[%11p] tmp=[%p] data=[%s] next=[%p]\n", pNode->prev, pNode, list->getKey(pUser), pNode->next);
}

void validate(LIST *list, int expectedSize)
{   
    NODE *pHead = list->pHead;
    NODE *pTail = list->pTail;
    printf("Size : 예상 %d 실제 %d\n", expectedSize, list->size);
    for (NODE *pTmp = pHead; pTmp != NULL; pTmp = pTmp->next)
    {
        if (pTmp == pHead)
            printf("prev=[%11p] HEAD=[%p] data=[%p] next=[%p]\n",pTmp->prev, pTmp, NULL, pTmp->next);
        else if (pTmp == pTail)
            printf("prev=[%p] TAIL=[%p] data=[%p] next=[%11p]\n",pTmp->prev, pTmp, NULL, pTmp->next);
        else
        {
            USER *pUser = pTmp->pData;
            printf("prev=[%11p] tmp =[%p] data=[%3s] next=[%11p]\n", pTmp->prev, pTmp, list->getKey(pUser),  pTmp->next);
        }
    }
    putchar('\n');
    clear(list);
}

int main(int argc, char const *argv[])
{
    LIST list = {0};
    initList(&list, getNameFromUser);
    validate(&list, 0);

    printf("insertHead() : 가장 앞에 데이터를 추가한다.\n");
    insertHead(&list, createUser("B", "010-1234-1234"));
    insertHead(&list, createUser("A", "010-1234-1234"));
    validate(&list, 2);

    printf("insertTail() : 가장 뒤에 데이터를 추가한다.\n");
    insertTail(&list, createUser("A", "010-1234-1234"));
    insertTail(&list, createUser("B", "010-1234-1234"));
    validate(&list, 2);

    printf("findNodeByKey() : 이름이 A인 노드를 반환한다.\n");
    insertTail(&list, createUser("A", "010-1234-1234"));
    insertTail(&list, createUser("B", "010-1234-1234"));
    validateNode(&list, findNodeByKey(&list, "A"));
    clear(&list);
    putchar('\n');
    
    printf("deleteByKey() : 이름이 A인 노드를 삭제한다.\n");
    insertTail(&list, createUser("A", "010-1234-1234"));
    insertTail(&list, createUser("B", "010-1234-1234"));
    deleteByKey(&list, "A");
    validate(&list, 1);

    return 0;
}