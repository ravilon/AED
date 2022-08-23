#include <stdio.h>

/*Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do 
teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco. */

int main ()
{
    int variable_1, variable_2;
    printf("Digite um valor para a variavel 1: \n");
    scanf("%d", &variable_1);

    printf("Digite um valor para a variavel 2: \n");
    scanf("%d", &variable_2);

    if (&variable_1 > &variable_2)
    {
        printf("%d", variable_1);
    }
    else 
    {
        printf("%d", variable_2);
    }

    return 0;
}