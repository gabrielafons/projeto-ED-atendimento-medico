#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

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

#endif