#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un empleado en memoria dinamica (Constructor por defecto)
 *
 * \return Employee* Retorna el empleado creado en memoria dinamica
 *
 */
Employee* employee_new();


/** \brief Crea un empleado en memoria dinamica, recibiendo los parametros y transformandolos en los tipos de datos correspondientes
 *         (Constructor Parametrizado)
 * \param idStr char* El id del empleado
 * \param nombreStr char* El nombre de empleado
 * \param horasTrabajadasStr char* Las horas trabajadas por el empleado
 * \param sueldoStr char* El sueldo del empleado
 * \return Employee* Retorna el empleado creado con parametros en memoria dinamica
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);
void employee_delete();

/** Setters y Getters para evitar usar el operador -> */
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
