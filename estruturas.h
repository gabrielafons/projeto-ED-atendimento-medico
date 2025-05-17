#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#define TAMHEAP  20

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Paciente {
    char nome[100];       
    int idade;             
    char rg[15];           
    Data* entrada;         
} Paciente;

typedef struct Elista{
    Paciente* dados;
    struct Elista* prox;
}Elista;

typedef struct Lista{
    int qtde;
    Elista* inicio;
    
}Lista;

typedef struct Efila{
    Paciente* dados;
    struct Efila* prox;
}Efila;

typedef struct Fila{
    Efila* head;
    Efila* tail;
    int qtde;
}Fila;

typedef struct Heap{
    Paciente* pacientes[TAMHEAP];
    int qtde;
}Heap;

typedef struct EABB{
    Paciente* dados;
    struct EABB* dir;
    struct EABB* esq;
}EABB;

typedef struct ABB{
    EABB* raiz;
    int qtde;
}ABB;

typedef struct Operacao{
    struct Operacao* anterior; 
    struct Operacao* prox;
    Efila* efila; //ponteiro para o eFila que contem os dados da ultima operação realizada
    int tipoOperacao; // 1 para inserção 2 para remoção
}Operacao;

typedef struct Pilha{
    Operacao* topo;
    int qtde;
}Pilha;

#endif