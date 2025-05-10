
#ifndef FUNCOES_H
#define FUNCOESCAD_H

#include "estruturas.h"

void mostrarLista(Lista* lista);
void Cadastrar(Lista* lista);
void tratamento(char *entrada,char *novaEntrada);
void consultarPaciente(Lista* lista);
void atualizar(Lista* lista);
void remover(Lista* lista);
Paciente* encontraPaciente (Lista* lista);

#endif

