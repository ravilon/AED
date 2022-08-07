#include <stdio.h>
int CalcularSalario(int salarioBruto);

/* 42) Receba o salário-base de um funcionário. Calcule e imprima o salário a receber, 
sabendo se que esse funcionário tem uma gratificação de 5% sobre o salário-base. 
Além disso, ele paga 7% de imposto sobre o salário-base
*/

int main(int argc, char const *argv[])
{
    int salarioBruto;
    int salarioLiquido;

    printf("Digite aqui o salario base \n");
    scanf("%d", &salarioBruto);
    salarioLiquido = CalcularSalario(salarioBruto);
    printf("O salario deste funcionario é %d \n", salarioLiquido);

    return 0;
}

int CalcularSalario(int salarioBruto) {
    int salarioLiquido=0;
    salarioLiquido = (salarioBruto) + (salarioBruto * 0,05) - (salarioBruto * 0,07);
    return salarioLiquido;
}