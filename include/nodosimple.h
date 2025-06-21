#ifndef NODOSIMPLE_H
#define NODOSIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "datos.h"

struct NodeS {
    struct Datos data;
    struct NodeS *next;
};

struct NodeS* crearNodo(int valor);

/** Con esta funcion inserto un nodo al inicio de la lista */
void insertarInicio(struct NodeS** cabeza, int numero);

/** Con esta funcion agrego un nodo al final */
void insertarFinal(struct NodeS** cabeza, int numero);
