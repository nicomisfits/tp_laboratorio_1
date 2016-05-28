#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    int index;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char link[50];
    int isEmpty;
}EMovie;

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char*);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char*);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char* mensaje,char* input);

/**
 *  Inicializa una pelicula al archivo binario
 *  @param iMovie la estructura a ser inicializada al archivo
 *  @param length parametro pasado como largo
 *  @return retorna -1 o 0 de acuerdo a si pudo inicializar la pelicula o no
 */
int initMovie(EMovie* iMovie, int length);

/**
 *  Busca el primer espacio vacio para completar
 *  @param list la estructura utilizada para verificar los espacios
 *  @param length parametro pasado como largo
 *  @return retorna posicion vacia (1)
 */
int emptySpace(EMovie* list, int length);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param length parametro pasado como largo
 *  @param index parametro que indica coincidencia en la busqueda
 *  @param puntero a char que obtiene titulo de la pelicula
 *  @param puntero a char que obtiene genero de la pelicula
 *  @param entero duracion de la pelicula
 *  @param puntero a char descrpicion de la pelicula
 *  @param entero puntaje
 *  @param puntero a char direccion html
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* aMovie, int length, int index, char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* link);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @param length parametro pasado como largo
 *  @param index parametro que indica coincidencia en la busqueda
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* movie, int length, int index);

/**
 *  Modifica una pelicula del archivo binario
 *  @param mMovie la estructura a ser modificada al archivo
 *  @param length parametro pasado como largo
 *  @param index parametro que indica coincidencia en la busqueda
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int modifyMovie(EMovie* mMovie, int length, int index);

/** \brief Guarda una struct al final de un archivo binario registro.bin
 * \param struct EMovie* p puntero a struct a ser escrita
 * \param nombre de archivo
 * \param Modo en que se quiere utilizar la funcion
 */
void trabajarArchivoBinario (EMovie* bMovie, char* n_file,char* mode);

/** \brief Modifica una struct de un archivo binario registro.bin
 * \param struct EMovie* p puntero a struct a ser escrita
 * \param nombre de archivo
 * \param Modo en que se quiere utilizar la funcion
 * \param cantidad maxima
 */
void modArchivoBinario (EMovie* bMovie, char* n_file, char* mode, int position);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre de archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie* lista, char* n_file, int length);


#endif // FUNCIONES_H_INCLUDED
