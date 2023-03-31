#include "singleLinkedList.c"

int push(LIST *stack, char *data)
{
    return insertHead(stack, data);
}

int pop(LIST *stack, NODE *pPopNode)
{
    if (isEmpty(stack)) return 0;

    NODE *pDelete = stack->pHead->next;
    memcpy(pPopNode, pDelete, sizeof(NODE));
    stack->pHead->next = pDelete->next;
    if (stack->pTail == pDelete) stack->pTail = NULL;
    printf("pop = [%p, %s]\n", pDelete, pDelete->data);
    free(pDelete);
    stack->size--;
    return 1;
}

NODE *top(LIST *stack)
{
    NODE *pTop = stack->pHead->next;
    printf("top = [%p, %s]\n", pTop, pTop->data);
    return pTop;
}