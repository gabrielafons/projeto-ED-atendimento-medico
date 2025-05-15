#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

/* digita isso para compilar todo o arquivo 
gcc main.c funcFilaAtend.c funcFilaAtend.h funcCadastrar.c funcCadastrar.h estruturas.h funcFilaPrior.c funcFilaPrior.h funcPesquisa.c funcPesquisa.h
chato dms ter que digitar isso
*/
#include "funcPesquisa.h"
#include "funcCadastrar.h"

void freeArvore(EABB* raiz) {
    if (raiz == NULL) return;

    freeArvore(raiz->esq);
    freeArvore(raiz->dir);
    free(raiz);
}

void mostrarArvore(EABB* raiz){
    if (raiz != NULL) {
        mostrarArvore(raiz->esq);
        printf("Nome: %s, Idade: %d, RG: %s, Data: %02d/%02d/%04d\n",
               raiz->dados->nome,
               raiz->dados->idade,
               raiz->dados->rg,
               raiz->dados->entrada->dia,
               raiz->dados->entrada->mes,
               raiz->dados->entrada->ano);
        mostrarArvore(raiz->dir);
    }
}

void contruirArvore(Lista* lista, ABB* arvore,int operacao){
    freeArvore(arvore->raiz);
    arvore->raiz = NULL;
    arvore->qtde = 0;

    
    Elista* eAtual = lista->inicio;
    EABB* anterior = NULL;
    EABB* atual = arvore->raiz;
  
    if(eAtual==NULL){
        printf("Nenhum Usuario cadastrado\n");
        return;
    }
    while(eAtual!=NULL){
        EABB* novo = (EABB*) malloc(sizeof(EABB));
        novo->dados = eAtual->dados;
        novo->dir = NULL;
        novo->esq = NULL;
        while(atual!=NULL){
            anterior = atual;
            if(operacao == 1){//ordenação por ano
                if(novo->dados->entrada->ano <= anterior->dados->entrada->ano){//comparação com ano se menor vai para esq
                    atual = atual->esq;
                }else{
                    atual= atual->dir;
                }
                // procurando um lugar vazio na arvore para inserir o novo
            }if(operacao == 2){ //ordenação por mes
                if(novo->dados->entrada->mes <= anterior->dados->entrada->mes){//comparação com mes se menor vai para esq
                    atual = atual->esq;
                }else{
                    atual= atual->dir;
                }
                // procurando um lugar vazio na arvore para inserir o novo
            }if(operacao == 3){// ordenação por dia
                if(novo->dados->entrada->dia <= anterior->dados->entrada->dia){//comparação com dia se menor vai para esq
                    atual = atual->esq;
                }else{
                    atual= atual->dir;
                }
                // procurando um lugar vazio na arvore para inserir o novo
            }if(operacao == 4){// ordenação por idade
                if(novo->dados->idade <= anterior->dados->idade){//comparação com ano se menor vai para esq
                    atual = atual->esq;
                }else{
                    atual= atual->dir;
                }
                // procurando um lugar vazio na arvore para inserir o novo
            }
        }

        if(anterior == NULL){
            arvore->raiz = novo;

        }else{
            if(operacao == 1){
                if (novo->dados->entrada->ano <= anterior->dados->entrada->ano){ // comparação com ano se menor vai para esq
                    anterior->esq = novo;
                }else{
                    anterior->dir = novo;
                }
            }if(operacao == 2){
                if (novo->dados->entrada->mes <= anterior->dados->entrada->mes){ // comparação com mes se menor vai para esq
                    anterior->esq = novo;
                }else{
                    anterior->dir = novo;
                }
            }if(operacao == 3){// inserção por dia
                if (novo->dados->entrada->dia <= anterior->dados->entrada->dia){ // comparação com dia se menor vai para esq
                    anterior->esq = novo;
                }else{
                    anterior->dir = novo;
                }
            }if(operacao == 4){// inserção por idade
                if (novo->dados->idade <= anterior->dados->idade){ // comparação com idade se menor vai para esq
                    anterior->esq = novo;
                }else{
                    anterior->dir = novo;
                }
            }
        }

        arvore->qtde++;
        eAtual = eAtual->prox;
        atual= arvore->raiz;
        anterior = NULL;
    }
    printf("============== Arvore Construida ==============\n");
    mostrarArvore(arvore->raiz);
    
}



