#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Static Funcion Privada solo del punto C donde se desarrolla, la firma o prototipo se declara en el Punto C.
//Asi la Funcion no se utiliza en el main.
static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int myGets(char* cadena, int longitud);
static int esFlotante(char* cadena);

int utn_verificacion(int valor,char* mensaje,char* mensajeError)
{
    int retorno = -1;

    if(valor == 0)
    {
        printf("%s",mensaje);
        retorno = 0;
    }
    else
    {
        printf("%s",mensajeError);
    }


    return retorno;
}

int normalizeAndCapitalize(char string[])
{
    int ret=-1;
    int i;
    int len=strlen(string);
    strlwr(string);
    if(strlen>0)
    {
        for(i=0; i<len; i++)
        {
            if(string[i-1]==' '||i==0 )
            {
                string[i]=toupper(string[i]);
            }
        }
        ret=1;
    }
    return ret;
}


int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int bufferInt;
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getInt(&bufferInt) == 0)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
    float bufferFloat;
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 0)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}


int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
    int retorno=-1;
    char bufferChar;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos >=0)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c", &bufferChar);
            if(bufferChar >=minimo && bufferChar <=maximo)
            {
                *pResultado= bufferChar;
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }

        }
        while(reintentos>=0);

    }


    return retorno;


}
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
static int myGets(char* cadena, int longitud)
{
    //char* bufferrString= malloc(sizeof(char)*longitud);

    int retorno=-1;
    char bufferString[750];

    if(cadena != NULL && longitud >0)
    {
        fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge

        if(fgets(bufferString,sizeof(bufferString),stdin)!= NULL)
        {
            if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]=='\n')
            {
                bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
            }
            if(strnlen(bufferString,sizeof(bufferString))<= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }

    }
    return retorno;
}

/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
static int esNumerica(char* cadena, int limite)
{
    int i=0;
    int retorno = 1;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(i=0; i<limite &&cadena[i]!='\0'; i++)
        {
            if(i==0 && (cadena[i] == '-' || cadena[i]=='+'))
            {
                continue;
            }

            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer,sizeof(buffer)))
        {
            *pResultado = atoi(buffer);
            retorno = 0;
        }
    }
    return retorno;
}



static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 0;
        }
    }
    return retorno;


}

static int esFlotante(char* cadena)
{
    int i=0;
    int retorno = 1;
    int contadorPuntos=0;

    if(cadena != NULL && strlen(cadena) > 0)
    {
        for(i=0; cadena[i]!='\0'; i++)
        {
            if(i==0 && (cadena[i] == '-' || cadena[i]=='+'))
            {
                continue;
            }

            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                if(cadena[i]=='.' && contadorPuntos==0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break;
                }

            }
        }
    }
    return retorno;
}




/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */

float getFloatSimple(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getIntSimple(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getCharSimple(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin); //__fpurge linux
    scanf("%c",&auxiliar);
    return auxiliar;
}
int getPalabra(char palabra[], char message[])
{
    int len;
    int i;
    int ret=0;


    printf("%s", message);
    fflush(stdin);
    fgets(palabra, 51, stdin);

    len=strlen(palabra);
    palabra[len-1]='\0';

    for(i=0; i<len; i++)
    {
        if(palabra[i] =='0' || palabra[i] =='1' || palabra[i] =='2' || palabra[i] =='3' || palabra[i] =='4'
                || palabra[i] =='5' || palabra[i] =='6' || palabra[i] =='7' || palabra[i] =='8' || palabra[i] =='9')
        {
            ret = -1;
            break;
        }
    }

    return ret;
}


void Menu()
{
    printf("1.Ingresar Empleado\n");
    printf("2.Modificar Empleado\n");
    printf("3.Eliminar Empleado\n");
    printf("4.Informar\n");
    printf("5.Salir\n");
    fflush(stdin);

}

