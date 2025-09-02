/* Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e retorne
um ponteiro. Crie uma função que receba um ponteiro para um vetor e um valor n e imprima os n
elementos desse vetor. Construa também uma função que receba um ponteiro para um vetor e
libere esta área de memória. Ao final, crie uma função principal que leia um valor n e chame a
função criada acima. Depois, a função principal deve ler os n elementos desse vetor. Então, a
função principal deve chamar a função de impressão dos n elementos do vetor criado e, finalmente,
liberara memória alocada através da função criada para liberação.*/
#include <stdio.h>
#include <stdlib.h>

void vectorFree(int *v){
     free(v);
}

int vectorPrinter(int *v, int n){
     if(!v || !n)
          return EXIT_FAILURE;
     printf("\nVetor impresso:\n");
     for(int index = 0; index < n; index++){
          printf(" %d ", v[index]);
     }
     return EXIT_SUCCESS;
}

int vectorAtribution(int *v, int n){
     if(!v || !n)
          return EXIT_FAILURE;
     printf("\nForneca o valor dos campos do vetor.\n");
     for(int index = 0; index < n; index++){
          printf("\nValor do %do indice:\n", index + 1);
          scanf("%d", &v[index]);
     }
     return EXIT_SUCCESS;
}

int* vectorCreation(int n){
     if(n < 1)
          return NULL;
     int *v = (int*) malloc(sizeof(int) * n);
     if(!v)
          return NULL;
     return v;
}

int vectorManipulation(){
     int n;
     printf("\nForneca o tamanho do vetor:\n");
     scanf("%d", &n);
     while(n < 1){
          printf("\nAviso: Voce deve passar um valor positivo para a criacao do vetor!\n");
          scanf("%d", &n);
     }
     int *vet = vectorCreation(n);
     if(!vet){
          perror("\nErro: Nao ha espaco de memoria suficiente.\n");
          return EXIT_FAILURE;
     }
     if(vectorAtribution(vet, n)){
          perror("\nErro: Funcao de atribuicao nao funcionou como o esperado!\n");
          return EXIT_FAILURE;
     }
     if(vectorPrinter(vet, n)){
          perror("\nErro: Funcao de impressao nao funcionou como o esperado!\n");
          return EXIT_FAILURE;
     }
     vectorFree(vet);
     return EXIT_SUCCESS;
}

int main(){
     return vectorManipulation();
}