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


void HardcodearServicios(eServicio servicio[], int tam)
{
    int i;
    int id[] = {20000, 20001, 20002};
    char descripcion[][25] = {"Corte", "Desparasitado", "Castrado"};
    float precio[] = {250, 300, 400};

    for (i = 0; i < tam; i++)
    {
        servicio[i].id = id[i];
        strcpy(servicio[i].descripcion, descripcion[i]);
        servicio[i].precio = precio[i];
        servicio[i].isEmpty = OCUPADO;
    }
}

int MostrarServicio(eServicio servicios)
{
    int retorno;
    retorno = 0;
    if (servicios.isEmpty == OCUPADO)
    {
        printf("%d %15s %15.1f\n", servicios.id, servicios.descripcion, servicios.precio);
        retorno = 1;
    }

    return retorno;
}

int DetectarServicios(eServicio servicio[], int tam)
{
    int i;
    int retorno;
    retorno = 0;
    for (i = 0; i < tam; i++)
    {
        if (servicio[i].isEmpty == OCUPADO)
        {
            retorno = 1;
        }
    }

    return retorno;
}

void ObtenerServicios(eServicio servicio[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        MostrarServicio(servicio[i]);
    }
}

int MostrarServicios(eServicio servicio[], int tam)
{
    int retorno;
    retorno = DetectarServicios(servicio, tam);
    if (retorno != 0)
    {
        printf("|ID         |DESCRIPCION      |PRECIO    |\n");
        ObtenerServicios(servicio, tam);
    }
    else
    {
        printf("No hay Servicios Cargados...\n");
    }

    return retorno;
}


