/*
 * menu.c
 *
 *  Created on: 26 sep. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "utn.h"
#include <string.h>

int menuOpcionesEmp()
    {

    printf("\n<<BIENVENIDO AL MENU>>\n");
    char respuesta = 'r';
    int comando;
    int flag1 = 0;
    int identify = 0;
    int index;
    float promSalary;
    float acumuladorSalarios = 0;
    int supSalProm;
    int contadorEmp = 0;

    Employee auxiliar;
    Employee aEmployees[QTY_EMPLOYEES];

    initEmployees(aEmployees, QTY_EMPLOYEES);
    do
	{
	printf(
		"\n#1-ALTAS.\n#2-MODIFICAR.\n#3-BAJA.\n#4-INFORMAR.\n#5-SALIR.\n");
	getNumberEmp(&comando, "\nIngrese Opcion: ", "\nOpcion Incorrecta\n", 1,
		6, 2);
	switch (comando)
	    {
	case 1:
	    system("cls");
	    printf("\nSECCION AGREGAR EMPLEADO\n");
	    if (getNameEmp(auxiliar.lastName, "\nIngrese Apellido: ",
		    "\n¡Error! Solo letras\n",
		    LRG_STRING, 'A', 'z', 2) == 0
		    && getNameEmp(auxiliar.name, "\nIngrese nombre: ",
			    "\n¡Error! Solo letras\n",
			    LRG_STRING, 'A', 'z', 2) == 0
		    && getNumberEmp(&auxiliar.sector, "\nIngrese Sector: ",
			    "\n¡Error! Minimo 0/Maximo 1000.\n", 0, 1000, 2)
			    == 0
		    && getNumberFloatEmp(&auxiliar.salary,
			    "\nIngrese Salario: ",
			    "\n¡Error! Minimo 1/Maximo 10 mil\n", 0, 10000, 2)
			    == 0)
		{
		identifyEmp(identify, &identify);
		addEmployee(aEmployees, QTY_EMPLOYEES, identify, auxiliar.name,
			auxiliar.lastName, auxiliar.salary, auxiliar.sector);
		contadorEmp++;
		index = findEmployeeById(aEmployees, QTY_EMPLOYEES, identify);
		printOneEmployee(aEmployees, QTY_EMPLOYEES, index);
		}
	    else
		{
		printf("\n¡Opcion inexistente!\n");
		}

	    flag1 = 1;
	    break;
	case 2:
	    if (flag1 == 1)
		{
	    system("cls");
	    printf("\nSECCION MODIFICAR EMPLEADO\n");
		getNumberEmp(&identify, "\nIngrese ID: ",
			"\n¡Opcion Incorrecta!\n", 1, 1000, 2);

		index = findEmployeeById(aEmployees, QTY_EMPLOYEES, identify);
		if (index != -1)
		    {

		    printOneEmployee(aEmployees, QTY_EMPLOYEES, index);
		    printf(
			    "\n#1-Apellido.\n#2-Nombre.\n#3-Salario.\n#4-Sector.\n#5-Atras.\n");

		    getNumberEmp(&comando, "\nIngrese Opcion: ",
			    "\n¡Opcion Incorrecta!\n", 1, 5, 2);
		    }
		else
		    {
		    printf("\nEse ID no esta registrado o fue dado de baja\n");
		    break;
		    }
		switch (comando)
		    {
		case 1:
		    printf("\nSECCION MODIFICAR APELLIDO\n");
		    getNameEmp(aEmployees[index].lastName,
			    "\nIngrese modificacion de apellido: ",
			    "\n¡Error!\n",
			    LRG_STRING, 'A', 'z', 2);
		    break;
		case 2:
		    printf("\nSECCION MODIFICAR NOMBRE\n");
		    getNameEmp(aEmployees[index].name,
			    "\nIngrese modificacion de nombre: ", "\n¡Error!\n",
			    LRG_STRING, 'A', 'z', 2);
		    break;
		case 3:
		    printf("\nSECCION MODIFICAR SALARIO\n");
		    getNumberFloatEmp(&aEmployees[index].salary,
			    "\nIngrese modificacion de salario: ",
			    "\n¡Error!\n", 0, 10000, 2);
		    break;
		case 4:
		    printf("\nSECCION MODIFICAR SECTOR\n");
		    getNumberEmp(&aEmployees[index].sector,
			    "\nIngrese modificacion de sector: ", "\n¡Error!\n",
			    0, 1000, 2);
		    break;
		case 5:
		    printf("\nVolviendo al menu principal\n");
		    system("pause");
		    break;
		    }

		printOneEmployee(aEmployees, QTY_EMPLOYEES, index);
		}
	    else
		{
		printf("\nDebe ingresar un empleado para poder modificarlo\n");
		}

	    break;
	case 3:
	    if (flag1 == 1)
		{
	    system("cls");
	    printf("\nSECCION ELIMINAR EMPLEADO\n");
		getNumberEmp(&identify, "\nIngrese ID: ",
			"\n¡Opcion Incorrecta!\n", 1, 1000, 2);
		index = findEmployeeById(aEmployees, QTY_EMPLOYEES, identify);
		if (index != -1)
		    {
		    printOneEmployee(aEmployees, QTY_EMPLOYEES, index);
		    printf("\n#1-Eliminar \n#2-Cancelar \n");
		    getNumberEmp(&comando, "\nIngrese Opcion: ",
			    "\n¡Opcion Incorrecta!\n", 1, 2, 2);
		    printf("\nVA A ELIMINAR A:\n ");
		    printOneEmployee(aEmployees, QTY_EMPLOYEES, index);
		    }
		else
		    {
		    printf("\nEse ID no esta registrado o fue dado de baja\n");
		    break;
		    }

		switch (comando)
		    {
		case 1:
		    removeEmployees(aEmployees, QTY_EMPLOYEES, identify);
		    contadorEmp--;
		    printf("\n¡Empleado eliminado!\n");
		    break;
		case 2:
		    printf("\nEliminar cancelado.\n");
		    break;
		    }
		}
	    else
		{
		printf("\nDebe ingresar un empleado antes de eliminar\n");
		}
	    break;

	case 4:
	    if (flag1 == 1)
		{
	    system("cls");
	    printf("\nSECCION MOSTRAR EMPLEADOS Y SUELDOS\n");
		printf(
			"\n#1-Listado de Empleados(ordenados).\n#2-Total,promedio y empleados sobre la media de salario.\n");
		getNumberEmp(&comando, "\nIngrese Opcion: ",
			"\n¡Opcion Incorrecta!\n", 1, 2, 2);
		switch (comando)
		    {
		case 1:
		    if (contadorEmp > 0)
			{
			sortEmployees(aEmployees, QTY_EMPLOYEES, 1);
			printEmployees(aEmployees, QTY_EMPLOYEES);
			}
		    else
			{
			printf("\nNo hay empleados para mostrar\n");
			}
		    break;
		case 2:

		    if (contadorEmp == 0)
			{
			acumuladorSalarios = 0;
			promSalary = 0;
			supSalProm = 0;
			}
		    else
			{
			totalSalary(aEmployees, &acumuladorSalarios,
			QTY_EMPLOYEES);
			promedio(aEmployees, &promSalary, QTY_EMPLOYEES);
			supSalProm = superanPromedio(aEmployees, promSalary,
			QTY_EMPLOYEES);

			}
		    printf("\nEl total de los salarios es: %.2f\n",
			    acumuladorSalarios);
		    printf("\nEl promedio de los salarios es: %.2f\n",
			    promSalary);
		    printf("\nSuperan el promedio: %d\n", supSalProm);
		    break;
		    }

		break;
		case 5:
		printf("\n¡Adios, hasta luego!\n");
		system("pause");
		respuesta = 'j';
		break;
		default:
		printf("\nIngrese opcion valida\n");
		break;
		}
	    else
		{
		printf("\nDebe ingresar un empleado antes de mostrar\n");
		}
	    }

	}
    while (respuesta == 'r');

    return 0;
    }

