#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"
#include "servicios.h"
#include "trabajo.h"
#include "mascotas.h"
#include "trabajoYservicio.h"
#include "trabajoYservicioYmascota.h"

#define VACIO 0
#define OCUPADO 1

int ObtenerCantidadServicio(eTrabajo trabajos[], eServicio servicio, int tam)
{
    int contador;

    contador = 0;

    for(int i = 0; i<tam; i++)
    {
        if(trabajos[i].idServicio == servicio.id && servicio.isEmpty != VACIO)
        {
            contador++;
        }
    }

    return contador;
}

int ObtenerPrecioServicio(eTrabajo trabajos[], eServicio servicio, int tam)
{
    int precioServicio;
    int cantidadServicio;

    cantidadServicio = ObtenerCantidadServicio(trabajos, servicio, tam);

    precioServicio = cantidadServicio * servicio.precio;

    return precioServicio;
}

void InicializarContador(int contador[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        contador[i] = 0;
    }
}

void CantidadServicioMasRealizado(eTrabajo trabajos[], eServicio servicios[], int tam, int sTam)
{
    int contador[sTam];
    int contadorMaximo;

    InicializarContador(contador, sTam);
    contadorMaximo = 0;


    for(int i = 0; i<sTam; i++)
    {
       contador[i] = ObtenerCantidadServicio(trabajos, servicios[i], tam);
    }

    for (int i = 0; i < sTam; i++)
    {
        if (contador[i] > contadorMaximo || i == 0)
        {
            contadorMaximo = contador[i];
        }
    }

    printf("|ID  \t\t|DESCRICION   \t|PRECIO \n");
    for(int i = 0; i<sTam; i++)
    {
        if(contador[i] == contadorMaximo)
        {
            MostrarServicio(servicios[i]);
        }
    }
}

int CorroborarFkConPk(eTrabajo trabajos, eServicio servicios, int precio)
{
    if (trabajos.idServicio == servicios.id)
    {
        precio += servicios.precio;
    }

    return precio;
}

int ObtenerPrecios(eTrabajo trabajos[], eServicio servicio[], int serviciosTam, int trabajosTam)
{
    int precio;
    int i;
    int j;
    precio = 0;
    for (i = 0; i < trabajosTam; i++)
    {
        for (j = 0; j < serviciosTam; j++)
        {
            precio = CorroborarFkConPk(trabajos[i], servicio[j], precio);
        }
    }
    return precio;
}

int MostrarPrecioTotal(eTrabajo trabajos[], eServicio servicio[], int serviciosTam, int trabajosTam)
{
    int precioTotal;
    precioTotal = ObtenerPrecios(trabajos, servicio, serviciosTam, trabajosTam);
    return precioTotal;
}

int ObtenerDescripcionDeServicio(eTrabajo trabajos[], eServicio servicio[], int index, int serviciosTam)
{
    int i;
    int id;
    for (i = 0; i < serviciosTam; i++)
    {
        if (trabajos[index].idServicio == servicio[i].id)
        {
            id = i;
        }
    }

    return id;
}
