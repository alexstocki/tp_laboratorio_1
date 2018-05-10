#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief estructura que almacena los datos que representan a la persona
            que se va a agendar
 *
 * \param array cadena de caracteres para nombre y apellido. 50 caracteres mas el
            finalizador de cadena
 * \param array cadena de caracteres que representa el dni
 * \param numero entero para la edad
 * \param numero entero para el estado. 0 array vacio. 1 array ocupado.
 * \return
 *
 */
typedef struct{
        char nombre[51];
        char dni[9];
        int edad;
        int estado;
}ePersona;

/** \brief se ingresa una cadena de numeros y se verifica que todos los elementos sean digitos
            si alguno no lo es, se devuelve 1
 *
 * \param codigo es la cadena de caracteres numeros
 * \return retorna 1 en caso de que algun elemento no sea digito. Si todos los son, devuelve 0
 *
 */
int stringNum(char codigo[]);
int isCha(char codigo[]);
int isChar(ePersona variable[],int CANT);

/** \brief menu grafico de opciones para el usuario
 *
 * \return numero entero que representa la opcion elegida
 *
 */
int menu();

/** \brief menu grafico de opciones para modificar un usuario
 *
 * \return numero entero que representa la opcion elegida
 *
 */
int menuModificar();

/** \brief inicializa todos los estados de la estructura en 0
 *
 * \param array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
void inicioEstados(ePersona variable[],int CANT);

/** \brief busca un array vacio y retorna el entero correspondiente
 *           al indice, si no hay mas espacios vacios retorna -1
 * \param array de tipo estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
int buscarEspacio(ePersona variable[],int CANT);

/** \brief compara el codigo que recibe con el elemento dni de los array estructura
           si coincide con un array que tambien tiene estado 1 devuelve el entero que
           indica el indice, sino retorna -1.
 *
 * \param array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return numero entero del indice si se encontro coincidencia, -1 de otro modo
 *
 */
int buscarDni(ePersona variable[],char codigo[],int CANT);

/** \brief imprime en pantalla el array estructura seleccionado
            junto con todos sus datos
 * \param array de estructura
 * \return
 *
 */
void mostrarPersona(ePersona variable);

/** \brief compara y ordena alfabeticamente los array de estructura
            tomando como parametro el elemento nombre de los mismos
 *
 * \param elemento nombre de los array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
void ordenar(ePersona variable[],int CANT);

/** \brief funcion que permite agregar una nueva persona
 *
 * \param array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
void alta(ePersona variable[],int CANT);

/** \brief funcion que elimina a una persona de la lista
            cambiando el elemento estado del array estructura
            de 1 a 0. Asi no se imprime por pantalla.
 *
 * \param array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
void baja(ePersona variable[],int CANT);

/** \brief funcion que permite modificar los campos del array estructura
            seleccionado.
 *
 * \param array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
void modificar(ePersona variable[],int CANT);

/** \brief imprime todos los array estructura con el elemento estado = 1
 *
 * \param array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
void listar(ePersona variable[],int CANT);

/** \brief imprime un grafico de barras que representa por edades
            a las personas agendadas con estado = 1.
 *
 * \param array de estructura
 * \param entero que marca la cantidad de arrays tipo estructura
 * \return
 *
 */
void grafico(ePersona variable[],int CANT);

/** \brief verifica que el array ingresado este compuestos por numeros y
            devuelve el aray convertido en entero
 *
 * \param numeroChar cadena de caracteres compuesta de numeros
 * \param minimo permitido para el numero convertido
 * \param maximo permitido para el numero convertido
 * \return cadena de caracteres verificada convertida en entero
            o -1 si algun caracter no es un numero.
 *
 */
int esNum(char numeroChar[],int min,int max);




#endif // FUNCIONES_H_INCLUDED

