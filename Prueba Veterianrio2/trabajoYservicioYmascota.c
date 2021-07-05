#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fechas.h"
#include "input.h"
#include "mascotas.h"
#include "servicios.h"
#include "trabajo.h"
#include "trabajoYmascota.h"
#include "trabajoYservicio.h"
#include "trabajoYservicioYmascota.h"
#include "duenio.h"

#define VACIO 0
#define OCUPADO 1

int crearId()
{
    static int id=0;
    id++;
    return id;
}

int ListadoDeTrabajos(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[], int trabajoTam, int servicioTam, int mascotasTam)
{
    int retorno;
    retorno = DetectarTrabajo(trabajos, trabajoTam);
    if (retorno != 0)
    {
        OrdenarMascotas(mascota, mascotasTam);
        ObtenerTrabajos(trabajos, servicio, mascota,trabajoTam, servicioTam, mascotasTam);
    }
    else
    {
        printf("No se cargaron datos aun...\n");
    }

    return retorno;
}

eTrabajo CargarTrabajo(eServicio servicio[], eTrabajo trabajos[], eMascota mascota[], int serviciosTam, int trabajoTam, int mascotasTam)
{
    eTrabajo Auxtrabajos;

    Auxtrabajos.id = crearId();
    printf("ID TRABAJO: %d\n", Auxtrabajos.id);

    MostrarMascotas(mascota, mascotasTam);
    utn_getNumero(&Auxtrabajos.idMascota,"\nIngrese el Id de la Mascota: ","Error Ingrese un Id Valido.",15,19,3);

    MostrarServicios(servicio, serviciosTam);
    utn_getNumero(&Auxtrabajos.idServicio,"\nIngrese el Servicio para la Mascota: ","\nIngrese Un Id Valido.",20000,20002,3);

    Auxtrabajos.fecha=CargarFecha();
    Auxtrabajos.isEmpty = OCUPADO;

    return Auxtrabajos;
}

int AltaTrabajo(eTrabajo trabajos[], eServicio servicio[], eMascota mascota[], int serviciosTam, int trabajoTam, int mascotasTam)
{
    int index;

    index = BuscarLibre(trabajos, trabajoTam);

    if (index == -1)
    {
        printf("No hay espacio disponible para Cargar un Trabajo...\n");
    }
    else
    {
        trabajos[index] = CargarTrabajo(servicio, trabajos, mascota, serviciosTam, trabajoTam, mascotasTam);
    }

    return 0;
}

void ImprimirMensaje(eTrabajo trabajos, eServicio servicios, eMascota mascota)
{
    printf("%5d %15s %d/%d/%d %20s %10.2f\n", trabajos.id, mascota.nombreMascota,
           trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio,
           servicios.descripcion, servicios.precio);
}

void ObtenerTrabajos(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[], int trabajoTam, int servicioTam, int mascotasTam)
{
    int i;
    for (i = 0; i < trabajoTam; i++)
    {
        if (trabajos[i].isEmpty != VACIO)
        {
            MostrarUnTrabajo(trabajos, servicio, mascota, i, trabajoTam, servicioTam, mascotasTam);
        }
    }
}

void MostrarUnTrabajo(eTrabajo trabajos[], eServicio servicio[], eMascota mascota[], int index, int trabajosTam, int serviciosTam, int masctoasTam)
{
    int idServicio;
    int idMascota;

    idMascota = ObtenerDescripcionDeMascota(trabajos, mascota, index, masctoasTam);
    idServicio = ObtenerDescripcionDeServicio(trabajos, servicio, index, serviciosTam);
    ImprimirMensaje(trabajos[index], servicio[idServicio], mascota[idMascota]);
}

int MostrarTrabajos(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[], int trabajoTam, int servicioTam, int mascotasTam)
{
    int retorno;
    retorno = DetectarTrabajo(trabajos, trabajoTam);
    if (retorno != 0)
    {
        OrdenarTrabajos(trabajos, mascota, trabajoTam, mascotasTam);
        printf("|ID    \t\t|NOMBRE|EDAD    \t|SERVICIO   |PRECIO    \n");
        ObtenerTrabajos(trabajos, servicio, mascota, trabajoTam, servicioTam, mascotasTam);
    }
    else
    {
        printf("No se cargaron datos aun...\n");
    }

    return retorno;
}

int BajaTrabajo(eTrabajo trabajos[], eServicio servicio[], eMascota mascota[], int serviciosTam, int trabajosTam, int mascotasTam)
{
    int retorno;
    int id;
    retorno = MostrarTrabajos(trabajos, servicio, mascota, trabajosTam, serviciosTam, mascotasTam);
    if (retorno != 0)
    {
        id = DarDeBaja(trabajos, trabajosTam);
    }
    return id;
}

eTrabajo OpcionModificarTrabajo(eTrabajo trabajos, eServicio servicio[], eMascota mascota[], int serviciosTam, int mascotasTam, int index)
{
    int opcion;

    utn_getNumero(&opcion,"\nQue desea Modificar del Trabajo? 1 (Nombre de la mascota) o 2 (Servicio): ","Ingrese 1(Nombre de la mascota) o 2(Servicio).",1,2,3);
    if (opcion == 1)
    {
        MostrarMascotas(mascota, mascotasTam);
        utn_getNumero(&trabajos.idMascota,"\nIngrese la Nueva Mascota: ","Ingrese un Id Valido.",15,19,3);
    }
    else
    {
        MostrarServicios(servicio, serviciosTam);
        utn_getNumero(&trabajos.idServicio,"\nIngrese el nuevo Servicio para la Mascota: ","Ingrese un Id Valido.",20000,20002,3);
    }

    return trabajos;
}

int HacerModificacion(eTrabajo trabajos[], int trabajosTam, eServicio servicio[], int serviciosTam, eMascota mascota[], int mascotasTam)
{
    int id;
	int idMascota;
	id = BuscarTrabajo(trabajos, trabajosTam);
	if (id != -1)
	{
		idMascota = ObtenerDescripcionDeMascota(trabajos, mascota, id, mascotasTam);
		trabajos[id] = OpcionModificarTrabajo(trabajos[id], servicio, mascota, serviciosTam, mascotasTam, idMascota);
	}
	else
	{
		printf("No se encontro la id\n");
	}
	return id;
}

int ModificarTrabajo(eTrabajo trabajos[], eServicio servicio[], eMascota mascota[], int serviciosTam, int trabajosTam, int mascotasTam)
{
    int status;
	int id;
	status = MostrarTrabajos(trabajos, servicio, mascota, trabajosTam, serviciosTam, mascotasTam);
	if (status != 0)
	{
		id = HacerModificacion(trabajos, trabajosTam, servicio, serviciosTam, mascota, mascotasTam);
	}

	return id;
}

void MostrarServiciosConNombre(eServicio servicio[], eTrabajo trabajo[], eMascota mascotas[],int tam, int sTam)
{
    eMascota mascota;
    int idMascota;

    printf("-------LISTADO de SERVICIOS con Nombre De La MASCOTA-------\n");
	for (int i = 0; i < sTam; i++)
	{
	    if(servicio[i].isEmpty == OCUPADO)
	    {
	        printf("\nMASCOTAS SERVICIO: %s \n", servicio[i].descripcion);

	        for(int j = 0; j<tam; j++)
	        {
	           idMascota = MascotasQueRealizaronServicio(trabajo[j], mascotas, servicio[i], tam);
	           mascota = ObtenerMascotaPorID(mascotas, idMascota, tam);

	           if(trabajo[j].isEmpty != VACIO && idMascota != -1)
	           {
	                printf("\nNOMBRE: %s \n", mascota.nombreMascota);
	           }
	        }
	    }
	}
}

int MascotasQueRealizaronServicio(eTrabajo trabajo, eMascota mascotas[], eServicio servicio, int tam)
{
    int idMascota;
    idMascota = -1;
    for (int i = 0; i<tam; i++)
    {
        if(trabajo.idServicio == servicio.id && trabajo.isEmpty != VACIO)
        {
           idMascota = trabajo.idMascota;
        }
    }
    return idMascota;
}

void MostrarServiciosConNombreYveterinario(eServicio servicio[], eTrabajo trabajo[], eMascota mascotas[], eVeterinario veterinario[], int tam, int sTam)
{
    eMascota mascota;
    int idMascota;

    printf("-------LISTADO de SERVICIOS CON NOMBRE DE LA MASCOTA Y VETERINARIO-------\n");
	for (int i = 0; i < sTam; i++)
	{
	    if(servicio[i].isEmpty == OCUPADO && veterinario[i].isEmpty== OCUPADO)
	    {
	        printf("\nMASCOTAS SERVICIO: %s \n", servicio[i].descripcion);
            printf("\nMASCOTAS VETERINARIO: %s \n", veterinario[i].nombreVeterinario);

	        for(int j = 0; j<tam; j++)
	        {
	           idMascota = MascotasQueRealizaronServicio(trabajo[j], mascotas, servicio[i], tam);
	           mascota = ObtenerMascotaPorID(mascotas, idMascota, tam);

	           if(trabajo[j].isEmpty != VACIO && idMascota != -1)
	           {
	                printf("\nNOMBRE: %s \n", mascota.nombreMascota);
	           }
	        }
	    }
	}
}
