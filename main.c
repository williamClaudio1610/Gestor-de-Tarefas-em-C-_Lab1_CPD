#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "tarefa.h"

int main() {
	int opcao = 1,prioridade;
	char id_tarefa[50];
struct Node * lista = NULL;

	printf("SEJA BEM VINDO AO GESTOR DE TAREFAS\n");
	
	while(opcao != 0)
	{
	printf("1 - Fazer a inserção de uma tarefa nova na lista\n");		
	printf("2 - Imprimir a lista de tarefas por ordem de prioridade\n");
	printf("3 - Remover uma tarefa da lista de tarefas\n");
	printf("4 - Sair\n");	
	scanf("%d", &opcao);


		if(opcao == 1)
		{
    printf("Escreva a prioridade da tarefa\n");
  scanf("%d",&prioridade);
  
  while((prioridade < 0) || (prioridade > 5))
  {
  	printf("Prioridade inválida\n\n");
    printf("Escreva a prioridade da tarefa\n");
  scanf("%d",&prioridade); 	
  }

  printf("Escreva a id da tarefa:\n");
  scanf("%s",id_tarefa);

    inserir_tarefaNaLista(&lista, id_tarefa, prioridade,time(NULL));

				
		}
		else
		if(opcao == 2)
		{
    imprimirListaTarefa(lista);			
		}		
		else
		if(opcao == 3)
		{
    printf("Escreva a prioridade da tarefa\n");
  scanf("%d",&prioridade);
  
  while((prioridade < 0) || (prioridade > 5))
  {
  	printf("Prioridade inválida\n\n");
    printf("Escreva a prioridade da tarefa\n");
  scanf("%d",&prioridade); 	
  }

  printf("Escreva a id da tarefa:\n");
  scanf("%s",id_tarefa);
			
			
			removerTarefa(&lista,id_tarefa,prioridade);
		}		
		else
		if(opcao == 4)
		{
		return 0;		
		}			
		else
		{
		printf("Número invalido\n");	
		}			
	}
	
   

}

