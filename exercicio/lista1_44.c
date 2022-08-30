#include <stdio.h>

/* 44) Receba a altura do degrau de uma escada e a altura que o usuário deseja alcançar 
subindo a escada. Calcule e mostre quantos degraus o usuário deverá subir para atingir 
seu objetivo */

int CalcularDegrais(int tamanhoDegrau, int alturaEscada);
int main(int argc, char const *argv[])
{
    int alturaDegrau; 
    int alturaEscada;
    int numeroDegrais;

    printf("Deigite (em metros) a altura do degrau e em seguida a altura da escada: \n");
    scanf("%d%d", &alturaDegrau, &alturaEscada);
    numeroDegrais = CalcularDegrais(alturaDegrau, alturaEscada);

    printf("Para uma escada com %dm de altura por degrau, e %dm de altura \n o numero ideal de degrais sera: %d", alturaDegrau, alturaEscada, numeroDegrais);
    return 0;
}

int CalcularDegrais (int alturaDegrau, int alturaEscada) {
    int numeroDegrais;
    numeroDegrais = alturaEscada / alturaDegrau;
    return numeroDegrais;
}