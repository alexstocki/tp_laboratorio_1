#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "menu.h"


int agregarPelicula(eMovie *movie, int indice, int *pIndice)
{
    char auxTitulo[50];
    int i;
    int flag = 0;

    strcpy(auxTitulo,validarCad("\nTitulo: ", "\nERROR. Se excedio limite de caracteres\n",50));

    for(i=0;i<indice;i++){
        if(strcmp(auxTitulo,(movie+i)->titulo)==0 && (movie+i)->duracion!=0){
            printf("\nERROR. Ya se almaceno una pelicula con ese titulo\n\n");
            flag = 1;
        }
    }

    if(flag == 0){
        strcpy((movie+indice)->titulo,auxTitulo);
        strcpy((movie+indice)->genero,validarCad("\nGenero: ","ERROR. Se excedio limite de caracteres\n",31));
        (movie+indice)->duracion = validarNum("\nDuracion (minutos): ","\nERROR. Ingrese una duracion valida: ",1,400);
        strcpy((movie+indice)->descripcion,validarCad("\nDescripcion (0-400 caracteres): ","ERROR. Se excedio limite de caracteres\n",500));
        (movie+indice)->puntaje = validarNum("\nPuntaje (1-10): ","ERROR. Ingrese un puntaje valido\n",1,10);
        strcpy((movie+indice)->linkImg,validarCad("\nLink de imagen: ","\nERROR. Se excedio cantidad de caracteres\n",500));

        *pIndice += 1;
    }
    return 0;
}

int borrarPelicula(eMovie *movie, int indice)
{
    char auxTitulo[50];
    char borrar;
    int i;
    int existe = -1;

    mostrarPelis(movie,indice);

    strcpy(auxTitulo,validarCad("\nIngrese titulo de pelicula a borrar: ","ERROR. Excedio cantidad de caracteres\n",50));

    for(i=0;i<indice;i++){
        if(strcmp(auxTitulo,(movie+i)->titulo)==0 && (movie+i)->duracion != 0){
            existe = i;
            break;
        }
    }

    if(existe != -1){
        mostrarPelicula(movie,existe);

        borrar = validarChar("\nDesea borrar la pelicula? [s|n]: ","ERROR. Ingrese una opcion valida\n");

        if(borrar == 's'){
            printf("\nBAJA EXITOSA\n\n");
            (movie+existe)->duracion = 0;
        }
        else{
            printf("\nBAJA CANCELADA\n\n");
        }
    }
    else{
        printf("\nERROR. No hay ninguna pelicula con ese titulo\n\n");
    }
    return 0;
}

int modificarPelicula(eMovie *movie, int indice)
{
    int i;
    int existe = -1;
    char auxTitulo[50];
    char seguir = 's';

    mostrarPelis(movie,indice);

    strcpy(auxTitulo,validarCad("\nIngrese titulo: ","\nERROR. Excedio numero de caracteres\n",50));

    for(i=0;i<indice;i++){
        if(strcmp((movie+i)->titulo,auxTitulo)==0 && (movie+i)->duracion!=0){
            existe = i;
            break;
        }
    }

    if(existe != -1){
        while(seguir == 's'){

            system("cls");
            mostrarPelicula(movie,existe);

            switch(menuModi())
            {
                case 1:
                    {
                        system("cls");
                        strcpy((movie+existe)->titulo,validarCad("\nNuevo titulo: ","\nERROR. Se excedio limite de caracteres\n",50));
                        system("pause");
                        break;
                    }
                case 2:
                    {
                        system("cls");
                        strcpy((movie+existe)->genero,validarCad("\nNuevo genero: ","\nERROR. Se excedio limite de caracteres\n",31));
                        system("pause");
                        break;
                    }
                case 3:
                    {
                        system("cls");
                        (movie+existe)->duracion = validarNum("\nNueva duracion (minutos): ","\nERROR. Ingrese una duracion valida\n",1,400);
                        system("pause");
                        break;
                    }
                case 4:
                    {
                        system("cls");
                        strcpy((movie+existe)->descripcion,validarCad("\nNueva descripcion: ","\nERROR. Se excedio limite de caracteres\n",500));
                        system("pause");
                        break;
                    }
                case 5:
                    {
                        system("cls");
                        (movie+existe)->puntaje = validarNum("\nNuevo puntaje (1-10): ","\nERROR. Ingrese una duracion valida\n",1,10);
                        system("pause");
                        break;
                    }
                case 6:
                    {
                        system("cls");
                        strcpy((movie+existe)->linkImg,validarCad("\nNuevo link de imagen: ","\nERROR. Se excedio limite de caracteres\n",500));
                        system("pause");
                        break;
                    }
                case 7:
                    {
                        system("cls");
                        seguir = 'n';
                        system("pause");
                        break;
                    }
            }
        }
    }
    else{
        printf("\nERROR. No hay ninguna pelicula con ese titulo\n\n");
    }

    return 0;
}

void generarPagina(eMovie *movie, int indice)
{
    int i;
    FILE *archivo;
    archivo = fopen("index.html","w");

    if(archivo == NULL){
        printf("\nERROR. No se pudo crear archivo\n\n");
    }
    else{
        fprintf(archivo,"<!DOCTYPE html>");
        fprintf(archivo,"<html lang='en'><head> <meta charset='utf-8'> <meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1'>");
        fprintf(archivo,"<title>Lista peliculas</title>");
        fprintf(archivo,"<link href='css/bootstrap.min.css' rel='stylesheet'>");
        fprintf(archivo,"<link href='css/custom.css' rel='stylesheet'>");
        fprintf(archivo,"</head>");
        fprintf(archivo,"<body>");
        fprintf(archivo,"<div class='container'><div class='row'>");
        fprintf(archivo,"<!-- Repetir esto para cada pelicula -->");
            for(i=0;i<indice;i++){
                if((movie+i)->duracion != 0){
                    fprintf(archivo,"<article class='col-md-4 article-intro'><a href='#'>");
                    fprintf(archivo,"<img class='img-responsive img-rounded' src='%s' alt='%s'></a>",(movie+i)->linkImg,(movie+i)->titulo);
                    fprintf(archivo,"<h3><a href='#'>%s</a></h3>",(movie+i)->titulo);
                    fprintf(archivo,"<ul><li>Genero: %s</li><li>Puntaje: %d</li><li>Duracion: %d</li></ul>",(movie+i)->genero,(movie+i)->puntaje,(movie+i)->duracion);
                    fprintf(archivo,"<p>%s</p></article>",(movie+i)->descripcion);
                }
        fprintf(archivo,"</div></div><script src='js/jquery-1.11.3.min.js'></script>");
        fprintf(archivo,"<script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script>");
        fprintf(archivo,"<script src='js/holder.min.js'></script></body></html>");
            }
    }
    fclose(archivo);
}

int cargarArchivo(eMovie *movie, int *pIndice, int *pContador)
{
    int flag = 0;
    FILE *archivo;

    archivo = fopen("infoPeliculas.dat", "rb");
    if(archivo == NULL){
        archivo = fopen("infoPeliculas.dat", "wb");
        if(archivo == NULL){
            return 1;
        }
        flag = 1;
    }

    if(flag == 0){
        fread(pIndice,sizeof(int),1,archivo);
        fread(pContador,sizeof(int),1,archivo);
        while(!feof(archivo)){
            fread(movie,sizeof(eMovie),*pIndice,archivo);
        }
    }
    fclose(archivo);
    return 0;
}

void guardarArchivo(eMovie *movie, int indice, int *pIndice, int *pContador)
{
    char guardar;
    FILE *archivo;

    archivo = fopen("infoPeliculas.dat","wb");
    if(archivo == NULL){
        printf("\nERROR. No se pudo guardar datos\n\n");
    }
    else{
            guardar = validarChar("\nDesea guardar los cambios? [s|n]: ","\nERROR. Ingrese opcion valida\n");
            if(guardar == 's'){
                fwrite(pIndice,sizeof(int),1,archivo);
                fwrite(pContador,sizeof(int),1,archivo);
                fwrite(movie,sizeof(eMovie),indice,archivo);
                printf("\nARCHIVO GUARDADO\n\n");
            }
            else{
                printf("\nNO SE GUARDARON LOS CAMBIOS\n\n");
            }
    }

    fclose(archivo);
}

int validarNum(char msg[], char msgError[], int min, int max)
{
    int num;

    printf("\n%s",msg);
    fflush(stdin);
    scanf("%d",&num);
    while(num<min || num>max){
        printf("\n%s",msgError);
        fflush(stdin);
        scanf("%d",&num);
    }
    return num;
}

char *validarCad(char msg[], char msgError[], int lon)
{
    char *cad;
    char *auxCad;
    int largo;
    int lon2;
    lon2 = lon + lon;

    cad = (char*)malloc(sizeof(char)*lon2);

    if(cad == NULL){
        printf("\nERROR. No hay mas espacio disponible\n\n");
    }
    else{

         do{
              printf("%s",msg);
              fflush(stdin);
              //gets(cad);
              scanf("%[^\n]",cad);
              largo = strlen(cad);
              if(largo >= lon){
                printf("%s",msgError);
                //auxCad = (char*)realloc(cad,sizeof(char)*lon);
              }
              else{
                auxCad = (char*)realloc(cad,sizeof(char)*lon);
                if(auxCad != NULL){
                    cad = auxCad;
                }
              }

         }while(largo >= lon);
        /*printf("%s",msg);
        fflush(stdin);
        scanf("%[^\n]",cad);
        largo = strlen(cad);

        while(largo>=lon){
            printf("\n%s",msgError);
            cad = NULL;
            cad = (char*)malloc(sizeof(char)*lon);

            if(cad == NULL){
                printf("\nERROR. No hay mas espacio disponible\n\n");
            }
            else{
                printf("\n%s",msg);
                fflush(stdin);
                scanf("%[^\n]",cad);
                largo = strlen(cad);
            }
        }*/
    }
    return cad;
}

char validarChar(char msg[], char msgError[])
{
    char opcion;

    printf("\n%s",msg);
    fflush(stdin);
    scanf("%c",&opcion);
    opcion = tolower(opcion);
    while(opcion != 's' && opcion != 'n'){
        printf("\n%s",msgError);
        fflush(stdin);
        scanf("%c",&opcion);
        opcion = tolower(opcion);
    }
    return opcion;
}

void mostrarPelicula(eMovie *movie, int indice)
{
    printf("\n%s\n%s\n\n",(movie+indice)->titulo,(movie+indice)->descripcion);
}

void mostrarPelis(eMovie *movie, int indice)
{
    int i;
    int flag = 0;

    for(i=0;i<indice;i++){
        if((movie+i)->duracion != 0){
            printf("\n%s\n",(movie+i)->titulo);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("\nNO HAY PELICULAS PARA LISTAR\n\n");
    }
}
