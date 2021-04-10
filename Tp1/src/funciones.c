/*
 * funciones.c
 *
 *  Created on: 10 abr. 2021
 *      Author: Thomas Hamer
 */
#include "funciones.h"

float CalcularFactorial(float a)
{
    float resultado;


    if(a==0 || a<0)
    {
        resultado=1;
    }
    else
    {
    resultado= a* CalcularFactorial(a - 1);

    }


    return resultado;
}

float SumarNumeros(float a, float b)
{
    float suma;
    suma = a + b;
     printf ("a)Calcular la Suma ( %.2f+ %.2f): \n",a, b);

    return suma;
}

float RestarNumeros(float a, float b)
{
       float resta;
       resta = a - b;
       printf ("b)Calcular la Resta ( %.2f- %.2f): \n",a, b);
       return resta;
}

float MultiplicarNumeros(float a, float b)
   {
       float multiplicar;
       printf("d) Calcular la Multiplicacion ( %.2f* %.2f): \n",a, b);
       multiplicar = a * b;
       return multiplicar;
   }


   float DividirNumeros(float a, float b)
   {
     float division;
     if(b != 0)
   {
       printf("c)Calcular la Division ( %.2f/ %.2f): \n",a, b);
       return (double)a/b;
   }
     else{
           return division= printf("c)La Division con cero no esta permitida. ");
         }

    }

int MostrarMenu(int opcionA)
{
    int opciona;

  printf ("Bienvenido, elija una opcion\n");
  printf("1.Ingresar 1er operando(A=x)\n2.Ingresar 2do operando(B=y)\n");
  printf("3.Calcular todas las operaciones: \na)Calcular la Suma(A+B)\nb)Calcular la Resta(A-B\n");
  printf("c)Calcular la Division(A/B)\nd)Calcular la Multiplicacion(A*B)\n");
  printf("e)Calcular el Factorial(A!)\n");
  printf("4.Informar Resultados:\na)El Resultado de A+B \nb)El Resultado de A-B \n");
  printf("c)El Resultado de A/B \nd)El Resultado de A*B \ne)El Factorial de A y El Factorial de B ");
  printf("\n5.Salir\n");
  scanf ("%d", &opciona);
    while(opciona!=1&&opciona!=2&&opciona!=3&&opciona!=4&&opciona!=5)
    {
    	printf ("Error, Elija una Opcion\n");
  printf("1.Ingresar 1er operando (A=x)\n2.Ingresar 2do operando (B=y)");
  printf("\n3.Calcular todas las operaciones: \na)Calcular la Suma (A+B)\nb)Calcular la Resta (A-B");
  printf("c)Calcular la Division (A/B)\nd)Calcular la Multiplicacion (A*B");
  printf("e)Calcular el Factorial (A!)");
  printf("\n4.Informar resultados:\na)El Resultado de A+B \nb)El Resultado de A-B  ");
  printf("c)El Resultado de A/B\nd)El Resultado de A*B \ne)El Factorial de A y El Factorial de B \n");
  printf("\n5.Salir\n");
  scanf ("%d", &opciona);
    }

    return opciona;
}




