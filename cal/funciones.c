#include <stdio.h>
#include <stdlib.h>

/**
*\brief utiliza los n�meros ingresados por el usuario y devuelve el resultado de la operaci�n
*\param
*\return el resultado de la operaci�n (suma)
*
*/

int suma (int nro1, int nro2){
    int rta;
    rta = nro1+nro2;
    return rta;
}

/**
*\brief utiliza los n�meros ingresados por el usuario y devuelve el resultado de la operaci�n
*\param
*\return el resultado de la operaci�n (resta)
*
*/

int resta (int nro1, int nro2){
    int rta;
    rta = nro1-nro2;
    return rta;
}

/**
*\brief utiliza los n�meros ingresados por el usuario y devuelve el resultado de la operaci�n
*\param
*\return el resultado de la operaci�n (multiplicaci�n)
*
*/

int multiplicacion (int nro1, int nro2){
    int rta;
    rta = nro1*nro2;
    return rta;
}

/**
*\brief utiliza los n�meros ingresados por el usuario y devuelve el resultado de la operaci�n
*\param
*\return el resultado de la operaci�n (divisi�n)
*
*/

float division (int nro1, int nro2){
    float rta;
    rta = (float)nro1/(float)nro2;
    return rta;
}

/**
*\brief utiliza el primer n�mero ingresado por el usuario y devuelve el resultado de la operaci�n
*\param
*\return el resultado de la operaci�n (factorial)
*
*/

 long int factorial (int nro1){
    int i;
    long int rta, factorial = 1;;
    for(i=1; i<=nro1; i++){
        factorial = factorial * i;
    }
    rta = factorial;
    return rta;
}
