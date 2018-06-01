#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "menu.h"


int main()
{
    char seguir='s';
    int index = 0;
    int cantidad = 10;
    int *pCantidad = &cantidad;
    int *pIndex = &index;
    eMovie *pelicula;
    eMovie *auxPelicula;


    auxPelicula = (eMovie*)malloc(sizeof(eMovie)*cantidad);
    if(auxPelicula == NULL){
        printf("\nERROR. No hay espacio disponible\n\n");
    }
    else
    {
        pelicula = auxPelicula;

        if(cargarArchivo(pelicula,pIndex,pCantidad)){
        printf("\nNo se pudo abrir la base de datos\n\n");
        }
        else{
            while(seguir=='s')
            {
                system("cls");
                switch(menuPrin())
                {
                    case 1:
                        {
                            system("cls");
                            if(index >= cantidad){
                                cantidad += 10;
                                auxPelicula = (eMovie*)realloc(pelicula,sizeof(eMovie)*cantidad);
                                if(auxPelicula == NULL){
                                    printf("\nERROR. No hay mas memoria disponible\n\n");
                                    break;
                                }
                                else{
                                pelicula = auxPelicula;
                                agregarPelicula(pelicula,index,pIndex);
                                }
                            }
                            else{
                                agregarPelicula(pelicula,index,pIndex);
                            }
                            system("pause");
                            break;
                        }
                    case 2:
                        {
                            system("cls");
                            borrarPelicula(pelicula,index);
                            system("pause");
                            break;
                        }
                    case 3:
                        {
                            system("cls");
                            modificarPelicula(pelicula,index);
                            system("pause");
                            break;
                        }
                    case 4:
                        {
                            system("cls");
                            generarPagina(pelicula,index);
                            system("pause");
                            break;
                        }
                    case 5:
                        {
                            system("cls");
                            guardarArchivo(pelicula,index,pIndex,pCantidad);
                            seguir = 'n';
                            system("pause");
                            break;
                        }
                }
            }
        }
    }
    return 0;
}
