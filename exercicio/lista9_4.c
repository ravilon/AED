#include <stdio.h>
#include <stdlib.h>

/* Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas 
2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas 
variaveis A e B por exemplo e apos a execucao da funcao, A contera o valor de B e B 
tera o valor de A. */

void trocaConteudo(int valor_1,int valor_2);

int *buffer;
int main ()
{
    int valor_1 = 5, valor_2 = 10;
    buffer = (int*)calloc(2, sizeof(int));

    printf("%d\n%d\n", valor_1, valor_2);
    trocaConteudo(valor_1, valor_2);
    
    free(buffer);
}

void trocaConteudo(int valor_1, int valor_2)
{   
    buffer[0] = valor_1;
    buffer[1] = valor_2;

    valor_1 = buffer[1];
    valor_2 = buffer[0];

    printf("%d\n%d\n", valor_1, valor_2);
}