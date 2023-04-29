#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"aluno.h"

typedef struct curso{
    int codigo;
    Aluno *lista_de_alunos;
    char nome[50];
    int vagas;
    int matriculados;
}Curso;

 Aluno *realizar_matricula(void){
	  	
		   Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
		   
		   printf("digite seu nome\n");
		   scanf(" %[^\n]", alunos->nome);
		   printf("\n");
		   
		   printf("digite sua matricula\n");
		   scanf("%d" , &alunos->matricula);
		   printf("\n");

           printf("digite seu curso\n");
		   scanf(" %[^\n]", &alunos->curso);
		   printf("\n"); 
		   
		   printf("digite sua nota\n");
		   scanf("%f" , &alunos->notas);
	       printf("\n");
        FILE* arq = fopen ("matricula.txt", "w");
	  	 if(arq ==NULL){
        printf("Erro ao abrir o arquivo: ");
        return 1; 
 }
