#include "nodosimple.h"

/*ESta es la funcion generica para crear los nodos
 *Recibe como parametro un valor entero que se le asigna al elemento creado
 *
 */
struct NodeS* crearNodo(int valor) {

        struct NodeS* newNodo = (struct NodeS*)malloc(sizeof(struct NodeS*));
        /*Verificar si se guardó la memoria */
        if (newNodo == NULL) {

                printf("Error al asignar memoria");
                exit(1);
        }
        newNodo->data.numeros = valor;
        newNodo->next = NULL;
        return newNodo;
}

/** Con esta funcion inserto un nodo al inicio de la lista
 * Recibe como argumentos un puntero doble al struct inicial para definir la cabeza
 * Recibe el argumento numero para usar la funcion de crear nodo correctamente
 */
void insertarInicio(struct NodeS** cabeza, int numero) {

        struct NodeS* newNodo = crearNodo(numero);
        newNodo->next = *cabeza;
        *cabeza = newNodo;
}

