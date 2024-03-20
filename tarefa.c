#include "tarefa.h"

void inserir_tarefaNaLista(struct Node** head, char id_tarefa[], int prioridade, time_t dataCriacao) {
	
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }

   
    strcpy(newNode->id_tarefa, id_tarefa);
    newNode->prioridade = prioridade;
    newNode->dataCriacao = dataCriacao;

 
    newNode->next = *head;

  
    *head = newNode;
}

void imprimirListaTarefa(struct Node* node) {
 
 int prioridade;
    for (prioridade = 5; prioridade >= 0; prioridade--) {
        printf("Prioridade %d:\n", prioridade);


        struct Node* curr = node;
        while (curr != NULL) {
            if (curr->prioridade == prioridade) {
                printf("ID da tarefa: %s, Prioridade: %d, Data de Criação: %s", curr->id_tarefa, curr->prioridade, ctime(&curr->dataCriacao));
            }
            curr = curr->next;
        }
    }
}

void removerTarefa(struct Node** head, char id_tarefa[], int prioridade) {
    if (*head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    if (strcmp((*head)->id_tarefa, id_tarefa) == 0 && (*head)->prioridade == prioridade) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Tarefa com a id '%s' e prioridade '%d' removido da lista.\n", id_tarefa, prioridade);
        return;
    }

    struct Node* prev = *head;
    struct Node* curr = (*head)->next;
    while (curr != NULL && (strcmp(curr->id_tarefa, id_tarefa) != 0 || curr->prioridade != prioridade)) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        prev->next = curr->next;
        free(curr);
        printf("Tarefa com a id '%s' e prioridade '%d' removido da lista.\n", id_tarefa, prioridade);
    } else {
        printf("TAREFA INEXISTENTE\n");
    }
}

