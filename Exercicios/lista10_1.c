#include <stdio.h>
#include <stdlib.h>

/*. Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros, 
(b) Pec¸a para o usuario digitar os 5 numeros no espaco alocado, 
(c) Mostre na tela os 5 numeros, 
(d) Libere a memoria alocada. */


int *PVnumeros;

int main(void)
{
    PVnumeros = (int*) malloc (5 * sizeof(int));

for (int i = 0; i < 5; i++)
{
    printf("Insira aqui 5 números inteiros: \n");
    scanf("%d", &PVnumeros[i]);
}

for ( int i = 0; i < 5; i++)
{
    printf("\n%d",PVnumeros[i]);
    
}

free(PVnumeros);
return 0;    
}
