/*
 * arrayEmployees.c
 *
 *  Created on: 26 sep. 2020
 *      Author: Lucasdamiann
 */

#ifndef ARRAYEMPLOYEES_C_
#define ARRAYEMPLOYEES_C_
#include "arrayEmployees.h"
#include <string.h>
#include "utn.h"
#endif /* ARRAYEMPLOYEES_C_ */

int printEmployees(Employee *list, int len)
    {
    int retorno = -1;
    if (list != NULL && len > 0)
	{
		printf("\n[Apellido]          [Nombre] 	        [ID]          [Sector]          [Salario]\n");
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0)
		{
		printf("\n»%-10s         »%-10s         »%-4.4d         »%-4.4d             »%-4.2f\n",
			list[i].lastName, list[i].name, list[i].id,
			list[i].sector, list[i].salary);
		}

	    }
	retorno = 0;
	}
    return retorno;
    }

int printOneEmployee(Employee *list, int len, int index)
    {
    int retorno = -1;
    if (list != NULL && len > 0)
	{
	if (list[index].isEmpty == 0)
	    {
	    printf("\n[Apellido]          [Nombre] 	        [ID]          [Sector]          [Salario]\n");
	    printf(
		    "\n»%-10s         »%-10s         »%-4.4d         »%-4.4d             »%-4.2f\n",
		    list[index].lastName, list[index].name,list[index].id, list[index].sector,
		    list[index].salary);
	    }
	retorno = 0;
	}
    return retorno;
    }

int initEmployees(Employee *list, int len)
    {
    int retorno = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {

	    list[i].isEmpty = 1;
	    }
	retorno = 0;
	}
    return retorno;
    }

int sortEmployees(Employee *list, int len, int order)
    {
    int retorno = -1;
    Employee aux;
    int flag = 0;
    int nuevoLimite;
    if (list != NULL && len > 0)
	{
	nuevoLimite = len - 1;
	while (flag == 0)
	    {
	    flag = 1;
	    for (int i = 0; i < nuevoLimite; i++)
		{
		if (((strcmp(list[i].lastName, list[i + 1].lastName) < 0)&& order == 0) || ((strcmp(list[i].lastName, list[i + 1].lastName) == 0) && ((list[i].sector < list[i + 1].sector) && order == 0)))
		    {
		    aux = list[i];
		    list[i] = list[i + 1];
		    list[i + 1] = aux;
		    retorno = 0;
		    flag = 0;
		    }
		else if (((strcmp(list[i].lastName, list[i + 1].lastName) > 0) && order == 1)|| ((strcmp(list[i].lastName, list[i + 1].lastName) == 0) && ((list[i].sector > list[i + 1].sector) && order == 1)))
		    {
		    aux = list[i];
		    list[i] = list[i + 1];
		    list[i + 1] = aux;
		    retorno = 0;
		    flag = 0;
		    }
		}
	    nuevoLimite--;
	    }
	}
    return retorno;
    }

int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
	float salary, int sector)
    {
    int ret = -1;
    int position;
    if (list != NULL && name != NULL && lastName != NULL && len > 0)
	{
	position = searchFreeSpace(list, QTY_EMPLOYEES);
	list[position].id = id;
	strncpy(list[position].lastName, lastName, LRG_STRING);
	strncpy(list[position].name, name, LRG_STRING);
	list[position].salary = salary;
	list[position].sector = sector;
	list[position].isEmpty = 0;
	ret = 0;
	}
    return ret;
    }



int removeEmployees(Employee *list, int len, int id)
    {
    int retorno = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].id == id && list[i].isEmpty == 0)
		{
		list[i].isEmpty = 1;
		retorno = 0;
		break;
		}

	    }
	}
    return retorno;
    }

int findEmployeeById(Employee *list, int len, int id)
    {
    int ret = -1;
    if (list != NULL && len>0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].id == id && list[i].isEmpty == 0)
		{
		ret = i;
		break;
		}
	      }
	}
    return ret;
    }

