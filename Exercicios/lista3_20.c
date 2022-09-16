#include <stdio.h>

/* 
20. Ler uma sequência de números inteiros e determinar se eles são pares ou não. 
Deverá ser informado o número de dados lidos e número de valores pares. 
O processo termina quando for digitado o número 1000.
*/

int main(int argc, char const *argv[])
{
    int numero = 0;
    int paridade;
    int teste = 0;
    
    while(teste != 1000){
    printf("Digite um numero: \n");
    scanf("%d", &numero);
    paridade = numero %2;
        
        if (paridade == 0){
            printf("%d e um numero par! \n", numero);
        }
        else{
            printf("%d e um numero impar! \n", numero);
        } 
    teste = numero;
    } 
    
return 0;
}


