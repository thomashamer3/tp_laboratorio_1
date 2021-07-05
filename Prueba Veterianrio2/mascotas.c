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

int HardcodearMascota(eMascota mascota[], int tam)
{
    int i;
    int id[] = {15, 16, 17, 18, 19};
    char nombreMascota[][25] = {"Coco", "Percy", "Bob", "Ares", "Fidel"};
    int edad[] = {4, 5, 12, 1, 2};
    char raza[][25] = {"Caniche", "Labrador", "Bulldog", "Boxer", "Pitbull"};
    for (i = 0; i < tam; i++)
    {
        mascota[i].id = id[i];
        strcpy(mascota[i].nombreMascota, nombreMascota[i]);
        strcpy(mascota[i].raza, raza[i]);
        mascota[i].edad = edad[i];
        mascota[i].isEmpty = OCUPADO;
    }

    return 0;
}

int MostrarMascota(eMascota mascota)
{
    int retorno;
    retorno = 0;
    if (mascota.isEmpty == OCUPADO)
    {
        printf("%d %10s %22d %12s\n", mascota.id, mascota.nombreMascota, mascota.edad, mascota.raza);
        retorno = 1;
    }

    return retorno;
}

int DetectarMascotas(eMascota mascota[], int tam)
{
    int i;
    int retorno;
    retorno = 0;
    for (i = 0; i < tam; i++)
    {
        if (mascota[i].isEmpty == OCUPADO)
        {
            retorno = 1;
        }
    }

    return retorno;
}

void ObtenerMascotas(eMascota mascota[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        MostrarMascota(mascota[i]);
    }
}

int MostrarMascotas(eMascota mascota[], int tam)
{
    int retorno;
    retorno = DetectarMascotas(mascota, tam);
    if (retorno != 0)
    {
        printf("|ID    \t|NOMBRE MASCOTA    \t|EDAD    |RAZA    |\n");
        ObtenerMascotas(mascota, tam);
    }
    else
    {
        printf("No hay Mascotas Cargadas...\n");
    }

    return retorno;
}

int OrdenarMascotas(eMascota mascota[], int mascotasTam)
{
    int i;
    int j;
    eMascota aux;
    for (i = 0; i < mascotasTam - 1; i++)
    {
        for (j = i + 1; j < mascotasTam; j++)
        {
            if (strcmp(mascota[i].nombreMascota, mascota[j].nombreMascota) > 0)
            {
                aux = mascota[i];
                mascota[i] = mascota[j];
                mascota[j] = aux;
            }
        }
    }

    return 0;
}

eMascota ObtenerMascotaPorID (eMascota mascota[], int idABuscar,int tam)
{
    int indice;
    indice = -1;

    for(int i = 0; i < tam; i++)
    {
        if(idABuscar == mascota[i].id)
        {
            indice = i;
        }
    }

    return mascota[indice];
}


