#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"
#include "mascotas.h"
#include "trabajo.h"

int ObtenerDescripcionDeMascota(eTrabajo trabajos[], eMascota mascota[], int index, int mascotasTam)
{
    int i;
    int id;
    for (i = 0; i < mascotasTam; i++)
    {
        if (trabajos[index].idMascota == mascota[i].id)
        {
            id = i;
        }
    }

    return id;
}

int CasoIgualdad(eTrabajo trabajos[], eMascota mascota[], int i, int j, int mascotasTam)
{
    if (trabajos[i].fecha.anio == trabajos[j].fecha.anio)
    {
        OrdenarMascotas(mascota, mascotasTam);
    }
    return 0;
}

int OrdenarTrabajos(eTrabajo trabajos[], eMascota mascota[], int trabajosTam, int mascotasTam)
{
    int i;
    int j;
    for (i = 0; i < trabajosTam - 1; i++)
    {
        for (j = i + 1; j < trabajosTam; j++)
        {
            OrdenPorAnio(trabajos, i, j);
            CasoIgualdad(trabajos, mascota, i, j, mascotasTam);
        }
    }

    return 0;
}



