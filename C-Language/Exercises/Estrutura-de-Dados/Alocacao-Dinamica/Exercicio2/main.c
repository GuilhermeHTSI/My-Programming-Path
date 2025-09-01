/*Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos e passe esse
vetor para uma função que vai ler os elementos desse vetor. Depois, no programa principal, o vetor
preenchido deve ser impresso. Além disso, antes de finalizar o programa, deve-se liberar a área de
memória alocada.*/
#include <stdio.h>
#include <stdlib.h>

/*Imprime o vetor dinamico.
* Retorna '0' se o vetor for impresso com sucesso ou '1'.*/
int printVector(int *v, int n){
     if(!v)
          return EXIT_FAILURE;
     for(int indice = 0; indice < n; indice++){
          printf(" %d ", v[indice]);
     }
     return EXIT_SUCCESS;
}

/*Funcao que preenche o vetor dinamico.
* Retorna o vetor preenchido ou NULL.*/
int* fulfillVector(int *v, int n){
     if(!v)
          return NULL;
     for(int indice = 0; indice < n; indice++){
          printf("\nInforme o valor do indice %d\n", indice + 1);
          scanf("%d", &v[indice]);
     }
     return v;
}

/*Cria um vetor dinamico com base em uma variavel informada pelo usuario.
* Se o vetor for criado com sucesso entao ele sera retornado, caso contrario sera retornado NULL.*/
int* createVector(int n){
     int *v = (int*) malloc(sizeof(int) * n);
     if(!v)
          return NULL;
     return v;
}

//Le um valor passado pelo usuario e cria um vetor dinamico.
int dataReader(){
     int n;
     printf("\nInforme o tamanho do vetor.\n");
     scanf("%d", &n);
     printf("\nVetor definido com o tamanho %d.\n", n);
     int *vet;

     vet = fulfillVector(createVector(n), n);
     printVector(vet, n);
     free(vet);
     return EXIT_SUCCESS;
}

int main(){
     return dataReader();
}