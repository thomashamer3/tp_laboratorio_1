/*
 ============================================================================
 Name        : Tp1.c
 Author      : Thomas Hamer
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	float a;
	    float b;
	    float resultado;
	    float suma;
	    float resta;
	    float multiplicar;
	    float division;
	    float resultadoDos;
	    int opcionA;
	    int flag1=0;
	    int flag2=0;

	    do
	    {
	        opcionA=MostrarMenu(opcionA);
	        switch (opcionA)
	        {
	        case 1:
	            printf ("Ingrese un numero : ");
	            scanf ("%f", &a);
	            flag1=1;
	            break;

	        case 2:
	            printf ("Ingrese su segundo numero : ");
	            scanf ("%f", &b);
	            flag2=1;
	            break;

	        case 3:
	        	if(flag1==1 && flag2==1)
	        	{

	            suma = SumarNumeros (a, b);
	            resta = RestarNumeros (a, b);
	            division = DividirNumeros (a, b);
	            multiplicar = MultiplicarNumeros (a, b);
	            resultado = CalcularFactorial (a);
	            resultadoDos=CalcularFactorial(b);
	            printf("e)Calcular el Factorial ( %.2f!): \n",a);

	        	}else
	        	{
	        		printf ("Ingrese sus dos Operando para Calcular las Operaciones\n");
	        	}
	            break;

	        case 4:
	            printf ("La Suma de los 2 numeros es : %.2f\n", suma);
	            printf ("La Resta de los 2 numeros es : %.2f\n", resta);
	            printf ("La Multiplicacion de los 2 numeros es :  %.2f\n", multiplicar);
	            printf ("La Division de los 2 numeros es : %.2f\n", division);
	            printf ("El Factorial de %.2f es:  %.2f y El factorial de %.2f es: %.2f \n", a, resultado,b,resultadoDos);

	            break;

	        case 5:
	            printf ("Adios");
	            break;

	        }
	    }while(opcionA!=5);

	    return 0;
	}

