#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "fechas.h"

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    int idVeterinario;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

/**
 * InicializarTrabajo, inicializa el isEmpty en 0 para saber si estan o no estan ocupados
 * @param eTrabajo obtiene los datos de la estructura eTrabajo
 * @param int el tamaño del array
 * */
void InicializarTrabajo(eTrabajo[], int);

/**
 * BuscarLibre, busca un espacio libre para poder ingresar datos o no dependiendo si existe el espacio o no
 * @param eTrabajo obtiene los datos de la estructura eTrabajo
 * @param int el tamaño del array
 * */
int BuscarLibre(eTrabajo[], int);

/**
 * BuscarTrabajo, busca un Trabajo por la id del mismo y devuelve el index, en caso de no encontrarlo devuelve -1
 * @param eTrabajo[], array de la estructura trabajos
 * @param int, el tamaño de la estructura trabajos
 * */
int BuscarTrabajo(eTrabajo[], int);

/**
 * OrdenPorAnio, ordena el array filtrando por año
 * @param eTrabajo[] obtiene el array de los trabajos
 * @param int, obtiene el contador i del for
 * @param int, obtiene el contador j del for
 * */
int OrdenPorAnio(eTrabajo[], int, int);

/**
 * DetectarTrabajo, detecta si existen trabajos cargados o no, retorna un status en 1 o 0 dependiendo el caso
 * @param eTrabajo[] array de la estructura de trabajo
 * @param int tamaño del array
 * */
int DetectarTrabajo(eTrabajo[], int);

/**
 * OpcionBajaTrabajo, controla la eliminacion del trabajo
 * eTrabajo, obtiene la estructura de trabajo
 * */
eTrabajo OpcionBajaTrabajo(eTrabajo);
/**
 * DarDeBaja, busca el Trabajo para ser eliminado
 * @param eTrabajo[], obtiene la estructura de trabajo
 * @param int, el tamaño del array
 * */
int DarDeBaja(eTrabajo[], int);



#endif // TRABAJO_H_INCLUDED
