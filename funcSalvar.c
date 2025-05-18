#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

/* digita isso para compilar todo o arquivo 
gcc main.c funcFilaAtend.c funcFilaAtend.h funcCadastrar.c funcCadastrar.h estruturas.h funcFilaPrior.c funcFilaPrior.h funcPesquisa.c funcPesquisa.h funcDesfazer.c funcDesfazer.h funcSalvar.c funcSalvar.h
chato dms ter que digitar isso
*/


#include "funcSalvar.h"

void liberarPilha(tempPilha* pilha){
    tempElista* ant = NULL;
    tempElista* atu = pilha->top;
    while(atu != NULL){
        ant = atu->anterior;
        free(atu);
        atu = ant;
    }
    free(pilha);
}

tempPilha* criaPilhaTemp(Lista* lista){
    tempPilha* pilhaTemp = (tempPilha*) malloc(sizeof(tempPilha));
    pilhaTemp->qtde = 0;
    pilhaTemp->top = NULL;

    Elista* atual = lista->inicio;

    while(atual!=NULL){
        tempElista* elistaTemp = (tempElista*) malloc(sizeof(tempElista)); 
        elistaTemp->anterior = NULL;
        elistaTemp->proximo = NULL;
        elistaTemp->pac = atual;

        if(pilhaTemp->qtde != 0){
            elistaTemp->anterior = pilhaTemp->top;
            pilhaTemp->top->proximo = elistaTemp;
        }
        pilhaTemp->top = elistaTemp;
        atual =atual->prox;
        pilhaTemp->qtde++;
    }
    return pilhaTemp;
}

void salvar(Lista* lista){// 
    FILE* pacientes;

    pacientes = fopen("paciente.txt","w"); // abrindo o arquivo para escrita

    if (!pacientes) {
        perror("erro ao abrir arquivo");
        return;
    }
    tempPilha* pilhaTemp = criaPilhaTemp(lista);
    tempElista* atual = pilhaTemp->top;

    while(atual != NULL){
        fprintf(pacientes, "%s,%d,%s,%02d,%02d,%04d\n",
        atual->pac->dados->nome, atual->pac->dados->idade, atual->pac->dados->rg,
        atual->pac->dados->entrada->dia, atual->pac->dados->entrada->mes, atual->pac->dados->entrada->ano);

        atual = atual->anterior;
    }


    fclose(pacientes);// fechando o arquivo
    liberarPilha(pilhaTemp);
    printf("Pacientes salvos com sucesso!\n");
}