#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX 3

int main()
{
    char seguir='s';
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char link[500];
    int opcion=0, i, position, index, indexBM;
    EMovie vecMovies[MAX];
    char binaryName[20]={"registro.bin"};
    char htmlName[20]={"web.html"};
    int contador=0;

    initMovie(vecMovies, MAX);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        opcion = getInt("Ingrese la opcion que desea ejecutar: ");
        switch(opcion)
        {
            case 1:
                for(i=0; i<MAX; i++)
                {
                    position=emptySpace(vecMovies,MAX);
                    if(position!=-1)
                    {
                        system("cls");
                        index=getInt("Ingrese el indice de la pelicula: ");
                        getString("ingrese el titulo de la pelicula: ", titulo);
                        getString("ingrese el genero de la pelicula: ", genero);
                        duracion=getInt("ingrese duracion(minutos): ");
                        getString("ingrese descripcion de la pelicula: ", descripcion);
                        puntaje=getInt("ingrese puntaje de la pelicula: ");
                        getString("ingrese link de la pelicula: ", link);
                        agregarPelicula(vecMovies,MAX,index,titulo,genero,duracion,descripcion,puntaje,link);
                        trabajarArchivoBinario(vecMovies, binaryName, "ab+");
                        system("pause");
                        system("cls");
                        seguir='s';
                        break;
                    }
                    else
                    {
                        printf("No hay mas espacio.\n");
                        break;
                    }
                }
                break;

            case 2:
                printf("ingrese el indice de la pelicula a eliminar: ");
                scanf("%d", &indexBM);
                borrarPelicula(vecMovies,MAX,indexBM);
                modArchivoBinario(vecMovies, binaryName, "wb", (vecMovies+i)->index);
                system("pause");
                system("cls");
                break;

            case 3:
                printf("ingrese el indice de la pelicula a modificar: ");
                scanf("%d", &indexBM);
                modifyMovie(vecMovies,MAX,indexBM);
                modArchivoBinario(vecMovies, binaryName, "wb", (vecMovies+i)->index);
                system("pause");
                system("cls");
               break;

            case 4:
                generarPagina(vecMovies,htmlName,MAX);
                system("pause");
                system("cls");
                break;

            case 5:
                seguir = 'n';
                break;
        }

    }

    return 0;
}
