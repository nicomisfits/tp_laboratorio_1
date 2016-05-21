#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define MAX 7

int main()
{
    char nombre[MAX];
    char seguir='s';
    int edad, dni, i, posicion, auxInicia;
    EPersona misPersonas[MAX];
    char auxiliarMenu;

    auxInicia=iniciaPersona(misPersonas, MAX);//Inicializa los estados de los registros a -1.

    while(seguir=='s')
    {
        auxiliarMenu=menu("1- Agregar persona\n2- Borrar persona\n3- Mostrar nomina\n4- Imprimir lista ordenada por  nombre\n5- Imprimir grafico de edades\n\n6- Salir\n",1,6);

        switch(auxiliarMenu)
        {
            case 1: //AGREGA PERSONAS
                for(i=0; i<MAX; i++)
                {
                    posicion=obtenerEspacioLibre(misPersonas, MAX);//Obtiene entero, espacio disponible para el registro ingresado.
                    if(posicion!=-1)
                    {
                         system("cls");
                         printf("Ingrese nombre: ");
                         fflush(stdin);
                         gets(nombre);
                         printf("Ingrese edad: ");
                         scanf("%d", &edad);
                         printf("Ingrese dni: ");
                         scanf("%d", &dni);
                         printf("\n");
                         add(misPersonas,MAX,nombre,edad,dni);//Crea el registro.
                         system("cls");
                         seguir='s';
                         break;
                    }
                    else
                    {
                        printf("No hay espacio\n");//posicion=-1.
                        break;
                    }
                    system("pause");
                    system("cls");
                }
            break;

            case 2: //BORRA PERSONAS
                printf("ingrese el dni que desea eliminar: ");
                scanf("%d", &dni);
                for(i=0; i<MAX; i++)
                {
                    if(misPersonas[i].dni == dni)
                    {
                        removePerson(misPersonas, MAX, dni);//cambia el estado del registro a -1.
                        printf("la persona ha sido eliminada.\n");
                        break;
                    }
                }
                system("pause");
                system("cls");
                break;

            case 3://MUESTRA NOMINA
                show(misPersonas, MAX);//Muestra los registros cuyos estados sean !=-1.
                system("pause");
                system("cls");
                break;

            case 4://ORDENA ALFABETICAMENTE
                ordenarPorNombre(misPersonas, MAX);//Ordena los registros alfabeticamente, utilizar "Mostrar nomina(op3)" para verificar.
                system("pause");
                system("cls");
                break;

            case 5:
                graficoEdades(misPersonas, MAX);//Muestra grafico de edades.
                system("pause");
                system("cls");
                break;

            case 6://FIN
                printf("Adios");
                seguir = 'n';
                break;
        }
    }

    return 0;
}


