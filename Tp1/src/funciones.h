/*
 * funciones.h
 *
 *  Created on: 10 abr. 2021
 *      Author: Thomas Hamer
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
/** \brief Calcula el Factorial de un numero flotante
 *
 * \param float El valor sobre el cual se calcula el Factorial
 * \return float El resultado del Factorial del numero
 *
 */
float CalcularFactorial(float);
/** \brief Calcula la Suma de dos numeros flotantes
 *
 * \param float El primer valor que se calcula la suma
 * \param float El segundo valor que se calcula la suma
 * \return float El resultado de la suma de los dos valores
 *
 */
float SumarNumeros(float, float);
/** \brief Calcula la Resta de dos numeros flotantes
 *
 * \param float El primer valor que se calcula la resta
 * \param float El segundo valor que se calcula la resta
 * \return float El resultado de la resta de los dos numeros
 *
 */
float RestarNumeros(float, float);
/** \brief Calcula la Division de dos numeros flotantes
 *
 * \param float El valor que se va a dividir
 * \param float El valor que va a dividir
 * \return float El Resultado de la Division
 *
 */
float DividirNumeros(float, float);
/** \brief Calcula la multiplicacion de dos numeros
 *
 * \param float El primer valor que va a ser multiplicado
 * \param float El segundo valor que multiplica al primero
 * \return float El resultado de la Multiplicacion
 *
 */
float MultiplicarNumeros(float, float);

int MostrarMenu(int);


#endif /* FUNCIONES_H_ */
