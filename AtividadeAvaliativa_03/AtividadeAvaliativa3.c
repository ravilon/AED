#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

struct Node
{
    int *number;
    struct Node *left;
    struct Node *right;
}; typedef struct Node Node;

void StartTree (Node *pRoot, int number){
    pRoot = (Node*) malloc(sizeof(Node));
    pRoot->number = number;
    pRoot->left = NULL;
    pRoot->right = NULL;
}

int ComapareNumber (int number, int number2){
    if (number > number2){
        return 1;
    } else if (number < number2){
        return 2;
    } else {
        return 0;
    }
}

void InsertNode(Node *pRoot, int InsertNumber) {
    if(pRoot == NULL) { StartTree ( pRoot, InsertNumber );}
    else {
        int Compare = CompareNumber( pRoot->number, InsertNumber);
        if (Compare == 1) { InsertNode(pRoot->left, InsertNumber);}
        else if (Compare == 2) { InsertNode(pRoot->right, InsertNumber);}
        else { printf("O número já existe na árvore!");}
    }   
}

int main (){
    printf("esse programa usa uma arvore de busca");
    Node *pRoot;
    InsertNode(pRoot, 5);
    InsertNode(pRoot, 3);
    InsertNode(pRoot, 7);
}