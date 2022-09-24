/* Fazer um programa que testa se uma sequencia de caracteres fornecida pelo usuário é um palindromo, 
ou seja, é uma palavra cuja primeira metade é simétrica à segunda metade.

o usuário digita uma letra e tecla enter, a entrada para quando ele digita x e enter para terminar a sequencia

FILO = First In Las Out
*/

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

void *pBuffer;
void *pPositionBuffer;
void *popBuffer;
char *pChar;

char character;
int charCounter;

RESET(char character);
POP();
PUSH(char character);

ReallocBuffer(int opcao);

int main (){
    pBuffer = (void*)malloc(2* sizeof(char));
    pBuffer = NULL;
    
    char character = "r";
    charCounter = 0;
    
    printf("=======================" );
    printf("Olá esse programa identifica palíndromos");
    printf("Digite  uma letra por vez e aperte ENTER, quando concluir sua palavra insira x e pressione ENTER");
    
    while (character != "x")
    {
        scanf("%c", &character);
        PUSH(character);
    }

    TestPalindrome();
    

    return 0;
}

ReallocBuffer(int opcao){   
    if (opcao == 1){

    pBuffer = realloc( pBuffer, charCounter * 2*sizeof( char ) + 2*sizeof( char ) );
    pPositionBuffer = pBuffer;
    pPositionBuffer += 2* sizeof(char);

    memcpy( pPositionBuffer, pBuffer, charCounter * 2*sizeof( char ));
    }

    if (opcao == 2){
    
    }
}

TestPalindrome(){

}

PUSH(char Character){  // PUSH pronto
    pChar = malloc(2*sizeof(char));

    pPositionBuffer = pBuffer;
    if( pPositionBuffer == NULL ) { RESET( character ); }
    else 
    {
        ReallocBuffer(1);
        pPositionBuffer = pBuffer;
        strcpy( pPositionBuffer, pChar );    
    }
    
    free(pChar);
}

POP(){
   pChar = malloc(2*sizeof(char));
   
   strcpy(pChar, pBuffer);
   pPositionBuffer = pBuffer;

   free(pChar); 
}

RESET(char character){ // Reset Pronto
pChar = malloc( 2*sizeof( char ));

*pChar = character;
strcpy(pBuffer, pChar);

free(pChar);    
}

