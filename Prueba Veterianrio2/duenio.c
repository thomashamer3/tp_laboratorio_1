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
#include "duenio.h" //ES VETERINARIO.C

#define VACIO 0
#define OCUPADO 1


void HardcodearVeterinario(eVeterinario veterinario[], int tam)
{
    int i;
    int id[] = {20000, 20001, 20002};
    char nombreVeterinario[][51] = {"Dr.Lopez", "Dra.Caneda", "Dr.Rodriguez"};

    for (i = 0; i < tam; i++)
    {
        veterinario[i].id = id[i];
        strcpy(veterinario[i].nombreVeterinario, nombreVeterinario[i]);
        veterinario[i].isEmpty = OCUPADO;
    }
}

int MostrarUnVeterinarioConServicio(eVeterinario veterinario,eServicio servicio)
{
    int retorno;
    retorno = 0;
    printf("|ID      |NOMBRE VETERINARIO   SERVICIO |\n");
    if (veterinario.isEmpty == OCUPADO && servicio.isEmpty== OCUPADO && servicio.id == veterinario.id)
    {
        printf("%d %10s %10s\n", veterinario.id, veterinario.nombreVeterinario, servicio.descripcion);
        retorno = 1;
    }

    return retorno;
}

void ObtenerVeterinariosConServicios(eVeterinario veterinario[], eServicio servicio[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        MostrarUnVeterinarioConServicio(veterinario[i],servicio[i]);
    }
}

int MostrarUnVeterinario(eVeterinario veterinario)
{
    int retorno;
    retorno = 0;
    if (veterinario.isEmpty == OCUPADO)
    {
        printf("%d %20s\n", veterinario.id, veterinario.nombreVeterinario);
        retorno = 1;
    }

    return retorno;
}

int DetectarVeterinarios(eVeterinario veterinario[], int tam)
{
    int i;
    int retorno;
    retorno = 0;
    for (i = 0; i < tam; i++)
    {
        if (veterinario[i].isEmpty == OCUPADO)
        {
            retorno = 1;
        }
    }

    return retorno;
}

void ObtenerVeterinarios(eVeterinario veterinario[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        MostrarUnVeterinario(veterinario[i]);
    }
}

int MostrarVeterinarios(eVeterinario veterinario[], int tam)
{
    int retorno;
    retorno = DetectarVeterinarios(veterinario, tam);
    if (retorno != 0)
    {
        printf("|ID      |NOMBRE VETERINARIO    |\n");
        ObtenerVeterinarios(veterinario, tam);
    }
    else
    {
        printf("No hay Servicios Cargados...\n");
    }

    return retorno;
}

int ListadoDeTrabajosTotales(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[],eVeterinario veterinario[],int trabajoTam, int servicioTam, int mascotasTam, int vetTam)
{
    int retorno;
    retorno = DetectarTrabajo(trabajos, trabajoTam);
    if (retorno != 0)
    {
        OrdenarMascotas(mascota, mascotasTam);
        ObtenerTrabajos(trabajos, servicio, mascota, trabajoTam, servicioTam, mascotasTam);
    }
    else
    {
        printf("No se cargaron datos aun...\n");
    }

    return retorno;
}

int ObtenerDescripcionDeVeterinario(eTrabajo trabajos[], eVeterinario veterinario[], int index, int vetTam)
{
    int i;
    int id;
    for (i = 0; i < vetTam; i++)
    {
        if (trabajos[index].idServicio == veterinario[i].id)
        {
            id = i;
        }
    }

    return id;
}


void ImprimirMensajeVet(eTrabajo trabajos, eServicio servicios, eMascota mascota,eVeterinario veterinario)
{
    printf("%5d %15s %d/%d/%d %20s %10.2f %20s\n", trabajos.id, mascota.nombreMascota,
           trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio,
           servicios.descripcion, servicios.precio,veterinario.nombreVeterinario);
}

void MostrarUnTrabajoConVet(eTrabajo trabajos[], eServicio servicio[], eMascota mascota[],eVeterinario veterinario[], int index, int trabajosTam, int serviciosTam, int masctoasTam,int vetTam)
{
    int idServicio;
    int idMascota;
    int idVeterinario;

    idMascota = ObtenerDescripcionDeMascota(trabajos, mascota, index, masctoasTam);
    idVeterinario= ObtenerDescripcionDeVeterinario(trabajos,veterinario,index,vetTam);
    idServicio = ObtenerDescripcionDeServicio(trabajos, servicio, index, serviciosTam);

    ImprimirMensajeVet(trabajos[index], servicio[idServicio], mascota[idMascota],veterinario[idVeterinario]);
}

void ObtenerTrabajosVet(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[], eVeterinario veterinario[], int trabajoTam, int servicioTam, int mascotasTam, int vetTam)
{
    int i;
    for (i = 0; i < trabajoTam; i++)
    {
        if (trabajos[i].isEmpty != VACIO)
        {
            MostrarUnTrabajoConVet(trabajos, servicio, mascota, veterinario, i, trabajoTam, servicioTam, mascotasTam,vetTam);
        }
    }
}

int ListadoDeTrabajosVet(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[],eVeterinario veterinario[], int trabajoTam, int servicioTam, int mascotasTam, int vetTam)
{
    int retorno;
    retorno = DetectarTrabajo(trabajos, trabajoTam);
    if (retorno != 0)
    {
        OrdenarMascotas(mascota, mascotasTam);
        printf("|ID    \t\t|NOMBRE|EDAD    \t|SERVICIO   |PRECIO        |NOMBRE VETERINARIO \n");
        ObtenerTrabajosVet(trabajos, servicio, mascota,veterinario ,trabajoTam, servicioTam, mascotasTam , vetTam);
    }
    else
    {
        printf("No se cargaron datos aun...\n");
    }

    return retorno;
}

