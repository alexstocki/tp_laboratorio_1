#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int n1 = 0;
    int n2 = 0;
    int res;
    long int resFac;
    float resDiv;


    do
    {
        printf("\n===============================\n");
        printf("1- Ingresar 1er operando (A=%d)\n", n1);
        printf("2- Ingresar 2do operando (B=%d)\n", n2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        printf("\n===============================\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {
                printf("Ingrese el 1er operando: ");
                scanf("%d", &n1);
                break;
                }
            case 2:
                {
                printf("Ingrese el 2do operando: ");
                scanf("%d", &n2);
                break;
                }
            case 3:
                {
                res = suma (n1, n2);
                printf("El resultado de la suma es: %d\n", res);
                break;
                }
            case 4:
                {
                res = resta (n1, n2);
                printf("El resultado de la resta es: %d\n", res);
                break;
                }
            case 5:
                {
                if(n2<1)
                {
                    printf("Error. El divisor tiene que ser mayor a 0.\n");
                    break;
                }
                resDiv = division (n1, n2);
                printf("El resultado de la division es: %.2f\n", resDiv);
                break;
                }
            case 6:
                {
                res = multiplicacion (n1, n2);
                printf("El resultado de la multiplicacion es: %d\n", res);
                break;
                }
            case 7:
                {
                    if(n1<0)
                    {
                        printf("Error. El numero tiene que ser positivo para realizar la factorial.\n");
                        break;
                    }
                    resFac = factorial (n1);
                    printf("El factorial es: %ld\n", resFac);
                    break;
                }
            case 8:
                {
                    res = suma (n1, n2);
                    printf("La suma es: %d\n", res);
                    res = resta (n1, n2);
                    printf("La resta es: %d\n", res);
                    if(n2>0)
                    {
                        resDiv = division (n1, n2);
                        printf("La division es: %.2f\n", resDiv);
                    }
                    else
                    {
                        printf("El divisor tiene que ser mayor a 0 para dividir.\n");
                    }
                    res = multiplicacion (n1, n2);
                    printf("La multiplicacion es: %d\n", res);
                    if(n1>=0)
                    {
                        resFac = factorial (n1);
                        printf("El factorial es: %ld\n", resFac);
                    }
                    else
                    {
                        printf("El numero tiene que ser positivo para realizar la factorial.\n");
                    }

                    break;
                }
            case 9:
                {
                seguir = 'n';
                break;
                }

        }

    }while(seguir == 's');
    return 0;

}
