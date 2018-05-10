#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int stringNum(char codigo[])
{
    int i,len,flag=0;

    len=strlen(codigo);

    for(i=0;i<len;i++)
    {
        if(!isdigit(codigo[i]))
        {
            flag=1;
            break;
        }
    }
    return flag;
}

int esNum(char numeroChar[],int min,int max)
{
    int i,aux=0;
    int len;

    len=strlen(numeroChar);

    for(i=0;i<len;i++)
    {
        if(!isdigit(numeroChar[i]))
        {
            aux=-1;
            break;
        }
    }
    if(aux==0)
    {
        aux=atoi(numeroChar);
        if(aux<min || aux>max)
        {
            aux=-1;
        }
    }

    return aux;
}

int isCha(char codigo[])
{
    int flag,longitud,i;

    flag=0;
    longitud=strlen(codigo);

    if(longitud>50)
    {
        flag=1;
    }
    else
    {
        for(i=0;i<longitud;i++)
        {
            if(i==0 && !isalpha(codigo[i]))
            {
                flag=1;
                break;
            }
            if((codigo[i]!=' ') && (codigo[i] < 'a' || codigo[i] > 'z') && (codigo[i] < 'A' || codigo[i] >'Z'))
            {
                flag=1;
                break;
            }
        }
    }
    return flag;
}

int menu()
{
    int opcion;

    printf("-----MENU PRINCIPAL-----\n\n");
    printf("\n1) Agregar persona\n");
    printf("\n2) Borrar persona\n");
    printf("\n3) Modificar persona\n");
    printf("\n4) Listar\n");
    printf("\n5) Graficar\n");
    printf("\n6) Salir\n");
    fflush(stdin);
    printf("\nOpcion: ");
    scanf("%d",&opcion);
    while(opcion<1 || opcion>6)
    {
        printf("\nError. Ingrese opcion valida: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    return opcion;
}

int menuModificar()
{
     int opcion;

    printf("\n-----MENU MODIFICAR-----\n\n");
    printf("\n1) Modificar nombre\n");
    printf("\n2) Modificar DNI\n");
    printf("\n3) Modificar edad\n");
    printf("\n4) Salir\n");
    fflush(stdin);
    printf("\nOpcion: ");
    scanf("%d",&opcion);
    while(opcion<1 || opcion>4)
    {
        printf("\nError. Ingrese opcion valida: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }
    return opcion;
}

void inicioEstados(ePersona variable[],int CANT)
{
    int i;

    for(i=0;i<CANT;i++)
    {
        variable[i].estado=0;
    }
}

int buscarEspacio(ePersona variable[],int CANT)
{
    int i,indice=-1;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarDni(ePersona variable[],char codigo[],int CANT)
{
    int i,indice=-1;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1 && strcmp(variable[i].dni,codigo)==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarPersona(ePersona variable)
{
    printf("NOMBRE\t\tEDAD\tDNI\n\n");
    printf("%s\t%d\t\t%s\n",variable.nombre,variable.edad,variable.dni);
}

void ordenar(ePersona variable[],int CANT)
{
    int i,j;
    ePersona auxiliarPersona;

    for(i=0;i<CANT-1;i++)
    {
        for(j=i+1;j<CANT;j++)
        {
            if(strcmp(variable[i].nombre,variable[j].nombre)>0)
            {
                auxiliarPersona=variable[i];
                variable[i]=variable[j];
                variable[j]=auxiliarPersona;
            }
        }
    }
}

void alta(ePersona variable[],int CANT)
{
    int indice,esta,edad;
    char auxEdad[4];
    char codigo[9];
    char auxName[51];

    indice=buscarEspacio(variable,CANT);
    if(indice==-1)
    {
        printf("\nERROR. No hay mas espacio disponible\n\n");
    }
    else
    {
        printf("\nIngrese DNI: ");
        fflush(stdin);
        scanf("%s",codigo);
        stringNum(codigo);
        while(stringNum(codigo)==1)
        {
            printf("\nERROR. Ingrese un DNI valido: ");
            fflush(stdin);
            scanf("%s",codigo);
            stringNum(codigo);
        }

        esta=buscarDni(variable,codigo,CANT);
        if(esta!=-1)
        {
            printf("\nERROR. Ya se ingreso una persona con ese DNI\n\n");
        }
        else
        {
            variable[indice].estado=1;
            strcpy(variable[indice].dni,codigo);
            printf("\nNombre y apellido: ");
            fflush(stdin);
            scanf("%[^\n]",auxName);
            isCha(auxName);
            while(isCha(auxName)==1 || strlen(auxName)>51)
            {
                printf("\nERROR. Ingrese un nombre mas corto: ");
                fflush(stdin);
                scanf("%[^\n]",auxName);
                isCha(auxName);
            }
            strcpy(variable[indice].nombre,auxName);

            printf("\nEdad: ");
            fflush(stdin);
            scanf("%s",auxEdad);
            edad=esNum(auxEdad,1,111);
            while(edad==-1)
            {
                printf("\nERROR. Ingrese una edad valida: ");
                fflush(stdin);
                scanf("%s",auxEdad);
                edad=esNum(auxEdad,1,111);
            }
            variable[indice].edad=edad;
            printf("\n\nALTA EXITOSA\n\n");
        }
    }
}

void baja(ePersona variable[],int CANT)
{
    int esta;
    char baja;
    char codigo[9];

    listar(variable,CANT);
    printf("\n\nIngrese el DNI de la persona: ");
    fflush(stdin);
    scanf("%[^\n]",codigo);
    while(strlen(codigo)>9)
    {
        printf("\nERROR. Ingrese un DNI valido: ");
        fflush(stdin);
        scanf("%[^\n]",codigo);
    }
    esta=buscarDni(variable,codigo,CANT);
    if(esta==-1)
    {
        printf("\nERROR. No hay ninguna persona con ese DNI\n");
    }
    else
    {
        system("cls");
        mostrarPersona(variable[esta]);
        printf("\n\nDesea borrar a esta persona? [s|n]: \n");
        fflush(stdin);
        scanf("%c",&baja);
        baja=tolower(baja);
        while(baja!='s' && baja!='n')
        {
            printf("\nERROR. Ingrese una opcion valida: ");
            fflush(stdin);
            scanf("%c",&baja);
        }
        if(baja=='s')
        {
            variable[esta].estado=0;
            printf("\n\nBAJA EXITOSA\n\n");
        }
        else
        {
            printf("\n\nBAJA CANCELADA\n\n");
        }
    }
}

void modificar(ePersona variable[],int CANT)
{
    char codigo[9];
    char auxEdad[4];
    int esta,edad,opcion=0;

    listar(variable,CANT);
    printf("\n\nIngrese el DNI de la persona: ");
    fflush(stdin);
    scanf("%[^\n]",codigo);
    while(strlen(codigo)>9)
    {
        printf("\nERROR. Ingrese un DNI valido: ");
        fflush(stdin);
        scanf("%[^\n]",codigo);
    }
    esta=buscarDni(variable,codigo,CANT);
    if(esta==-1)
    {
        printf("\nERROR. No hay ninguna persona con ese DNI\n");
    }
    else
    {
        do{
            system("cls");
            mostrarPersona(variable[esta]);
            switch(menuModificar())
            {
                case 1:
                {
                    printf("\nNombre y apellido: ");
                    fflush(stdin);
                    scanf("%[^\n]",variable[esta].nombre);
                    while(strlen(variable[esta].nombre)>51)
                    {
                        printf("\nERROR. Ingrese un nombre mas corto: ");
                        fflush(stdin);
                        scanf("%[^\n]",variable[esta].nombre);
                    }
                    break;
                }
                case 2:
                {
                    printf("\nDNI: ");
                    fflush(stdin);
                    scanf("%[^\n]",variable[esta].dni);
                    while(strlen(variable[esta].dni)>9 || stringNum(variable[esta].dni)==1)
                    {
                        printf("\nERROR. Ingrese un DNI valido: ");
                        fflush(stdin);
                        scanf("%[^\n]",variable[esta].dni);
                    }
                    break;
                }
                case 3:
                {
                    printf("\nEdad: ");
                    fflush(stdin);
                    scanf("%s",auxEdad);
                    edad=esNum(auxEdad,1,111);
                    while(edad==-1)
                    {
                        printf("\nERROR. Ingrese una edad valida: ");
                        fflush(stdin);
                        scanf("%s",auxEdad);
                        edad=esNum(auxEdad,1,111);
                    }
                    variable[esta].edad=edad;
                    break;
                }
                case 4:
                {
                    opcion=4;
                    break;
                }
            }

        }while(opcion!=4);
    }
}

void listar(ePersona variable[],int CANT)
{
    int i,flag=0;

    printf("\nNOMBRE\t\tEDAD\tDNI\n\n");
    ordenar(variable,CANT);
    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            printf("%s\t%d\t%s\n",variable[i].nombre,variable[i].edad,variable[i].dni);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nERROR. No se ingresaron personas\n\n");
    }
}

void grafico(ePersona variable[],int CANT)
{
    int i,j,total,flag=-1;
    int menor18=0;
    int entre18y35=0;
    int mayor35=0;

    for(i=0;i<CANT;i++)
    {
        if(variable[i].estado==1)
        {
            if(variable[i].edad<=18)
            {
                menor18++;
                flag=0;
            }
            else if(variable[i].edad>18 && variable[i].edad<=35)
            {
                entre18y35++;
                flag=0;
            }
            else
            {
                mayor35++;
                flag=0;
            }
        }
    }

    if(flag==-1)
    {
        printf("\nERROR. No se ingresaron personas\n\n");
    }

    total=menor18+entre18y35+mayor35;

    for(j=total;j>0;j--)
    {
        if(menor18==j)
        {
            printf("*");
            menor18--;
        }
        printf("\t");
        if(entre18y35==j)
        {
            printf("*");
            entre18y35--;
        }
        printf("\t");
        if(mayor35==j)
        {
            printf("*");
            mayor35--;
        }
        printf("\n");
    }

    printf("<18\t19-35\t>35\n");
}
