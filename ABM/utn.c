/*
 * validacion.c
 *
 *  Created on: 23 sep. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "arrayEmployees.h"

int getNameEmp(char *aResultado, char *mensaje, char *mensajeError, int len,
	char minimo, char maximo, int retries)
    {
    int retorno = -1;
    char buffer[len];
    if (aResultado != NULL && mensaje != NULL && mensajeError != NULL
	    && minimo <= maximo && retries >= 0)
	{
	do
	    {
	    printf("%s", mensaje);
	    fflush(stdin);

	    if (myGetsEmp(buffer, sizeof(buffer)) == 0
		    && isNameEmp(buffer) == 1)
		{
		strupr(strncpy(aResultado, buffer, len));
		retorno = 0;
		break;
		}
	    else
		{
		printf("%s", mensajeError);
		retries--;
		if (retries == 0)
		    {
		    printf("\nNo hay mas reintentos\n");
		    }
		printf("\nCantidad de reintentos: %d\n", retries);
		}
	    }
	while (retries >= 0);
	}

    return retorno;
    }

int isNameEmp(char *aResultado)
    {
    int retorno = 1;

    if (aResultado != NULL)
	{
	for (int i = 0; aResultado[i] != '\0'; i++)
	    {
	    if ((aResultado[i] < 'A' || aResultado[i] > 'Z')
		    && (aResultado[i] < 'a' || aResultado[i] > 'z')
		    && aResultado[i] != ' ')
		{
		retorno = 0;
		break;
		}
	    }
	}
    return retorno;
    }

int myGetsEmp(char *aResultado, int longitud)
    {
    int retorno = -1;
    char bufferString[4096];
    if (aResultado != NULL && longitud > 0)
	{
	fflush(stdin);
	if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
	    {
	    if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
		    == '\n')
		{
		bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
			'\0';
		}
	    if (strnlen(bufferString, sizeof(bufferString)) <= longitud)
		{
		strncpy(aResultado, bufferString, longitud);
		retorno = 0;
		}
	    }
	}
    return retorno;
    }

int getNumberEmp(int *pResultado, char *mensaje, char *mensajeError, int minimo,
	int maximo, int reintentos)
    {
    int retorno = -1;
    int bufferInt;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
	    && minimo <= maximo && reintentos > 0)
	{
	do
	    {
	    printf("%s", mensaje);
	    if (getIntEmp(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
		*pResultado = bufferInt;
		retorno = 0;
		break;
		}
	    else
		{
		printf("%s", mensajeError);
		reintentos--;
		}
	    }
	while (reintentos >= 0);
	}
    return retorno;
    }

int getNumberFloatEmp(float *pResultado, char *mensaje, char *mensajeError,
	float minimo, float maximo, int reintentos)
    {
    int retorno = -1;
    float bufferFloat;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
	    && minimo <= maximo && reintentos >= 0)
	{
	do
	    {
	    printf("%s", mensaje);
	    if (getFloatEmp(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
		{
		*pResultado = bufferFloat;
		retorno = 0;
		break;
		}
	    else
		{
		printf("%s", mensajeError);
		reintentos--;
		}
	    }
	while (reintentos >= 0);
	}
    return retorno;
    }
int getIntEmp(int *pResultado)
    {
    int retorno = -1;
    char buffer[4096];
    if (pResultado != NULL)
	{
	if (myGetsEmp(buffer, sizeof(buffer)) == 0 && isNumberEmp(buffer) == 1)
	    {
	    *pResultado = atoi(buffer);
	    retorno = 0;

	    }
	}
    return retorno;
    }

int getFloatEmp(float *pResultado)
    {
    int retorno = -1;
    char buffer[4096];
    if (pResultado != NULL)
	{
	if (myGetsEmp(buffer, sizeof(buffer)) == 0 && isNumberEmp(buffer) == 1)
	    {
	    *pResultado = atof(buffer);
	    retorno = 0;
	    }
	}
    return retorno;
    }
int isNumberEmp(char *pResultado)
    {
    int contadorPuntos = 0;
    int retorno = 1;
    int i = 0;
    if (pResultado != NULL)
	{

	if (pResultado[0] == '-')
	    {
	    i = 1;
	    }

	for (; pResultado[i] != '\0'; i++)
	    {
	    if (pResultado[i] == '.')
		{
		contadorPuntos++;
		}
	    if (((pResultado[i] > '9' || pResultado[i] < '0')
		    && pResultado[i] != '.') || contadorPuntos > 1)
		{
		retorno = 0;
		break;
		}

	    }
	}
    return retorno;
    }
float promedio(Employee *list, float *pCalculoResultProm, int len)
    {
    int retorno = -1;
    float acumSalary = 0;
    int counSalary = 0;
    if (list != NULL && pCalculoResultProm != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0)
		{
		counSalary++;
		acumSalary += list[i].salary;
		}
	    }
	*pCalculoResultProm = acumSalary / counSalary;
	retorno = 0;
	}
    return retorno;
    }
float superanPromedio(Employee *list, float salaryProm, int len)
    {
    int counter = 0;
    int ret = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0 && list[i].salary > salaryProm)
		{
		counter++;
		ret = counter;
		}
	    else if (list[i].isEmpty == 0 && list[i].salary == salaryProm)
		{
		ret = counter;
		}
	    else if (list[i].isEmpty == 1)
		{
		ret = counter;
		}
	    }
	}
    return ret;
    }
float totalSalary(Employee *list, float *salary, int len)
    {
    int ret = -1;
    float acumSalary = 0;
    if (list != NULL && salary != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 0)
		{
		acumSalary += list[i].salary;
		*salary = acumSalary;
		ret = 0;
		}
	    }
	}
    return ret;
    }
int searchFreeSpace(Employee *list, int len)
    {
    int ret = -1;
    if (list != NULL && len > 0)
	{
	for (int i = 0; i < len; i++)
	    {
	    if (list[i].isEmpty == 1)
		{
		ret = i;
		break;
		}
	    }
	}
    return ret;
    }
int identifyEmp(int valorId, int *id)
    {
    int ret = -1;
    int buffer;
    if (id != NULL)
	{
	buffer = valorId + 1;
	*id = buffer;
	ret = 0;
	}
    return ret;
    }

