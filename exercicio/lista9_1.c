#include <stdio.h>

/* Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a modificacao. */


int main()
{
    int inteiro=1; 
    float real= 0.1f; 
    char caracter = 'a';

    int *pinteiro; float *preal; char *pcaracter;

    pinteiro = &inteiro;
    preal = &real;
    pcaracter = &caracter;

    printf("%d\n%f\n%c\n", *pinteiro, *preal, *pcaracter);

    return 0;
}




