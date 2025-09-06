//5) Idem a questão acima, mas use a função realloc.
#include <stdio.h>
#include <stdlib.h>
#define VEC_TAM 10

int* vecExpansion(int *vet, int *n){
     int *newVet = (int*) realloc(vet, (*n + VEC_TAM) * sizeof(int));
     if(!newVet)
          return NULL;
     *n = (*n) + VEC_TAM;
     return newVet;
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
          if(loopSize == vetSize){
               printf("--Expandindo vetor (+%d)--", VEC_TAM);
               vet = vecExpansion(vet, &vetSize);
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
