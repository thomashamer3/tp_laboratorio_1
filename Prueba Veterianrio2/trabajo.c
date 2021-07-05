#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fechas.h"
#include "input.h"
#include "mascotas.h"
#include "servicios.h"
#include "trabajo.h"

#define VACIO 0
#define OCUPADO 1


void InicializarTrabajo(eTrabajo trabajos[], int tam)
{
    int i;
    for (i = 0; i <= tam; i++)
    {
        trabajos[i].isEmpty = VACIO;
    }
}

int BuscarLibre(eTrabajo trabajos[], int tam)
{
    int i;
    int index;
    index = -1;
    for (i = 0; i < tam; i++)
    {
        if (trabajos[i].isEmpty == VACIO)
        {
            index = i;
            break;
        }
    }
    return index;
}


int DetectarTrabajo(eTrabajo trabajos[], int trabajoTam)
{
    int i;
    int retorno;

    retorno = 0;
    for (i = 0; i < trabajoTam; i++)
    {
        if (trabajos[i].isEmpty != VACIO)
        {
            retorno = 1;
        }
    }

    return retorno;
}



///////////// BUSCAR

int BuscarTrabajo(eTrabajo trabajos[], int tam)
{
    int i;
    int id;
    int find;
    find = -1;

    utn_getNumero(&id,"\nIngrese la Id del Trabajo: ","\nIngrese una Id Valida.",1,1000,3);

    for (i = 0; i < tam; i++)
    {
        if (id == trabajos[i].id && trabajos[i].isEmpty != VACIO)
        {
            find = i;
            break;
        }
    }

    return find;
}


//////////////// BAJA TRABAJOS

eTrabajo OpcionBajaTrabajo(eTrabajo trabajos)
{
    char opcion;
    utn_getCaracter(&opcion,"\nDesea Dar de Baja este Trabajo? S/N: ","\nIngrese S o N: ",'S','N',3);
    if (opcion == 'S')
    {
        trabajos.isEmpty = VACIO;
    }
    else
    {
        printf("Cancelado.\n");
    }

    return trabajos;
}

int DarDeBaja(eTrabajo trabajos[], int trabajosTam)
{
    int id;
    id = BuscarTrabajo(trabajos, trabajosTam);
    if (id != -1)
    {
        trabajos[id] = OpcionBajaTrabajo(trabajos[id]);
    }
    else
    {
        printf("No se encontro la id\n");
    }

    return id;
}


///////////// Ordenar

int OrdenPorAnio(eTrabajo trabajos[], int i, int j)
{
    eTrabajo auxTrabajos;
    if (trabajos[i].fecha.anio > trabajos[j].fecha.anio)
    {
        auxTrabajos = trabajos[i];
        trabajos[i] = trabajos[j];
        trabajos[j] = auxTrabajos;
    }
    return 0;
}


