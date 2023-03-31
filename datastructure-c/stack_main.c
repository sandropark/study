#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.c"

int main(int argc, char const *argv[])
{
    LIST stack = {0};
    initList(&stack);

    NODE pTmp = {0};
    printf("pop() : 스택이 비어있다면 0이 출력된다.\n");
    printf("result = %d\n\n", pop(&stack, &pTmp));

    printf("pop() : 가장 처음 요소를 꺼낸다.\n");
    push(&stack, "A");
    printf("result = %d\n", pop(&stack, &pTmp));
    if (isEmpty(&stack)) printf("Stack is empty\n\n");
    
    printf("top() : 가장 처음 요소를 조회한다.\n");
    push(&stack, "A");
    top(&stack);
    deleteAll(&stack);

    printf("CBA가 들어있는 Stack에 Pop()을 하면 CBA 순서대로 꺼내진다.\n");
    push(&stack, "A");
    push(&stack, "B");
    push(&stack, "C");
    pop(&stack, &pTmp);
    pop(&stack, &pTmp);
    pop(&stack, &pTmp);

    return 0;
}
