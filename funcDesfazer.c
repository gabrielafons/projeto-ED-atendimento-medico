#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

/* digita isso para compilar todo o arquivo 
gcc main.c funcFilaAtend.c funcFilaAtend.h funcCadastrar.c funcCadastrar.h estruturas.h funcFilaPrior.c funcFilaPrior.h funcPesquisa.c funcPesquisa.h funcDesfazer.c funcDesfazer.h
chato dms ter que digitar isso
*/

#include "funcDesfazer.h"

void mostrarPilha(Pilha* pilha){
    Operacao* atual = pilha->topo;
    
    if(atual==NULL){
        printf("Pilha vazia\n");
    }

    printf("Pilha de Operações\n");
    printf("Ultimas operações realizadas\n");
    while(atual != NULL){
        if(atual->tipoOperacao == 1){
            printf("Inserção de paciente: %s,idade: %d,RG: %s, Data de entrada%02d/%02d/%04d\n", 
                atual->efila->dados->nome,atual->efila->dados->idade,atual->efila->dados->rg,
                atual->efila->dados->entrada->dia, atual->efila->dados->entrada->mes, atual->efila->dados->entrada->ano);    

        }else if(atual->tipoOperacao == 2){
            printf("Remoção de paciente: %s,idade: %d,RG: %s, Data de entrada%02d/%02d/%04d\n", 
                atual->efila->dados->nome,atual->efila->dados->idade,atual->efila->dados->rg,
                atual->efila->dados->entrada->dia, atual->efila->dados->entrada->mes, atual->efila->dados->entrada->ano);    
        }
        atual = atual->anterior;
    }
}

void construirPilha(Efila* eFila,Pilha* pilha, int tipoOperacao){
    Operacao* operacao = (Operacao*) malloc(sizeof(Operacao));
    operacao->efila = eFila;
    operacao->tipoOperacao = tipoOperacao;
    operacao->prox= NULL;
    operacao->anterior = NULL;

    if(pilha->qtde !=0){
        operacao->anterior = pilha->topo;
        pilha->topo->prox = operacao;
    }
    pilha->topo = operacao;
    pilha->qtde++;

}

void popPilha(Pilha* pilha){
    if (pilha->topo == NULL) return;

    Operacao* remover = pilha->topo;
    pilha->topo = remover->anterior;

    if (pilha->topo != NULL) {
        pilha->topo->prox = NULL;
    }

    free(remover);
    pilha->qtde--;
}

void desfazerOperacao(Pilha* pilha,Fila* fila){
    if(pilha->topo == NULL){
        printf("Pilha vazia. Nenhuma operação para desfazer.\n");
        return;
    }

    
    Operacao* operacao = pilha->topo;
    if(operacao->tipoOperacao == 1){ // operação de inserção
        char confirmacao;
        printf("Deseja realmente desfazer a inserção do Paciente: %s e RG: %s da fila? (s/n): ",operacao->efila->dados->nome,operacao->efila->dados->rg);
        scanf(" %c\n", &confirmacao);

        if (confirmacao != 's') {
            printf("Desfazer cancelado pelo usuário.\n");
            return;
        }

        Efila* anterior =NULL;
        Efila* atual = fila->head;

        if(fila->qtde == 1){
            fila->head = NULL;
            fila->tail = NULL;
        }else{
            while(atual != fila->tail){
                anterior =atual;
                atual = atual->prox;
            }
            fila->tail = anterior;
            fila->tail->prox = NULL;
        }
        fila->qtde--;
    }else if(operacao->tipoOperacao == 2){

        char confirmacao;
        printf("Deseja realmente desfazer a remoção do Paciente: %s e RG: %s da fila? (s/n): ",operacao->efila->dados->nome,operacao->efila->dados->rg);
        scanf(" %c\n", &confirmacao);

        if (confirmacao != 's') {
            printf("Desfazer cancelado pelo usuário.\n");
            return;
        }

        operacao->efila->prox = fila->head;
        fila->head = operacao->efila;
        if(fila->qtde == 0){
            fila->tail = operacao->efila;
        }
        fila->qtde++;
    }

    printf("Operação Desfeita\n");
    popPilha(pilha);
}
