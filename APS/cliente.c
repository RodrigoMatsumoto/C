#include "cliente.h"

void imprimirCliente(TCliente cliente){
    printf("=== Dados do Cliente ===\n");
    printf("Nome: %s\n", cliente.nome);
    printf("CPF: %s\n", cliente.cpf);
    printf("Telefone: %s\n", cliente.telefone);
}
