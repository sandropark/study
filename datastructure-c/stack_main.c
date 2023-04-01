#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.c"

void validate(LIST *stack, int expectedSize)
{
    printf("Size : 예상=[%d] 실제=[%d]\n", expectedSize, stack->size);
    printAllElements(stack);
}

int main(int argc, char const *argv[])
{
    LIST stack = {0};
    initList(&stack);

    printf("push() : ABC 순서로 push하면 CBA가 출력된다.\n");
    push(&stack, "A");
    push(&stack, "B");
    push(&stack, "C");
    validate(&stack, 3);
    deleteAll(&stack);

    printf("pop() : 스택이 비어있다면 0이 출력된다.\n");
    NODE *pPopNode = pop(&stack);
    printf("result = [%p, %s]\n\n", pPopNode, pPopNode->data);

    printf("pop() : 가장 처음 요소를 꺼낸다. 1을 출력한다.\n");
    push(&stack, "A");
    pPopNode = pop(&stack);
    printf("result = [%p, %s]\n", pPopNode, pPopNode->data);
    validate(&stack, 0);
    
    printf("top() : 가장 처음 요소를 조회한다.\n");
    push(&stack, "A");
    printf("%s\n", top(&stack)->data);
    deleteAll(&stack);

    printf("CBA가 들어있는 Stack에 Pop()을 하면 CBA 순서대로 꺼내진다.\n");
    push(&stack, "A");
    push(&stack, "B");
    push(&stack, "C");
    printf("%s\n", pop(&stack)->data);
    printf("%s\n", pop(&stack)->data);
    printf("%s\n", pop(&stack)->data);
    
    return 0;
}
