#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 		  un m�ximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiar� la cadena obtenida.
 * \param longitud Define el tama�o de cadena.
 * \return Retorna 0 (�XITO) si se obtiene una cadena y -1 (ERROR) si no.
 *
 */
static int getString(char *cadena, int longitud);

/**
 * \brief Obtiene un n�mero entero desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \return Retorna 0 (�XITO) si se obtiene un n�mero entero y -1 (ERROR) si no.
 *
 */
static int getInt(int *pResultado);

/**
 * \brief Verifica si la cadena ingresada es num�rica.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tama�o de cadena.
 * \return Retorna 1 (verdadero) si la cadena es num�rica y 0 (falso) si no lo es.
 *
 */
static int esNumerica(char *cadena,int limite);

/**
 * \brief Obtiene un n�mero float desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \return Retorna 0 (�XITO) si se obtiene un n�mero entero y -1 (ERROR) si no.
 *
 */
static int getFloat(float *pResultado);

/**
 * \brief Verifica si la cadena ingresada es de tipo float.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tama�o de cadena.
 * \return Retorna 1 (verdadero) si la cadena es num�rica y 0 (falso) si no lo es.
 *
 */
static int esFloat(char *cadena,int limite);

/**
 * \brief Obtiene un caracter desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \return Retorna 0 (�XITO) si se obtiene un n�mero entero y -1 (ERROR) si no.
 */
static int getCaracter(char *pResultado);

/**
 * \brief Verifica si la cadena ingresada es de tipo char.
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tama�o de cadena.
 * \return Retorna 1 (verdadero) si la cadena es num�rica y 0 (falso) si no lo es.
 */
static int esCaracter(char *cadena,int limite);

/**
 * \brief Obtiene un nombre desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \param longitud Define el tama�o de cadena.
 * \return Retorna 0 (�XITO) si se obtiene un nombre y -1 (ERROR) si no.
 *
 */
static int getNombre(char *pResultado, int longitud);

/**
 * \brief Verifica si la cadena ingresada es un array de caracteres(nombre).
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tama�o de cadena.
 * \return Retorna 1 (verdadero) si la cadena es alfabetica y 0 (falso) si no lo es.
 *
 */
static int esNombre(char *cadena,int limite);

/**
 * \brief Recibe una cadena de caracteres y convierte el primero en may�scula,
 * 		  y los restantes en min�sculas.
 * \param cadena Cadena a ser acomodada.
 * \return Retorna 0 (�XITO) si se acomoda la cadena, y 1 (ERROR) si no.
 */
static int acomodarNombre(char *cadena);

/**
 * \brief Obtiene una fecha desde la terminal.
 * \param pResultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \param longitud Define el tama�o de cadena.
 * \return Retorna 0 (�XITO) si se obtiene un nombre y -1 (ERROR) si no.
 */
static int getFecha(char *pResultado, int longitud);

/**
 * \brief Verifica si la cadena ingresada concuerda con el formato "fecha".
 * \param cadena Cadena de caracteres a ser analizada.
 * \param limite Define el tama�o de cadena.
 * \return Retorna 1 (verdadero) si la cadena es una fecha y 0 (falso) si no lo es.
 */
static int esFecha(char *cadena, int limite);

int utn_getNumero(int *resultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(resultado != NULL &&
	   mensaje != NULL &&
	   mensajeError != NULL &&
	   minimo <= maximo &&
	   reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getInt(&bufferInt) == 0 &&
			   bufferInt >= minimo &&
			   bufferInt <= maximo)
			{
				*resultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

int utn_getNumeroFlotante(float *resultado,char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int retorno;

	if(resultado != NULL &&
	   mensaje != NULL &&
	   mensajeError != NULL &&
	   minimo <= maximo &&
	   reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0 &&
			   bufferFloat >= minimo &&
			   bufferFloat <= maximo)
			{
				*resultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

int utn_getCaracter(char *pResultado,char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos)
{
	char bufferChar;
	int retorno = -1;

	if(pResultado != NULL &&
	   mensaje != NULL &&
	   mensajeError != NULL &&
	   minimo > 0 &&
	   maximo > 0 &&
	   reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getCaracter(&bufferChar) == 0 &&
			  (bufferChar == minimo ||
			   bufferChar == maximo))
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}

int utn_getNombre(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos)
{
	char bufferString[256];
	int retorno = -1;

	do
	{
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos --;
		}
	}while(reintentos >= 0);

	return retorno;
}

int utn_getFecha(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos)
{
	char bufferString[256];
	int retorno = -1;

	do
	{
		printf("%s",mensaje);
		if(getFecha(bufferString,sizeof(bufferString)) == 0)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			reintentos --;
		}
	}while(reintentos >= 0);

	return retorno;
}

static int getString(char *cadena,int longitud)
{
	int retorno = -1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL &&
		   bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
		{
			bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}

static int getInt(int *pResultado)
{
	int retorno = -1;
	char bufferString[64];

	if(pResultado != NULL &&
	   getString(bufferString,sizeof(bufferString)) == 0 &&
	   esNumerica(bufferString,sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno = 0;
	}

	return retorno;
}

static int esNumerica(char *cadena,int limite)
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

static int getFloat(float *pResultado)
{
	int retorno = -1;
	char buffer[128];

	if(pResultado != NULL &&
	   getString(buffer,sizeof(buffer)) == 0 &&
	   esFloat(buffer,sizeof(buffer)))
	{
		*pResultado = atof(buffer);
		retorno = 0;
	}

	return retorno;
}

static int esFloat(char *cadena, int limite)
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

static int getCaracter(char *pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
	   getString(bufferString,sizeof(bufferString)) == 0 &&
	   esCaracter(bufferString,sizeof(bufferString)))
	{
		*pResultado = bufferString[0];
		retorno = 0;
	}

	return retorno;
}

static int esCaracter(char *cadena,int limite)
{
	int retorno = 1;
	int i;

	for(i = 0;i < limite && cadena[i] != '\0';i ++)
	{
		if((cadena[i] < 'a' || cadena[i] > 'z') &&
		   (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

static int getNombre(char *pResultado, int longitud)
{
	int retorno = -1;
	char buffer[256];

	if(pResultado != NULL &&
	   getString(buffer,sizeof(buffer)) == 0 &&
	   esNombre(buffer,sizeof(buffer)) &&
	   acomodarNombre(buffer) == 0 &&
	   strnlen(buffer,sizeof(buffer)) < longitud)
	{
		strncpy(pResultado,buffer,longitud);
		retorno = 0;
	}

	return retorno;
}

static int esNombre(char *cadena,int limite)
{
	int retorno = 1;
	int i ;

	for (i = 0; i <= limite && cadena[i] != '\0'; i ++)
	{
		if((cadena[i] < 'a' || cadena[i] > 'z') &&
		   (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

static int acomodarNombre(char *cadena)
{
	int retorno = -1;

	while(*cadena != '\0')
	{
		while(!isalpha(*cadena) && (*cadena != '\0'))
		{
			cadena ++;
		}

		if(isalpha(*cadena) && *cadena >= 'A')
		{
			*cadena = toupper(*cadena);
			cadena ++;
		}
		while(isalpha(*cadena))
		{
			*cadena = tolower(*cadena);
			cadena ++;
		}

		retorno = 0;
	}

	return retorno;
}

static int getFecha(char *pResultado, int longitud)
{
	int retorno = -1;
	char buffer[256];

	if(pResultado != NULL &&
	   getString(buffer,sizeof(buffer)) == 0 &&
	   esFecha(buffer,sizeof(buffer)) &&
	   strnlen(buffer,sizeof(buffer)) < longitud)
	{
		strncpy(pResultado,buffer,longitud);
		retorno = 0;
	}

	return retorno;
}

static int esFecha(char *cadena, int limite)
{
	int retorno = 1;
	int i;

	for(i = 0; cadena[i] != '\0' ; i ++)
	{
		if((cadena[0] < '0' || cadena[0] > '3') &&
		   (cadena[1] < '0' || cadena[1] > '9') &&
		   (cadena[2] != '/') &&
		   (cadena[3] < '0' || cadena[3] > '1') &&
		   (cadena[4] < '0' || cadena[4] > '2') &&
		   (cadena[5] != '/') && (cadena[6] != '2') &&
		   (cadena[7] < '0' || cadena[7] > '9') &&
		   (cadena[8] < '0' || cadena[8] > '9') &&
		   (cadena[9] < '0' || cadena[9] > '9'))
		{
			retorno = 0;
			break;
		}

		return retorno;
	}

	return retorno;
}

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
    //strlwr(string);
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

int utn_getPalabra(char palabra[], char message[])
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
        printf("1. ALTA TRABAJO.\n");
        printf("2. MODIFICAR TRABAJO.\n");
        printf("3. BAJA TRABAJO.\n");
        printf("4. LISTAR TRABAJOS.\n");
        printf("5. LISTAR SERVICIOS.\n");
        printf("6. TOTAL DE LOS SERVICIOS PRESTADOS.\n");
        printf("7. LISTADO DE TRABAJOS ORDENADOS POR NOMBRE DE LA MASCOTA.\n");
        printf("8. EL o LOS SERVICIOS CON MAS TRABAJOS REALIZADOS.\n");
        printf("9. LISTADO DE SERVICIOS CON LOS NOMBRES DE LAS MASCOTAS QUE LO REALIZARON.\n");
        printf("10. PROMEDIO DE EDADES DE LAS MASCOTAS QUE REALIZARON UN SERVICIO ELEGIDO POR EL USUARIO.\n");
        printf("12. LISTADO DE SERVICIOS CON LOS NOMBRES DE LAS MASCOTAS Y VETERINARIOS.\n");
        printf("11. LISTAR VETERINARIOS.\n");
        printf("13. SALIR.\n");

}
