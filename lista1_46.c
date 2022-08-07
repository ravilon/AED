#include <stdio.h>

/*
46. Faça um programa que leia um número inteiro positivo de três dígitos (de 100 a 999). 
Gere outro número formado pelos dígitos invertidos do número lido 
*/
char InverteString (char stringNumero);
int main(int argc, char const *argv[])
{
    int numero;
    char stringNumero[20];
    printf("Digite um numero de 3 digitos: \n");
    scanf("%d", &numero);

    while (numero < 100 || numero > 999 )
    {
        printf("O numero %d, nao tem 3 digitos \n", numero);
        printf("Por favor, digite um numero de 3 digitos: \n");
        scanf("%d", &numero);  
    }
    
    itoa(numero,stringNumero, 10);
    printf("%s \n", stringNumero);

    return 0;
}

char InverteString (char stringNumero) {
}