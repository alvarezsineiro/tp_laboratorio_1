#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MiLibreria.h"

/** \brief Se encarga de tomar la cantidad de peliculas guardadas
 *
 * \return int
 *
 */
int leercantidad()
{
    int cant = 0;
    FILE *f;
	f = fopen("cantidad.bin","rb");
	fread(&cant,sizeof(int),1,f);
	fclose(f);
	return cant;
}

/** \brief Se encarga de guardar la cantidad de peliculas en un archivo binario
 *
 * \param cant int Recibe la cantidad de peliculas que hay
 * \return void
 *
 */
void guardarcantidad(int cant)
{
    FILE *f;
	f = fopen("cantidad.bin", "wb");
	if(f == NULL)
	{
		printf("No se puede abrir el archivo");
		exit(1);
	}
	fwrite(&cant,sizeof(int),1,f);
	fclose(f);
}

/** \brief Se encarga de tomar las peliculas del archivo binario
 *
 * \param cartelera EMovie*  Recibe la dirreccion de la cartelera
 * \param cant int Recibe la cantidad de peliculas que hay guardadas
 * \return void
 *
 */
void cargarcartelera(EMovie *cartelera,int cant)
{
	FILE *f;
	f = fopen("cartelera.bin","rb");
	if(f == NULL)
	{
		printf("No se puede abrir el archivo\n");
		exit(1);
	}
	fread(cartelera,sizeof(EMovie),cant,f);
	fclose(f);
}

/** \brief Se encarga de guardar la cartelera en un archico binario
 *
 * \param cartelera EMovie* Recibe la dirreccion de la cartelera
 * \param cant int  Recibe la cantidad de peliculas que hay guardadas
 * \return void
 *
 */
void guardarcartelera(EMovie *cartelera,int cant)
{
	FILE *f;
	f = fopen("cartelera.bin","wb");
	if(f == NULL)
	{
		printf("No se pudo crear el archivo\n");
		exit(1);
	}
	fwrite(cartelera, sizeof(EMovie),cant,f);
	guardarcantidad(cant);
	printf("\nCartelera guardada\n");
	fclose(f);
}

/** \brief Se encarga de intercambiar dos memorias de lugar
 *
 * \param a EMovie* Recibe el primer valor a intercambiar
 * \param b EMovie* Recibe el segundo valor a intercambiar
 * \return void
 *
 */
void intercambiar(EMovie *a, EMovie *b)
{
 EMovie aux;
 aux = *a;
 *a = *b;
 *b = aux;
}

/** \brief Se encarga de borrar una de las peliculas ingresadas
 *
 * \param cartelera EMovie*  Recibe la dirreccion de la cartelera
 * \param cant int  Recibe la cantidad de peliculas que hay guardadas
 * \return int
 *
 */
int borrarPelicula(EMovie *cartelera,int cant)
{
    int i,flag=0;
    char aux[50];
    printf("Ingrese Titulo de la pelicula que desea eliminar: ");
    fflush(stdin);
    gets(aux);
    for(i=0;i<cant;i++)
    {
        if(strcmp(aux,(cartelera+i)->titulo)==0)
        {
            intercambiar((cartelera+i),(cartelera+cant));
            cartelera=(EMovie*)realloc(cartelera,(cant -1)*sizeof(EMovie));
            cant--;
            flag=1;
            break;
        }
    }
    return flag;
}

/** \brief Se encarga de modificar una de las peliculas ingresadas
 *
 * \param cartelera EMovie*  Recibe la dirreccion de la cartelera
 * \param cant int Recibe la cantidad de peliculas que hay guardadas
 * \return int
 *
 */
int modificarPelicula(EMovie *cartelera,int cant)
{
    int i,flag=0;
    char aux[50];
    int opcion;
    printf("Ingrese Titulo de la pelicula que desea modificar: ");
    fflush(stdin);
    gets(aux);
    for(i=0;i<cant;i++)
    {
        if(strcmp(aux,(cartelera+i)->titulo)==0)
        {
            printf("\nElija la opcion que desea modificar\n");
            printf("1- Titulo\n");
            printf("2- Genero\n");
            printf("3- Duracion\n");
            printf("4- Descripcion\n");
            printf("5- Puntaje\n");
            printf("6- Link de la caratula\n\n");

            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                system("cls");
                printf("Ingrese Titulo de la pelicula: ");
                fflush(stdin);
                gets((cartelera+i)->titulo);
                flag=1;
                break;

                case 2:
                system("cls");
                printf("Ingrese genero de la pelicula: ");
                fflush(stdin);
                gets((cartelera+i)->genero);
                flag=1;
                break;

                case 3:
                system("cls");
                printf("Ingrese duracion de la pelicula: ");
                scanf("%d",&(cartelera+i)->duracion);
                flag=1;
                break;

                case 4:
                system("cls");
                printf("Ingrese descripcion de la pelicula: ");
                fflush(stdin);
                gets((cartelera+i)->descripcion);
                flag=1;
                break;

                case 5:
                system("cls");
                printf("Ingrese puntaje de la pelicula: ");
                scanf("%d",&(cartelera+i)->puntaje);
                flag=1;
                break;

                case 6:
                system("cls");
                printf("Ingrese link de la caratula de la pelicula: ");
                fflush(stdin);
                gets((cartelera+i)->descripcion);
                flag=1;
                break;

                default:
                printf("Error,opcion no valida\n");
            }

            break;
        }
    }
    return flag;
}

/** \brief Se encarga de agregar una pelicula
 *
 * \param cartelera EMovie*  Recibe la dirreccion de la cartelera
 * \param cant int  Recibe la cantidad de peliculas que hay guardadas
 * \return int
 *
 */
int agregarPelicula(EMovie *cartelera,int cant)
{
    cartelera=(EMovie*)realloc(cartelera,(cant +1)*sizeof(EMovie));
    if(cartelera==NULL)
    {
        printf("\n No se pudo asignar memoria");
        exit(1);
	}

    printf("Ingrese Titulo de la pelicula: ");
    fflush(stdin);
    gets((cartelera+cant)->titulo);

    printf("Ingrese genero de la pelicula: ");
    fflush(stdin);
    gets((cartelera+cant)->genero);

    printf("Ingrese duracion de la pelicula: ");
    scanf("%d",&(cartelera+cant)->duracion);

    printf("Ingrese descripcion de la pelicula: ");
    fflush(stdin);
    gets((cartelera+cant)->descripcion);

    printf("Ingrese puntaje de la pelicula: ");
    scanf("%d",&(cartelera+cant)->puntaje);

    printf("Ingrese link de la caratula de la pelicula: ");
    fflush(stdin);
    gets((cartelera+cant)->linkImagen);
    return 0;
}

/** \brief Se encarga de generar la pagina web
 *
 * \param cartelera EMovie* Recibe la dirreccion de la cartelera
 * \param nombre[] char  Recibe el nombre que va a tener el archivo
 * \param cant int  Recibe la cantidad de peliculas que hay guardadas
 * \return void
 *
 */
void generarPagina(EMovie *cartelera,char nombre[],int cant)
{
    FILE*f;
    char aux[100];
    int i=0;
    strcpy(aux,nombre);
    strcat(aux,".html");
    f=fopen(aux,"w");
    if(f==NULL)
    {
        printf("\nNo se pudo generar pagina\n");
        exit(1);
    }

    fprintf(f,"<html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Cartelera</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'><!-- Repetir esto para cada pelicula -->");
    for(i=0;i<cant;i++)
    {
       fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>",(cartelera+i)->linkImagen,(cartelera+i)->titulo,(cartelera+i)->genero,(cartelera+i)->puntaje,(cartelera+i)->duracion,(cartelera+i)->descripcion);
    }
    fprintf(f,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
}
