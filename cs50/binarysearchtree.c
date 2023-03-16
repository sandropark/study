#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

node *add(node *tree, int number);
void print(node *tree);

int main(int argc, char const *argv[])
{
    node *tree = NULL;

    tree = add(tree, 2);
    tree = add(tree, 3);
    tree = add(tree, 1);

    print(tree);

    return 0;
}

void print(node *tree)
{   
    printf("%i\n", tree->left->number);
    printf("%i\n", tree->number);
    printf("%i\n", tree->right->number);
}

node *add(node *tree, int number)
{
    node *n = malloc(sizeof(node));
    n->number = number;

    if (tree == NULL)
    {
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    
    if (tree->number > number)
    {
        n->right = tree;
        tree->left = n;
    } 
    else
    {
        n->left = tree;
        tree->right = n;
    }
    return tree;
}