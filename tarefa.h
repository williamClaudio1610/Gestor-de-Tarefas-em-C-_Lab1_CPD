#ifndef TAREFA_H
#define TAREFA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
    time_t dataCriacao;
    char id_tarefa[50];
    int prioridade;
    struct Node* next;
};

typedef struct Node Node;

void inserir_tarefaNaLista(Node** head, char id_tarefa[], int prioridade, time_t dataCriacao);
void imprimirListaTarefa(Node* node);
void removerTarefa(Node** head, char id_tarefa[], int prioridade);

#endif /* TAREFA_H */
