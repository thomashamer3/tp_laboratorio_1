#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;

	    char id[51];
	    char nombre[51];
	    char horasTrabajadas[51];
	    char sueldo[51];

	    char encabezado[51];
	    int i=-1;

	    if(pFile!=NULL)
	    {
	        while(!feof(pFile))
	        {
	        	i++;
	        	if(i==0)
	        	{
	        	   fscanf(pFile, "%[^\n]\n", encabezado);// hacer fuera del while
	        	    i++;
	        	 }

	            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
	            auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
	            ll_add(pArrayListEmployee, auxEmployee);
	        }
	        printf("*Se cargaron los datos desde el archivo data.csv (Modo Texto)\n\n");
	        fclose(pFile);
	    }
	    else
	    {
	        printf("*Imposible cargar los datos\n\n");
	    }

	    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;

	    if(pFile!=NULL)
	    {
	        while(!feof(pFile))
	        {
	            if(feof(pFile))
	            {
	                break;
	            }
	            auxEmployee = employee_new();
	            if(fread(auxEmployee,sizeof(Employee),1,pFile)==1)
	            {
	                ll_add(pArrayListEmployee, auxEmployee);
	            }
	        }
	        printf("*Se cargaron los datos desde el archivo data.bin (Modo Binario)\n\n");
	        fclose(pFile);
	    }
	    else
	    {
	        printf("*Imposible cargar los datos\n\n");
	    }
	    return 1;
}

int crearEmployeeId(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int tamanio;
    int maximo;
    int id;

    tamanio = ll_len(pArrayListEmployee); //Arreglar

    if(tamanio>0)
    {
        for(i=0; i<tamanio; i++)
        {
            auxEmployee =(Employee*) ll_get(pArrayListEmployee, i);
            if(auxEmployee!=NULL)
            {
                employee_getId(auxEmployee, &id);
                if(id > maximo || i==0)
                {
                	maximo = id;
                }
            }
        }
    }
    else
    {
    	maximo = 0;
    }
    maximo++;

    return maximo;
}
