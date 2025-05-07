#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

#include "funcCadastrar.h"

Paciente encontraPaciente (Lista* lista) {
    char rg[15];
    while(1) {
        printf("===================================================================\n");
        printf("Digite o Rg do paciente: \n");
        printf("===================================================================\n");

        fgets(rg, sizeof(rg), stdin);
        rg[strcspn(rg, "\n")] = '\0';  // Remove o '\n' extra que fgets pode deixar
        if (strlen(rg) == 0) {
            printf("RG não pode ser vazio. Tente novamente.\n");
            continue;
        }
        break;
    }
    Elista* atual = lista->inicio;
    Paciente* paciente = NULL;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0) {
            paciente = atual->dados;
            return *paciente;
        }
        atual = atual->prox;
    }
    printf("Paciente com RG %s não encontrado.\n", rg);

    return *paciente;
}

void consultarPaciente(Lista* lista) {
    char rg[15];
    while(1) {
        printf("================================ Consulta de Paciente ===================================\n");
        printf("Digite o Rg do paciente: \n");
        printf("===================================================================\n");

        fgets(rg, sizeof(rg), stdin);
        rg[strcspn(rg, "\n")] = '\0';  // Remove o '\n' extra que fgets pode deixar
        if (strlen(rg) == 0) {
            printf("RG não pode ser vazio. Tente novamente.\n");
            continue;
        }
        break;
    }

    Elista* atual = lista->inicio;
    Paciente* paciente;
    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg) == 0) {
            printf("Nome: %s, Idade: %d, RG: %s, Data de Entrada: %02d/%02d/%d\n",
                   atual->dados->nome, atual->dados->idade, atual->dados->rg,
                   atual->dados->entrada.dia, atual->dados->entrada.mes, atual->dados->entrada.ano);
            return;
        }
        atual = atual->prox;
    }
    printf("Paciente com RG %s não encontrado.\n", rg);
}
void tratamento(char *entrada,char *novaEntrada){
    int i = 0;
    int j = 0;
    int count = 0;
    while(entrada[i]!='\0'){
        if(isdigit(entrada[i])){
            novaEntrada[j] = entrada[i];
            j++;
            count++;
            if(count == 2 || count == 4 ){
                novaEntrada[j] = ' '; 
                j++;
            }
        }
        i++;            
    }
    novaEntrada[j] ='\0';
}

void Cadastrar(Lista *lista){
    Paciente *novoPaciente = (Paciente*) malloc(sizeof(Paciente)); 
    Elista* elista = (Elista*) malloc(sizeof(Elista));
    elista->dados = novoPaciente;     
    elista->prox = lista->inicio;
    lista->inicio = elista;
    lista->qtde++;


    // Recebe o nome do paciente
    printf("Nome: ");
    fgets(novoPaciente->nome, sizeof(novoPaciente->nome), stdin);  // Usa fgets para garantir que o nome completo seja lido
    novoPaciente->nome[strcspn(novoPaciente->nome, "\n")] = '\0';  // Remove o '\n' extra que fgets pode deixar

    // Recebe a idade do paciente
    printf("Idade: ");
    scanf("%d", &novoPaciente->idade);
    getchar();  // Limpa o buffer para evitar problemas com fgets em seguida

    
    printf("RG: ");
    fgets(novoPaciente->rg, sizeof(novoPaciente->rg), stdin);  // Usa fgets para RG
    novoPaciente->rg[strcspn(novoPaciente->rg, "\n")] = '\0';  // Remove o '\n' extra

    char newData[11];
    char data[11] ;
    // Recebe a data de entrada do paciente
    printf("Data de Entrada (dia.mes.ano): ");
    fgets(data, sizeof(data),stdin);
    
    tratamento(data,newData);
    // scanf("%d %d %d", &novoPaciente->entrada.dia, &novoPaciente->entrada.mes, &novoPaciente->entrada.ano);
    sscanf(newData,"%d %d %d", &novoPaciente->entrada.dia, &novoPaciente->entrada.mes, &novoPaciente->entrada.ano);

    // printf("------DEBUG ---- retirar depois\n\n");
    // printf("dia: %d\n",novoPaciente->entrada.dia );
    // printf("mes: %d\n",novoPaciente->entrada.mes );
    // printf("ano: %d\n",novoPaciente->entrada.ano );
    // printf("------DEBUG ---- retirar depois\n\n");

    getchar(); // Limpa o buffer para evitar problemas nas próximas leituras
    printf("Cadastro feito! \n");
}

void mostrarLista(Lista* lista) {
    Elista* atual = lista->inicio;
    if (atual == NULL) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, RG: %s, Data de Entrada: %02d/%02d/%d\n",
               atual->dados->nome, atual->dados->idade, atual->dados->rg,
               atual->dados->entrada.dia, atual->dados->entrada.mes, atual->dados->entrada.ano);
        atual = atual->prox;
    }
}
