#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 1000
#include "ArrayEmployees.h"

int main()
{
    int opcion;
    int i;
    int entradaOpcion=0;
    eEmployee listaEmpleados[T];
    i=initEmployee(listaEmpleados,T);

    do
    {
        printf("1.Ingresar Empleado\n");
        printf("2.Modificar Empleado\n");
        printf("3.Eliminar Empleado\n");
        printf("4.Informar\n");
        printf("5.Salir");
        printf("\nIngrese una Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {

        case 1:
            entradaOpcion=0;
            addEmployee(listaEmpleados,T);
            entradaOpcion=1;

            if(i!=-1)
            {
                printf("\nCarga Realizada\n");
            }
            else
            {
                printf("\nNo hay Espacio\n");
            }
            break;
        case 2:

            if(entradaOpcion==0)
            {
                printf("\nIngrese un Empleado\n");
            }
            else
            {
                modificarEmpleado(listaEmpleados,T);
            }

            break;
        case 3:

            if(entradaOpcion==0)
            {
                printf("\nIngrese un Empleado\n");
            }
            else
            {
                removeEmployee(listaEmpleados,T);
            }

            break;
        case 4:

            if(entradaOpcion==0)
            {
                printf("\nIngrese un Empleado\n");
            }
            else
            {
                printEmployees(listaEmpleados,T);
            }

            break;
        case 5:
            printf("Adios");
            break;
        }
    }
    while(opcion!=5);

    return 0;
}
