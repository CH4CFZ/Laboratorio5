/**
 *Aqui se definieron el struct principal 
 *la funcion para imprimir 
 *La funcion para crear los datos
 */

#ifndef DATOS_H
#define DATOS_H

#include <stdio.h>

struct Datos {
    int numeros;
};


void printDatos(struct Datos d);
struct Datos crearDatos(int numero);
