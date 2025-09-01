/*Este é um programa feito durante a primeira aula de Sistema Operacional, por enquanto o código está incompleto*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_LINES 4
#define SIZE_COLUMNS 12
#define READ 10
#define WRITE 11
#define HALT 12
#define NONE -1

typedef char Palavra[SIZE_COLUMNS]; 
typedef unsigned int Endereco; // Endereço de 32 bits

Palavra memoria[SIZE_LINES]; // equivale a char memoria[3][12];

void removeEnter(char *word){
        
}

void lerPrograma(){
    printf("\nA seguir digite os códigos para cada linha.\n\n");
    for(int line = 0; line < SIZE_LINES; line++){
        printf("\n%do comando:\n", line + 1);    
        setbuf(stdin, NULL);
        fgets(memoria[line], SIZE_COLUMNS, stdin);
        removeEnter(memoria[line]);
    }
}


/*
    READ - (10)
    WRITE - (11)
    HALT - (12)
    NONE - (-1)

*/
int identificarInstrucao(Palavra instrucao){
    char *tokenInstrucao = strtok(instrucao, " ");
    if(!strcmp(tokenInstrucao, "READ"))
        return READ;
    if(!strcmp(tokenInstrucao, "WRITE"))
        return WRITE;
    if(!strcmp(tokenInstrucao, "HALT"))
        return HALT;
    else
        return NONE;
}

int localizarDado(Palavra instrucao, int tipoInstrucao){
    char *tokenDado = strtok(instrucao, " ");
    char dado[SIZE_COLUMNS];
    while(tokenDado){
        strcpy(dado, tokenDado);
        tokenDado = strtok(NULL, " ");
    }

    return 1;
}

int executarInstrucao(int tipoInstrucao, int dado){
    return 1;
}

int interpretador(Endereco enderecoInicial) {
	Endereco pc, // Registrador que possui o endereço da próxima instrução.
	  	     localizacaoDado;
	Palavra instrucao;
	
	int dado, execucao = 1, tipoInstrucao;

	pc = enderecoInicial;
	while (execucao && pc <= SIZE_LINES) {
	    strcpy(instrucao, memoria[pc]);
	    
		pc = pc + 1; // Passo 2
		
		tipoInstrucao = identificarInstrucao(instrucao); // Passo 3
		localizacaoDado = localizarDado(instrucao, tipoInstrucao); // Passo 4

		// Verifica se a instrução possui operando.
		if (localizacaoDado >= 0) 
		    dado = atoi(memoria[localizacaoDado]); // Passo 5
		
		execucao = executarInstrucao(tipoInstrucao, dado); // Passo 6
	}
	return 1;
}


int main(){
    lerPrograma();
    return interpretador(0);
}

