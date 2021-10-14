/*
    4.5 어떤 이진 트리가 이진 탐색 트리인지 판별하는 함수를 구현하라.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGE 30
#define LEFT 0
#define RIGHT 1

int used[RANGE];

typedef struct node {
    struct node *left;
    struct node *right;
    int value;
} node_t;

void addRandNode(node_t **tree){
    if(*tree == NULL){
        *tree = malloc(sizeof(node_t));
        int t;
        do{
            t = rand()%RANGE;
        }while(used[t]);
        (*tree)->value = t;
        (*tree)->left = (*tree)->right = NULL;
        used[t] = 1;
        return;
    }

    int res = rand()%2;
    node_t *cursor = (*tree);
    while(1){
        if(res == LEFT){ // odd
            if(cursor->left != NULL){
                cursor = cursor->left;
                continue;
            }else{
                cursor->left = malloc(sizeof(node_t));
                int t;
                do{
                    t = rand()%RANGE;
                }while(used[t]);
                cursor->left->value = t;
                cursor->left->left = cursor->left->right = NULL;
                used[t] = 1;
                return;
            }
        }else{ // even
            if(cursor->right != NULL){
                cursor = cursor->right;
                continue;
            }else{
                cursor->right = malloc(sizeof(node_t));
                int t;
                do{
                    t = rand()%RANGE;
                }while(used[t]);
                cursor->right->value = t;
                cursor->right->left = cursor->right->right = NULL;
                used[t] = 1;
                return;
            }
        }
    }
}

void addRandBSTNode(node_t **tree){
    if(*tree == NULL){
        *tree = malloc(sizeof(node_t));
        int t;
        do{
            t = rand()%RANGE;
        }while(used[t]);
        (*tree)->value = t;
        (*tree)->left = (*tree)->right = NULL;
        used[t] = 1;
        return;
    }

    int res = rand()%RANGE;
    node_t *cursor = (*tree);
    do{
        res = rand()%RANGE;
    }while(used[res]);
    used[res] = 1;
    while(1){
        if(cursor->value > res){
            if(cursor->left != NULL){
                cursor = cursor->left;
                continue;
            }else{
                cursor->left = malloc(sizeof(node_t));
                cursor->left->value = res;
                cursor->left->left = cursor->left->right = NULL;
                return;
            }
        }else{
            if(cursor->right != NULL){
                cursor = cursor->right;
                continue;
            }else{
                cursor->right = malloc(sizeof(node_t));
                cursor->right->value = res;
                cursor->right->left = cursor->right->right = NULL;
                return;
            }
        }
    }
}

node_t *newRandBTree(int numNodes){
    node_t *tree = NULL;
    for(int i=0;i<numNodes;++i){
        addRandNode(&tree);
    }
    return tree;
}

node_t *newRandBST(int numNodes){
    node_t *tree = NULL;
    for(int i=0;i<numNodes;++i){
        addRandBSTNode(&tree);
    }
    return tree;
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->value);
    printInorder(node->right);
}

void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
 
    printf("%d ", node->value);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->value);
}

void printTree(node_t *tree){
    if (tree == NULL)
        return;
 
    printf("InOrder: ");
    printInorder(tree);
    printf("\n");

    printf("PreOrder: ");
    printPreorder(tree);
    printf("\n");

    printf("PostOrder: ");
    printPostorder(tree);
    printf("\n");
}

int chkNode(node_t *tree, int value, int side){
    if(tree == NULL)
        return 0;

    printf("tree->value: %d, value: %d, side: %s\n", tree->value, value, side==LEFT?"LEFT":"RIGHT");
    
    if(side == LEFT && tree->value > value)
        return 1;
    if(side == RIGHT && tree->value < value)
        return 1;
    return chkNode(tree->left, tree->value, LEFT) || chkNode(tree->right, tree->value, RIGHT);
}

int chkBST(node_t *tree){
    if (tree == NULL)
        return 1;
    return chkNode(tree->left, tree->value, LEFT) || chkNode(tree->right, tree->value, RIGHT);
}

int main(){
    node_t *Tree = NULL;

    srand(time(NULL));
    for(int i=0;i<RANGE;++i) used[i] = 0;

    Tree = newRandBTree(10);
    printTree(Tree);
    printf("Is BST: %s\n", (chkBST(Tree))?"False":"True");
    free(Tree);

    printf("\n\n");

    Tree = newRandBST(10);
    printTree(Tree);
    printf("Is BST: %s\n", (chkBST(Tree))?"False":"True");
    free(Tree);
}