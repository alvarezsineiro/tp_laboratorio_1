#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Libreria.h"

int main()
{
    float a=0,b=0;
    int c;
    int opcion;
    int flag1=0,flag2=0;
    char respuesta='n';
    do{
    system("cls");
    printf("Trabajo practico N°1\n");
    printf("Elija una opcion:\n");
    printf("1. Ingresar 1er operando (A=%.2f)\n",a);
    printf("2. Ingresar 2do operando (B=%.2f)\n",b);
    printf("3. Calcular la suma (A+B)\n");
    printf("4. Calcular la resta (A-B)\n");
    printf("5. Calcular la division (A/B)\n");
    printf("6. Calcular la multiplicacion (A*B)\n");
    printf("7. Calcular el factorial (A!)\n");
    printf("8. Calcular todas las operaciones\n");
    printf("9. Salir\n\n");

    scanf("%d",&opcion);
    while(opcion<1||opcion>9)
    {
        printf("Error, reingrese la opcion deseada entre 1 y 9\n");
        scanf("%d",&opcion);
    }
    switch(opcion)
    {
        case 1:
            system("cls");
            a=ingreso();
            c=a;
            flag1=1;
            break;
        case 2:
            system("cls");
            b=ingreso();
            flag2=1;
            break;
        case 3:
            system("cls");
            if(flag1==0||flag2==0)
            {
                printf("Ingrese los valores de A Y B antes de realizar la operacion\n");
            }
            else
            {
                printf("La suma de A y B es: %.2f\n",suma(a,b));
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(flag1==0||flag2==0)
            {
                printf("Ingrese los valores de A Y B antes de realizar la operacion\n");
            }
            else
            {
                printf("La resta de A y B es: %.2f\n",resta(a,b));
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(flag1==0||flag2==0)
            {
                printf("Ingrese los valores de A Y B antes de realizar la operacion\n");
            }
            else
            {
                if(b==0)
                {
                    printf("Error, no se puede dividir por 0\n");
                }
                else
                {
                    printf("La division de A y B es: %.2f\n",(float)division(a,b));
                }
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(flag1==0||flag2==0)
            {
                printf("Ingrese los valores de A Y B antes de realizar la operacion\n");
            }
            else
            {
                printf("La multiplicacion de A y B es: %.2f\n",multiplicar(a,b));
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(flag1==0)
            {
                printf("Ingrese los valores de A Y B antes de realizar la operacion\n");
            }
            else
            {
                if(a<0||(a-c)!=0)
                {
                    printf("No se puede realizar el factorial de numeros negativos o con coma\n");
                }
                else
                {
                    printf("El factorial de A es: %.0lf\n",factorial(a));
                }
            }
            system("pause");
            break;
        case 8:
            system("cls");
            if(flag1==0||flag2==0)
            {
                printf("Ingrese los valores de A Y B antes de realizar la operacion\n");
            }
            else
            {
                printf("La suma de A y B es: %.2f\n",suma(a,b));
                printf("La resta de A y B es: %.2f\n",resta(a,b));
                if(b==0)
                {
                    printf("No se puede realizar la division por 0\n");
                }
                else
                {
                    printf("La division de A y B es: %.2f\n",(float)division(a,b));
                }
                printf("La multiplicacion de A y B es: %.2f\n",multiplicar(a,b));
                if(a<0||(a-c)!=0)
                {
                    printf("No se puede realizar el factorial de numeros negativos o con coma\n");
                }
                else
                {
                    printf("El factorial de A es: %.0lf\n",factorial(a));
                }
            }
            system("pause");
            break;
        case 9:
            system("cls");
            printf("Esta seguro que desea salir? (s/n)\n");
            fflush(stdin);
            scanf("%c",&respuesta);
            respuesta=tolower(respuesta);
            while(respuesta!='s'&&respuesta!='n')
            {
                printf("\nError, Reingrese respuesta (s/n)\n");
                fflush(stdin);
                scanf("%c",&respuesta);
                respuesta=tolower(respuesta);
            }
    }
    }while(respuesta!='s');
    system("cls");
    return 0;
}
