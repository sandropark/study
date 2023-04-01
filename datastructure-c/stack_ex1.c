#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.c"

int solution1(LIST *stack, char *input)
{
    NODE pTmp = {0};
    for (int i = 0; i < strlen(input); i++)
    {
        char tmpValue = input[i];
        if (tmpValue == '(')
            push(stack, "1");
        else if (tmpValue == ')')
        {
            if (isEmpty(stack)) return 0;
            pop(stack);
        }
    }
    return isEmpty(stack);
}

void test1()
{
    LIST stack = {0};
    initList(&stack);

    printf("괄호 검증\n");

    char *input = "()";
    printf("input = %s : 예상=1 실제=%d\n", input, solution1(&stack, input));
    deleteAll(&stack);

    input = ")(";
    printf("input = %s : 예상=0 실제=%d\n", input, solution1(&stack, input));
    deleteAll(&stack);

    input = "()()";
    printf("input = %s : 예상=1 실제=%d\n", input, solution1(&stack, input));
    deleteAll(&stack);

    input = "(())())";
    printf("input = %s : 예상=0 실제=%d\n", input, solution1(&stack, input));
    deleteAll(&stack);
}

void printStack(LIST *stack)
{
    for (NODE *pTmp = stack->pHead->next; pTmp != NULL; pTmp = pTmp->next)
        printf("%s", pTmp->data);
    putchar('\n');
}

int isOperator(char input)
{   
    return input == '+' || input == '-' || input == '*' || input == '/' || input == '(' || input == ')';
}

int isNotEmpty(LIST *stack)
{
    return stack->size > 0;
}

int getPriority(char operator)
{
    if (operator == '*' || operator == '/') return 0;
    if (operator == '+' || operator == '-') return 1;
    return  2;
}

int isTopSmaller(char tmpElement, NODE *pTop)
{
    if (pTop == NULL || tmpElement == '(') return 0;
    if (tmpElement == ')') return 1;
    return getPriority(tmpElement) >= getPriority(pTop->data[0]);
}

void infixToPostfixSolution(char *input)
{
    LIST operators = {0};
    initList(&operators);

    LIST result = {0};
    initList(&result);

    for (int i = 0; i < strlen(input); i++)
    {
        char tmpElement = input[i];
        char str[2] = {tmpElement, '\0'};
        if (isOperator(tmpElement))
        {
            while (isTopSmaller(tmpElement, top(&operators))) // 연산자를 스택에 쌓기 전에 top을 조회해서 넣으려는 연산자와 top을 비교한다. 
            {
                char *pPop = pop(&operators)->data;
                if (strcmp(pPop, "(") != 0)
                    insertTail(&result, pPop);
                else
                    break;
            }
            if (tmpElement != ')')
                push(&operators, str);
        }
        else
            insertTail(&result, str);
    }
    while (isNotEmpty(&operators))
        insertTail(&result, pop(&operators)->data);
    printStack(&result);
}

void infixToPostfix()
{
    printf("계산기\n");

    char *input = "1+1";
    printf("input = %s : 예상=11+ 실제=", input);
    infixToPostfixSolution(input);

    input = "1*1";
    printf("input = %s : 예상=11* 실제=", input);
    infixToPostfixSolution(input);

    input = "1+1+1";
    printf("input = %s : 예상=11+1+ 실제=", input);
    infixToPostfixSolution(input);

    input = "1+1*1";
    printf("input = %s : 예상=111*+ 실제=", input);
    infixToPostfixSolution(input);

    input = "1*1+1";
    printf("input = %s : 예상=11*1+ 실제=", input);
    infixToPostfixSolution(input);

    input = "1*1*1+1";
    printf("input = %s : 예상=11*1*1+ 실제=", input);
    infixToPostfixSolution(input);

    input = "6+(3-2)*4";
    printf("input = %s : 예상=632-4*+ 실제=", input);
    infixToPostfixSolution(input);
}

int main(int argc, char const *argv[])
{
    // 1. 괄호 검증
    // test1();

    // 2. infix to postfix
    infixToPostfix();

    return 0;
}
