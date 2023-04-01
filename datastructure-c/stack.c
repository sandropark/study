#include "singleLinkedList.c"

int push(LIST *stack, char *data)
{
    return insertHead(stack, data);
}

NODE *pop(LIST *stack)
{
    if (isEmpty(stack)) return 0;

    NODE *pTmp = malloc(sizeof(NODE));
    NODE *pDelete = stack->pHead->next;
    memcpy(pTmp, pDelete, sizeof(NODE));
    stack->pHead->next = pDelete->next;
    if (stack->pTail == pDelete) stack->pTail = NULL;
    free(pDelete);
    stack->size--;
    return pTmp;
}

NODE *top(LIST *stack)
{   
    return stack->pHead->next;
}