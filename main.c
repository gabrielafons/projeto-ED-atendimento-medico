#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

#include "funcCadastrar.h"
#include "funcFilaAtend.h"
#include "funcFilaPrior.h"
#include "funcPesquisa.h"
#include "funcDesfazer.h"

int main(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->qtde = 0;

    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail=NULL;
    fila->qtde =0;

    Heap* heap = (Heap*) malloc(sizeof(Heap));
    heap->qtde = 0;

    ABB* arvore = (ABB*) malloc(sizeof(ABB));
    arvore->raiz = NULL;
    arvore->qtde = 0;

    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    pilha->qtde =0;
  

    int opcao;
    int opcao2;
    do{
        printf("\n======================== Menu ==========================\n");
        printf("1 - Cadastrar \n");
        printf("2 - Atendimento\n");
        printf("3 - Atendimento Prioritário \n");
        printf("4 - Pesquisa \n");
        printf("5 - Desfazer\n");
        printf("6 - Carregar/salvar \n");
        printf("7 - Sobre \n");
        printf("0 - Sair\n");
        printf("========================================================\n");
        printf("Escolha uma opcao: \n ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer do teclado após o scanf
        
        switch (opcao) {
            case 1:
                do{
                    printf("\n======================== Menu Cadastrar ==========================\n");
                    printf("1 - Cadastrar novo paciente \n");
                    printf("2 - Consultar paciente cadastrado\n");
                    printf("3 - Mostrar lista completa\n");
                    printf("4 - Atualizar dados de paciente\n");
                    printf("5 - Remover paciente\n");
                    printf("0 - Voltar\n");
                    printf("===================================================================\n");
                    printf("Escolha uma opcao: \n ");
                    scanf("%d", &opcao2);
                    getchar();  // Limpa o buffer do teclado após o scanf
                    
                    switch (opcao2) {
                        case 1:
                            Cadastrar(lista);  
                            break;
                        case 2:
                            consultarPaciente(lista);  
                            break;
                        case 3:
                            mostrarLista(lista);  
                            break;
                        case 4: 
                            atualizar(lista);
                            break;
                        case 5:
                            remover(lista);
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while (opcao2 != 0);
                        break;

            case 2:
               do{
                    printf("\n======================== Menu Atendimento ==========================\n");
                    printf("1 - Enfileirar paciente\n");
                    printf("2 - Desenfileirar paciente\n");
                    printf("3 - Mostrar fila\n");
                    printf("0 - Voltar\n");
                    printf("===================================================================\n");
                    printf("Escolha uma opcao: \n ");
                    scanf("%d", &opcao2);
                    getchar();  // Limpa o buffer do teclado após o scanf
                    
                    switch (opcao2) {
                        case 1:
                            enfileirar(lista,fila,pilha);
                            break;
                        case 2:
                            desinfileirar(fila,pilha);
                            break;
                        case 3:
                            mostra(fila);
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while (opcao2 != 0);
                    break;

            case 3:
                do{
                    printf("\n======================== Menu Atendimento Prioritario ==========================\n");
                    printf("1 - Enfileirar paciente\n");
                    printf("2 - Desenfileirar paciente\n");
                    printf("3 - Mostrar fila\n");
                    printf("0 - Voltar\n");
                    printf("=========================================================================\n");
                    printf("Escolha uma opcao: \n ");
                    scanf("%d", &opcao2);
                    getchar();  // Limpa o buffer do teclado após o scanf
                    
                    switch (opcao2) {
                        case 1:
                            enfileirarPrio(lista,heap);
                            break;
                        case 2:
                            desinfileirarPrio(heap);
                            break;
                        case 3:
                            mostrarFilaPrioridade(heap);
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while (opcao2 != 0);
                    break;

            case 4:
                do{
                    printf("\n======================== Menu Pesquisa ==========================\n");
                    printf("1 - Mostrar registros ordenados por ano de registro\n");
                    printf("2 - Mostrar registros ordenados por mês de registro\n");
                    printf("3 - Mostrar registros ordenados por dia de registro\n");
                    printf("4 - Mostrar registros ordenados por idade do paciente\n");
                    printf("0 - Voltar\n");
                    printf("===================================================================\n");
                    printf("Escolha uma opcao: \n ");
                    scanf("%d", &opcao2);
                    getchar();  // Limpa o buffer do teclado após o scanf
                    
                    switch (opcao2) {
                        case 1:// 1 ordenação por ano
                            contruirArvore(lista,arvore,opcao2); 
                            break;
                        case 2:// 2 ordenação por mes
                            contruirArvore(lista,arvore,opcao2); 
                            break;
                        case 3: // 3 ordenação por dia
                            contruirArvore(lista,arvore,opcao2); 
                            break;
                        case 4://ordenação por idade
                            contruirArvore(lista,arvore,opcao2);
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while (opcao2 != 0);
                    break;
        
            case 5:
                do{
                    printf("\n======================== Menu Desfazer ==========================\n");
                    printf("1 - Mostrar as operações realizadas sobre a fila de atendimento\n");
                    printf("2 - Desfazer a última operação realizada para a montagem da fila de atendimento\n");
                    printf("0 - Voltar\n");
                    printf("===================================================================\n");
                    printf("Escolha uma opcao: \n ");
                    scanf("%d", &opcao2);
                    getchar();  // Limpa o buffer do teclado após o scanf
                    
                    switch (opcao2) {
                        case 1:
                            mostrarPilha(pilha);
                            break;
                        case 2:
                             desfazerOperacao(pilha,fila);
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while (opcao2 != 0);
                    break;
        
            case 6:
                do{
                    printf("\n======================== Menu Salvar/Carregar ==========================\n");
                    printf("1 - Ler um arquivo e Carregar na lista\n");
                    printf("2 - Salvar um arquivo\n");
                    printf("0 - Voltar\n");
                    printf("===================================================================\n");
                    printf("Escolha uma opcao: \n ");
                    scanf("%d", &opcao2);
                    getchar();  // Limpa o buffer do teclado após o scanf
                    
                    switch (opcao2) {
                        case 1:
                            printf("Em Construção");
                            break;
                        case 2:
                            printf("Em Construção");
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while (opcao2 != 0);
                    break;

            case 7:
                do{
                    printf("\n======================== Sobre ==========================\n");
                    printf("===================================================================\n");
                    printf("Deseja sair (0 = sim / 1 = nao) \n ");
                    scanf("%d", &opcao2);
                    getchar();  // Limpa o buffer do teclado após o scanf
                    
                    switch (opcao2) {
                        case 1:
                            break;
                        case 0:
                            printf("Voltando...\n");
                            break;
                        default:
                            printf("Opcao invalida!\n");
                    }
                } while (opcao2 != 0);
                    break;

            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
