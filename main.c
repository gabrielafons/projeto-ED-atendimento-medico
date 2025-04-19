#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Paciente {
    char nome[100];       
    int idade;             
    char rg[15];           
    Data entrada;         
    struct Paciente* proximo;  // Ponteiro para o próximo paciente (para lista encadeada)
} Paciente;

void Cadastrar(Paciente **lista){
    Paciente *novoPaciente = (Paciente*) malloc(sizeof(Paciente));  

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

    // Recebe a data de entrada do paciente
    printf("Data de Entrada (DD MM AAAA): ");
    scanf("%d %d %d", &novoPaciente->entrada.dia, &novoPaciente->entrada.mes, &novoPaciente->entrada.ano);
    getchar(); // Limpa o buffer para evitar problemas nas próximas leituras

    // Insere o novo paciente no início da lista
    novoPaciente->proximo = *lista;
    *lista = novoPaciente;  // Atualiza o início da lista

    printf("Cadastro feito! \n");
}

void mostrarLista(Paciente* lista) {
    Paciente* atual = lista;
    if (atual == NULL) {
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, RG: %s, Data de Entrada: %02d/%02d/%d\n",
               atual->nome, atual->idade, atual->rg,
               atual->entrada.dia, atual->entrada.mes, atual->entrada.ano);
        atual = atual->proximo;
    }
}

int main(){
    Paciente* lista = NULL; 
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar novo paciente\n");
        printf("2 - Mostrar lista completa de pacientes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer do teclado após o scanf
        
        switch (opcao) {
            case 1:
                Cadastrar(&lista);  
                break;
            case 2:
                mostrarLista(lista);  
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
