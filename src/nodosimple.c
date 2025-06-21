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


/**
 * Con esta funcion agrego un nodo al final
 * Recibe los mismos parametros que la anterior pero esta vez para definir el final
 *
 */
void insertarFinal(struct NodeS** cabeza, int numero) {

        struct NodeS* newNodo = crearNodo(numero);
        if (*cabeza == NULL) {  /*Si la lista esta vacia se crea ahi ya que no hay otro nodo mas */

                *cabeza = newNodo;
                return;
        }
        struct NodeS* actual = *cabeza;
        while (actual->next != NULL) { /*Se define un nodo actual para recorrer hasta llegar al final y poder insertar ahi*/
                actual  = actual->next;
        }
        actual->next = newNodo;
}

/** Esta es la funcion encargada de insertar un nodo en una posicion ingresada a la funcion
 * Recibe como parametros un puntero doble al nodo cabeza(primero de la lista) y el numero con su posicion de donde agregar
 *
 *--Inicialmente si la lista esta vacia se agrega este nodo a la cabeza que seria el primero ahora (en el if se hace esto)
 *--Si la lista no esta vacia (ciclo while) se recorre de tal manera que se coloque el numero ingresado en la posicion deseada
 * tambien valida que el actual tenga un next y que no se salga de la lista enlazada con el idx
 */
void insertarEnPos(struct NodeS** cabeza, int numero, int pos) {

        struct NodeS* newNodo = crearNodo(numero);
        if (pos <= 1 || *cabeza == NULL) {

                newNodo->next = *cabeza;
                *cabeza = newNodo;
                return;
        }

        struct NodeS* actual = *cabeza;
        int idx = 1; /*Con esta variable se itera en el ciclo while para ver que se cumpla lo requerido*/
        while (actual->next != NULL && idx < pos - 1) {
                actual = actual->next;
                idx++;
        }
        newNodo->next = actual->next;
        actual->next = newNodo;
}


/**
 *Esta es la funcion encargada de eliminar elementos segun su data
 *Recibe como parametro puntero doble al primer elemento, y el numero del elemento que se quiere eliminar
 *
 */
void eliminarElemento(struct NodeS** cabeza, int numero) {

	if (*cabeza == NULL) { /*Si la lista esta vacia se para el programa*/
	    return;
        }

        struct NodeS* actual = *cabeza;
        struct NodeS* prev = NULL;

        while (actual != NULL) {  /*Recorre hasta llegar al final de la lista*/

        	if (actual->data.numeros == numero) { /*Verifica si se el nodo se encuentra en el que se busca*/
                       if (prev == NULL) { /*Si el actual es el primero actualiza para que el primero sea el siguiente de la actual*/
                          *cabeza = actual->next;
                       } else {
                               prev->next = actual->next; /*Con esto se elimina el nodo que se buscaba*/
                         }

                       free(actual); /*LIbera el espacio del nodo eliminado */
                       return;
                }
                prev = actual;
                actual = actual->next;
        }
}

/**
 * Esta funcion es la encargada de buscar el elemento segun su data
 * Busca un elemento por el data que tiene y retorna true si lo encuentra
 *Recorre desde la cabeza(inicio) hasta encontrar el numero del elemento buscado
 * */

bool buscarElemento(struct NodeS* cabeza, int numero) {

        struct NodeS* actual = cabeza;

        while (actual != NULL) {

                if (actual->data.numeros == numero) {

                        return true;
                }
        actual = actual->next;
        }
        return false;
}

/** Esta es la funcion encargada de imprimir los elementos de la lista
 *Recorre desde la cabeza de la lista hasta llegar a NULL
 *
 * */
void imprimirLista(struct NodeS* cabeza) {

	struct NodeS* actual = cabeza;

        printf("Lista: ");
        while (actual != NULL) {

                printDatos(actual->data); /*Esta funcion para imprimir viene desde los header files*/
                if (actual->next != NULL) { /*Agrega flechas entre los datos impresos*/
			printf(" -> ");
	        }
                actual = actual->next;

	}

        printf("\n");
}
