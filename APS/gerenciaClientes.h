#ifndef GERENCIACLIENTES_H
#define GERENCIACLIENTES_H

#include "cliente.h"

TCliente clientes[10];
int totalClientes = 0;

void adicionarCliente(TCliente clientes);
int existeCPF(TCliente clientes);
char* listarClientes();

#endif // GERENCIACLIENTES_H
