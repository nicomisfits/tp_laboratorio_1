#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Menu por defecto.
 * @param String Menu.
 * @param caracter minimo permitido.
 * @param caracter maximo permitido.
 * @return retorna char.
 */
int menu(char[],char min,char max);

/**
 * inicializa los items de estructura.
 * @param variable de estructura.
 * @param variable entero de cantidad.
 * @return retorna entero.
 */
int iniciaPersona(EPersona* ,int);

/**
 * Crea un item de estructura.
 * @param variable de estructura.
 * @param variable entero de cantidad.
 * @param variable de nombre.
 * @param variable de edad.
 * @param variable de dni.
 * @return item de estructura.
 */
int add(EPersona*, int, char[], int, int);

/**
 * Borra un item de estructura.
 * @param variable de estructura.
 * @param variable entero de cantidad.
 * @return el indice a eliminar.
 */
int removePerson(EPersona* , int, int);

/**
 * Obtiene todos los indices del array.
 * @param lista el array se pasa como parametro.
 * @param variable entero de cantidad.
 * @return indices disponibles.
 */
int show(EPersona* ,int);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param variable entero de cantidad.
 * @return el primer indice disponible.
 */
int obtenerEspacioLibre(EPersona lista[], int);

/**
 * Ordena los item por nombre.
 * @param variable de estructura.
 * @param variable entero de cantidad.
 * @return el primer indice disponible.
 */
int ordenarPorNombre(EPersona* ,int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */

 int graficoEdades(EPersona*, int);

#endif // FUNCIONES_H_INCLUDED
