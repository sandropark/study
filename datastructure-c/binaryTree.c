#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    int value;

    struct NODE *left;
    struct NODE *right;
} NODE;

NODE *g_pRoot;
int g_size;

NODE *createNode(int value)
{
    NODE *pNew = malloc(sizeof(NODE));
    memset(pNew, 0, sizeof(NODE));
    pNew->value = value;
    return pNew;
}

void locateNode(NODE *pNew, NODE *pTmp)
{
    if (pNew->value > pTmp->value) {
        if (pTmp->right == NULL) {
            pTmp->right = pNew;
            g_size++;
        }
        else locateNode(pNew, pTmp->right);
    }
    
    if (pNew->value < pTmp->value) {
        if (pTmp->left == NULL) {
            pTmp->left = pNew;
            g_size++;
        }
        else locateNode(pNew, pTmp->left);
    }
}

void addNode(int value)
{
    NODE *pNew = createNode(value);
    if (g_pRoot == NULL) {
        g_pRoot = pNew;
        g_size++;
        return;
    }
    locateNode(pNew, g_pRoot);
}

void printNode(int depth, NODE *pParent)
{
    if (pParent == NULL) return;
    depth++;
    printNode(depth, pParent->left);
    printf("depth=[%d], value=[%d]\n", depth, pParent->value);
    printNode(depth, pParent->right);
}

void clear(NODE *pParent)
{
    if (pParent == NULL) return;
    clear(pParent->left);
    clear(pParent->right);
    // printf("left=[%11p] tmp=[%11p] value=[%d] right=[%11p]\n", pParent->left, pParent, pParent->value, pParent->right);
    free(pParent);
}

void validate(int expectedSize)
{
    printf("Size : 예상 %d 실제 %d\n", expectedSize, g_size);
    printNode(0, g_pRoot);
    clear(g_pRoot);
    g_pRoot = NULL;
    g_size = 0;
    putchar('\n');
}

NODE *findNode(int value, NODE *pTmp)
{
    if (pTmp == NULL) return NULL;
    if (pTmp->value == value) return pTmp;
    findNode(value, pTmp->left);
    findNode(value, pTmp->right);
}

void validateResult(NODE *result)
{
    if (result->value) 
        printf("[%p] [%d]\n", result, result->value);
    else 
        printf("Tree is empty\n");
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    printf("addNode() : 노드가 하나인 경우 루트가 된다.\n");
    addNode(2);
    validate(1);

    printf("addNode() : 노드가 2개인 트리에 헤드보다 큰 요소를 추가하는 경우\n");
    addNode(4);
    addNode(2);
    addNode(6);
    addNode(1);
    addNode(3);
    validate(5);

    printf("findNode() : 트리가 비어있는 경우. NULL을 반환한다.\n");
    validateResult(findNode(1, g_pRoot));

    // printf("findNode() : 원하는 데이터가 없는 경우. NULL을 반환한다.\n");
    // addNode(1);
    
    // validateResult(findNode(2, g_pRoot));
    // clear(g_pRoot);

    // printf("findNode() : 원하는 데이터가 있는 경우. 해당 노드의 포인터를 반환한다.\n");
    // addNode(1);
    // validateResult(findNode(1, g_pRoot));

    return 0;
}
