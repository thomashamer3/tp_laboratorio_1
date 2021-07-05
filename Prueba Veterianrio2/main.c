/*============================================================================
Thomas Hamer
1°C
Turno Mañana
Recuperatorio 1 Parcial Lab
============================================================================*/

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

#define TamanioServicios 3
#define TamanioTrabajo 12
#define TamanioMascota 5

int main(void)
{
    int total;
    int opcion;

    eServicio servicio[TamanioServicios];
    eTrabajo trabajos[TamanioTrabajo];
    eMascota mascota[TamanioMascota];
    eVeterinario veterinario[TamanioServicios];

    HardcodearServicios(servicio, 3);
    HardcodearMascota(mascota, TamanioMascota);
    HardcodearVeterinario(veterinario,TamanioServicios);

    InicializarTrabajo(trabajos, TamanioTrabajo);

    do
    {
        Menu(opcion);
        utn_getNumero(&opcion,"\nIngrese una Opcion:","Error Ingrese una Opcion entre 1-11",1,13,3);
        switch (opcion)
        {
        case 1:
            AltaTrabajo(trabajos, servicio, mascota, TamanioServicios, TamanioTrabajo, TamanioMascota);
            break;

        case 2:
            ModificarTrabajo(trabajos, servicio, mascota, TamanioServicios, TamanioTrabajo, TamanioMascota);
            break;

        case 3:
            BajaTrabajo(trabajos, servicio, mascota, TamanioServicios, TamanioTrabajo, TamanioMascota);
            break;

        case 4:
            MostrarTrabajos(trabajos, servicio, mascota,TamanioTrabajo, TamanioServicios, TamanioMascota);
            break;

        case 5:
            MostrarServicios(servicio, TamanioServicios);
            break;

        case 6:
            total = MostrarPrecioTotal(trabajos, servicio, TamanioServicios, TamanioTrabajo);
            printf("Total: $%d\n", total);
            break;

        case 7:
            ListadoDeTrabajos(trabajos, servicio, mascota, TamanioTrabajo, TamanioServicios, TamanioMascota);
            break;

        case 8:
            CantidadServicioMasRealizado(trabajos,servicio,TamanioTrabajo,TamanioServicios);
            break;

        case 9:
            MostrarServiciosConNombre(servicio,trabajos,mascota,TamanioTrabajo,TamanioServicios);
            break;

        case 10:

            break;

        case 11:
            ListadoDeTrabajosVet(trabajos,servicio,mascota,veterinario,TamanioTrabajo,TamanioServicios,TamanioMascota,TamanioServicios);
            break;

        case 12:
            MostrarServiciosConNombreYveterinario(servicio,trabajos,mascota,veterinario,TamanioTrabajo,TamanioServicios);
            break;

        case 13:
            return 0;
            break;
        }
    }
    while (opcion != 13);
    return 0;
}
