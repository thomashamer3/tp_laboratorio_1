#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int utn_verificacion(int valor,char* mensaje,char* mensajeError);

int normalizeAndCapitalize(char string[]);

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int getIntSimple(char mensaje[]);

float getFloatSimple(char mensaje[]);

char getCharSimple(char mensaje[]);

int getPalabra(char palabra[], char message[]);

int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);

void Menu();

#endif // INPUT_H_INCLUDED
