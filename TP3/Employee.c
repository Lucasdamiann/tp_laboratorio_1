#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

Employee* employee_new()
    {
    Employee *nuevoEmpleado = NULL;
    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if (nuevoEmpleado != NULL)
	{
	employee_setId(nuevoEmpleado, 0);
	employee_setNombre(nuevoEmpleado, " ");
	employee_setHorasTrabajadas(nuevoEmpleado, 0);
	employee_setSueldo(nuevoEmpleado, 0);
	}

    return nuevoEmpleado;

    }

Employee* employee_newParametros(char *idStr, char *nombreStr,
	char *horasTrabajadasStr, char *sueldoStr)
    {
    Employee *nuevoEmpleado = employee_new();

    if (nuevoEmpleado != NULL)
	{
	if (!employee_setId(nuevoEmpleado, atoi(idStr))
		&& !employee_setNombre(nuevoEmpleado, nombreStr)
		&& !employee_setHorasTrabajadas(nuevoEmpleado,
			atoi(horasTrabajadasStr))
		&& !employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))
	    {

	    return nuevoEmpleado;
	    }
	}

    free(nuevoEmpleado);
    return NULL;
    }

void employee_delete(Employee *this)
    {
    free(this);
    }

int employee_setId(Employee *this, int id)
    {
    int retorno = -1;

    if (this != NULL && id > 0)
	{
	this->id = id;
	retorno = 0;
	}
    return retorno;
    }

int employee_getId(Employee *this, int *id)
    {
    int retorno = -1;

    if (this != NULL && id != NULL)
	{
	*id = this->id;
	retorno = 0;
	}
    return retorno;
    }

int employee_setNombre(Employee *this, char *nombre)
    {
    int retorno = -1;

    if (this != NULL && nombre != NULL)
	{
	strcpy(this->nombre, nombre);
	retorno = 0;
	}

    return retorno;
    }
int employee_getNombre(Employee *this, char *nombre)
    {
    int retorno = -1;

    if (this != NULL && nombre != NULL)
	{
	strcpy(nombre, this->nombre);
	retorno = 0;
	}

    return retorno;
    }

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
    {
    int retorno = -1;
    if (this != NULL)
	{
	this->horasTrabajadas = horasTrabajadas;
	retorno = 0;
	}
    return retorno;
    }

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas)
    {
    int retorno = -1;
    if (this != NULL && horasTrabajadas != NULL)
	{
	*horasTrabajadas = this->horasTrabajadas;
	retorno = 0;
	}
    return retorno;
    }

int employee_setSueldo(Employee *this, int sueldo)
    {
    int retorno = -1;
    if (this != NULL)
	{
	this->sueldo = sueldo;
	retorno = 0;
	}
    return retorno;
    }
int employee_getSueldo(Employee *this, int *sueldo)
    {
    int retorno = -1;
    if (this != NULL && sueldo != NULL)
	{
	*sueldo = this->sueldo;
	retorno = 0;
	}
    return retorno;
    }
int employee_print(Employee *this)
    {
    int retorno = -1;
    Employee aux;
    if (this != NULL)
	{

	if ((employee_getId(this, &aux.id) == 0)
		&& (employee_getNombre(this, aux.nombre) == 0)
		&& (employee_getHorasTrabajadas(this, &aux.horasTrabajadas) == 0)
		&& (employee_getSueldo(this, &aux.sueldo)) == 0)
	    {

	    printf(" %5d   %15s   %20d  %12d\n", aux.id, aux.nombre,
		    aux.horasTrabajadas, aux.sueldo);
	    retorno = 0;

	    }

	}

    return retorno;
    }

int employee_setNewId(char *path)
    {

    FILE *pFile;
    int id;
    if (path != NULL)
	{
	if ((pFile = fopen(path, "r")) != NULL)
	    {
	    id = parser_IdFromText(pFile);
	    }

	fclose(pFile);
	}
    return id + 1;
    }
int employee_saveNewId(char *path, int id)
    {
    int retorno = -1;
    FILE *pFile;
    if (path != NULL)
	{
	if ((pFile = fopen(path, "a")) != NULL)
	    {
	    fprintf(pFile, "%d\n", id);
	    retorno = 0;
	    }
	fclose(pFile);
	}
    return retorno;
    }
Employee* employee_add()
    {

    Employee aux;
    Employee *auxEmployee;
    char arrayId[5];
    char horasT[4];
    char arraySueldo[7];

    if (!getNameEmp(aux.nombre, "\nIngrese nombre: ",
	    "\nError al ingresar nombre\n", 30, 'A', 'z', 2)
	    && !getNumberEmp(&aux.horasTrabajadas,
		    "\nIngrese cantidad de horas trabajadas:",
		    "\nError al ingresar horas\n", 0, 744, 2)
	    && !getNumberEmp(&aux.sueldo, "\nIngrese sueldo:",
		    "\nError al ingresar sueldo\n", 0, 999999, 2))
	{
	aux.id = employee_setNewId("dataID.csv");
	employee_saveNewId("dataID.csv", aux.id);
	itoa(aux.id, arrayId, 10);
	itoa(aux.horasTrabajadas, horasT, 10);
	itoa(aux.sueldo, arraySueldo, 10);
	auxEmployee = employee_newParametros(arrayId, aux.nombre, horasT,
		arraySueldo);

	}
    return auxEmployee;
    }
Employee* employee_edit(LinkedList *this)
    {
    int opcion;
    int idSeleccionada;
    char nombre[30];
    int hs;
    int sueldo;
    int index;
    Employee *auxEmployee;

    getNumberEmp(&idSeleccionada, "\nIngrese ID de empleado a modificar: \n",
	    "\nID incorrecta\n", 1, ll_len(this), 2);
    employee_getIndexbyId(this, idSeleccionada, &index);
    printf("\n"
	    "#1-Modificar Nombre\n"
	    "#2-Modificar Horas Trabajadas\n"
	    "#3-Modificar Sueldo\n"
	    "#4-Salir\n");
    getNumberEmp(&opcion, "\nIngrese opcion: \n", "\nOpcion inexistente\n", 1,
	    4, 2);
    auxEmployee = ll_get(this, index);
    switch (opcion)
	{

    case 1:
	getNameEmp(nombre, "\nIngrese nombre nuevo: ", "\nNombre incorrecto\n",
		29, 'A', 'z', 2);
	employee_setNombre(auxEmployee, nombre);
	break;
    case 2:
	getNumberEmp(&hs, "\nIngrese Horas trabajadas nuevas: \n",
		"\nCantidad de horas incorrecta\n", 1, ll_len(this), 2);
	employee_setHorasTrabajadas(auxEmployee, hs);
	break;
    case 3:
	getNumberEmp(&sueldo, "\nIngrese sueldo nuevo: \n",
		"\nCantidad de sueldo incorrecta\n", 1, ll_len(this), 2);
	employee_setSueldo(auxEmployee, sueldo);
	break;
    case 4:

	break;
	}
    ll_set(this, index, auxEmployee);
    return auxEmployee;
    }

int employee_getIndexbyId(LinkedList *this, int id, int *index)
    {
    int retorno = -1;
    int idSelec;
    Employee *auxEmployee;
    if (this != NULL)
	{
	for (int i = 0; i < ll_len(this); i++)
	    {
	    auxEmployee = ll_get(this, i);
	    if (auxEmployee != NULL && !employee_getId(auxEmployee, &idSelec)
		    && idSelec == id)
		{
		*index = i;
		retorno = 0;
		break;
		}
	    }
	}
    return retorno;
    }
void employee_sort(Employee *this, int tam)
    {
    Employee aux;
    for (int i = 0; i < tam - 1; i++)
	{
	for (int j = i + 1; j < tam; j++)
	    {
	    if ((*(this + i)).sueldo > ((*(this + j)).sueldo))
		{
		aux = *(this + i);
		*(this + i) = *(this + j);
		*(this + j) = aux;
		}
	    }
	}
    }

