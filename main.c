#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

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
} Paciente;

typedef struct Elista{
    Paciente* dados;
    struct Elista* prox;
}Elista;

typedef struct Lista{
    int qtde;
    Elista* inicio;
    
}Lista;

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

void submenu(int opt, Lista* lista){
    if(opt == 1){ //cadastrar
        int opcao;
        do{
            printf("\nMenu Cadastrar\n");
            printf("1 - Cadastrar \n");
            printf("2 - ");
            scanf("%d", &opcao);
            getchar();  // Limpa o buffer do teclado após o scanf
            
            switch (opcao) {
                case 1:
                    Cadastrar(lista);  
                    break;
                case 2:
                    mostrarLista(lista);  
                    break;
                case 0:
            
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        } while (opcao != 0);

        }

}

int main(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->qtde = 0;

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
                            mostrarLista(lista);  
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

            case 4:
                do{
                    printf("\n======================== Menu Pesquisa ==========================\n");
                    printf("1 - Mostrar registros ordenados por ano de registro\n");
                    printf("2 - Mostrar registros ordenados por mês de registro\n");
                    printf("3 - Mostrar registros ordenados por dia de registro\n");
                    printf("4 - Mostrar registros ordenados por idade do paciente\n ");
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
