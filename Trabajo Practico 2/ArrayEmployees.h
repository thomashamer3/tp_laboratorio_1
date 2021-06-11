#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;
/** \brief Agrega un Empleado a la array existente los valores recibidos.
 *
 * \param eEmployee[]
 * \param int tam
 * \return void
 *
 */
void addEmployee(eEmployee[],int);
/** \brief Busca un espacio libre en la array.
 *
 * \param eEmployee[]
 * \param int tam
 * \return int index
 *
 */
int buscarLibre(eEmployee[],int);
/** \brief Elimina un Empleado de la array.
 *
 * \param eEmployee[]
 * \param int tam
 * \return void
 *
 */
void removeEmployee(eEmployee[],int);
/** \brief Imprime la lista de Empleados en la array.
 *
 * \param eEmployee[]
 * \param int tam
 * \return void
 *
 */
void printEmployees(eEmployee[],int);
/** \brief Modifica al Empleado obteniendo su Id
 *
 * \param eEmployee[]
 * \param int tam
 * \return void
 *
 */
void modificarEmpleado(eEmployee[],int);
/** \brief Busca el Empleado por Id.
 *
 * \param eEmployee[]
 * \param int tam
 * \param int id
 * \return int busqueda
 *
 */
int findEmployeeById(eEmployee[],int,int);
/** \brief Ordena la array por Apellido.
 *
 * \param eEmployee[]
 * \param int tam
 * \return void
 *
 */
void sortEmployee(eEmployee[],int);
/** \brief Suma los Salarios ingresados.
 *
 * \param eEmployee[]
 * \param int
 * \return float salariosTotales
 *
 */
float salariosSumados(eEmployee[],int);
/** \brief Inicializa vaciando el array.
 *
 * \param eEmployee[]
 * \param int tam
 * \return int 0
 *
 */
int initEmployee(eEmployee[],int);


#endif // ARRAYEMPLOYEES_H_INCLUDED
