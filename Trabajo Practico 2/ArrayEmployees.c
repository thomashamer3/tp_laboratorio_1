#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define TAM 1000
#include "ArrayEmployees.h"

void addEmployee(eEmployee listaEmpleados[],int tam)
{
    eEmployee empleado;
    int i;
    i=buscarLibre(listaEmpleados,tam);
    if(i!=-1)
    {
        printf("\nNombre Del Empleado: ");
        fflush(stdin);
        scanf("%[^\n]", empleado.name);
        printf("\nApellido Del Empleado: ");
        fflush(stdin);
        scanf("%[^\n]", empleado.lastName);
        printf("\nSalario Del Empleado: ");
        scanf("%f", &empleado.salary);
        printf("\nSector Del Empleado: ");
        scanf("%d", &empleado.sector);
        listaEmpleados[i]=empleado;
        listaEmpleados[i].isEmpty=0;

    }
    else
    {
        printf("No hay Espacio");
    }

}

void removeEmployee(eEmployee listaEmpleados[],int tam)
{
    int i;
    int id;
    printEmployees(listaEmpleados,tam);
    printf("\nIngrese el Id del Empleado: ");
    scanf("%d",&id);
    i=findEmployeeById(listaEmpleados,tam,id);
    if(i>=0)
    {
        listaEmpleados[i].isEmpty=1;
        printf("\nEmpleado Eliminado\n");

    }
    else
    {
        printf("\nEmpleado no Encontrado\n");
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
    float sumaSalarios;
    sortEmployee(listaEmpleados,tam);
    printf("\tApellido \tNombre \t \tSalario \t\tSector \t\tID\n");
    for(i=0; i<tam; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            listaEmpleados[i].id=i+1;
            printf("\n%14s  %14s  %14.2f  %18d  %15d\n", listaEmpleados[i].lastName, listaEmpleados[i].name,listaEmpleados[i].salary, listaEmpleados[i].sector, listaEmpleados[i].id);

        }
    }
    sumaSalarios=salariosSumados(listaEmpleados,tam);
    printf("\nSalario Total: %.2f\n", sumaSalarios);
}


void modificarEmpleado(eEmployee listaEmpleados[],int tam)
{
    int id;
    char nuevoNombre[51];
    char nuevoApellido[51];
    int nuevoSector;
    float nuevoSalario;
    int lugar;

    printEmployees(listaEmpleados,tam);
    printf("\nIngrese Id del Empleado a Modificar: ");
    scanf("%d",&id);

    lugar=findEmployeeById(listaEmpleados,tam,id);

    if(lugar>=0)
    {
        printf("Ingrese Nombre Del Empleado: ");
        fflush(stdin);
        scanf("%[^\n]", nuevoNombre);
        strcpy(listaEmpleados[lugar].name,nuevoNombre);
        printf("Ingrese Apellido Del Empleado:");
        fflush(stdin);
        scanf("%[^\n]", nuevoApellido);
        strcpy(listaEmpleados[lugar].lastName,nuevoApellido);
        printf("Ingrese Salario Del Empleado:");
        fflush(stdin);
        scanf("%f", &nuevoSalario);
        listaEmpleados[lugar].salary=nuevoSalario;
        printf("Ingrese Sector Del Empleado:");
        scanf("%d", &nuevoSector);
        listaEmpleados[lugar].sector=nuevoSector;
        printf("\nModificacion Realizada\n");
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


