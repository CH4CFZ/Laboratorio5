#include "datos.h"

struct Datos crearDatos(int numero) {
    struct Datos d;
    d.numeros = numero;
    return d;
}


void printDatos(struct Datos d) {
    printf("%d", d.numeros);
}
