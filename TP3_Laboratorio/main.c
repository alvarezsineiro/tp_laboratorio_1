#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiLibreria.h"

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie *cartelera;
    char nombre[50];

	int cant=leercantidad();
	cartelera=(EMovie*)malloc((cant +1)*sizeof(EMovie));
				if(cartelera==NULL)
				{
					printf("\n No se pudo asignar memoria");
					exit(1);
				}
    if(cant!=0)
	{
		cargarcartelera(cartelera,cant);
	}

    while(seguir=='s')
    {
        system("cls");
        printf("Elija la opcion deseada\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar Pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");

                if(agregarPelicula(cartelera,cant)==0)
                {
                    printf("\nLa pelicula ha sido agregada\n");
                    cant++;
                }

                system("pause");
                break;
            case 2:
                system("cls");
                if(cant!=0)
                {
                   if(borrarPelicula(cartelera,cant)==1)
                    {
                        printf("\nLa pelicula ha sido borrada\n");
                        cant--;
                    }
                    else
                    {
                        printf("\nLa pelicula no se encuentra en la cartelera\n");
                    }
                }
                else
                {
                    printf("\nRealice un ingreso primero\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if(cant!=0)
                {
                   if(modificarPelicula(cartelera,cant)==1)
                    {
                        printf("\nLa pelicula ha sido modificada\n");
                    }
                    else
                    {
                        printf("\nLa pelicula no se encuentra en la cartelera\n");
                    }
                }
                else
                {
                    printf("\nRealice un ingreso primero\n");
                }
                system("pause");
               break;
            case 4:
                system("cls");
                if(cant!=0)
                {
                    printf("Ingrese Titulo del archivo html: ");
                    fflush(stdin);
                    gets(nombre);
                    generarPagina(cartelera,nombre,cant);
                }
                else
                {
                    printf("\nRealice un ingreso primero\n");
                }
                system("pause");

               break;
            case 5:
                system("cls");
                guardarcartelera(cartelera,cant);
                free(cartelera);
                seguir = 'n';
                break;
            default:
                printf("Error, Ingrese una opcion valida(1-5)\n");
                system("pause");
                system("cls");
        }
    }

    return 0;
}
