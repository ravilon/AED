#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int numero;
    struct Node *esquerda;
    struct Node *direita;
};
typedef struct Node Node;

void StartTree(Node **pRaiz) {
    *pRaiz = NULL;
}

void Insert(Node **pRaiz, int numero2) {
    if (*pRaiz == NULL) {
        *pRaiz = (Node *)malloc(sizeof(Node));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita;
    }
    else {
		if (numero2 < ((*pRaiz)->numero)) {
			insercao(&((*pRaiz)->esquerda), numero2);
		}
		else {
			insercao(&((*pRaiz)->direita), numero2);
		}
	}
}
