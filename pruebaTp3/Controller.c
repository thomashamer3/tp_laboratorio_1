#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pData=NULL;

	    pData = fopen(path,"r");

	    if(pArrayListEmployee!=NULL && pData!=NULL)
	    {
	        parser_EmployeeFromText(pData, pArrayListEmployee);
	    }

	    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pData=NULL;

	    pData = fopen(path,"rb");

	    if(pArrayListEmployee!=NULL && pData!=NULL)
	    {
	    	parser_EmployeeFromBinary(pData, pArrayListEmployee);
	    }

	    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	 Employee* auxEmployee;
	    int id;
	    int horasTrabajadas;
	    char nombre[51];
	    int sueldo;

	    int ret;
	    int retAdd;

	    if(pArrayListEmployee!=NULL)
	    {
	        auxEmployee = employee_new();
	        if(auxEmployee!=NULL)
	        {
	            id = crearEmployeeId(pArrayListEmployee);
	            employee_setId(auxEmployee, id);

	            printf("*Id de empleado: %d\n", id);

	            do
	            {
	                ret = getPalabra(nombre, "\nIngrese el nombre del empleado: ");
	            }
	            while(ret!=0);
	            employee_setNombre(auxEmployee, nombre);

	            utn_getNumero(&horasTrabajadas,"\nIngrese la cantidad de horas trabajadas: ","\nError, ingrese la cantidad de horas trabajadas: ",1,600,3);
	            employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);

	            utn_getNumero(&sueldo,"\nIngrese el sueldo: ","\nError, ingrese el sueldo: ", 100, 700000,3);
	            employee_setSueldo(auxEmployee, sueldo);

	            retAdd = ll_add(pArrayListEmployee, auxEmployee);
	            if(retAdd!=-1)
	            {
	                printf("\n*Se cargo el empleado correctamente\n\n");
	            }
	            else
	            {
	                printf("\n*La carga de empleado fallo\n\n");
	            }
	        }
	        else
	        {
	            printf("\n*Imposible cargar el empleado\n\n");
	        }
	    }
	    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	    int buscarId;
	    int i;
	    int size=0;

	    int opcion;
	    int id;
	    int horasTrabajadas;
	    int sueldo;
	    char nombre[51];

	    char answer;

	    size = ll_len(pArrayListEmployee);

	    if(size>0)
	    {
	    	utn_getNumero(&buscarId,"\nIngrese el id de usuario que desea modificar: ", "\nError, ingrese un id valido", 1, 5000,3);
	        for(i=0; i<size; i++)
	        {
	            auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
	            if(auxEmployee!=NULL)
	            {
	                employee_getId(auxEmployee, &id);
	                employee_getNombre(auxEmployee, nombre);
	                employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
	                employee_getSueldo(auxEmployee, &sueldo);
	                if(id==buscarId)
	                {
	                    system("cls");
	                    break;
	                }
	            }
	        }

	        if(auxEmployee!=NULL && auxEmployee->id==buscarId)
	        {
	            do
	            {
	                printf("  Id     Nombre  Horas Trabajadas        Sueldo\n\n");
	                printf("%4d %10s %10d              $ %4d", id, nombre, horasTrabajadas, sueldo); //*******
	                printf("\n\n*** Menu Editar ***\n");
	                printf("1.Nombre\n");
	                printf("2.Horas Trabajadas\n");
	                printf("3.Sueldo\n");
	                printf("4.Guardar cambios\n");
	                printf("5.Salir del menu\n");

	                utn_getNumero(&opcion,"Seleccione una opcion: ", "\nError, ingrese una opcion valida: ", 1, 5,3);
	                system("cls");

	                switch(opcion)
	                {
	                case 1:
	                	getPalabra(nombre, "Ingrese el nuevo nombre: ");
	                    system("cls");
	                    break;

	                case 2:
	                	utn_getNumero(&horasTrabajadas,"Ingrese la nueva cantidad de horas trabajadas: ", "\nError, ingrese una cantidad valida: ", 1, 200,3);
	                    system("cls");
	                    break;

	                case 3:
	                	utn_getNumero(&sueldo,"Ingrese el nuevo sueldo: ", "\nError, ingrese un sueldo valido: ", 100, 700000,3);
	                    system("cls");
	                    break;

	                case 4:
	                	utn_getCaracter(&answer,"Esta seguro que desea actualizar este empleado? (Enter=Si / n=No): ", "\nError, ingrese (Enter=Si / n=No): ", '\n', 'n',3);
	                    if(answer=='\n')
	                    {
	                        system("cls");
	                        employee_setNombre(auxEmployee, nombre);
	                        employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);
	                        employee_setSueldo(auxEmployee, sueldo);
	                        printf("*El empleado fue modificado satisfactoriamente\n\n");
	                    }
	                    else
	                    {
	                        system("cls");
	                        employee_getId(auxEmployee, &id);
	                        employee_getNombre(auxEmployee, nombre);
	                        employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
	                        employee_getSueldo(auxEmployee, &sueldo);
	                        printf("*Se cancelo la modificacion de el empleado\n\n");
	                    }
	                    break;
	                }
	            }
	            while(opcion!=5);
	            system("cls");
	            printf("*Saliendo del menu de edicion...\n\n");
	        }
	        else
	        {
	            system("cls");
	            printf("*Error, empleado no encontrado...\n\n");
	        }
	    }
	    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	    int index;
	    int i;
	    int retRemove;
	    int buscarId;
	    int size=0;
	    char answer;

	    int id;
	    int horasTrabajadas;
	    int sueldo;
	    char nombre[51];

	    size = ll_len(pArrayListEmployee);

	    if(size>0)
	    {
	    	utn_getNumero(&buscarId,"\nIngrese el id de usuario que desea modificar: ", "\nError, ingrese un id valido", 1, 5000,3);

	        for(i=0; i<size; i++)
	        {
	            auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
	            if(auxEmployee!=NULL)
	            {
	                employee_getId(auxEmployee, &id);
	                employee_getNombre(auxEmployee, nombre);
	                employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
	                employee_getSueldo(auxEmployee, &sueldo);
	                if(id==buscarId)
	                {
	                    index = i;
	                    break;
	                }
	            }
	        }

	        if(auxEmployee!=NULL && auxEmployee->id==buscarId)
	        {
	            system("cls");
	            printf("  Id     Nombre  Horas Trabajadas        Sueldo\n\n");
	            printf("%4d %10s %10d              $ %4d", id, nombre, horasTrabajadas, sueldo);//*******
	            utn_getCaracter(&answer,"Esta seguro que desea actualizar este empleado? (Enter=Si / n=No): ", "\nError, ingrese (Enter=Si / n=No): ", '\n', 'n',3);
	            if(answer=='\n')
	            {
	                retRemove = ll_remove(pArrayListEmployee, index);
	                if(retRemove!=-1)
	                {
	                    system("cls");
	                    printf("*El empleado fue removido satisfactoriamente\n\n");
	                }
	                else
	                {
	                    system("cls");
	                    printf("*La eliminacion de empleado fallo\n\n");
	                }
	            }
	            else
	            {
	                system("cls");
	                printf("*Se cancelo la eliminacion de el empleado\n\n");
	            }
	        }
	        else
	        {
	            system("cls");
	            printf("*Error, empleado no encontrado...\n\n");
	        }
	    }
	    else if(size==0)
	    {
	        system("cls");
	        printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
	    }
	    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	    int i;
	    int size=0;
	    int id;
	    int horasTrabajadas;
	    int sueldo;
	    char nombre[51];

	    if(pArrayListEmployee!=NULL)
	    {
	        size = ll_len(pArrayListEmployee);
	        if(size>0)
	        {
	            printf("  Id     Nombre  Horas Trabajadas        Sueldo\n\n");
	            for(i=0; i<size; i++)
	            {
	                auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
	                if(auxEmployee!=NULL)
	                {
	                    employee_getId(auxEmployee, &id);
	                    employee_getNombre(auxEmployee, nombre);
	                    employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
	                    employee_getSueldo(auxEmployee, &sueldo);
	                    printf("%4d %10s %10d              $%.1d\n", id, nombre, horasTrabajadas, sueldo);//*******
	                }
	            }
	            printf("\n");
	        }
	        else if(size==0)
	        {
	            printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
	        }
	    }
	    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	 int opcion;
	    int size=0;
	    int retSort;

	    size = ll_len(pArrayListEmployee);

	    if(size>0)
	    {
	        do
	        {
	            system("cls");
	            printf("*** Menu ordenar ***\n");
	            printf("1.Ordenar por Nombre de la A-Z\n");
	            printf("2.Ordenar por Nombre de la Z-A\n");
	            printf("3.Ordenar por Id de menor a mayor\n");
	            printf("4.Ordenar por Id mayor a menor\n");
	            printf("5.Salir del menu ordenar\n");
	            utn_getNumero(&opcion,"Seleccione una opcion: ", "\nError, ingrese una opcion valida: ", 1, 5,3);
	            system("cls");

	            switch(opcion)
	            {
	            case 1:
	                printf("*Ordenando la lista, un momento por favor.\n\n");
	                retSort = ll_sort(pArrayListEmployee, employee_CompareByName, 1);
	                if(retSort!=-1)
	                {
	                    controller_ListEmployee(pArrayListEmployee);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;

	            case 2:
	                printf("*Ordenando la lista, un momento por favor...\n\n");
	                retSort = ll_sort(pArrayListEmployee, employee_CompareByName, 0);
	                if(retSort!=-1)
	                {
	                    controller_ListEmployee(pArrayListEmployee);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;

	            case 3:
	                printf("*Ordenando la lista, un momento por favor...\n\n");
	                retSort = ll_sort(pArrayListEmployee, employee_CompareById, 1);
	                if(retSort!=-1)
	                {
	                    controller_ListEmployee(pArrayListEmployee);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;

	            case 4:
	                printf("*Ordenando la lista, un momento por favor...\n\n");
	                retSort = ll_sort(pArrayListEmployee, employee_CompareById, 0);
	                if(retSort!=-1)
	                {
	                    controller_ListEmployee(pArrayListEmployee);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;
	            }
	        }
	        while(opcion!=5);
	        printf("*Saliendo del menu ordenar...\n\n");
	    }
	    else if(size==0)
	    {
	        printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
	    }
	    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	    FILE* pData;
	    int i;
	    int size=0;

	    int id;
	    int horasTrabajadas;
	    int sueldo;
	    char nombre[51];

	    size = ll_len(pArrayListEmployee);

	    if(size>0)
	    {
	        pData = fopen(path, "w");
	        if(pData!=NULL)
	        {
	            for(i=0; i<size; i++)
	            {
	                if(i==0)
	                {
	                    fprintf(pData, "id,nombre,horasTrabajadas,sueldo\n");
	                }
	                auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
	                if(auxEmployee!=NULL)
	                {
	                    employee_getId(auxEmployee, &id);
	                    employee_getNombre(auxEmployee, nombre);
	                    employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
	                    employee_getSueldo(auxEmployee, &sueldo);
	                    fprintf(pData, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
	                }
	            }
	            printf("*Se guardo la lista correctamente en el archivo data.csv (Modo Texto)\n\n");
	        }
	        else
	        {
	            printf("*Imposible cargar el archivo");
	        }
	        fclose(pData);
	    }
	    else if(size==0)
	    {
	        printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
	    }
	    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	    FILE* pData;
	    int i;
	    int size=0;

	    size = ll_len(pArrayListEmployee);

	    if(size>0)
	    {
	        pData = fopen(path, "wb");
	        if(pData!=NULL)
	        {
	            for(i=0; i<size; i++)
	            {
	                auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
	                if(auxEmployee!=NULL)
	                {
	                    fwrite(auxEmployee, sizeof(Employee),1,pData);
	                }
	            }
	            printf("*Se se guardo la lista correctamente en el archivo data.bin (Modo Binario)\n\n");
	        }
	        else
	        {
	            printf("*Imposible cargar el archivo");
	        }
	        fclose(pData);
	    }
	    else if(size==0)
	    {
	        printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
	    }
	    return 1;
}

