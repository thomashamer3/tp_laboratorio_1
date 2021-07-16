#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 1000
#include "ArrayEmployees.h"
#include "input.h"

int main()
{
    int opcion;
    int flagAdd;
    float sumaSalarios;
    eEmployee listaEmpleados[T];
    initEmployee(listaEmpleados,T);

    do
    {
        Menu(opcion);
        utn_getNumero(&opcion,"\nIngrese una Opcion:","\nError Ingrese una Opcion entre 1-5.",1,5,3);

        switch(opcion)
        {

        case 1:
            flagAdd=addEmployee(listaEmpleados,T);
            if(flagAdd==0)
            {
                printf("\nCarga Realizada.\n");
            }
            else
            {
                printf("\nNo hay Espacio.\n");
            }
            break;

        case 2:
            if(flagAdd==0)
            {
                modificarEmpleado(listaEmpleados,T);
            }
            else
            {
                printf("\nIngrese un Empleado.\n");
            }
            break;

        case 3:

            if(flagAdd==0)
            {
                removeEmployee(listaEmpleados,T);
            }
            else
            {
                printf("\nIngrese un Empleado.\n");
            }
            break;

        case 4:
            if(flagAdd==0)
            {
                printEmployees(listaEmpleados,T);
                sumaSalarios=salariosSumados(listaEmpleados,T);
                printf("Salario Total: %.2f\n", sumaSalarios);
                mostraSalarioPromedio(listaEmpleados,T);
            }
            else
            {
                printf("\nIngrese un Empleado.\n");
            }

            break;
        case 5:
            printf("Adios.");
            break;
        }
    }
    while(opcion!=5);

    return 0;
}
