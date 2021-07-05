#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
    int isEmpty;
} eServicio;

/**
 * HardcodearServicios permite guardar datos hardcodeados en la estructura de servicios
 * @param eServicio permite guardar datos en la estructura de servicios
 * @param int es el tamaño del array
 * */
void HardcodearServicios(eServicio[], int);
/**
 * DetectarServicios, detecta si existen servicios cargados o no
 * @param eServicio[] obtiene el array de los servicios
 * @param int el tamaño del array
 * */
int DetectarServicios(eServicio[], int);
/**
 * ObtenerServicios, Obtiene todos los elementos cargados en el array
 * @param eServicio[] obtiene el array de los servicios
 * @param int el tamaño del array
 * */
void ObtenerServicios(eServicio[], int);
/**
 * MostrarServicio permite mostrar un dato de la estructura servicios
 * @param sServicio obtiene los datos de la estructura
 * @param int es el tamaño del array
 * */
int MostrarServicio(eServicio);
/**
 * MostrarServicios permite mostrar los datos de la estructura servicios verificando que existan datos cargados
 * @param eServicio obtiene los datos de la estructura
 * @param int es el tamaño del array
 * */
int MostrarServicios(eServicio [], int);


#endif // SERVICIOS_H_INCLUDED
