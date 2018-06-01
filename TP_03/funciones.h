#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[31];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImg[500];
}eMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param indice es el numero de elemento del puntero movie
 *  @param pIndice modifica el indice si se logro cargar la pelicula
 **/
int agregarPelicula(eMovie *movie, int indice, int *pIndice);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param indice el espacio que ocupa el elemento movie
 */
int borrarPelicula(eMovie *movie, int indice);

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param indice el espacio que ocupa el elemento movie
 */
int modificarPelicula(eMovie *movie, int indice);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param indice, cantidad de elementos para corroborar cuales se incluyen y cuales no, en caso de haber elementos eliminados.
 */
void generarPagina(eMovie *movie, int indice);

/**
 *  Carga elementos movies previamente almacenados en el programa
 *  @param movie la estructura a ser eliminada al archivo
 *  @param pIndice leer la cantidad de elementos que se cargaron en el archivo
 *  @param pContados leer la cantidad de espacio reservado para los elementos movies
 */
int cargarArchivo(eMovie *movie, int *pIndice, int *pContador);

/**
 *  Guarda los cambios efectuados en el documento binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param indice el espacio que ocupa el elemento movie
 *  @param pIndice puntero a la cantidad de elementos cargados
 *  @param pContador puntero a la cantidad de espacio de memoria solicitado
 */
void guardarArchivo(eMovie *movie, int indice, int *pIndice, int *pContador);

/**
 *  Solicita y devuelve un numero entero
 *  @param msg es el mensaje que se imprime para solicitar el ingreso del dato
 *  @param msgError es el mensaje que se imprime cuando se produce un error
 *  @param min es el tope minimo que no puede sobrepasar el numero ingresado
 *  @param max es el tope maximo que no puede sobrepasar el numero ingresado
 */
int validarNum(char msg[], char msgError[], int min, int max);

/**
 *  Solicita y devuelve una cadena de caracteres
 *  @param msg es el mensaje que se imprime para solicitar el ingreso del dato
 *  @param msgError es el mensaje que se imprime cuando se produce un error
 *  @param lon es el maximo permitido para la cadena de caracteres
 */
char *validarCad(char msg[], char msgError[], int lon);

/**
 *  Solicita y devuelve un char
 *  @param msg es el mensaje que se imprime para solicitar el ingreso del dato
 *  @param msgError es el mensaje que se imprime cuando se produce un error
 */
char validarChar(char msg[], char msgError[]);

/**
 *  Imprime por pantalla una determinada pelicula
 *  @param movie elemento de tipo estructura eMovie que contiene los datos de una pelicula
 *  @param indice especifica el espacio que ocupa el elemento movie a mostrar
 */
void mostrarPelicula(eMovie *movie, int indice);

/**
 *  Imprime por pantalla todas aquellas peliculas cargadas que no fueron eliminadas
 *  @param movie elemento de tipo estructura eMovie que contiene los datos de una pelicula
 *  @param indice es el dato que se utiliza para itinerar en la busqueda de peliculas cargadas
 */
void mostrarPelis(eMovie *movie, int indice);

#endif // FUNCIONES_H_INCLUDED
