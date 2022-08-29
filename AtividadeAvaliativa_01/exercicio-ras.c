#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
===============================================================================
Aluno: Rávilon Aguiar Dos Santos
===============================================================================

Atividade avaliativa

Faça um programa que solicita do usuário uma série de números, cada número pode ser um
int, float ou double. Antes de solicitar o número pergunte qual tipo de dado o usuário vai entrar.
Todos os números entrados devem ser armazenados num buffer único. Esse buffer deve ter tamanho
dinâmico e não deve desperdiçar memória, por exemplo, alocar sempre espaço para um double
quando o usuário inserir um int ou float.
Você não deve solicitar para o usuário quantos números ele deseja entrar, na escolha do tipo
de dados coloque uma opção para parar a entrada da série de números. Após isso você deve imprimir
todos os números do buffer, primeiro toda a série em sequência depois novamente, mas primeiro os
ints seguido dos floats e doubles
===============================================================================
*/
int menu;        // Opção escolhida do menu

void *pBuffer;        // Aponta para endereço incial do buffer sempre
void *pPosicaoBuffer; // Aponta para endereço vazio no buffer (ao aplicar realloc direcionar sempre neste)

char *pTipo;     // Armazena sempre 1 char para diferenciar itens do buffer
int *pInteiro;   // Armazena sempre 1 Inteiro para adcionar itens ao buffer
float *pFloat;   // Armazena sempre 1 Float para adcionar itens ao buffer
double *pDouble; // Armazena sempre 1 Double para adcionar itens ao buffer

int contadorInteiro = 0; // contadores para saber quantos numeros de cada tipo tem no buffer
int contadorFloat = 0;   // contadores para saber quantos numeros de cada tipo tem no buffer
int contadorDouble = 0;  // contadores para saber quantos numeros de cada tipo tem no buffer

void Menu();
void NumeroInteiro();
void NumeroFloat();
void NumeroDouble();
void ListarSequencia_r();
void RealocaPonteiro();
void ReposicionaPonteiro();

int main()
{
    // Aloca espaço de memória para cada ponteiro:
    pBuffer = (void *)malloc(0);

    Menu();
    free( pBuffer );
    return 0;
}
/*
====================
Menu

Acessa o menu
====================
*/
void Menu() {
    printf( "==============================\n" );
    printf( "Este programa armazena uma série de números!\n" );
    printf( "Escolha uma das opções a seguir \n" );
    printf( "1. Inserir número Inteiro na sequência\n2. Inserir número Float na sequência\n3. Inserir número double na sequência\n4. listar sequencia\n5. Sair\n");
    scanf("%d", &menu );

    if ( menu == 1 ) {
        NumeroInteiro();
    }

    if ( menu == 2 ) {
        NumeroFloat();
    }

    if ( menu == 3 ) {
        NumeroDouble();
    }

    if ( menu == 4 ) {
        ListarSequencia_r();
    }

    if ( menu == 5 ) {
    printf( "Obrigado!" );
    }
}
/*
====================
RalocaPonteiro
1-INT
2-FLOAT
3-DOUBLE
realoca o ponteiro
pBuffer
(Usar sempre antes
de adicionar um
número a memória)
====================
*/
void RealocaPonteiro(int tipo) {
    int tamanhoDoBuffer = (contadorInteiro * sizeof(int)) + (contadorFloat * sizeof( float )) 
        + (contadorDouble * sizeof( double )) + 2*(contadorDouble + contadorFloat + contadorInteiro) * (sizeof( char ));
    
    if (tipo == 1) {
        pBuffer = realloc( pBuffer, tamanhoDoBuffer + sizeof( int ) + 2*sizeof( char ) );
    }

    if (tipo == 2) {
        pBuffer = realloc( pBuffer, tamanhoDoBuffer + sizeof( float ) + 2*sizeof( char ) );
    }

    if (tipo == 3) {
        pBuffer = realloc( pBuffer, tamanhoDoBuffer + sizeof( double ) + 2* sizeof( char ) );
    }
}
/*
====================
ReposicionaPonteiro

reposiciona o
ponteiro
pPosicaoBuffer
(Usar sempre que
realocar memória)
====================
*/
void ReposicionaPonteiro() {
    pPosicaoBuffer = pBuffer;
    pPosicaoBuffer += (contadorInteiro * sizeof( int )) + (contadorFloat * sizeof( float )) 
        + (contadorDouble * sizeof( double )) + (contadorDouble + contadorFloat + contadorInteiro) * ( sizeof( char ));
}
/*
====================
NumeroInteiro

adciona numero
inteiro ao Buffer
====================
*/
void NumeroInteiro() {
    // Aloca a memória e reposiciona o ponteiro de posição
    RealocaPonteiro(1);
    ReposicionaPonteiro();
    pTipo = ( char* )malloc(2* sizeof( char ));
    pInteiro = (int*)malloc( sizeof( int ));

    strcpy( pTipo, "i" );            // Insere o marcador do tipo de entrada no Buffer pTipo
    strcpy( pPosicaoBuffer, pTipo ); // Acrescenta char do tipo ao pBuffer
    pPosicaoBuffer += sizeof( char );  // Posiciona ponteiro para próxima posição vazia

    // Acrescenta numero 
    printf( "Digite o número Inteiro: \n" );
    scanf( "%d", pInteiro );
    memcpy(pPosicaoBuffer, pInteiro, sizeof( int ));

    contadorInteiro++;
    free( pInteiro );
    free( pTipo );
    Menu();
}
/*
====================
NumeroFloat
adciona numero Float
ao Buffer
====================
*/
void NumeroFloat() {
    // Aloca a memória e reposiciona o ponteiro de posição
    RealocaPonteiro( 2 );
    ReposicionaPonteiro();
    pTipo = ( char * )malloc( 2*sizeof ( char ) );
    pFloat = ( float * )malloc( sizeof( float ) );

    strcpy( pTipo, "f" );            // Insere o marcador do tipo de entrada no Buffer pTipo
    strcpy( pPosicaoBuffer, pTipo ); // Acrescenta char do tipo ao pBuffer
    pPosicaoBuffer += sizeof( char );  // Posiciona ponteiro para próxima posição vazia

    // Acrescenta numero 
    printf( "Digite o número Float:\n" );
    scanf( "%f", pFloat );
    memcpy( pPosicaoBuffer, pFloat, sizeof( float ) );

    // Retorna ao menu
    contadorFloat++;

    free( pTipo );
    free( pFloat );
    Menu();
}
/*
====================
NumeroDouble

adciona numero
Double ao Buffer
====================
*/
void NumeroDouble() {
    // Aloca a memória e reposiciona o ponteiro de posição
    RealocaPonteiro(3);
    ReposicionaPonteiro();
    pTipo = (char *)malloc(2* sizeof( char ));
    pDouble = (double *)malloc( sizeof( double ));
    
    strcpy( pTipo, "d" );            // Insere o marcador do tipo de entrada no Buffer pTipo
    strcpy( pPosicaoBuffer, pTipo ); // Acrescenta char do tipo ao pBuffer
    pPosicaoBuffer += sizeof( char );  // Posiciona ponteiro para próxima posição vazia

    // Acrescenta numero 
    printf("Digite o número Double:\n");
    scanf("%lf", pDouble);
    memcpy(pPosicaoBuffer, pDouble, sizeof( double ));

    contadorDouble++; 
    free( pDouble );
    free( pTipo );               
    Menu();
}
/*
====================
ListarSequencia_r
Lista Sequência dos
números no Buffer
====================
*/
void ListarSequencia_r() {
    int totalNumeros = contadorDouble + contadorFloat + contadorInteiro; // total de números no buffer
    pPosicaoBuffer = pBuffer;                                            // ponteiro auxiliar
    // Imprime os números em ordem cronológica
    for ( int i = 0; i < totalNumeros; i++ ) {
        pTipo = pPosicaoBuffer;
        char tipo = *pTipo;
        
        if( tipo == 105 ) {
            pPosicaoBuffer += sizeof( char );
            pInteiro = pPosicaoBuffer;
            printf("%d\n", *( int * ) pInteiro );
            pPosicaoBuffer += sizeof( int );
        }

        if( tipo == 102 ) {
            pPosicaoBuffer += sizeof( char );
            pFloat = pPosicaoBuffer;
            printf("%f\n", *( float *) pFloat );
            pPosicaoBuffer += sizeof( float );
        }

        if(tipo == 100) {
            pPosicaoBuffer += sizeof(char);
            pDouble = pPosicaoBuffer;
            printf("%lf\n", *( double* ) pDouble );
            pPosicaoBuffer += sizeof( double );
        }
    }
    // Imprime os números em ordem de tipo inteiros
    pPosicaoBuffer = pBuffer;  
    printf("===============Inteiros============\n");
    for ( int i = 0; i < totalNumeros; i++ ) {
        pTipo = pPosicaoBuffer;
        char tipo = *pTipo;
        
        if( tipo == 105 ) {
            pPosicaoBuffer += sizeof( char );
            pInteiro = pPosicaoBuffer;
            printf("é um inteiro: %d\n", *( int* ) pInteiro );
            pPosicaoBuffer += sizeof( int );
        }

        if( tipo == 102 ) {
            pPosicaoBuffer += sizeof( char );
            pPosicaoBuffer += sizeof( float );
        }

        if( tipo == 100 ) {
            pPosicaoBuffer += sizeof(char);
            pPosicaoBuffer += sizeof(double);
        }            
    }
    pPosicaoBuffer = pBuffer;  
    // Imprime os números em ordem de tipo float
    printf("=================Float==============\n");
    for ( int i = 0; i < totalNumeros; i++ ) { 
        pTipo = pPosicaoBuffer;
        char tipo = *pTipo;
        
        if( tipo == 105 ){
            pPosicaoBuffer += sizeof( char );
            pPosicaoBuffer += sizeof( int );
        }

        if( tipo == 102 ){
            pPosicaoBuffer += sizeof( char );
            pFloat = pPosicaoBuffer;
            printf("é um float: %f\n", *( float* ) pFloat);
            pPosicaoBuffer += sizeof( float );
        }

        if(tipo == 100){
            pPosicaoBuffer += sizeof( char );
            pPosicaoBuffer += sizeof( double );
        }
    }
    pPosicaoBuffer = pBuffer;  
    // imprime os numeros em ordem de double
    printf("=================Double=============\n");
    for ( int i = 0; i < totalNumeros; i++ ) { 
        pTipo = pPosicaoBuffer;
        char tipo = *pTipo;
        
        if( tipo == 105 ) {
            pPosicaoBuffer += sizeof( char );
            pPosicaoBuffer += sizeof( int );
        }

        if( tipo == 102 ) {
            pPosicaoBuffer += sizeof( char );
            pPosicaoBuffer += sizeof( float );
        }

        if( tipo == 100 ) {
            pPosicaoBuffer += sizeof( char );
            pDouble = pPosicaoBuffer;
            printf("%lf\n", *( double* ) pDouble);
            pPosicaoBuffer += sizeof( double );
        }
    }
    Menu();
}