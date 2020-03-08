#include <stdio.h>
#include <stdlib.h> //sugerencia del compilador

struct _agenda {

    char nombre[20];
    char telefono[12];
    struct _agenda *siguiente;

};

struct _agenda *primero, *ultimo;

void mostrar_menu() {

    printf("\n\nMenú:\n=====\n\n");
    printf("1.- Añadir elementos\n");
    printf("2.- Borrar elementos\n");
    printf("3.- Mostrar lista\n");
    printf("4.- Salir\n\n");
    printf("Escoge una opción: ");

    fflush(stdout);
}

/* Con esta función añadimos un elemento al final de la lista */
void anadir_elemento() {

    struct _agenda *nuevo;

    /* reservamos memoria para el nuevo elemento */
    nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));

    if (nuevo==NULL){
        printf( "No hay memoria disponible!\n");
        return; // se le agrega return a la validacion porque sino se cae el programa en caso de no haber memoria
    }

    printf("\nNuevo elemento:\n");
    printf("Nombre: ");
    fflush(stdout);
    fgets(nuevo->nombre, 20, stdin); // cambio de gets() a fgets() por sugerencia del compilador
    for (int i = 0; i < 20; i++){
        if (nuevo->nombre[i] == '\n'){
            nuevo->nombre[i] = '\000';
        }
    }; // El for elimina el caracter \n basura que queda en el array luego de que se presiona enter en la consola

    printf("Teléfono: ");
    fflush(stdout);
    fgets(nuevo->telefono, 12, stdin); // cambio de gets() a fgets() por sugerencia del compilador
    for (int i = 0; i < 12; i++){
        if (nuevo->nombre[i] == '\n'){
            nuevo->nombre[i] = '\000';
        }
    }; // El for elimina el caracter \n basura que queda en el array luego de que se presiona enter en la consola


    /* el campo siguiente va a ser NULL por ser el último
    elemento de la lista */
    nuevo->siguiente = NULL;

    /* ahora metemos el nuevo elemento en la lista. lo situamos
    al final de la lista, se comprueba si la lista está vacía.
    si primero==NULL es que no hay ningún elemento en la lista.
    también vale ultimo==NULL */
    if (primero==NULL) {

    printf( "Primer elemento\n");
    primero = nuevo;
    ultimo = nuevo;

    }
    else {

    /* el hasta ahora último apuntará al nuevo */
    ultimo->siguiente = nuevo;

    /* hacemos que el nuevo sea ahora el último */
    ultimo = nuevo;

    }

}

void mostrar_lista() {

    struct _agenda *auxiliar; /* para recorrer la lista */

    int i; i=0;
    auxiliar = primero;

    printf("\nMostrando la lista completa:\n");

    while (auxiliar!=NULL) {

        printf( "Nombre: %s, Telefono: %s\n",
        auxiliar->nombre,auxiliar->telefono);

        auxiliar = auxiliar->siguiente;

        i++;

    }

    if (i==0){
        printf( "\nLa lista está vacía!!\n" );
    }

}

int main() {

    char opcion;

    primero = (struct _agenda *) NULL;
    ultimo = (struct _agenda *) NULL;

    do {

        mostrar_menu();
        scanf("%c", &opcion);// cambio de getch() a scanf() para poder limpiar el buffer de entrada y eliminar el \n
        while ((getchar()) != '\n');// elimina el \n en el buffer de entrada

        switch ( opcion ) {

            case '1': anadir_elemento(); break;

            case '2': printf("No disponible todavía!\n"); break;

            case '3': mostrar_lista(primero); break;

            case '4': exit( 1 );

            default:

            printf( "Opción no válida\n" );

            break;

        }

    } while (opcion!='4');

    return 0;
}