#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[300];
    int puntaje;
    char linkImagen[300];
}EMovie;

int agregarPelicula(EMovie *cartelera,int cant);
int borrarPelicula(EMovie *cartelera,int cant);
int modificarPelicula(EMovie *cartelera,int cant);
void generarPagina(EMovie *cartelera,char nombre[],int cant);

int leercantidad();
void guardarcantidad(int cant);
void cargarcartelera(EMovie *cartelera,int cant);
void guardarcartelera(EMovie *cartelera,int cant);
void intercambiar(EMovie *a, EMovie *b);
