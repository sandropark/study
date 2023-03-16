#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void print(node *list);
node *getNode(int number);

int main(int argc, char const *argv[])
{
    node *list = NULL;
    list = getNode(2);
    print(list);

    list->next = getNode(3);
    print(list);

    // 맨 앞에 1추가
    node *n = malloc(sizeof(node));
    if (n == NULL) return 1;
    n->number = 1;
    n->next = list;
    list = n;
    
    print(list);

    // 2 삭제하기
    node *pre = NULL;
    node *tmp = list;
    while(tmp != NULL)
    {
        if (tmp->number == 2)
        {
            if (pre == NULL)
                list = list->next;
            else {
                pre->next = tmp->next;
                free(tmp);
            }
        }
        pre = tmp;
        tmp = tmp->next;
    }

    print(list);

    return 0;
}

void print(node *list)
{
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
        printf("%i\n", tmp->number);
    printf("------\n");
}

node *getNode(int number)
{
    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = number;
        n->next = NULL;
    }
    return n;
}