#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiLibreria.h"

int main()
{
    char seguir='s';
    int opcion=0,indice,dni,validar;
    EIndice aux;
    EPersona lista[20];
    inicializarLista(lista);
    while(seguir=='s')
    {
        printf("Elija la opcion que desea: \n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        validar=validarRango(opcion,1,5);
        while(validar!=1)
        {
            printf("\nError, opcion no valida ");
            printf("\nReingrese por favor(1-5): ");
            scanf("%d",&opcion);
            validar=validarRango(opcion,1,5);
        }

        switch(opcion)
        {
            case 1:
                system("cls");
                indice=obtenerEspacioLibre(lista);
                if(indice==-1)
                {
                    printf("\n No hay lugar \n");
                    system("pause");
                }
                else
                {
                    printf("Ingrese dni: ");
                    scanf("%d",&dni);
                    validar=validarRango(dni,1000000,99999999);
                    while(validar!=1)
                    {
                        printf("\nError, el dni debe tener entre 7 y 8 digitos");
                        printf("\nReingrese por favor: ");
                        scanf("%d",&dni);
                        validar=validarRango(dni,1000000,99999999);
                    }
                    aux=buscarPorDni(lista,dni);
                    if(aux.flag==-1)
                    {
                        printf("Empleado ya ingresado\n");
                    }
                    else
                    {
                        lista[indice].dni=dni;
                        printf("Ingrese Nombre: ");
                        fflush(stdin);
                        gets(lista[indice].nombre);
                        printf("Ingrese edad: ");
                        scanf("%d", &lista[indice].edad);
                        validar=validarRango(lista[indice].edad,1,99);
                        while(validar!=1)
                        {
                            printf("\nError, la edad no es valida (1-99) ");
                            printf("\nReingrese por favor: ");
                            scanf("%d",&lista[indice].edad);
                            validar=validarRango(lista[indice].edad,1,99);
                        }
                        lista[indice].estado=1;
                        printf("Empleado ingresado correctamente\n");
                    }
                }
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Ingrese dni: ");
                scanf("%d",&dni);
                validar=validarRango(dni,1000000,99999999);
                while(validar!=1)
                {
                    printf("\nError, el dni debe tener entre 7 y 8 digitos");
                    printf("\nReingrese por favor: ");
                    scanf("%d",&dni);
                    validar=validarRango(dni,1000000,99999999);
                }
                aux= buscarPorDni(lista,dni);
                if(aux.flag==-1)
                {
                    borrarEmpleado(lista,aux.indice);
                    printf("Empleado borrado\n");
                }
                else
                {
                     printf("El empleado no se ha podido borrar debido a que no esta ingresado\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                ordenarLista(lista);
                mostrarLista(lista);
                system("pause");
                break;
            case 4:
                system("cls");
                mostrarGrafico(lista);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
        system("cls");
    }
    return 0;
}
