#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cont = 0;

typedef struct Pessoa
{
    char nome[50];
    int idade;
    float salario;
    int indicadorRegistro;
} tPessoa;

void mostrarMenu();
void mostrarMenuPesquisa();
void selecionarOpcaoMenu();
tPessoa inserirPessoa();
void alterarPessoa();
void apagarPessoa();
void listarPessoa();
void mostrarMenuPesquisa();
void pesquisarNome(tPessoa pessoa[]);

int main()
{
    tPessoa pessoa[100];
    int opcao;
    int opcaoMenuPesquisa;

    do{
        mostrarMenu();

        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);

        switch(opcao){
            case 1:{
                pessoa[cont] = inserirPessoa();
                cont++;
                break;
            }
            case 2:{
                alterarPessoa(pessoa);
                break;
            }
            case 3:{
                 apagarPessoa(pessoa);
                 break;
            }
            case 4:{
                listarPessoa(pessoa);
                break;
            }
            case 5:{

                do{
                    mostrarMenuPesquisa();

                    printf("Digite a opcao desejada: ");
                    scanf("%i", &opcaoMenuPesquisa);

                    switch(opcaoMenuPesquisa){
                        case 1:{

                            break;
                        }
                        case 2:{
                            pesquisarNome(pessoa);
                            break;
                        }
                    }
                } while(opcaoMenuPesquisa != 3);
                break;
            }
        }

     } while(opcao != 6);

    printf("\n\n---------------------------------------------------------------------------------------\n");
    printf("----------------------------------- FIM DO PROGRAMA -----------------------------------\n");
    printf("---------------------------------------------------------------------------------------\n\n");

    return 0;
}

void mostrarMenu()
{
    printf("-------------------- MENU --------------------\n");
    printf("|1) Inserir Pessoa                            |\n");
    printf("|2) Alterar Pessoa                            |\n");
    printf("|3) Apagar Pessoa                             |\n");
    printf("|4) Listar Pessoa                             |\n");
    printf("|5) Pesquisas                                 |\n");
    printf("|6) Sair                                      |\n");
    printf("----------------------------------------------\n");
}

/*void selecionarOpcaoMenu(int opcao)
{
    switch(opcao){
        case 1:
            inserirPessoa();
            break;
        case 2:
            alterarPessoa(pessoa);
            break;
        case 3:
            apagarPessoa(pessoa);
            break;
        case 4:
            listarPessoa(pessoa);
            break;
        case 5:
            mostrarMenuPesquisa();

        }
}*/

tPessoa inserirPessoa()
{
    tPessoa pessoa;

    printf("\n----------------------------------- INSERIR PESSOA ------------------------------------\n");

    fflush(stdin);

    printf("Digite o nome: ");
    gets(pessoa.nome);

    printf("Digite a idade: ");
    scanf("%i", &pessoa.idade);

    printf("Digite o salario: ");
    scanf("%f", &pessoa.salario);

    pessoa.indicadorRegistro = 0;

    printf("\n");

    return pessoa;
}

void alterarPessoa(tPessoa pessoa[])
{
    printf("\n----------------------------------- ALTERAR PESSOA ------------------------------------\n");

    int idAlterar;

    printf("\nDigite o numero do id da pessoa a ser apagada: ");
    scanf("%i", &idAlterar);

    pessoa[idAlterar] = inserirPessoa();

}

void apagarPessoa(tPessoa pessoa[])
{
    printf("------------------------------------ APAGAR PESSOA ------------------------------------\n");
    int idApagar;
    printf("\nDigite o numero do id da pessoa a ser apagada: ");
    scanf("%i", &idApagar);
    pessoa[idApagar].indicadorRegistro = 1;
}

void mostrarPessoa(tPessoa pessoa)
{
    printf("Nome:\t\tIdade:\t\tSalario:\n");
    printf("%s\t\t%i\t\t%.2f\n", pessoa.nome, pessoa.idade, pessoa.salario);
}


void listarPessoa(tPessoa pessoa[])
{
    printf("------------------------------------ LISTAR PESSOA ------------------------------------\n");
    printf("ID:\t\t\tNome:\t\t\tIdade:\t\t\tSalario:\n");
    for(int i = 0; i < cont; i++){
        if(pessoa[i].indicadorRegistro == 0){
             printf("%i\t\t\t%s\t\t\t%i\t\t\t%.2f\n", i, pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
        }
    }

}

void mostrarMenuPesquisa()
{
    printf("--------------- MENU PESQUISA ----------------\n");
    printf("|1) Pesquisar por intervalo de idades         |\n");
    printf("|2) Pesquisar por nome                        |\n");
    printf("|3) Voltar                                    |\n");
    printf("----------------------------------------------\n");
}


void pesquisarNome(tPessoa pessoa[])
{
    char nome[50];
    printf("\nDigite o nome: ");
    gets(nome);

    for(int i = 0; i < cont; i++){
        if(strcmp(pessoa[i].nome, nome) == 0){
            printf("Nome");
            break;
        }
    }
}

