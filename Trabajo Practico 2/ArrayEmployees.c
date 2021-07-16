#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 1000
#include "ArrayEmployees.h"
#include "input.h"

int addEmployee(eEmployee listaEmpleados[],int tam)
{
    eEmployee empleado;
    int retorno=-1;
    char nombreEmpleado[51];
    char apellidoEmpleado[51];
    int returnNombre;
    int returnApellido;
    int i;
    i=buscarLibre(listaEmpleados,tam);

    if(i!=-1)
    {
        fflush(stdin);
        returnNombre= getPalabra(nombreEmpleado,"\nIngrese el Nombre Del Empleado: ");
        if(returnNombre==0)
        {
            strcpy(empleado.name,nombreEmpleado);
            normalizeAndCapitalize(empleado.name);
        }
        else
        {
            fflush(stdin);
            returnNombre= getPalabra(nombreEmpleado,"\nError Ingrese el Nombre Del Empleado: ");
            strcpy(empleado.name,nombreEmpleado);
            normalizeAndCapitalize(empleado.name);
        }

        returnApellido= getPalabra(apellidoEmpleado,"\nIngrese el Apellido Del Empleado: ");
        if(returnApellido==0)
        {
            strcpy(empleado.lastName,apellidoEmpleado);
            normalizeAndCapitalize(empleado.lastName);
        }
        else
        {
            fflush(stdin);
            returnApellido= getPalabra(apellidoEmpleado,"\nError Ingrese el Apellido Del Empleado: ");
            strcpy(empleado.lastName,apellidoEmpleado);
            normalizeAndCapitalize(empleado.lastName);
        }

        utn_getNumeroFloat(&empleado.salary,"\nIngrese el Salario del Empleado: ","Error Ingrese un Salario Valido.",0,999999,3);
        utn_getNumero(&empleado.sector,"\nIngrese el Sector del Empleado: ","Error Ingrese un Sector Valido.",0,10,3);


        empleado.id=crearEmpleadoId();
        listaEmpleados[i]=empleado;
        listaEmpleados[i].isEmpty=0;
        retorno=0;

    }
    else
    {
        printf("No hay Espacio.");
    }

    return retorno;
}

void removeEmployee(eEmployee listaEmpleados[],int tam)
{
    int i;
    int id;
    printEmployees(listaEmpleados,tam);

    utn_getNumero(&id,"Ingrese el Id del Empleado: ","\n Error Ingrese Un Id Valido.",0,1000,3);

    i=findEmployeeById(listaEmpleados,tam,id);
    if(i>=0)
    {
        listaEmpleados[i].isEmpty=1;
        printf("\nEmpleado Eliminado.\n");

    }
    else
    {
        printf("\nEmpleado no Encontrado.\n");
    }

}

int findEmployeeById(eEmployee listaEmpleados[],int tam, int id)
{
    int i;
    eEmployee empleado;
    int busqueda;
    busqueda=-1;
    for(i=0; i<tam; i++)
    {
        empleado=listaEmpleados[i];

        if(empleado.id==id && empleado.isEmpty==0)
        {
            busqueda=i;
            break;

        }

    }

    return busqueda;
}
float salariosSumados(eEmployee listaEmpleados[],int tam)
{
    int i;
    float salariosTotales;
    salariosTotales=0;

    for(i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            salariosTotales=salariosTotales+listaEmpleados[i].salary;
        }
    }
    return salariosTotales;

}

int initEmployee(eEmployee listaEmpleados[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaEmpleados[i].isEmpty=1;
    }

    return 0;

}
void sortEmployee(eEmployee listaEmpleados[],int tam)
{
    int i;
    int j;
    eEmployee auxEmployee;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listaEmpleados[i].lastName,listaEmpleados[j].lastName)<0 && listaEmpleados[i].sector<listaEmpleados[j].sector)
            {
                auxEmployee=listaEmpleados[i];
                listaEmpleados[i]=listaEmpleados[j];
                listaEmpleados[j]=auxEmployee;


            }
        }
    }
}

void printEmployees(eEmployee listaEmpleados[],int tam)
{
    int i;
    sortEmployee(listaEmpleados,tam);
    printf("\tApellido \tNombre \t \tSalario \t\tSector \t\tID\n");
    for(i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            printf("\n%14s  %14s  %14.2f  %18d  %15d\n", listaEmpleados[i].lastName, listaEmpleados[i].name,listaEmpleados[i].salary, listaEmpleados[i].sector, listaEmpleados[i].id);

        }
    }

}


void modificarEmpleado(eEmployee listaEmpleados[],int tam)
{
    int id;
    char nuevoNombre[51];
    char nuevoApellido[51];
    int returnNombre;
    int returnApellido;
    int nuevoSector;
    float nuevoSalario;
    int lugar;

    printEmployees(listaEmpleados,tam);
    utn_getNumero(&id,"\nIngrese Id del Empleado a Modificar: ","Ingrese un Id Valido.",0,1000,3);
    lugar=findEmployeeById(listaEmpleados,tam,id);

    if(lugar>=0)
    {
        returnNombre= getPalabra(nuevoNombre,"\nIngrese el Nombre Del Empleado: ");
        if(returnNombre==0)
        {
            normalizeAndCapitalize(nuevoNombre);
            strcpy(listaEmpleados[lugar].name,nuevoNombre);
        }
        else
        {
            fflush(stdin);
            returnNombre= getPalabra(nuevoNombre,"\nError Ingrese el Nombre Del Empleado: ");
            strcpy(listaEmpleados[lugar].name,nuevoNombre);
            normalizeAndCapitalize(nuevoNombre);
        }

        fflush(stdin);
        returnApellido= getPalabra(nuevoApellido,"\nIngrese Apellido Del Empleado:");
        if(returnApellido==0)
        {
            normalizeAndCapitalize(nuevoApellido);
            strcpy(listaEmpleados[lugar].lastName,nuevoApellido);
        }
        else
        {
            fflush(stdin);
            returnApellido= getPalabra(nuevoApellido,"\n Error Ingrese Apellido Del Empleado:");

        }

        utn_getNumeroFloat(&nuevoSalario,"Ingrese el Nuevo Salario del Empleado: ","Error Ingrese Un Salario Valido.",0,999999,3);
        listaEmpleados[lugar].salary=nuevoSalario;

        utn_getNumero(&nuevoSector,"Ingrese el Nuevo Sector del Empleado: ","Error Ingrese un Sector Valido.",0,10,3);
        listaEmpleados[lugar].sector=nuevoSector;

        printf("\nModificacion Realizada.\n");
    }

}

int buscarLibre(eEmployee listaEmpleados[],int tam)
{
    int i;
    int index;
    index=-1;
    for(i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }

    return index;
}

int crearEmpleadoId(void)
{
    static int id=0;
    id++;
    return id;
}

void mostraSalarioPromedio(eEmployee listaEmpleados[], int tam)
{
    int i;
    int contador=0;
    float total=0;
    float promedio;

    for(i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            total+= listaEmpleados[i].salary;
            contador++;
        }

    }

    promedio = total/contador;

    if(total==0)
    {
        promedio=0;
    }
    if(contador>0)
    {
        printf("\nSalario Promedio: $%.1f\n", promedio);

        printf("\nLos Empleado que Superan el Salario Promedio son:\n");

        for(i=0; i<tam; i++)
        {
            if(listaEmpleados[i].salary>=promedio && listaEmpleados[i].isEmpty==0)
            {
                mostrarUnEmpleado(listaEmpleados[i]);
            }
        }
    }

}

void mostrarUnEmpleado(eEmployee auxEmployee)
{
    printf("\n%8d %8s %8s\t $%8.1f %8.d\n", auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
}
