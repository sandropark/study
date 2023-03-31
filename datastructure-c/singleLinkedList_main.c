#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "singleLinkedList.c"

void validate(LIST *list, int expectedSize)
{
    printf("Size : 예상=[%d] 실제=[%d]\n", expectedSize, list->size);
    printAllElements(list);
}

int main(int argc, char const *argv[])
{
    LIST list = {0};
    initList(&list);

    printf("isEmpty() : 리스트가 비어있는 경우. 1을 반환한다.\n");
    printf("%d\n\n", isEmpty(&list));

    printf("insertHead() : 리스트 처음에 A를 추가한다. A가 출력된다.\n");
    insertHead(&list, "A");
    validate(&list, 1);
    deleteAll(&list);
    
    printf("isEmpty() : 리스트에 요소가있는 경우. 0을 반환한다.\n");
    insertHead(&list, "A");
    printf("%d\n", isEmpty(&list));
    deleteAll(&list);
    
    printf("insertHead() : 리스트 처음에 AB를 추가한다. BA가 출력된다.\n");
    insertHead(&list, "A");
    insertHead(&list, "B");
    validate(&list, 2);
    deleteAll(&list);

    printf("insertTail() : 리스트 마지막에 AB를 추가한다. AB가 출력된다.\n");
    insertTail(&list, "A");
    insertTail(&list, "B");
    validate(&list, 2);
    deleteAll(&list);

    printf("find() : 빈 리스트의 요소를 찾는 경우 0x0이 출력된다.\n");
    printf("result : %p\n\n", find(&list, "A"));

    printf("find() : A가 들어있는 리스트에서 A를 찾는 경우 A 노드의 이전 노드의 주소가 출력된다.\n");
    insertHead(&list, "A");
    find(&list, "A");
    deleteAll(&list);

    printf("find() : A가 들어있는 리스트에서 B를 찾는 경우 0이 출력된다.\n");
    insertHead(&list, "A");
    printf("result : %p\n", find(&list, "B"));
    deleteAll(&list);

    printf("delete() : 비어있는 리스트에서 A를 삭제한다. 0이 출력된다.\n");
    printf("Delete Result : %d\n\n", delete(&list, "A"));

    printf("delete() : A가 들어있는 리스트에서 A를 삭제한다. 1이 출력된다.\n");
    insertHead(&list, "A");
    printf("Delete Result : %d\n", delete(&list, "A"));
    validate(&list, 0);
    deleteAll(&list);



    // // Queue
    // printf("Queue : ABC를 순서대로 Put()한다. ABC가 출력된다.\n");
    // put("A");
    // put("B");
    // put("C");
    // printAllElements();
    // putchar('\n');

    // printf("Queue : ABC가 들어있는 Queue에서 Get()을 하면 ABC 순서대로 삭제된다.\n");
    // get(&tmp);
    // get(&tmp);
    // get(&tmp);
    // putchar('\n');

    // printf("Tail 추가 - insertHead() : 빈 리스트에 A를 넣으면 head와 tail 모두 A를 가르킨다.\n");
    // insertHead("A");
    // printf("Head : %s\n", g_pHead.next->data);
    // printf("tail : %s\n", g_pTail->data);
    // putchar('\n');

    // printf("Tail 추가 - insertHead() : A가 든 리스트에 B를 넣으면 head는 B, tail은 A를 가르킨다.\n");
    // insertHead("B");
    // printf("Head : %s\n", g_pHead.next->data);
    // printf("tail : %s\n", g_pTail->data);
    // deleteAll();

    // printf("Tail 추가 - insertTail() : 빈 리스트에 A를 넣으면 head와 tail 모두 A를 가르킨다.\n");
    // insertTail("A");
    // printf("Head : %s\n", g_pHead.next->data);
    // printf("tail : %s\n", g_pTail->data);
    // putchar('\n');

    // printf("Tail 추가 - insertTail() : A가 든 리스트에 B를 넣으면 head는 A, tail은 B를 가르킨다.\n");
    // insertTail("B");
    // printf("Head : %s\n", g_pHead.next->data);
    // printf("tail : %s\n", g_pTail->data);
    // deleteAll();

    return 0;
}
