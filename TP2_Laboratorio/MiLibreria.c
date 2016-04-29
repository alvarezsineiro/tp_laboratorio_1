#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiLibreria.h"

/** \brief La funcion se encarga de verificar que el valor ingresado este dentro de un rango determinado
 *
 * \param x int Recibe el valor a verificar
 * \param inf int Recibe el limite inferior del rango
 * \param sup int Recibe el superior inferior del rango
 * \return int Retorna un 1 en caso de exito o un 0 en caso de error
 *
 */
int validarRango(int x,int inf, int sup)
{
    int valido=0;

    if(x>=inf&&x<=sup)
    {
        valido=1;
    }

    return valido;
}

/** \brief Se encarga de incializar el array de estructuras
 *
 * \param lista[] EPersona Recibe el array de estructuras que debe inicializar
 * \return void No retorna ningun valor
 *
 */
void inicializarLista(EPersona lista[])
{
    int i;

    for(i=0;i<20;i++)
    {
        lista[i].estado=-1;
        lista[i].dni=-1;
    }
}

/** \brief Recorre el array de estructuras buscando el indice de una posicion vacia
 *
 * \param lista[] EPersona Recibe el array de estructuras en el que debe buscar la posicion vacia
 * \return int Retorna el indice de la posicion vacia
 *
 */
int obtenerEspacioLibre(EPersona lista[])
{
    int i,indice=-1;
    for(i=0;i<20;i++)
    {
        if(lista[i].estado==-1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

/** \brief Recorre el array de estructuras buscando el dni ingresado
 *
 * \param lista[] EPersona Recibe el array de estructuras en el que debe buscar
 * \param dni int  Recibe el dni que debe buscar
 * \return EIndice  Retorna una estructura con un flag y el indice donde se encuentra en el array
 *
 */
EIndice buscarPorDni(EPersona lista[],int dni)
{
    EIndice busqueda;
    for(busqueda.indice=0;busqueda.indice<20;busqueda.indice++)
    {
        if(lista[busqueda.indice].dni==dni)
        {
            busqueda.flag= -1;
            break;
        }
    }
    return busqueda;
}
/** \brief Se encarga de borrar los datos del empleado en el indice indicado en el array de estructuras
 *
 * \param lista[] EPersona Recibe el array de estructuras en el que debe borrar el empleado
 * \param indice int  Recibe el indice del array del empleado a borrar
 * \return void No retorna ningun valor
 *
 */
void borrarEmpleado(EPersona lista[],int indice)
{
    lista[indice].dni=-1;
    lista[indice].estado=-1;
}
/** \brief Se encarga de ordenar el array de estructuras por nombre
 *
 * \param lista[] EPersona Recibe el array de estructuras que debe ordenar
 * \return void No retorna ningun valor
 *
 */
void ordenarLista(EPersona lista[])
{
    EPersona aux;
    int i, j;

    for(i=0; i<19; i++)
    {
        for(j=i+1; j<20; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)==1)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}
/** \brief Se encarga de ir recorriendo el array de estructuras y mostrar por pantalla los empleados ingresados
 *
 * \param lista[] EPersona Recibe el array de estructuras que debe ir recorriendo y mostrano por pantalla
 * \return void No retorna ningun valor
 *
 */
void mostrarLista(EPersona lista[])
  {
  int i;
  for(i=0; i<20; i++)
       {
           if(lista[i].estado!=-1)
           {
                printf("\nNombre: %s",lista[i].nombre);
                printf("\nEdad: %d",lista[i].edad);
                printf("\nDni: %d",lista[i].dni);
           }
       }
       printf("\n\n");
  }
/** \brief Se encarga de imprimir por pantalla un grafico de la cantidad de empleados en 3 rangos de edades
 *
 * \param lista[] EPersona Recibe el array de estructuras del que debe obtener la cantidad de empleados de los distintos rangos para luego mostrarlos en el grafico
 * \return void No retorna ningun valor
 *
 */
void mostrarGrafico(EPersona lista[])
{
    int hasta18=0;
    int de19a35=0;
    int mayorDe35=0;
    int flag;
    int mayor;
    int i;
    for(i=0;i<20;i++)
    {
        if(lista[i].estado!=-1)
        {
            if(lista[i].edad<19)
            {
                hasta18++;
            }
            if(lista[i].edad>35)
            {
                mayorDe35++;
            }
            if(lista[i].edad>18&&lista[i].edad<36)
            {
                de19a35++;
            }
        }
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
        {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }
    printf("\nEmpleados\n");
    for(i=mayor; i>0; i--)
    {
        flag=0;
        printf("\t%02d|",i);
        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                 printf("\t*");
            }
        }
        printf("\n");
    }
    printf("\t--+-----------------");
    printf("\n\t  |<18\t19-35\t>35   Edades");
    printf("\n\t   %d\t%d\t%d\n", hasta18, de19a35, mayorDe35);
}
