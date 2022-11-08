#include <stdio.h>
#include <stdlib.h> 

/*
====================
struct Node

Estrutura de dados para armazenar um nó da árvore
====================
*/
struct Node {
    int number;
    struct Node *left;
    struct Node *right;
}; typedef struct Node Node;

/*
====================
CompareNumbers  

Comapara dois inteiros e retorna 1 se o primeiro for maior, 2 se o segundo for maior e 0 se forem iguais.
====================
*/
int CompareNumbers(int number1, int number2) {
    if (number1 > number2) { return 1; }
    else if (number1 < number2) { return -1; }
    else { return 0; }
}

/*
====================
newNode 

Cria um novo nó e retorna o endereço de memória do mesmo.
====================
*/
Node *NewNode(int number) {
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->number = number;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/*
====================
InsertNode

Insere um novo numero na árvore.
====================
*/
Node *InsertNode( Node *pRoot, int number ) {
    if ( pRoot == NULL ) { pRoot = NewNode( number ); }
    else {
        if ( CompareNumbers( number, pRoot->number ) == 1) {
            pRoot->right = InsertNode ( pRoot->right, number );
        }
        else if ( CompareNumbers( number, pRoot->number ) == -1) {
            pRoot->left = InsertNode( pRoot->left, number );
        }
    }
    return pRoot;
}

/*
====================
HeightTree

retorna a altura da árvore
====================
*/
int HeightTree( Node *pRoot ) {
    if (pRoot == NULL) {
        return 0;
    }
    else {
        int heightLeft = HeightTree( pRoot->left );
        int heightRight = HeightTree( pRoot->right );
        if (heightLeft > heightRight) {
            return heightLeft + 1;
        }
        else {
            return heightRight + 1;
        }
    }
}

/*
====================
isBalanced

testa se a árvore está balanceada
====================
*/
void isBalanced ( Node *pRoot ){
    if ( pRoot == NULL )
    {
        printf( "A arvore esta balanceada" );
    }
    else
    {
        int heightLeft = heightTree( pRoot->left );
        int heightRight = heightTree( pRoot->right );
        if (abs( heightLeft - heightRight ) > 1)
        {
            printf( "A arvore nao esta balanceada! \n" );
        }
        else
        {
            printf( "A arvore esta balanceada! \n" );
        }
    }
}

/*
====================
freeTree    

Limpa a árvore usando pós ordem.
====================
*/
void freeTree( Node *pRoot ){
    if ( pRoot != NULL ) {
        freeTree( pRoot->left );
        freeTree( pRoot->right );
        free( pRoot );
    }
}

int main () {
    printf( "===============Arvore de Busca================= \n" );
    Node *pRoot = NULL;
    int opt = 0;
    do
    {
        printf( " Escolha a opcao desejada: \n 0 - Inserir novo numero a arvore \n 1 - Verificar se e balanceada \n ===Digite qualquer outro numero para sair...=== \n" );
        scanf( "%d", &opt );
        switch ( opt ) {
        case 0:
            printf( "Digite o numero que deseja inserir na arvore: \n" );
            int number;
            scanf( "%d", &number );
            pRoot = InsertNode( pRoot, number );
            break;
        case 1:
            isBalanced( pRoot );
            freeTree( pRoot );
            break;
        default:
            break;
        }
    } while ( opt != 1 );
    return 0;
}