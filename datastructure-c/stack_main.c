#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.c"

void printAllElements(LIST *list)
{
    for (NODE *pTmp = list->pHead->next; pTmp != NULL; pTmp = pTmp->next)
        printf("[%p] %s, next[%p]\n", pTmp, (char *)pTmp->pData, pTmp->next);
    putchar('\n');
}

void deleteAll(LIST *list)
{
    NODE *pTmp = list->pHead->next;
    NODE *pDelete = NULL;
    while (pTmp != NULL)
    {
        pDelete = pTmp;
        pTmp = pTmp->next;
        printf("Delete: [%p] %s next[%p]\n", pDelete, (char *)pDelete->pData, pTmp);
        free(pDelete);
    }
    list->pHead->next = NULL;
    list->pTail = NULL;
    list->size = 0;
    putchar('\n');
}

void validate(LIST *stack, int expectedSize)
{
    printf("Size : 예상=[%d] 실제=[%d]\n", expectedSize, stack->size);
    printAllElements(stack);
}

void stackTest()
{
    LIST stack = {0};
    initList(&stack);

    printf("push() : ABC 순서로 push하면 CBA가 출력된다.\n");
    push(&stack, "A");
    push(&stack, "B");
    push(&stack, "C");
    validate(&stack, 3);
    deleteAll(&stack);

    printf("pop() : 스택이 비어있다면 NULL을 반환한다.\n");
    printf("result = %p\n\n", pop(&stack));

    printf("pop() : 가장 처음 요소를 꺼낸다. 1을 출력한다.\n");
    push(&stack, "A");
    NODE *pPopNode = pop(&stack);
    printf("result = [%p, %s]\n", pPopNode, (char *)pPopNode->pData);
    validate(&stack, 0);
    
    printf("top() : 가장 처음 요소를 조회한다.\n");
    push(&stack, "A");
    printf("%s\n", (char *)top(&stack)->pData);
    deleteAll(&stack);

    printf("CBA가 들어있는 Stack에 Pop()을 하면 CBA 순서대로 꺼내진다.\n");
    push(&stack, "A");
    push(&stack, "B");
    push(&stack, "C");
    printf("%s\n", (char *)pop(&stack)->pData);
    printf("%s\n", (char *)pop(&stack)->pData);
    printf("%s\n", (char *)pop(&stack)->pData);
}

typedef struct CHAR
{
    char value;
} CHAR;

typedef struct INTEGER
{
    int value;
} INTEGER;

CHAR *createChar(char value)
{
    CHAR *pChar = malloc(sizeof(CHAR));
    memset(pChar, 0, sizeof(CHAR));
    pChar->value = value;
    return pChar;
}

void printStack(LIST *stack)
{
    for (NODE *pTmp = stack->pHead->next; pTmp != NULL; pTmp = pTmp->next)
        printf("%c", ((CHAR *)pTmp->pData)->value);
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
    return getPriority(operator) >= getPriority(((CHAR *)pTop->pData)->value);
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
        if (isOperator(tmpElement))
        {
            while (isTopSmaller(tmpElement, top(&operators))) // 연산자를 스택에 쌓기 전에 top을 조회해서 넣으려는 연산자와 top을 비교한다. 
            {
                CHAR *pPop = pop(&operators)->pData;
                if (pPop->value != '(')
                    insertTail(result, pPop);
                else
                    break;
            }
            if (tmpElement != ')')
                push(&operators, createChar(tmpElement));
        }
        else
            insertTail(result, createChar(tmpElement));
    }
    while (isNotEmpty(&operators))
        insertTail(result, pop(&operators)->pData);
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

int calculate(int n1, int n2, char operator)
{
    if (operator == '+') return n1 + n2;
    if (operator == '-') return n1 - n2;
    if (operator == '*') return n1 * n2;
    if (operator == '/') return n1 / n2; 
    return 0;
}

INTEGER *createIntegerFromChar(char value)
{
    INTEGER *pTmp = malloc(sizeof(INTEGER));
    memset(pTmp, 0, sizeof(INTEGER));
    pTmp->value = value - 48;
    return pTmp;
}

INTEGER *createIntegerFromInt(int value)
{
    INTEGER *pTmp = malloc(sizeof(INTEGER));
    memset(pTmp, 0, sizeof(INTEGER));
    pTmp->value = value;
    return pTmp;
}

int getResult(char *input)
{
    LIST stack = {0};
    initList(&stack);

    LIST *list = infixToPostfixSolution(input);

    while (isNotEmpty(list))
    {
        char pTmp = ((CHAR *)pop(list)->pData)->value;
        
        if (isOperator(pTmp))
        {
            char operator = pTmp;
            int n2 = ((INTEGER *)pop(&stack)->pData)->value;
            int n1 = ((INTEGER *)pop(&stack)->pData)->value;
            push(&stack, createIntegerFromInt(calculate(n1, n2, operator)));
        }
        else
            push(&stack, createIntegerFromChar(pTmp));
    }
    return ((INTEGER *)pop(&stack)->pData)->value;
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
    // infixToPostfix();
    calculateTest();

    return 0;
}
