/*Faça um laço de entrada de dados, onde o usuário deve digitar uma sequência de números, sem
limite de quantidade de dados a ser fornecida. O usuário irá digitar os números um a um, sendo
que caso ele deseje encerrar a entrada de dados, ele irá digitar o número Zero. No final, todos os
dados digitados deverão ser salvos em um arquivo texto em disco. Atenção: os dados devem ser
armazenados na memória deste modo... faça com que o programa inicie criando um ponteiro para
um bloco (vetor) de 10 valores inteiros, e alocando dinamicamente espaço em memória para este
bloco; após, caso o vetor alocado esteja cheio; aloque um novo vetor do tamanho do vetor anterior
adicionado com espaço para mais 10 valores (tamanho N+10, onde N inicia com 10), copie os
valores já digitados da área inicial para esta área maior e libere a memória da área inicial; repita
este procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada vez que o
mesmo estiver cheio. Assim o vetor irá ser “expandido” de 10 em 10 valores. Usar a função
malloc para alocar memória de forma dinâmica.*/
#include <stdio.h>
#include <stdlib.h>
#define VEC_TAM 10

int* vecExpansion(int n){
     int* v = (int*) malloc(sizeof(int) * (n + VEC_TAM));
     if(!v)
          return NULL;
     return v;
}

int* vecCreator(int n){
     if(n < 1)
          return NULL;
     int *v = (int*) malloc(sizeof(int) * n);
     if(!v)
          return NULL;
     return v;
}

void printVector(int *v, int size){
     for(int index = 0; index < size; index++)
          printf(" %d ", v[index]);
}

int storeInFile(int *v, int size){
     FILE *f = fopen("vector.txt", "w");
     if(!f)
          return EXIT_FAILURE;
     for(int i = 0; i < size; i++)
          fprintf(f, "%d\n", v[i]);
     fclose(f);
     return EXIT_SUCCESS;
}

int numberInsertion(){
     int vetSize = VEC_TAM, loopSize = 0;
     int *vet = vecCreator(vetSize);
     int value = 1;
     printf("\nForneca os numeros que quiser: (0 -> Finalizar programa)\n");
     while(value){
          if(loopSize == vetSize - 1){
               printf("--Expandindo vetor (+%d)--", VEC_TAM);
               int *newVet = vecExpansion(vetSize);
               vetSize = vetSize + VEC_TAM;

               for(int index = 0; index < loopSize; index++)
                    newVet[index] = vet[index];
               free(vet);
               vet = newVet;     
          }
          printf("\nIndice %d:\n", loopSize);
          scanf("%d", &vet[loopSize]);
          if(!(vet[loopSize])) break;

          loopSize++;
     }
     printf("\nVetor:\n");
     printVector(vet, loopSize);
     if(storeInFile(vet, loopSize))
          perror("\nERRO: Nao foi possivel abrir o arquivo.\n");
     free(vet);
     return EXIT_SUCCESS;
}

int main(){
     return numberInsertion();  
}