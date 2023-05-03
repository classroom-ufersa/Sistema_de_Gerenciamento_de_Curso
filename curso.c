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

  else if(arq){
            printf("arquivo criado\n");
        }
         
    	 fprintf(arq, "nome: %s\n matricula %d\n nota: %.2f\n\n", alunos->nome, alunos->curso, alunos->matricula, alunos->notas);
    	 
    fclose(arq);
    return alunos;
	}
 void inserir_matricula (Aluno *novo_aluno, Curso *curso){
            
            if(curso->vagas == 0){
                printf("\nNao ha mais vagas no curso de %s", curso->nome);              
            }

            if(curso->lista_de_alunos == NULL){
                curso->lista_de_alunos = novo_aluno;
                curso->lista_de_alunos->next = NULL;
                curso->matriculados++;
                curso->vagas--;
            } else if(curso->lista_de_alunos != NULL){
                novo_aluno->next = curso->lista_de_alunos;
                curso->lista_de_alunos = novo_aluno;
                curso->matriculados++;
                curso->vagas--;
            }              
    }
    
	int remover(int mat, Curso *c){

    if(c->lista_de_alunos == NULL){
        printf("\nNao existem pessoas matriculadas no curso\n");
        return 0;
    }