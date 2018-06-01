#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "menu.h"

int menuPrin()
{
    int opcion;
    printf("1) Agregar pelicula\n");
    printf("2) Borrar pelicula\n");
    printf("3) Modificar pelicula\n");
    printf("4) Generar pagina web\n");
    printf("5) Salir\n");

    opcion = validarNum("Opcion: ","ERROR. Ingrese una opcion valida\nOpcion: ",1,5);

    return opcion;
}

int menuModi()
{
    int opcion;
    printf("-----MENU MODIFICAR-----\n\n");
    printf("1) Modificar titulo\n");
    printf("2) Modificar genero\n");
    printf("3) Modificar duracion\n");
    printf("4) Modificar descripcion\n");
    printf("5) Modificar puntaje\n");
    printf("6) Modificar link de imagen\n");
    printf("7) Salir\n");

    opcion = validarNum("Opcion: ", "ERROR. Ingrese opcion valida\nOpcion: ",1,7);

    return opcion;
}
