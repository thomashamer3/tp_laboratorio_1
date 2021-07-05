#ifndef DUENIO_H_INCLUDED
#define DUENIO_H_INCLUDED
typedef struct
{
    int id;
    char nombreVeterinario[51];
    int isEmpty;
}eVeterinario;

void HardcodearVeterinario(eVeterinario veterinario[], int tam);
int MostrarVeterinario(eVeterinario veterinario);
int DetectarVeterinarios(eVeterinario veterinario[], int tam);
void ObtenerVeterinarios(eVeterinario veterinario[], int tam);
int MostrarVeterinarios(eVeterinario veterinario[], int tam);

int MostrarUnVeterinarioConServicio(eVeterinario veterinario,eServicio servicio);
void ObtenerVeterinariosConServicios(eVeterinario veterinario[], eServicio servicio[], int tam);
int ObtenerDescripcionDeVeterinario(eTrabajo trabajos[], eVeterinario veterinario[], int index, int vetTam);

void ImprimirMensajeVet(eTrabajo trabajos, eServicio servicios, eMascota mascota,eVeterinario veterinario);
void MostrarUnTrabajoConVet(eTrabajo trabajos[], eServicio servicio[], eMascota mascota[],eVeterinario veterinario[], int index, int trabajosTam, int serviciosTam, int masctoasTam,int vetTam);
void ObtenerTrabajosVet(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[], eVeterinario veterinario[], int trabajoTam, int servicioTam, int mascotasTam, int vetTam);


/** \brief Muestra El Listado de los Trabajos Realizados con Los Nombres de los Veterinarios
 *
 * \param trabajos[] eTrabajo Obtiene los datos de la Estrutura trabajo.
 * \param servicio[] eServicio Obtiene los datos de la Estrutura servicio.
 * \param mascota[] eMascota Obtiene los datos de la Estrutura mascota.
 * \param veterinario[] eVeterinario Obtiene los datos de la Estrutura veterinario.
 * \param trabajoTam int Recibe el tamanio de Trabajo
 * \param servicioTam int Recibe el tamanio de Servicio
 * \param mascotasTam int Recibe el tamanio de Mascota
 * \param vetTam int Recibe el tamanio de Vterinario
 * \return int Regresa 1 si puedo Mostrar.
 *
 */
int ListadoDeTrabajosVet(eTrabajo trabajos[],eServicio servicio[], eMascota mascota[],eVeterinario veterinario[], int trabajoTam, int servicioTam, int mascotasTam, int vetTam);

#endif // DUENIO_H_INCLUDED
