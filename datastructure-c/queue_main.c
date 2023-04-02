#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.c"

typedef struct INTEGER
{
    int value;
} INTEGER;

void test()
{
    LIST queue = {0};
    initList(&queue);

    enqueue(&queue, "A");
    enqueue(&queue, "B");
    enqueue(&queue, "C");
    printf("%s\n", (char *)dequeue(&queue)->pData);
    printf("%s\n", (char *)dequeue(&queue)->pData);
    printf("%s\n", (char *)dequeue(&queue)->pData);
}

INTEGER *createInteger(int value)
{
    INTEGER *pTmp = malloc(sizeof(INTEGER));
    memset(pTmp, 0, sizeof(INTEGER));
    pTmp->value = value;
    return pTmp;
}

LIST *createJosephusQueue(int n)
{
    LIST *queue = malloc(sizeof(LIST));
    queue->pHead = malloc(sizeof(NODE));
    memset(queue->pHead, 0, sizeof(NODE));
    queue->size = 0;
    for (int i = 1; i <= n; i++)
        enqueue(queue, createInteger(i));
    return queue;
}

int josephus(int n, int k)
{   
    // 1. 큐 생성 및 초기화
    LIST *queue = createJosephusQueue(n);

    // 2. 로직 시작
    for (int i = 1; queue->size > 1; i++)
    {
        NODE *pTmp = dequeue(queue);
        if (i % k != 0)
            enqueueNode(queue, pTmp);
    }

    return ((INTEGER *)pop(queue)->pData)->value;
}

void josephusTest()
{
    int result = josephus(2, 1);
    printf("예상 %d 실제 %d\n", 2, result);

    result = josephus(3, 1);
    printf("예상 %d 실제 %d\n", 3, result);

    result = josephus(2, 2);
    printf("예상 %d 실제 %d\n", 1, result);

    result = josephus(6, 2);
    printf("예상 %d 실제 %d\n", 5, result);

    result = josephus(9, 3);
    printf("예상 %d 실제 %d\n", 1, result);
}

int main(int argc, char const *argv[])
{
    // test();
    josephusTest();

    return 0;
}