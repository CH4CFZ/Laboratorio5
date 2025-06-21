#include <stdio.h>


int main () {


	struct NodeS* head = NULL;
        struct NodeS* nodo1 = crearNodo(crearDatos(5).numeros);
        insertarInicio(&head,nodo1->data.numeros); 

        struct NodeS* nodo2 = crearNodo(crearDatos(10).numeros);
        insertarFinal(&head,nodo2->data.numeros);
   

        struct NodeS* nodo3 = crearNodo(crearDatos(15).numeros);
        insertarEnPos(&head,nodo3->data.numeros,2);

        struct NodeS* nodo4 = crearNodo(crearDatos(10).numeros);
        eliminarElemento(&head,nodo4->data.numeros);
  

    return 0;






}
