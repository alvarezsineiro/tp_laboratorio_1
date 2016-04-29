typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

typedef struct{
int indice;
int flag;
}EIndice;

int validarRango(int x,int inf, int sup);
void inicializarLista(EPersona lista[]);
int obtenerEspacioLibre(EPersona lista[]);
EIndice buscarPorDni(EPersona lista[], int dni);
void borrarEmpleado(EPersona lista[],int indice);
void ordenarLista(EPersona lista[]);
void mostrarLista(EPersona lista[]);
void mostrarGrafico(EPersona lista[]);

