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
