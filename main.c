#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
 printf("Bienvenido, Calculadora 1.0 \n");
 system("pause");

 float firstValue;
 float secondValue;
 char extension='s';
 int option;

 while(extension=='s')//validacion, da utilidad a la opcion salir del programa.
 {
    printf("\nIngrese 1er operando: \n");
    scanf("%f", &firstValue);
    printf("Ingrese 2do operando: \n");
    scanf("%f", &secondValue);

    printf("\n1.Suma\n2.Resta\n3.division\n4.Multiplicacion\n5.Factorial (solo el primer operando)\n6.Todas las operaciones\n7.Salir\n\ningrese su opcion: ");
    scanf("%d", &option);

    while(option <= 0 || option >=8)//validacion, el numero indicado debe ser correspondiente a las opciones del indice.
    {
        printf("ese numero no corresponde a ninguna opcion, reingrese:\n");
        scanf("%d", &option);
    }

    switch(option)
    {
        case 1:
        printf("La suma es: %.2f \n", Sum(firstValue, secondValue)); //Resultado de la suma (parametros formales).
        break;

        case 2:
        printf("La resta es: %.2f \n", Rest(firstValue, secondValue)); //Resultado de la resta (parametros formales).
        break;

        case 3:
        while(secondValue==0)//validacion, impide dividir por 0.
        {
            printf("No se puede dividir por cero, reingrese 2do operando:\n");
            scanf("%f", &secondValue);
        }
        printf("La division es: %.2f \n", Div(firstValue, secondValue)); //Resultado de la división (parametros formales).
        break;

        case 4:
        printf("La multiplicacion es: %.2f \n", Multiplication(firstValue, secondValue)); //Resultado de la multiplicación (parametros formales).
        break;

        case 5:
        while(firstValue>=35)//validacion, impide realizar un factorial de un numero mayor a 35 el cual arroja error.
        {
            printf("No se puede calcular factorial de un numero mayor a 35, reingrese 1er operando:\n");
            scanf("%f", &firstValue);
        }
        printf("El factorial del primer operando es: %.2f \n", Factorial(firstValue)); //Resultado del factorial (parametros formales).
        break;

        case 6://Todas las operaciones juntas (parametros formales).
        printf("La suma es: %.2f \n", Sum(firstValue, secondValue));
        printf("La resta es: %.2f \n", Rest(firstValue, secondValue));
        printf("La division es: %.2f \n", Div(firstValue, secondValue));
        printf("La multiplicacion es: %.2f \n", Multiplication(firstValue, secondValue));
        while(firstValue>=35)
        {
            printf("\nNo se puede calcular factorial de un numero mayor a 35, reingrese 1er operando:\n");
            scanf("%f", &firstValue);
        }
        printf("El factorial del primer operando es: %.2f \n", Factorial(firstValue));
        break;

        default://salida del programa.
        printf("\nAdios\n");
        extension='n';
        break;
    }
    system("pause");
    system("cls");

 }
 return 0;
}



