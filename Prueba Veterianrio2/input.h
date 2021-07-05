#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/**
 * \brief Solicita un n�mero al usuario, luego de verificarlo devuelve el resultado.
 * \param resultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es el n�mero m�nimo a ser aceptado.
 * \param maximo Es el n�mero m�ximo a ser aceptado.
 * \return Retorna 0 si se obtuvo el n�mero y -1 si no.
 *
 */
int utn_getNumero(int *resultado,char *mensaje,char *mensajeError,int minimo,int maximo,int reintentos);

/**
 * \brief Solicita un n�mero float al usuario, luego de verificarlo devuelve el resultado.
 * \param resultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es el n�mero m�nimo a ser aceptado.
 * \param maximo Es el n�mero m�ximo a ser aceptado.
 * \return Retorna 0 si se obtuvo el n�mero y -1 si no.
 *
 */
int utn_getNumeroFlotante(float *resultado,char *mensaje,char *mensajeError,float minimo,float maximo,int reintentos);

/**
 * \brief Solicita un caracter al usuario, luego de verificarlo devuelve el resultado.
 * \param resultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param minimo Es uno de los caracteres a ser aceptado.
 * \param maximo Es el otro caracter a ser aceptado.
 * \return Retorna 0 si se obtuvo el caracter y -1 si no.
 *
 */
int utn_getCaracter(char *resultado,char *mensaje,char *mensajeError,char minimo,char maximo,int reintentos);

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \param longitud Define el tama�o de cadena.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError Es el mensaje de error a ser mostrado.
 * \param reintentos Recibe la cantidad de reintentos que habr� para ingresar el dato correcto en caso de error.
 * \return Retorna 0 si se obtuvo el n�mero y -1 si no.
 */
int utn_getNombre(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos);

/**
 * \brief Solicita una fecha en formato (dd/mm/aaaa) al usuario, verifica el string y devuelve el resultado.
 * \param pResultado Puntero al espacio de memoria donde se dejar� el resultado de la funci�n.
 * \param longitud Define el tama�o de cadena.
 * \param mensaje Es el mensaje a ser mostrado.
 * \param mensajeError mensajeError Es el mensaje de error a ser mostrado.
 * \param reintentos Recibe la cantidad de reintentos que habr� para ingresar el dato correcto en caso de error.
 * \return Retorna 0 si se obtuvo el n�mero y -1 si no.
 */
int utn_getFecha(char* pResultado,int longitud,char* mensaje,char* mensajeError,int reintentos);

int utn_verificacion(int valor,char* mensaje,char* mensajeError);

int normalizeAndCapitalize(char string[]);

int utn_getPalabra(char palabra[], char message[]);

void Menu();

#endif // INPUT_H_INCLUDED
