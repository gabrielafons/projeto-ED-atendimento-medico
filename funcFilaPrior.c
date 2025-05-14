#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

/* digita isso para compilar todo o arquivo 
gcc main.c funcFilaAtend.c funcFilaAtend.h funcCadastrar.c funcCadastrar.h estruturas.h funcFilaPrior.c funcFilaPrior.h
chato dms ter que digitar isso
*/
#include "funcFilaPrior.h"
#include "funcCadastrar.h"
// implementar

int filho_esq(int pai) { 
    return 2 * pai + 1;
    }

int filho_dir(int pai) { 
    return 2 * pai + 2;
    }

int pai(int filho) { 
    return (filho - 1)/2;
    }

int ultimo_pai(Heap *h) { 
    return (h->qtde / 2) - 1;
}

void peneirar(Heap *h, int pai) {
  int maior = pai;
  int direito = filho_dir(pai);
  int esquerdo = filho_esq(pai);

  if(esquerdo < h->qtde && h->pacientes[esquerdo]->idade > h->pacientes[maior]->idade){
    maior = esquerdo;
  }
  if(direito < h->qtde && h->pacientes[direito]->idade > h->pacientes[maior]->idade){
    maior = direito;
  }

  if(pai != maior){
    Paciente* temp = h->pacientes[pai];
    h->pacientes[pai] = h->pacientes[maior];
    h->pacientes[maior] = temp;
    peneirar(h, maior);
  }
}

void construir(Heap *h) {
  for(int i = ultimo_pai(h); i >= 0; i--){
    peneirar(h, i);
  }
}

void enfileirarPrio(Lista* lista, Heap* heap){
    if(heap->qtde >= TAMHEAP){
        printf("Fila Cheia, impossivel inserir");
        return;
    }
    Paciente* paciente = encontraPaciente(lista); // ponteiro para o paciente na lista

    
    // Insere no final
    heap->pacientes[heap->qtde] = paciente;
    heap->qtde++;
    construir(heap);

}

void desinfileirarPrio(Heap* heap) {
    if (heap->qtde == 0) {
        printf("Fila vazia, impossível remover.\n");
        return;
    }

    Paciente* removido = heap->pacientes[0];

    printf("Paciente removido: %s (Idade: %d, RG: %s)\n",
           removido->nome, removido->idade, removido->rg);

    // Substitui a raiz pelo último elemento e reorganiza a heap
    heap->pacientes[0] = heap->pacientes[heap->qtde - 1];
    heap->qtde--;

    peneirar(heap, 0);
}

void mostrarFilaPrioridade(Heap* heap){
    if (heap->qtde == 0) {
        printf("A fila de prioridade está vazia.\n");
        return;
    }

    printf("=== Pacientes na fila ===\n");
    for (int i = 0; i < heap->qtde; i++) {
        Paciente* paciente = heap->pacientes[i];
        printf("Posição %d:\n", i);
        printf("  Nome: %s\n", paciente->nome);
        printf("  Idade: %d\n", paciente->idade);
        printf("  RG: %s\n\n", paciente->rg);  
        }
}

