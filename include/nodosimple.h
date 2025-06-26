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

/** inserta un nodo en una posicion especifica */
void insertarEnPos(struct NodeS** cabeza, int numero, int pos);

/** elimina por numero */
void eliminarElemento(struct NodeS** cabeza, int numero);

/** busca un elemento por data.numeros y devuelve true si lo encuentra */
bool buscarElemento(struct NodeS* cabeza, int numero);

/** print la lista hacia adelante */
void imprimirLista(struct NodeS* cabeza);

#endif
