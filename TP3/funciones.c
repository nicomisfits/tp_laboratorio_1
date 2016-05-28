#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION OBTENER CARACTER
char getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    auxiliar=tolower(getche());
    return auxiliar;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION OBTENER ENTERO
int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION OBTENER CADENA DE CARACTERES
void getString(char* mensaje,char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION INICIALIZADORA
int initMovie(EMovie* iMovie, int length)
{
    int i, auxReturn=-1;
    if(iMovie!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            (iMovie+i)->isEmpty=1;
        }
        auxReturn=0;
    }
    return auxReturn;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION BUSCAR LIBRE
int emptySpace(EMovie* list, int length)
{
    int i, index=-1;
    if(list!=NULL && length>0)
    {
        for(i=0; i<length; i++)
        {
            if((list+i)->isEmpty==1)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION ALTA
int agregarPelicula(EMovie* aMovie, int length, int index, char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* link)
{
    int i, auxReturn=-1;
    if(aMovie!=NULL && length>0)
    {
        for(i=0; i<length;i++)
        {
            if((aMovie+i)->isEmpty==1)
            {
                (aMovie+i)->index=index;
                strcpy((aMovie+i)->titulo, titulo);
                strcpy((aMovie+i)->genero, genero);
                (aMovie+i)->duracion = duracion;
                strcpy((aMovie+i)->descripcion, descripcion);
                (aMovie+i)->puntaje=puntaje;
                strcpy((aMovie+i)->link,link);
                (aMovie+i)->isEmpty=0;
                break;
            }
        }
        auxReturn=0;
    }
    return auxReturn;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION BAJA
int borrarPelicula(EMovie* movie, int length, int index)
{
 int i, auxReturn=-1, flag=-1;
 char activate;
 if(movie!=NULL && length>0)
 {
     for(i=0;i<length;i++)
     {
         if((movie+i)->isEmpty==0)
         {
             if((movie+i)->index==index)
             {
                 printf("el registro es:\nindice: %d, titulo: %s, genero: %s, puntaje: %d\n",(movie+i)->index,(movie+i)->titulo, (movie+i)->genero, (movie+i)->puntaje);
                 activate=getChar("Esta seguro que quiere modificar este registro?(s/n)\n");
                 if(activate=='s')
                 {
                     flag=0;
                     break;
                 }
             }
         }
         else
         {
             printf("El registro no existe o ya fue eliminado.\n");
             break;
         }
     }
     if(flag!=-1)
     {
         (movie+i)->isEmpty=1;
         printf("el registro se elimino correctamente.\n");
     }
     auxReturn=0;
 }
 return auxReturn;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION MODIFICAR
int modifyMovie(EMovie* mMovie, int length, int index)
{
    int i, auxReturn=-1,flag=-1;
    char activate;
    if(mMovie!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if((mMovie+i)->isEmpty==0)
            {
                if((mMovie+i)->index==index)
                {
                    printf("el registro es:\nindice: %d, titulo: %s, genero: %s, puntaje: %d\n",(mMovie+i)->index,(mMovie+i)->titulo, (mMovie+i)->genero, (mMovie+i)->puntaje);
                    activate=getChar("Esta seguro que quiere modificar este registro?(s/n)\n");
                    if(activate=='s')
                    {
                        flag=0;
                        break;
                    }
                    else
                    {
                        printf("accion cancelada por el usuario.\n");
                        break;
                    }
                }
            }
            else
            {
                printf("el registro no existe o fue eliminado.\n");
                break;
            }
        }
        if(flag==0)
        {
            printf("\ningrese el nuevo titulo de la pelicula: ");
            fflush(stdin);
            gets((mMovie+i)->titulo);
            printf("ingrese el nuevo genero de la pelicula: ");
            fflush(stdin);
            gets((mMovie+i)->genero);
            printf("ingrese nueva duracion(minutos): ");
            scanf("%d", &((mMovie+i)->duracion));
            printf("ingrese nueva descripcion de la pelicula: ");
            fflush(stdin);
            gets((mMovie+i)->descripcion);
            printf("ingrese nuevo puntaje de la pelicula: ");
            scanf("%d", &((mMovie+i)->puntaje));
            printf("ingrese nuevo link de la pelicula: ");
            fflush(stdin);
            gets((mMovie+i)->link);
        }
        auxReturn=0;
    }
    return auxReturn;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION ARCHIVO BINARIO
void trabajarArchivoBinario (EMovie* bMovie, char* n_file, char* mode)
{
    FILE* binary;
    binary = fopen(n_file,mode);
    if(binary==NULL)
    {
        printf("el registro no se pudo guardar.\n");
    }
    else
    {
        fwrite(&bMovie, sizeof(EMovie), 1, binary);
        printf("registro actualizado.\n");
    }
    fclose(binary);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION MODIFICAR ARCHIVO BINARIO
void modArchivoBinario (EMovie* bMovie, char* n_file, char* mode, int position)
{
    FILE* binary;
    binary = fopen(n_file,mode);
    if(binary==NULL)
    {
        printf("el registro no se pudo guardar.\n");
    }
    else
    {
        if(fseek(binary, sizeof(EMovie)*position, SEEK_SET)==0)
        {
        fwrite(&bMovie, sizeof(EMovie), 1, binary);
        printf("registro actualizado.\n");
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//FUNCION GENERAR HTML
void generarPagina(EMovie* lista, char* n_file, int length)
{
    int i;
    FILE* webFile;
    webFile = fopen(n_file, "w");
    if(webFile==NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        fprintf(webFile,"<!DOCTYPE html>\n");
        fprintf(webFile,"<html lang='en'>\n");
        fprintf(webFile,"<head>\n");
        fprintf(webFile,"<meta charset='utf-8'>\n");
        fprintf(webFile,"<meta http-equiv='X-UA-Compatible' content='IE-edge'>\n");
        fprintf(webFile,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(webFile,"<title>Lista peliculas</title>\n");
        fprintf(webFile,"<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(webFile,"<link href='css/custom.css' rel='stylesheet'>");
        fprintf(webFile,"<head>\n");
        fprintf(webFile,"<body>\n");
        fprintf(webFile,"<div class='container'>\n");
        fprintf(webFile,"<div class='row'>\n");
        for(i=0;i<length;i++)
        {
            if((lista+i)->isEmpty==0)
            {
                fprintf(webFile,"<article class='col-md-4 article-intro'>\n");
                fprintf(webFile,"<a href='#'>\n");
                fprintf(webFile,"<img class='img-responsive img-rounded' src='%s' alt=''>\n", (lista+i)->link);
                fprintf(webFile,"</a>\n");
                fprintf(webFile,"<h3>\n");
                fprintf(webFile,"<a href='#'>%s</a>\n",(lista+i)->titulo);
                fprintf(webFile,"</h3>\n");
                fprintf(webFile,"<ul>\n");
                fprintf(webFile,"<li>Genero: %s</li>\n",(lista+i)->genero);
                fprintf(webFile,"<li>Puntaje: %d</li>\n",(lista+i)->puntaje);
                fprintf(webFile,"<li>Duracion: %d</li>\n",(lista+i)->duracion);
                fprintf(webFile,"</ul>\n");
                fprintf(webFile,"<p>\n");
                fprintf(webFile,"'%s'\n",(lista+i)->descripcion);
                fprintf(webFile,"</p>\n");
                fprintf(webFile,"</article>\n");
            }
        }
        fprintf(webFile,"</div>\n");
        fprintf(webFile,"</div>\n");
        fprintf(webFile,"<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(webFile,"<script src='js/bootstrap.min.js'></script>\n");
        fprintf(webFile,"<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(webFile,"<script src='js/holder.min.js'></script>\n");
        fprintf(webFile,"</body>\n");
        fprintf(webFile,"</html>\n");
    }
    fclose(webFile);
    printf("Peliculas listadas.\n\n");
}

