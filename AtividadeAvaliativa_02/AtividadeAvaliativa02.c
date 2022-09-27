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
void *pPopBuffer;
void *pPopPositionB;
char *pChar;

char character;
int charCounter;
int charCounterPop;

void RESET();
void POP();
void PUSH();

int TestPalindrome();
void ReallocBuffer();

int main (){

    pBuffer = (void*)malloc(2* sizeof(char));
    
    charCounter = 0;
    
    printf("=======================\n" );
    printf("Olá esse programa identifica palíndromos\n");
    printf("Digite  uma letra por vez e aperte ENTER, quando concluir sua palavra insira x e pressione ENTER\n");
    scanf("%c", &character);

    while (character != 120)
    {
        PUSH();
        printf("Digite mais uma letra e aperte ENTER, insira x e pressione ENTER para parar\n");
        scanf("%s", &character);
    } 

    int teste = TestPalindrome();
    
    if (teste == 0) { 
        printf("é um palindromo!");
        }
    else { printf("não é um palindromo!"); }
    
    pBuffer -= 2*sizeof(char);
    pPopBuffer -= 2*sizeof(char);

    free(pBuffer);
    free(pPopBuffer);
    return 0;
}

void ReallocBuffer(int opcao) {   

    if (opcao == 1){

    pBuffer = realloc( pBuffer, charCounter * 2*sizeof( char ) + 2*sizeof( char ) );
    
    pPositionBuffer = pBuffer;
    pPositionBuffer += 2* sizeof(char);

    memcpy( pPositionBuffer, pBuffer, charCounter * 2*sizeof( char ));
    }
}

int TestPalindrome() {    
int resultado;
    
    if(charCounter % 2 == 0) {
    charCounterPop = charCounter/2;
    pPopBuffer = ( void* )malloc( charCounterPop * 2 *sizeof ( char )); 
    pPopPositionB = pPopBuffer;
        for (int i = 0; i < charCounter/2 ; i++) {
            POP();
            charCounterPop--;
        }
    
    pBuffer += 2*sizeof(char);
    resultado = strcmp( pBuffer, pPopBuffer);
    return resultado;
    }

    else {
         for (int i = 0; i < charCounter/2 ; i++) {    
            POP();
        }
        pBuffer += 2*sizeof(char);
        resultado = strcmp( pBuffer, pPopBuffer);
        return resultado;    
    }
}

void PUSH(){  // PUSH pronto
    
    pChar = malloc(2*sizeof(char));
    strcpy(pChar, &character);
    pPositionBuffer = pBuffer;

    if( charCounter == 0 ) { RESET( character ); }
    
    else {
        ReallocBuffer(1);
        pPositionBuffer = pBuffer;
        strcpy( pPositionBuffer, pChar );    
    }
    charCounter ++;
}

void POP(){
    
    pPositionBuffer = pBuffer;
    pPositionBuffer += charCounter*2*sizeof(char) - 2*sizeof(char);
    

    strcpy(pPopPositionB, pPositionBuffer);
    charCounterPop++;
    pPopPositionB += 2*sizeof(char);
    
    pBuffer = realloc( pBuffer, charCounter * 2*sizeof( char ) - 2*sizeof( char ) );
    charCounter --;

}

void RESET(){ // Reset Pronto

    pChar = &character;
    strcpy(pBuffer, pChar);

}
