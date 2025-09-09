/*Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME 50
#define MAX_DATE 3
#define AUX_DATE 15
#define MAX_TRIES 3
#define MAX_CPF 11

typedef struct TUser{
     char name[MAX_NAME];
     int bDate[MAX_DATE];
     char cpf[MAX_CPF];
}User;

typedef User *user;

void printUserInfo(user data){
     printf("\n\n--Imprimindo as informacoes do usuario:\n");
     printf("\nNome de usuario: %s\nData de nascimento: %d/%d/%d\nCPF:%s\n", 
          data->name, data->bDate[0], data->bDate[1], data->bDate[2], data->cpf);
}

bool checkDate(char *birth, int *d, int *m, int *y, char *delim){
     char *token = strtok(birth, delim);
     if(!token)
          return false;
     for(int count = 0; token && count < MAX_DATE; count++){
          if(!count){
               *d = atoi(token);
          }
          else if(count == 1)
               *m = atoi(token);
          else
               *y = atoi(token);
          token = strtok(NULL, delim);
     }
     return true;
}

int bDateFormat(user data, char *birth){
     int day, month, year;
     char *try[MAX_TRIES] = {"/", " ", "\t"};
     bool found = false;
     for(int index = 0; index < MAX_TRIES && !found; index++)
          found = checkDate(birth, &day, &month, &year, try[index]);
     data->bDate[0] = day;
     data->bDate[1] = month;
     data->bDate[2] = year;
     return EXIT_SUCCESS;
}

int requestInfo(user data){
     char date[AUX_DATE];

     
     printf("\nPreencha os campos de usuario a seguir:\n");     
     printf("\nNome: ");
     fgets(data->name, MAX_NAME, stdin);
     setbuf(stdin, NULL);
     data->name[strcspn(data->name, "\n")] = 0; // Separar

     printf("\nData de nascimento: ");
     fgets(date, AUX_DATE, stdin);
     setbuf(stdin, NULL);
     date[strcspn(date, "\n")] = 0; // Separar
     bDateFormat(data, date);

     printf("\nCPF: ");
     fgets(data->cpf, MAX_CPF, stdin);
     data->cpf[strcspn(data->cpf, "\n")] = 0;

     return EXIT_SUCCESS;
}

user initializeUser(){
     user data = (user) calloc(1, sizeof(User));
     if(!data)
          return NULL;
     return data;
}

int infoUser(){
     user person = initializeUser();
     requestInfo(person);
     printUserInfo(person);
     return EXIT_SUCCESS;
}

int main(){
     return infoUser();
}