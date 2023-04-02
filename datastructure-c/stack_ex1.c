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
    return 2;
}

int isTopSmaller(char operator, NODE *pTop)
{
    if (pTop == NULL || operator == '(') return 0; // 스택이 비어있거나 현재 연산자가 '('인 경우 push 한다.
    if (operator == ')') return 1;                 // 현재 연산자가 ')'인 경우 계속 pop한다.
    return getPriority(operator) >= getPriority(pTop->data[0]);
}

LIST *infixToPostfixSolution(char *input)
{
    LIST operators = {0};
    initList(&operators);

    LIST *result = malloc(sizeof(LIST));
    initList(result);

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
                    insertTail(result, pPop);
                else
                    break;
            }
            if (tmpElement != ')')
                push(&operators, str);
        }
        else
            insertTail(result, str);
    }
    while (isNotEmpty(&operators))
        insertTail(result, pop(&operators)->data);
    return result;
}

void infixToPostfix()
{
    printf("infix to postfix\n");

    char *input = "1+1";
    printf("input = %s : 예상=11+ 실제=", input);
    printStack(infixToPostfixSolution(input));

    input = "1*1";
    printf("input = %s : 예상=11* 실제=", input);
    printStack(infixToPostfixSolution(input));

    input = "1+1+1";
    printf("input = %s : 예상=11+1+ 실제=", input);
    printStack(infixToPostfixSolution(input));

    input = "1+1*1";
    printf("input = %s : 예상=111*+ 실제=", input);
    printStack(infixToPostfixSolution(input));

    input = "1*1+1";
    printf("input = %s : 예상=11*1+ 실제=", input);
    printStack(infixToPostfixSolution(input));

    input = "1*1*1+1";
    printf("input = %s : 예상=11*1*1+ 실제=", input);
    printStack(infixToPostfixSolution(input));

    input = "6+(3-2)*4";
    printf("input = %s : 예상=632-4*+ 실제=", input);
    printStack(infixToPostfixSolution(input));
}

int calculate(char *n1, char *n2, char operator)
{
    if (operator == '+')
        return atoi(n1) + atoi(n2);
    if (operator == '-')
        return atoi(n1) - atoi(n2);
    if (operator == '*')
        return atoi(n1) * atoi(n2);
    if (operator == '/')  
        return atoi(n1) / atoi(n2);
    return 0;
}

int getResult(char *input)
{
    LIST stack = {0};
    initList(&stack);

    LIST *list = infixToPostfixSolution(input);

    while (isNotEmpty(list))
    {
        char *pTmp = pop(list)->data;
        
        if (isOperator(pTmp[0]))
        {
            char operator = pTmp[0];
            char *n2 = pop(&stack)->data;
            char *n1 = pop(&stack)->data;
            char result[64];
            sprintf(result, "%d", calculate(n1, n2, operator));
            push(&stack, result);
        }
        else
            push(&stack, pTmp);
    }
    return atoi(pop(&stack)->data);
}

void calculateTest()
{
    char *input = "1+1";
    printf("input = %s : 예상=2 실제=%d\n", input, getResult(input));

    input = "2*2";
    printf("input = %s : 예상=4 실제=%d\n", input, getResult(input));

    input = "1+1+1";
    printf("input = %s : 예상=3 실제=%d\n", input, getResult(input));

    input = "3*3+3";
    printf("input = %s : 예상=12 실제=%d\n", input, getResult(input));

    input = "3+3*3";
    printf("input = %s : 예상=12 실제=%d\n", input, getResult(input));

    input = "6+(3-2)*4";
    printf("input = %s : 예상=10 실제=%d\n", input, getResult(input));
}

int main(int argc, char const *argv[])
{
    // 1. 괄호 검증
    // test1();

    // 2. infix to postfix
    // infixToPostfix();

    // 3. 계산기
    calculateTest();

    return 0;
}
