#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *PVestoque;
void *buffer;


void AdcionaProduto();
void AlocaEstoque();

int main (){
AlocaEstoque();
AdcionaProduto();

printf("Produtos do estoque: %s", (char*)PVestoque);


free(buffer);
free(PVestoque);
}

void AlocaEstoque(){

    buffer = (void*)malloc(sizeof(int));

    printf("Insira o número de produtos a ser adcionados: \n");
    scanf("%d", (int*)&buffer);
    PVestoque = (char*) malloc ((* sizeof(char)) + sizeof(int));
    (int*) malloc (5 * sizeof(int));
    
    free(buffer);
}

void AdcionaProduto(){
    realloc(buffer, (sizeof(10*(char)));
    printf("Insira o nome do produto a ser adcionado: \n");
    scanf("%s",(char*)&buffer);
    strcat(PVestoque, buffer);
    free(buffer);
}
