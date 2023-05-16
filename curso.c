#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.c"

typedef struct curso{
    int codigo;
    Aluno *lista_de_alunos;
    char nome[50];
    int vagas;
    int matriculados;
}curso;

typedef struct list{
    curso *info;
    struct list *next;
}list;

 void LimpaBuffer(void) {
    int valorLido;
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
} 

   void atualizarArquivo(curso *c) {
    FILE *arq = fopen("ListadaMatricua.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fclose(arq);

    arq = fopen("ListadaMatricua.txt","a+");
    Aluno *aluno = c->lista_de_alunos;
    while (aluno != NULL) {
        fprintf(arq, "INFORMACOES DO MATRICULADO\nNome: %s\nMatricula: %d\nNota: %.2f\n\n", aluno->nome, aluno->matricula, aluno->nota);
        aluno = aluno->next;
    }

    fclose(arq);
    
}


   Aluno *realizar_matricula(void){
	  	
		   Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
		  printf("INSIRA SUAS INFORMACOES!\n"); 
		   printf("digite seu nome\n");
		   scanf(" %[^\n]", alunos->nome);
		   printf("\n");
		   
		   printf("digite sua matricula\n");
		   scanf("%d" , &alunos->matricula);
		   printf("\n");
		   
		   printf("digite sua nota\n");
		   scanf("%f" , &alunos->nota);
	       printf("\n");
	  
	  	FILE* arq = fopen ("ListadaMatricua.txt", "a+");
	  	 if(arq ==NULL){
        printf("Erro ao abrir o arquivo: "); 
    }
        else{
            printf("arquivo criado\n");

            
             fprintf(arq, "INFORMACOES DO MATRICULADO\nNome: %s\nMatricula: %d\nNota: %.2f\n\n", alunos->nome, alunos->matricula, alunos->nota);
        }

    fclose(arq);
    return alunos;
	}

