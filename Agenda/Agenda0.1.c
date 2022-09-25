/* 
==============================================================================================================================
1-Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, 
porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.

2-Não pergunte para o usuário quantas pessoas ele vai incluir. 
Não pode alocar espaço para mais pessoas do que o necessário.

3-Cada pessoa tem nome[10], idade e telefone.

4-O trabalho que vale nota será uma continuação deste.

5-Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.

6-Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)

7-Não pode usar struct em todo o programa.

8-Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.

9-Implementar a base de dados da agenda usando lista duplamente ligada

10-Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
================================================================================================================================
Pessoa
nome[10]char // idade[1]int // telefone[1]int
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ======================================Declaração de Variáveis=================================

void *pBuffer;                                  // Ponteiro que guarda o Buffer ( endereço do primeiro e ultimo )
void *pPosition;                          // Ponteiro que guarda o próximo endereço vazio no buffer

void *pPeople;
char *pName;                                    // Ponteiro que guarda o nome a ser adcionado ao pessoa
int  *pAge;                                     // Ponteiro que guarda a idade a ser adcionado ao pessoa
int  *pNumber;                                  // Ponteiro que guarda o numero a ser adcionado ao pessoa

int *pCounterPeople;                            // Ponteiro que guarda o número de Pessoas na agenda
int *pTamanhoBuffer;                            // Ponteiro que guarda o tamanho do buffer em bytes
int *pMenu;                                     // Ponteiro que guarda a opção do menu
int *pSizePeople;                            // Ponteiro que guarda o tamanho de uma pessoa
int *pContador;                                 // Ponteiro usado como contador em laços de repetição

// ======================================Declaração de Funções Menu====================================

void Menu();        //OK
void Insert();     //OK
void Apagar_r();    
void Buscar_r();
void Listar_r();    //OK

// ======================================Declaração de Funções Memória=================================

void RealocaMemoria();

void PUSH(void *People);
void POP();
void RESET();
void CLOSE();


/*
====================
Int Main

Main
====================
*/
int main () {

    pMenu = (int*)malloc( sizeof( int ) ); 
    pTamanhoBuffer = (int*)malloc( sizeof( int ) );
    pCounterPeople = (int*)malloc( sizeof( int ) ); 
    pSizePeople = (int*)malloc( sizeof( int ) ); 

    *(int*)pCounterPeople = 0; // Numero de Pessoas na Lista
    *(int*)pSizePeople =  10* sizeof(char) + 4*sizeof(int)  ; // Tamanho de 1 pessoa

    pBuffer = (void*)malloc(sizeof(void));

    printf( "==============================\n" );
    printf( "Bem vindo a Agenda\n" );
    printf( "==============================\n" );

    Menu();

    free( pMenu );
    free( pCounterPeople );
    free( pTamanhoBuffer );
    free( pSizePeople );
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
    printf( "Escolha uma das opcoes a seguir: \n" );
    printf( "1. Incluir pessoa\n2. Apagar pessoa\n3. Buscar pessoa\n4. Listar Agenda\n5. Sair\n");
    printf( "==============================\n" );
    scanf("%d", pMenu);

    if ( *(int*)pMenu == 1 ) {
        Insert();
    }

    if ( *(int*)pMenu == 2 ) {
        Apagar_r();
    }

    if ( *(int*)pMenu == 3 ) {
        Buscar_r();
    }

    if ( *(int*)pMenu == 4 ) {
        Listar_r();
    }

    if ( *(int*)pMenu == 5 ) {
    printf( "Obrigado!" );
    }
}
/*
====================
RESET

Starts the linked list
====================
*/
void RESET( void *People ) {

pBuffer = malloc(2*sizeof(void*));
pPosition = pBuffer;

*(int*)pNumber = (void*)People;
memcpy( pPosition, pNumber, sizeof( int ));
pPosition += sizeof(void*);
memcpy( pPosition, pNumber, sizeof( int ));
}

/*
====================
PUSH

Insert element on linked list
====================
*/
void PUSH( void *People ) {

if ( pBuffer == NULL ) {
    RESET(People);
}




    
}

/*
====================
Incluir

Inclui pessoa a 
Agenda
====================
*/
void Insert() {

pPeople = malloc(*( int* ) pSizePeople);
pPosition = pPeople;

pName = ( char* )malloc( 10 * sizeof( char ));
pAge = ( int* )malloc( sizeof( int ) );
pNumber = ( int* )malloc( sizeof( int ) );

// Acrescenta Nome
printf( "Digite o nome da pessoa: \n" );
scanf( "%s", ( char* ) pName );
memcpy( pPosition, pName, 10* sizeof( char ));
pPosition += 10*sizeof( char );

// Acrescenta Idade
printf( "Digite a Idade da pessoa: \n" );
scanf( "%d", pAge );
memcpy( pPosition, pAge, sizeof( int ));
pPosition += sizeof( int );

// Acrescenta Numero
printf( "Digite o numero da pessoa: \n" );
scanf( "%d", pNumber );
memcpy( pPosition, pNumber, sizeof( int ));
pPosition += sizeof( int );

*(int*)pCounterPeople = *(int*)pCounterPeople + 1;

PUSH( pPeople );
free( pNumber );
free( pName );
free( pAge );
Menu();
}

/*
====================
Apagar_r

Apaga uma pessoa da 
Agenda
====================
*/
void Apagar_r() {

*(int*)pCounterPeople = *(int*)pCounterPeople - 1;
Menu();
}

/*
====================
Buscar_r

Apaga uma pessoa da 
Agenda
====================
*/
void Buscar_r() {
pName = (char*)malloc(10*sizeof(char));
pContador = ( int* )malloc( sizeof( int ) );

printf( "Essa busca será feita usando o número de telefone! \n" );
printf( "Digite o nome desejado: " );
scanf("%s", ( char* )pName );

free( pContador );
free( pName );

Menu();
}
/*
====================
Listar_r

Lista todas pessoas
na Agenda
====================
*/
void Listar_r() {  
pName = ( char* )malloc( 10 * sizeof( char ));
pAge = ( int* )malloc( sizeof( int ) );
pNumber = ( int*)malloc( sizeof( int ) );
pContador = ( int* )malloc( sizeof( int ) );

pPosition = pBuffer;

for (*( int* )pContador = 0; *( int* )pContador < *( int* )pCounterPeople; *( int* )pContador = *( int* )pContador + 1) {
    printf( "================Pessoa %d===============\n", *( int* )pContador );

    //Imprime o nome da pessoa
    memcpy( pName, pPosition, 10 * sizeof( char ) );
    printf( "O nome da pessoa é: %s \n", pName );
    pPosition += 10 * sizeof( char );

    //Imprime a idade
    memcpy(pAge, pPosition, sizeof( int ) );
    printf( "Idade: %d \n", *( int* ) pAge );
    pPosition += sizeof( int );

    //Imprime o numero 
    memcpy(pNumber, pPosition, sizeof( int) );
    printf("Numero: %d \n", *(int*)pNumber );
    pPosition += sizeof( int );

    printf( "======================================\n" );
    }

free( pContador);
free( pName );
free( pAge );
free( pNumber );

Menu();
}

