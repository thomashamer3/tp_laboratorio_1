#include "servicios.h"
#include "trabajo.h"

#ifndef TRABAJOYSERVICIO_H_INCLUDED
#define TRABAJOYSERVICIO_H_INCLUDED

int ObtenerDescripcionDeServicio(eTrabajo[], eServicio[], int, int);

int CorroborarFkConPk(eTrabajo, eServicio, int);

int ObtenerPrecios(eTrabajo[], eServicio[], int, int);

/** \brief  Muestra el Precio total por los Servicios Prestados.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \return int Total de los Servicios.
 *
 */
int MostrarPrecioTotal(eTrabajo[], eServicio[], int, int);

int ObtenerCantidadServicio(eTrabajo[], eServicio servicio, int tam);

int ObtenerPrecioServicio(eTrabajo[], eServicio servicio, int tam);

void InicializarContador(int contador[], int tam);

/** \brief Obtiene la cantidad De Servicios mas Realizados
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param tam  int Recibe el tamanio de Trabajo
 * \param sTam int Recibe el tamanio de Servicio
 * \return void
 *
 */
void CantidadServicioMasRealizado(eTrabajo[], eServicio[], int tam, int sTam);

#endif // TRABAJOYSERVICIO_H_INCLUDED
