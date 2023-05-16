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
curso* capturarListaAlunos(curso* c) {
    FILE* arq = fopen("ListadaMatricua.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {
        Aluno* aluno = NULL;
        while (1) {
            aluno = (Aluno*)malloc(sizeof(Aluno));
            if (aluno == NULL) {
                printf("Erro ao alocar memoria.\n");
                break;
            }
            int result = fscanf(arq, "INFORMACOES DO MATRICULADO\nNome: %99[^\n]\nMatricula: %d\nNota: %f\n\n", aluno->nome, &aluno->matricula, &aluno->nota);
            if (result != 3) {
                free(aluno);
                break;
            }
            aluno->next = NULL;
            if (c->lista_de_alunos == NULL) {
                c->lista_de_alunos = aluno;
            } else {
                aluno->next = c->lista_de_alunos;
                c->lista_de_alunos = aluno;
            }
        }
        fclose(arq);
    }
    //Inserir algoritmo de ordenção aqui 

    return c;
   
}

    void inserir_matricula (Aluno *novo_aluno, curso *curso){
            
            if(curso->vagas != 0){
                           
            if(curso->lista_de_alunos == NULL){
                curso->lista_de_alunos = novo_aluno;
                curso->lista_de_alunos->next = NULL;
                curso->matriculados++;
                curso->vagas--;
            } else if(curso->lista_de_alunos != NULL){
                novo_aluno->next = curso->lista_de_alunos;
                curso->lista_de_alunos = novo_aluno;
                curso->vagas--;
                }             
            
            } else {
                 printf("\nNao ha mais vagas no curso de %s", curso->nome);  
         }
    }
    
 int remover(int mat, curso *c){
    c = capturarListaAlunos(c);
    Aluno *alunoRemovido = c->lista_de_alunos;
    Aluno *aux = NULL;

    if(alunoRemovido->matricula == mat){
         c->lista_de_alunos = alunoRemovido->next;
         free(alunoRemovido);
         atualizarArquivo(c);
         return 1;
    }

    for(alunoRemovido = c->lista_de_alunos; alunoRemovido != NULL; alunoRemovido = alunoRemovido->next){    
            if(alunoRemovido->matricula == mat){
               aux->next = alunoRemovido->next;
               free(alunoRemovido);
               atualizarArquivo(c);
               break;
            }
            aux = alunoRemovido; 
       } 
      
} 

