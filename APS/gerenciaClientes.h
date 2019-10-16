#include "cliente.h"

TCliente clientes[10];
int totalClientes = 0;

void adicionarCliente(TCliente cliente);
int existeCPF(TCliente cliente);
char *listarClientes();
