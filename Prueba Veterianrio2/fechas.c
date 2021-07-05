#include "fechas.h"
#include "input.h"


eFecha CargarFecha()
{
    eFecha fecha;

    utn_getNumero(&fecha.dia,"\nIngrese un Dia: ","Error Reingrese La Fecha Correctamente",1,31,4);
    utn_getNumero(&fecha.mes,"\nIngrese un Mes: ","Error Reingrese El Mes Correctamente",1,12,4);
    utn_getNumero(&fecha.anio,"\nIngrese un Anio: ","Error Reingrese El Anio Correctamente",1950,2030,4);

    return fecha;
}
