#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <ctype.h> 

#include "funcSalvar.h"


void salvar(Lista*  lista){
    FILE* arquivo;

    arquivo = fopen("paciente.txt","w");

    if (!arquivo) {
    perror("Erro ao abrir arquivo");
    return;
}

}