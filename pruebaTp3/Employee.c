#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "Employee.h"


Employee* employee_new()
{
    Employee* listaEmpleados = (Employee*) malloc(sizeof(Employee));
    return listaEmpleados;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* listaEmpleados;
    int auxInt;

    listaEmpleados = employee_new();
    if(listaEmpleados!=NULL)
    {
        auxInt = atoi(idStr);
        employee_setId(listaEmpleados, auxInt);

        employee_setNombre(listaEmpleados, nombreStr);

        auxInt = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(listaEmpleados, auxInt);

        auxInt = atoi(sueldoStr);
        employee_setSueldo(listaEmpleados, auxInt);
    }
    return listaEmpleados;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ret = 0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        ret = 1;
    }
    return ret;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int ret = 0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre, this->nombre);
        ret = 1;
    }
    return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int ret = 0;
    if(this!=NULL && sueldo >= 100)
    {
        this->sueldo = sueldo;
        ret = 1;
    }
    return ret;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret = 0;
    if(this!=NULL && *sueldo >= 100)
    {
        *sueldo = this->sueldo;
        ret = 1;
    }
    return ret;
}

int employee_setId(Employee* this,int id)
{
    int ret = 0;
    if(this!=NULL && id > 0)
    {
        this->id = id;
        ret = 1;
    }
    return ret;
}
int employee_getId(Employee* this,int* id)
{
    int ret = 0;
    if(this!=NULL && id > 0)
    {
        *id = this->id;
        ret = 1;
    }
    return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret = 0;
    //if(this!=NULL && horasTrabajadas <= 550)
    if(this!=NULL && horasTrabajadas > 1)
    {
        this->horasTrabajadas = (int)horasTrabajadas;
        ret = 1;
    }
    return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret = 0;
    //if(this!=NULL && *horasTrabajadas <= 550)
    if(this!=NULL && *horasTrabajadas > 1)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ret = 1;
    }
    return ret;
}


int employee_CompareByName(void* e1, void* e2)
{
    Employee* employee1 = (Employee*) e1;
    Employee* employee2 = (Employee*) e2;
    int ret;
    char nameEmployee1[51];
    char nameEmployee2[51];

    employee_getNombre(employee1, nameEmployee1);
    employee_getNombre(employee2, nameEmployee2);

    if(employee1!=NULL && employee2!=NULL)
    {
        ret = strcmp(nameEmployee1, nameEmployee2);
    }
    else
    {
        ret = -1;
    }
    return ret;
}
int employee_CompareById(void* e1, void* e2)
{
    Employee* employee1 = (Employee*) e1;
    Employee* employee2 = (Employee*) e2;
    int ret;
    int idEmployee1;
    int idEmployee2;

    employee_getId(employee1, &idEmployee1);
    employee_getId(employee2, &idEmployee2);

    if(employee1!=NULL && employee2!=NULL)
    {
        if(idEmployee1 > idEmployee2)
        {
            ret = 1;
        }
        else
        {
            if(idEmployee1 < idEmployee2)
            {
                ret = -1;
            }
            else
            {
                ret = 0;
            }
        }
    }
    return ret;
}


