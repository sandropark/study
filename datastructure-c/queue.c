#include "stack.c"

void enqueue(LIST *queue, void *data)
{
    insertTail(queue, data);
}

void enqueueNode(LIST *queue, NODE *pNode)
{
    if (isEmpty(queue))
        queue->pHead->next = pNode;
    else 
        queue->pTail->next = pNode;
    queue->pTail = pNode;
    queue->size++;
}

NODE *dequeue(LIST *queue)
{
    return pop(queue);
}