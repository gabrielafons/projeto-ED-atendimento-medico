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

void enfileirar(Lista* lista,Fila* fila){
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
   fila->tail = efila;
   fila->qtde++;
}

