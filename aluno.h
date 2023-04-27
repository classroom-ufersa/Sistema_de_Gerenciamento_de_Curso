#include<stdio.h>
#include<stdlib.h>

  struct aluno{
    char nome[100];
    int matricula;
    char curso;
    float notas;
	struct alunos *next;
};
