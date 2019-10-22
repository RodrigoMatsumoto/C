#include "conta.h"
#define LIMITE 1000

void depositar(TConta conta, float valor){
    conta.saldo = conta.saldo + valor;
}

int debitar(TConta conta, float quantia){
    if(quantia <= (conta.saldo + LIMITE)){
        conta.saldo = conta.saldo - quantia;
        return 1;
    }else{
        return 0;
    }
}

int transferir(TConta origem, TConta destino, float quantia){
    if(debitar(origem, quantia) == 1){
        depositar(destino, quantia);
        return 1;
    } else{
        return 0;
    }
}

void imprimirConta(TConta conta){
    printf("=== Dados da Conta ===\n");
    printf("Numero Conta: %i\n", conta.numero);
    printf("Data Abertura: %i/ %i/ %i\n", conta.dataAbertura.dia, conta.dataAbertura.mes, conta.dataAbertura.ano);
    printf("Saldo: %.2f\n", conta.saldo);
    if(conta.ativa == 1){
        printf("Status: Ativa\n");
    } else{
        printf("Status: Inativa\n");
    }
}
