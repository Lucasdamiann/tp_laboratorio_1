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
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
    {
    int ret = -1;
    char buffer[4][30];
    Employee *pAuxEmpleado;
    int cant;
    if (pFile == NULL)
	{
	printf("No se pudo abrir el archivo\n");
	exit(EXIT_FAILURE);
	}

    while (!feof(pFile))
	{
	cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],
		buffer[2], buffer[3]);

	if (cant < 4)
	    {
	    break;
	    }

	pAuxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2],
		buffer[3]);
	ll_add(pArrayListEmployee, pAuxEmpleado);
	ret = 0;
	}

    return ret;
    }

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
    {

    Employee* pAuxEmpleado;
       int retorno=-1;
       if(pFile!=NULL && pArrayListEmployee!=NULL)
       {
           while(!feof(pFile))
           {
               pAuxEmpleado = employee_new();
               if( fread(pAuxEmpleado,sizeof(Employee),1,pFile)==1 )
               {
                   ll_add(pArrayListEmployee, pAuxEmpleado);
                   retorno=0;
               }
               else
               {
                   employee_delete(pAuxEmpleado);
               }
           }
       }
       return retorno;
       }

int parser_IdFromText(FILE *pFile)
    {

    int retorno = -1;
    char bufferId[5];
    int cant;

    if (pFile == NULL)
	{
	printf("\nNo se pudo abrir el archivo\n");
	exit(1);
	}
    while (!feof(pFile))
	{
	cant = fscanf(pFile,"%s",bufferId);
	if (cant < 1)
	    {
	    break;
	    }
	retorno = atoi(bufferId);
	}
    return retorno;
    }
