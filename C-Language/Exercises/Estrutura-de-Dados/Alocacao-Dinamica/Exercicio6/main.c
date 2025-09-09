/*Construa um programa (main) que aloque em tempo de execução (dinamicamente) uma matriz de
ordem m x n (linha por coluna), usando 1+m chamadas a função malloc. Agora, aproveite este
programa para construir uma função que recebendo os parâmetros m e n aloque uma matriz de
ordem m x n e retorne um ponteiro para esta matriz alocada. Crie ainda uma função para liberar a
área de memória alocada pela matriz. Finalmente, crie um novo programa (main) que teste/use as
duas funções criadas acima.*/
#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int **mat, int m, int n){
     for(int lines = 0; lines < m; lines++)
          for(int colums = 0; colums < n; colums++)
               free(mat[lines][colums]);
}

void printMat(int **mat, int m, int n){
     for(int lines = 0; lines < m; lines++){
          for(int colums = 0; colums < n; colums++)
               printf("%d\t", mat[lines][colums]);
          printf("\n");
     }
}

int fullFillMat(int **mat, int m, int n){
     if(!mat)
          return EXIT_FAILURE;
     for(int lines = 0; lines < m; lines++){
          for(int colums = 0; colums < n; colums++){
               printf("\nLinha %d Coluna %d:\n", lines + 1, colums + 1);
               scanf("%d", &mat[lines][colums]);
          }
     }
     return EXIT_SUCCESS;
}

int** matrixSecondTest(int m, int n){

}

int matrixFirstTest(int ***mat, int m, int n){
     *mat = (int**) malloc(sizeof(int*) * m);
     for(int lines = 0; lines < m; lines++){
          (*mat)[lines] = (int*) malloc(sizeof(int) * n);
     }
     return EXIT_SUCCESS;
}

int matrixManipulation(){
     int lines, colums, option;
     printf("\nForneca o numero de linhas:\n");
     scanf("%d", &lines);
     int **matrix;
     printf("\nForneca o numero de colunas:\n");
     scanf("%d", &colums);

     printf("\n1-Forma retornada\t2-Forma de criacao comum.\n");
     scanf("%d", &option);

     if(option == 1)
          matrix = matrixSecondTest(colums, lines);
     else
          matrixFirstTest(&matrix, lines, colums);

     fullFillMat(matrix, colums, lines);
     printMat(matrix, colums, lines);
     freeMatrix(matrix, lines, colums);
     return EXIT_SUCCESS;
}

int main(){
     return matrixManipulation();
}