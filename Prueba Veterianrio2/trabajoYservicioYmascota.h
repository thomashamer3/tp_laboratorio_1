#include "mascotas.h"
#include "servicios.h"
#include "trabajo.h"
#include "duenio.h"

#ifndef TRABAJOYSERVICIOYMASCOTA_H_INCLUDED
#define TRABAJOYSERVICIOYMASCOTA_H_INCLUDED

/** \brief Realiza la Carga del Trabajo ingresando datos.
 *
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return eTrabajo devuelve El Trabajo cargado en la posicion.
 *
 */
eTrabajo CargarTrabajo(eServicio[], eTrabajo[], eMascota[], int, int, int);


/** \brief Busca si hay espacio y Realiza el Alta.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return int 0 si puedo dar de Alta.
 *
 */
int AltaTrabajo(eTrabajo[], eServicio[], eMascota[], int, int, int);

void ImprimirMensaje(eTrabajo, eServicio, eMascota);

void MostrarUnTrabajo(eTrabajo[], eServicio[], eMascota[], int, int, int, int);

/** \brief Obtiene un Trabajo en una posiscion Ocupada.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return void
 *
 */
void ObtenerTrabajos(eTrabajo[],eServicio[], eMascota[], int, int, int);

/** \brief Muestra Los Datos de los Trabajos Realizados.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return int Devuelve 1 si Puedo Mostrar.
 *
 */
int MostrarTrabajos(eTrabajo[],eServicio[], eMascota[], int, int, int);


/** \brief Realiza la Baja del Trabajo.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return int Regresa el Id Donde se Realizo la Baja.
 *
 */
int BajaTrabajo(eTrabajo[], eServicio[], eMascota[], int, int, int);


/** \brief Le da al Usuarion Opciones de Modificacion.
 *
 * \param eTrabajo Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return eTrabajo devuelve El Trabajo Modificado en la posicion.
 *
 */
eTrabajo OpcionModificarTrabajo(eTrabajo, eServicio[], eMascota[], int, int,int);


/** \brief Busca El Id ingresado para Realizar la Modificacion.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param int Recibe el tamanio de Trabajo
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param int Recibe el tamanio de Servicio
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Mascota
 * \return int Regresa el Id Donde se Modifico.
 *
 */
int HacerModificacion(eTrabajo[], int, eServicio[], int, eMascota[], int);


/** \brief Realiza la Modificacion del Trabajo Ingresado.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return int Regresa el Id Donde se Modifico.
 *
 */
int ModificarTrabajo(eTrabajo[], eServicio[], eMascota[], int, int, int);


/** \brief Muestra el Listado Completo de los Trabajos Realizados.
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \param int Recibe el tamanio de Mascota
 * \return int Devuelve 1 si Puedo Mostrar.
 *
 */
int ListadoDeTrabajos(eTrabajo[], eServicio[], eMascota[], int, int, int);

int crearId();


/** \brief Muestra el Servicio con el Nombre de la Mascota
 *
 * \param eTrabajo[] Obtiene los datos de la Estrutura trabajo.
 * \param eServicio[] Obtiene los datos de la Estrutura servicio.
 * \param eMascota[] Obtiene los datos de la Estrutura mascota.
 * \param int Recibe el tamanio de Servicio
 * \param int Recibe el tamanio de Trabajo
 * \return void
 *
 */
void MostrarServiciosConNombre(eServicio[], eTrabajo[], eMascota[],int, int);

int MascotasQueRealizaronServicio(eTrabajo, eMascota[], eServicio, int);

/** \brief Muestra un Listado de las Mascotas con su Veterinario y Servicio
 *
 * \param servicio[] eServicio Obtiene los datos de la Estrutura servicio.
 * \param trabajo[] eTrabajo Obtiene los datos de la Estrutura trabajo.
 * \param mascotas[] eMascota Obtiene los datos de la Estrutura mascota.
 * \param veterinario[] eVeterinario Obtiene los datos de la Estrutura veterinario.
 * \param tam int Recibe el tamanio de Trabajo
 * \param sTam int Recibe el tamanio de Servicio
 * \return void
 *
 */
void MostrarServiciosConNombreYveterinario(eServicio servicio[], eTrabajo trabajo[], eMascota mascotas[], eVeterinario veterinario[], int tam, int sTam);



#endif // TRABAJOYSERVICIOYMASCOTA_H_INCLUDED
