#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

/* digita isso para compilar todo o arquivo 
gcc main.c funcFilaAtend.c funcFilaAtend.h funcCadastrar.c funcCadastrar.h estruturas.h
chato dms ter que digitar isso
*/
#include "funcFilaAtend.h"
#include "funcCadastrar.h"
#include "funcDesfazer.h"

void enfileirar(Lista* lista,Fila* fila, Pilha* pilha){
    Paciente* paciente = encontraPaciente(lista); // ponteiro para o paciente na lista
     if(paciente == NULL){
        return;
    }

    Efila* efila = (Efila*) malloc(sizeof(Efila));
    efila->dados = paciente;
    efila->prox = NULL;    

   if(fila->qtde == 0){// caso a fila esteja vazia
        fila->head = efila;
        printf("Paciente \"%s\" adicionado como o primeiro da fila.\n", paciente->nome);
   }else{// caso tenha algo na lista
        fila->tail->prox = efila;
        printf("Paciente \"%s\" adicionado ao final da fila.\n", paciente->nome);
   }
   //atualização da pilha de operações
   construirPilha(efila,pilha,1);

   fila->tail = efila;
   fila->qtde++;
}

void desinfileirar(Fila* fila,Pilha* pilha){// desinfileirar recebe só a fila pq sempre tira o primeiro da fila, não é necessario busca
    if(fila->head == NULL){
        printf("Fila vazia. Nenhum paciente para atender.\n");
        return;
    }

    Efila* remover = fila->head;
    Paciente* paciente = remover->dados;

    printf("Próximo paciente:\n");
    printf("Nome: %s\n", paciente->nome);
    printf("Idade: %d\n", paciente->idade);
    printf("RG: %s\n", paciente->rg);
    printf("\nTem certeza que deseja atender este paciente?\n");
    printf("Digite 's' para confirmar: ");

    char confirmacao;
    scanf(" %c", &confirmacao);

    if (confirmacao != 's') {
        printf("Remoção cancelada.\n");
        return;
    }

    if(fila->qtde == 1){//ultimo paciente a ser atendido
        fila->head = NULL;
        fila->tail = NULL;
    }else{
        fila->head = fila->head->prox;
    }
  
    //atualização da pilha de operações
    construirPilha(remover,pilha,2);
    fila->qtde--;
    printf("Paciente atendido com sucesso. Fila agora possui %d paciente(s).\n", fila->qtde);
}

void mostra(Fila* fila){
    if (fila->head == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    printf("=== Pacientes na fila ===\n");
    Efila* atual = fila->head;
    int posicao = 1;

    while (atual != NULL) {
        Paciente* paciente = atual->dados;
        printf("Posição %d:\n", posicao);
        printf("  Nome: %s\n", paciente->nome);
        printf("  Idade: %d\n", paciente->idade);
        printf("  RG: %s\n\n", paciente->rg);

        atual = atual->prox;
        posicao++;
    }

    printf("Total de pacientes na fila: %d\n", fila->qtde);

}

