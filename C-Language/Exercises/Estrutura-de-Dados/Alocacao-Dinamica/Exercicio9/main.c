/*Faça um programa que leia um número inteiro n, representando a quantidade de elementos que
serão armazenados. Em seguida, aloque dinamicamente um vetor capaz de armazenar n inteiros.
O programa deve solicitar que o usuário digite os valores um a um, preenchendo todo o vetor. Após
a leitura, exiba todos os elementos armazenados na tela, na mesma ordem em que foram digitados.
Por fim, libere corretamente a memória alocada. */
#include <stdio.h>
#include <stdlib.h>
#define NEW_LINE "\n"

int printVector(int *vector, int vectorSize){
     printf("\n\nImprimindo o vetor:\n\n");
     for(int index = 0; index < vectorSize; index++)
          printf("\t[%d]\t", vector[index]);
     return EXIT_SUCCESS;
}

int fulFillVector(int *vector, int vectorSize){
     printf("\nAgora preencha o vetor:\n");
     for(int index = 0; index < vectorSize; index++){
          printf("\n\tForneca o valor do %do indice:", index + 1);
          scanf("%d", &vector[index]);
          printf(NEW_LINE);
     }
     return EXIT_SUCCESS;
}

void freeVector(int *vector){
     free(vector);
}

int* createVector(int vectorSize){
     int *vector = (int*) malloc(sizeof(int) * vectorSize);
     if(!vector)
          return NULL;
     return vector;
}

int defineSize(){
     int size;
     printf("\nDigite o tamanho do vetor:\n");
     scanf("%d", &size);
     if(size < 1)
          return EXIT_FAILURE; // Definindo o retorno como EXIT_FAILURE, pois assim o menor valor possível sempre sera 1.
     return size;
}

int vectorUser(){
     int vectorSize = defineSize();
     int *vector = createVector(vectorSize);
     fulFillVector(vector, vectorSize);
     printVector(vector, vectorSize);
     freeVector(vector);
     return EXIT_SUCCESS;
}

int main(){
     return vectorUser();
}