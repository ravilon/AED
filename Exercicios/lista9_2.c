#include <stdio.h>

/* Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e
exiba o maior endereco. */

int main()
{
    int variavel_1, variavel_2;
    if (variavel_1>variavel_2)
    {
        printf("%d foi a variavel 1", &variavel_1);
    }
    else 
    {
        printf("%d foi a 2", &variavel_2);
    }
    return 0;
    free(variavel_1);
    free(variavel_2);
}
