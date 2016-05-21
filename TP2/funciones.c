#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//------------------------------------------------------------------------------------------------------------------------------------
//FUNCION MENU
int menu(char textoMenu[],char min,char max)
{
    char opcion;
    printf("%s",textoMenu);
    scanf("%d",&opcion);
    while(opcion<min||opcion>max)
    {
        printf("ERROR, Reingrese: \n");
        scanf("%c",&opcion);
        system("pause");
        system("cls");
        break;
    }
    return opcion;
}
//------------------------------------------------------------------------------------------------------------------------------------
//FUNCION INICIALIZADORA
int iniciaPersona(EPersona* iPersona, int length)
{
    int i, auxRetorno=-1;
    if(iPersona!=NULL && length>0)//verifica que la variable no sea NULL y el largo no menor a 0.
    {
        for(i=0; i<length; i++)
        {
            iPersona[i].estado=-1;
        }
        auxRetorno=0;
    }
    return auxRetorno;
}
//------------------------------------------------------------------------------------------------------------------------------------
//FUNCION BUSCAR LIBRE
int obtenerEspacioLibre(EPersona lista[], int length)
{
    int index=-1;
    int i;
    for(i=0;i<length;i++)
    {
        if(lista[i].estado==-1)
        {
            //Esta vacio
            index=i;
            break;
        }
    }
    return index;
}
//------------------------------------------------------------------------------------------------------------------------------------
//FUNCION ALTA
int add(EPersona* aPersona, int length, char nombre[], int edad, int dni)
{
    int i, auxRetorno=-1;
    if(aPersona!=NULL && length>0)//verifica que la variable no sea NULL y el largo no menor a 0.
        {
            for(i=0; i<length; i++)
            {
                if(aPersona[i].estado==-1)
                {
                    strcpy(aPersona[i].nombre, nombre);
                    aPersona[i].edad = edad;
                    aPersona[i].dni = dni;
                    aPersona[i].estado=0;
                    auxRetorno=0;
                    break;
                }
            }
        }
    return auxRetorno;
}
//------------------------------------------------------------------------------------------------------------------------------------
//FUNCION BAJA
int removePerson(EPersona* rPersona, int length, int dni)
{
    int i, auxRetorno=-1, auxDelete=0;
    if(rPersona!=NULL && length>0)//verifica que la variable no sea NULL y el largo no menor a 0.
        {
            for(i=0; i<length; i++)
            {
                if(rPersona[i].estado==0)
                {
                    if(rPersona[i].dni==dni)
                    {
                        auxDelete=1;
                        break;
                    }
                }
            }
            if(auxDelete==1)
            {
                rPersona[i].estado=-1;
                auxRetorno=0;
            }
        }
    return auxRetorno;
}
//------------------------------------------------------------------------------------------------------------------------------------
//FUNCION ORDENAR POR NOMBRE

int ordenarPorNombre(EPersona* oPersona, int length)
{
    int i, j, auxOrdenDni,auxRetorno=-1;
    EPersona auxOrden;
    if(oPersona!=NULL && length>0)//verifica que la variable no sea NULL y el largo no menor a 0.
        {
            for(i=0; i<length-1; i++)
            {
                for(j=i+1; j<length; j++)
                {
                    if(strcmp(oPersona[i].nombre, oPersona[j].nombre)>0)
                    {
                        auxOrden=oPersona[i];
                        oPersona[i]=oPersona[j];
                        oPersona[j]=auxOrden;
                        printf("los registros se ordenaron alfabeticamente(Mostrar nomina para verificar)\n");
                        break;
                    }
                }
            }
        }
    return auxRetorno;
}

//------------------------------------------------------------------------------------------------------------------------------------
//UTILIZADO PARA MOSTRAR LAS PERSONAS

int show(EPersona* laPersona, int length)
{
int i, auxRetorno=-1;
for(i=0; i<length; i++)
{
    if(laPersona[i].estado!=-1)
    {
        printf("El nombre es: %s Y el dni es: %d\n", laPersona[i].nombre, laPersona[i].dni);
    }
    auxRetorno=0;
}
return auxRetorno;
}

//------------------------------------------------------------------------------------------------------------------------------------
//UTILIZADO PARA GRAFICAR LAS EDADES
int graficoEdades(EPersona* gPersona, int length)
{
    int i;
    if(gPersona!=NULL && length>0)
    {
        printf("\n\t<18\t19-35\t>34\n");
        for(i=0; i<length; i++)//verifica que la variable no sea NULL y el largo no menor a 0.
        {
            if(gPersona[i].estado==0)//verifica que el registro no este vacio.
            {
                if(gPersona[i].edad < 19)
                {
                    printf("\t* \n");
                }
                else if(gPersona[i].edad <35)
                {
                    printf("\t\t* \n");
                }
                else
                {
                    printf("\t\t\t* \n");
                }
            }
        }
    }
}
