#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int id;
    char nombreMascota[25];
    int edad;
    char raza[25];
    int isEmpty;
} eMascota;

int MostrarMascota(eMascota);
int DetectarMascotas(eMascota[], int);
void ObtenerMascotas(eMascota[], int);
int MostrarMascotas(eMascota[], int);

int HardcodearMascota(eMascota[], int);
int OrdenarMascotas(eMascota[], int);

void MostrarServicioElaborado(int[], char[][25], int);
void OrdenarServiciosMasRealizados(int[], char[][25], int);

eMascota ObtenerMascotaPorID (eMascota mascota[], int idABuscar,int tam);

#endif // MASCOTAS_H_INCLUDED
