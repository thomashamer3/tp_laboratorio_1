#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int opcion;
    int flag=0;
    setbuf(stdout, NULL);

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    	Menu(opcion);
    	utn_getNumero(&opcion,"\nIngrese una Opcion:","Error Ingrese una Opcion entre 1-10",1,10,3);

        switch(opcion)
        {
                case 1:
                    controller_loadFromText("data.csv", listaEmpleados);
                    flag=1;
                    break;

                case 2:
                    controller_loadFromBinary("data.bin", listaEmpleados);
                    flag=1;
                    break;

                case 3:
                    if(flag==1)
                    {
                        controller_addEmployee(listaEmpleados);
                    }
                    else
                    {
                        printf("*Por favor, primero carge la lista con la opcion 1 o 2\n\n");
                    }
                    break;

                case 4:
                    controller_ListEmployee(listaEmpleados);
                    controller_editEmployee(listaEmpleados);
                    break;

                case 5:
                    controller_ListEmployee(listaEmpleados);
                    controller_removeEmployee(listaEmpleados);
                    break;

                case 6:
                    controller_ListEmployee(listaEmpleados);
                    break;

                case 7:
                    controller_sortEmployee(listaEmpleados);
                    break;

                case 8:
                    controller_saveAsText("data.csv", listaEmpleados);
                    break;

                case 9:
                    controller_saveAsBinary("data.bin", listaEmpleados);
                    break;

                case 10:
                    break;
                }
    }while(opcion != 10);
    return 0;
}

