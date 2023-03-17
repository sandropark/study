#include <stdio.h>

typedef struct NODE
{
    int number;         // 관리될 데이터
    struct NODE *next;  // 데이터 관리를 위한 포인터
} NODE;

int main(int argc, char const *argv[])
{
    NODE list[5] = {0};

    list[0].number = 100;
    list[1].number = 200;
    list[2].number = 300;
    list[3].number = 400;
    list[4].number = 500;

    list[0].next = &list[1];
    list[1].next = &list[2];
    list[2].next = &list[3];
    list[3].next = &list[4];
    list[4].next = NULL;

    for (int i = 0; i < 5; i++)
        printf("list[%d]: %d\n", i, list[i].number);

    for (NODE *pTmp = &list[0]; pTmp != NULL; pTmp = pTmp->next)
        printf("%p : %d\n", pTmp, pTmp->number);

    return 0;
}
