#include <stdio.h>
#include <stdlib.h>


void mostarMenu();

int main(){
    int opcaoMenu;

    do{
        mostrarMenu();
        scanf("%i", &opcaoMenu);
        printf("\n");

        switch(opcaoMenu){
            case 1:
                break;
            case 2:
                break;
            case 3:
                 break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                printf("Fim do Programa.\n\n");
                break;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }
     } while(opcaoMenu != 9);
    return 0;
}

void mostrarMenu(){
    printf("=== Menu Do Banco ===\n");
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Cadastrar Conta\n");
    printf("3 - Listar Conta\n");
    printf("4 - Pesquisar Conta\n");
    printf("5 - Depositar\n");
    printf("6 - Debitar (Sacar)\n");
    printf("7 - Transferir\n");
    printf("8 - Remover Conta\n");
    printf("9 - Sair\n");
    printf("Escolha uma opcao: ");
}
