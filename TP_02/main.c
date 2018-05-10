#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


#define CANT 20

int main()
{
    int opcion;
    ePersona persona[CANT];
    inicioEstados(persona,CANT);

    do{
        system("cls");
        switch(menu())
        {
        case 1:
            {
                system("cls");
                alta(persona,CANT);
                system("pause");
                break;
            }
        case 2:
            {
                system("cls");
                baja(persona,CANT);
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                modificar(persona,CANT);
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                listar(persona,CANT);
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                grafico(persona,CANT);
                system("pause");
                break;
            }
        case 6:
            {
                opcion=6;
                break;
            }
        }
    }while(opcion!=6);
}
