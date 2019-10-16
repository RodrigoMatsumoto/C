#include "cont.h"

TConta contas[10];
int numeroConta = 0;

void adicionarConta(TConta conta);
char *listarContas();
char *pesquisarConta(int numero);
Tconta getConta(int numero);
int removerConta(int numero);

