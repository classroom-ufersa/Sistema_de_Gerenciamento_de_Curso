#ifndef CURSO.H
#define CURSO.H
#include <string.h>
#include "curso.c"

typedef struct curso;

typedef struct list list;

void LimpaBuffer();

void atualizarArquivo(curso *c);

Aluno *realizar_matricula(void);

curso* capturarListaAlunos(curso* c);

void inserir_matricula (Aluno *novo_aluno, curso *curso);

int remover(int mat, curso *c);

Aluno* busca(int mat, curso* c);

int imprime (curso *c);

int editar(curso *c);
