#include <stdio.h>
#include <stdlib.h>

#include "gerenciaClientes.h"

void adicionarCliente(TCliente cliente){
    fflush(stdin);
    printf("Nome: ");
    gets(cliente.nome);

    printf("CPF: ");
    gets(cliente.cpf);

    printf("Telefone: ");
    gets(cliente.telefone);
}

int existeCPF(TCliente cliente){
    char cpfProcurado[11];

    fflush(stdin);

    printf("Digite o CPF: ");
    gets(cpfProcurado);

    for(int i = 0; i < totalClientes; i++){
        if(strcmp(clientes[i].cpf, cpfProcurado) == 0){
            printf("\nCPF encontrado: ");
            return 1;
        }
    }

    printf("\nCPF nao encontrado!");

    return 0;
}

char* listarClientes(){
    for(int i = 0; i < totalClientes; i++){
        imprimirCliente(clientes[i]);
    }
}
