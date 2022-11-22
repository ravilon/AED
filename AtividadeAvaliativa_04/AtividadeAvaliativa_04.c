/*Dado um vetor nums contendo n número inteiros positivos e únicos encontre o número
faltante na sequência. Assuma que somente um número está faltando para completar a
sequência numérica.*/

#include <stdlib.h>
#include <stdio.h>

int numberMissing (int array[], int arraySize){
    int numberMissing = 0;
    for (int i = 0; i < arraySize; i++){
        if (array[i] != i+1){
            numberMissing = i+1;
            break;
        }
    }
    return numberMissing;
}

void MergeSort(int array[], int arraySize) {
    if (arraySize > 1) {
        int middle = arraySize/2;
        int left[middle];
        int right[arraySize-middle];
        for (int i = 0; i < middle; i++) {
            left[i] = array[i];
        }
        for (int i = middle; i < arraySize; i++) {
            right[i-middle] = array[i];
        }
        MergeSort(left, middle);
        MergeSort(right, arraySize-middle);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < middle && j < arraySize-middle) {
            if (left[i] < right[j]) {
                array[k] = left[i];
                i++;
            }
            else {
                array[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < middle) {
            array[k] = left[i];
            i++;
            k++;
        }
        while (j < arraySize-middle) {
            array[k] = right[j];
            j++;
            k++;
        }
    }
}

int main() {
    int arraySize=0;

    printf("Esse programa identifica o número faltante em uma sequência de números inteiros positivos e únicos.\n");
    printf("Digite a quantidade de números que deseja inserir: \n");
    scanf("%d", &arraySize);
    
    int array[arraySize];
    
    for (int i = 0; i < arraySize; i++){
        printf("Digite o %dº número: \n", i+1);
        scanf("%d", &array[i]);
    }

    MergeSort(array, arraySize);
    printf("O número faltante é: %d \n", numberMissing(array, arraySize));
}

