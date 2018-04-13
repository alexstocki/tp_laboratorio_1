#include <stdio.h>
#include <stdlib.h>

/**
*\brief utiliza los números ingresados por el usuario y devuelve el resultado de la operación
*\param
*\return el resultado de la operación (suma)
*
*/

int suma (int nro1, int nro2){
    int rta;
    rta = nro1+nro2;
    return rta;
}

/**
*\brief utiliza los números ingresados por el usuario y devuelve el resultado de la operación
*\param
*\return el resultado de la operación (resta)
*
*/

int resta (int nro1, int nro2){
    int rta;
    rta = nro1-nro2;
    return rta;
}

/**
*\brief utiliza los números ingresados por el usuario y devuelve el resultado de la operación
*\param
*\return el resultado de la operación (multiplicación)
*
*/

int multiplicacion (int nro1, int nro2){
    int rta;
    rta = nro1*nro2;
    return rta;
}

/**
*\brief utiliza los números ingresados por el usuario y devuelve el resultado de la operación
*\param
*\return el resultado de la operación (división)
*
*/

float division (int nro1, int nro2){
    float rta;
    rta = (float)nro1/(float)nro2;
    return rta;
}

/**
*\brief utiliza el primer número ingresado por el usuario y devuelve el resultado de la operación
*\param
*\return el resultado de la operación (factorial)
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
