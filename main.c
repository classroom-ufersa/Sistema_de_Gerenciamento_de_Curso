#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "curso.c"
#include "locale.h"
#define TITULO_OPCAO1 "Realizar Matricula"
#define TITULO_OPCAO2 "Excluir Matricula"
#define TITULO_OPCAO3 "Listar Matriculados"
#define TITULO_OPCAO4 "Buscar curso"
#define TITULO_OPCAO5 "Editar Matricula"
#define TITULO_OPCAO6 "Consultar vagas disponiveis para um curso"
#define TITULO_OPCAO7 "Consultar quantitativo de alunos em um curso"
#define TITULO_OPCAO8 "Sair"

#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %d e %d. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}


void ApresentaMenu(int nItens, int menorOpcao, ...) {
    int i;
    va_list argumentos;

    va_start(argumentos, menorOpcao);

    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);
}


int main(void) {
  unsigned char op;
    setlocale(LC_ALL,"");
    curso* bti = (curso*)malloc(sizeof(curso));
    curso* cet = (curso*)malloc(sizeof(curso));
    bti->lista_de_alunos = NULL;
    cet->lista_de_alunos = NULL;
    
    bti->codigo = 28091;
    bti->matriculados = 0;
    bti->vagas = 50;
    strcpy(bti->nome,"bti");
    cet->codigo = 29091;
    cet->matriculados = 0;
    cet->vagas = 80;
    strcpy(cet->nome,"cet");
    unsigned int saida = 0;

    do {
        printf("==========================================\n");
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4,
					  TITULO_OPCAO5, TITULO_OPCAO6,
					  TITULO_OPCAO7, TITULO_OPCAO8);
                      printf("=======================================\n");
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        switch(op) {
            case OPCAO1:
                 
                
                printf("\nQual curso sera realizado a matricula?");
                printf("\n 1 - bti \n 2 - cet\n");
                int option;
                Aluno *alunos = NULL;
                scanf("%i", &option);
                if(option == 1){

                alunos = realizar_matricula();
            

                } else if (option == 2){

                alunos = realizar_matricula();


                }
                
                break;

            case OPCAO2:

                printf("\nInsira uma matricula a ser removida: ");
                int mat;
                scanf("%i", &mat);
                printf("\nEm qual curso desejar realizar a remocao?");
                
                printf("\n1 - bti \n2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){
                    
                remover(mat,bti);

                } else if (option == 2){

                remover(mat,cet);
                
                }
                
                
                break; 

            case OPCAO3:
            
               printf("\nEm qual curso desejar realizar a listagem?");
                
                printf("\n1 - bti \n2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){

                imprime(bti);
                } else if (option == 2){

                imprime(cet);
                
                }
                
                break;

			    case OPCAO4:
                
                

                printf("\nInsira uma matricula a ser buscada: ");
                scanf("%i", &mat);
                printf("\nEm qual curso desejar realizar a busca?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){

                alunos = busca(mat,bti);

                if(alunos != NULL){
                printf("\nAluno encontrado\n");
                printf("Nome: %s\n", alunos->nome);
                printf("Matricula: %d\n", alunos->matricula);
                printf("Nota: %.2f\n\n", alunos->nota);
              
                    } else {
                        printf("\nAluno não encontrado\n");
                    }
                } else if (option == 2){

                alunos = busca(mat,cet);

                if(alunos != NULL){
                printf("\nAluno encontrado\n");
                printf("\nNome: %s\n curso: %s\n Matricula %d\n Nota: %.2f\n\n", alunos->nome, alunos->curso, alunos->matricula, alunos->nota);
                        }
                    }

                break;
                
            case OPCAO5:
                
                 
                printf("\nEm qual curso desejar realizar a edição?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                
                if(option == 1){
                
                editar(bti);
                printf("\nMatricula editada com sucesso!\n\n");
                } else if (option == 2){

                editar(cet);
                printf("\nMatricula editada com sucesso!\n\n");

                }
                break;
                
            case OPCAO6:
                
                printf("\nEm qual curso desejar verificar as vagas disponiveis?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){
                
                printf("\nQuantidade de vagas disponiveis em %s: %i\n\n",bti->nome, bti->vagas);
                } else if (option == 2){

                printf("\nQuantidade de vagas disponiveis em %s: %i\n\n",cet->nome, cet->vagas);

                }
                break;
                
            case OPCAO7:
               
                printf("\nEm qual curso desejar verificar a quantidade de alunos?");
                
                printf("\n 1 - bti \n 2 - cet\n");
                
                scanf("%i", &option);
                if(option == 1){
                
                printf("\nQuantidade de alunos em %s: %i\n\n",bti->nome, bti->matriculados);
                } else if (option == 2){

                printf("\nQuantidade de alunos em %s: %i\n\n",cet->nome, cet->matriculados);

                }
                break;
	    case OPCAO8:
                
                saida = 1;
                printf("Obrigado por usar este programa.");
                break; 

            default:
                printf("Este programa possui um bug.");
                return 1;
        }
    
    } while(!saida);
   
    return 0;
}
