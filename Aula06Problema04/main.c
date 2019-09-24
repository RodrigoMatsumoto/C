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
tPessoa inserirPessoa();
void alterarPessoa();
void apagarPessoa();
void listarPessoa();
void mostrarMenuPesquisa();
void pesquisarIntervaloIdades(tPessoa pessoa[]);
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
                            pesquisarIntervaloIdades(pessoa
);
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
    printf("\n-------------------- MENU --------------------\n");
    printf("|1) Inserir Pessoa                            |\n");
    printf("|2) Alterar Pessoa                            |\n");
    printf("|3) Apagar Pessoa                             |\n");
    printf("|4) Listar Pessoa                             |\n");
    printf("|5) Pesquisas                                 |\n");
    printf("|6) Sair                                      |\n");
    printf("----------------------------------------------\n");
}

tPessoa inserirPessoa()
{
    tPessoa pessoa;

    printf("\n\n----------------------------------- INSERIR PESSOA ------------------------------------\n");

    fflush(stdin);

    printf("Digite o nome: ");
    gets(pessoa.nome);

    printf("Digite a idade: ");
    scanf("%i", &pessoa.idade);

    printf("Digite o salario: ");
    scanf("%f", &pessoa.salario);

    pessoa.indicadorRegistro = 0;

    printf("\n--------------------------------- FIM INSERIR PESSOA ----------------------------------\n\n\n");

    return pessoa;
}

void alterarPessoa(tPessoa pessoa[])
{
    printf("\n\n----------------------------------- ALTERAR PESSOA ------------------------------------\n");

    int idAlterar;

    printf("\nDigite o numero do id da pessoa a ser alterada: ");
    scanf("%i", &idAlterar);

    if(idAlterar < cont){
        fflush(stdin);

        printf("\nDigite o nome: ");
        gets(pessoa[idAlterar].nome);

        printf("Digite a idade: ");
        scanf("%i", &pessoa[idAlterar].idade);

        printf("Digite o salario: ");
        scanf("%f", &pessoa[idAlterar].salario);

        pessoa[idAlterar].indicadorRegistro = 0;
    }else {
        printf("\nO ID %i nao existe! Utilize a opcao 4)Listar para verificar os IDs.", idAlterar);
    }

     printf("\n--------------------------------- FIM ALTERAR PESSOA ----------------------------------\n\n\n");
}

void apagarPessoa(tPessoa pessoa[])
{
    printf("\n\n------------------------------------ APAGAR PESSOA ------------------------------------\n");

    int idApagar;

    printf("\nDigite o numero do id da pessoa a ser apagada: ");
    scanf("%i", &idApagar);
    if(pessoa[idApagar].indicadorRegistro == 1){
        printf("\nID ja apagado! Utilize a opcao 4)Listar para verificar os IDs.");
    } else if(idApagar < cont){
        pessoa[idApagar].indicadorRegistro = 1;
        printf("\nID apagado com sucesso!");
        } else{
            printf("\nO ID %i nao existe! Utilize a opcao 4)Listar para verificar os IDs.", idApagar);
        }


    printf("\n\n---------------------------------- FIM APAGAR PESSOA ----------------------------------\n\n\n");
}

void listarPessoa(tPessoa pessoa[])
{
    printf("\n\n------------------------------------ LISTAR PESSOA ------------------------------------\n");

    printf("\nID:\t\t\tNome:\t\t\tIdade:\t\t\tSalario:\n");
    for(int i = 0; i < cont; i++){
        if(pessoa[i].indicadorRegistro == 0){
             printf("%i\t\t\t%s\t\t\t%i\t\t\t%.2f\n", i, pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
        }
    }
    printf("\n---------------------------------- FIM LISTAR PESSOA ----------------------------------\n\n\n");
}

void mostrarMenuPesquisa()
{
    printf("\n--------------- MENU PESQUISA ----------------\n");
    printf("|1) Pesquisar por intervalo de idades         |\n");
    printf("|2) Pesquisar por nome                        |\n");
    printf("|3) Voltar                                    |\n");
    printf("----------------------------------------------\n");
}

void pesquisarNome(tPessoa pessoa[])
{
    char nome[50];
    int encontrado = 0;

    printf("\n\n----------------------------------- PESQUISAR POR NOME ---------------------------------\n");

    fflush(stdin);
    printf("Digite o nome: ");
    gets(nome);

    for(int i = 0; i < cont; i++){
        if(strcmp(pessoa[i].nome, nome) == 0){
            printf("\nNome encontrado no ID: %i", i);
            encontrado = 1;
            if(pessoa[i].indicadorRegistro == 1){
                printf("\nO ID ja foi apagado!");
            }
        }
    }

    if(encontrado == 0){
        printf("\nNome nao encontrado!");
    }

    printf("\n\n--------------------------------- FIM PESQUISAR POR NOME -------------------------------\n\n\n");
}

void pesquisarIntervaloIdades(tPessoa pessoa[])
{
    int idadeMenor, idadeMaior, encontrado = 0;

    printf("\n\n---------------------------- PESQUISAR POR INTERVALO DE IDADE --------------------------\n");

    printf("Digite a menor idade: ");
    scanf("%i", &idadeMenor);

    printf("Digite a maior idade: ");
    scanf("%i", &idadeMaior);

    if(idadeMenor > idadeMaior){
        int idadeTroca = idadeMaior;
        idadeMaior = idadeMenor;
        idadeMenor = idadeTroca;
    }

    for(int i = 0; i < cont; i++){
        if(pessoa[i].idade >= idadeMenor && pessoa[i].idade <= idadeMaior){
            printf("\nIdade no intervalo encontrada no ID: %i", i);
            printf("\tA idade eh: %i", pessoa[i].idade);
            encontrado =1;
            if(pessoa[i].indicadorRegistro == 1){
                printf("\nO ID ja foi apagado!");
            }
        }
    }

     if(encontrado == 0){
        printf("\nIdade no intervalo nao encontrada!");
    }

    printf("\n\n-------------------------- FIM PESQUISAR POR INTERVALO DE IDADE ------------------------\n");
}
