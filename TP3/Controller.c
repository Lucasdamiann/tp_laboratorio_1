#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "controller.h"
#include "parser.h"
#include "utn.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
    {
    FILE *pArch;
    if (path != NULL && pArrayListEmployee != NULL)
	{
	if ((pArch = fopen(path, "r")) != NULL)
	    {
	    printf("\nArchivo cargado con exito\n");
	    parser_EmployeeFromText(pArch, pArrayListEmployee);
	    }
	else
	    {
	    printf("\nOcurrio un error y no se puede abrir\n");
	    }

	fclose(pArch);
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
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
    {
    int retorno=-1;
    FILE *pArch;
       if (path != NULL && pArrayListEmployee != NULL)
   	{
   	if ((pArch = fopen(path, "rb")) != NULL)
   	    {
   	    printf("\nArchivo cargado con exito\n");
   	    parser_EmployeeFromBinary(pArch, pArrayListEmployee);
   	    retorno=0;
   	    }
   	else
   	    {
   	    printf("\nOcurrio un error y no se puede abrir\n");
   	    }

   	fclose(pArch);
   	}
       return retorno;
       }


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
    {
    int retorno = -1;

    if (pArrayListEmployee != NULL)
	{
	ll_add(pArrayListEmployee, employee_add());

	retorno = 0;
	}
    return retorno;
    }

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
    {
    int retorno = -1;

    if (pArrayListEmployee != NULL)
	{
	controller_ListEmployee(pArrayListEmployee);
	employee_edit(pArrayListEmployee);

	}
    return retorno;
    }

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
    {
    int retorno = -1;
    int index;
    int id;
    if (pArrayListEmployee != NULL)
	{
	controller_ListEmployee(pArrayListEmployee);
	getNumberEmp(&id, "\nIngrese ID de empleado a eliminar\n",
		"\nID inexistente", 1, ll_len(pArrayListEmployee), 2);
	employee_getIndexbyId(pArrayListEmployee, id, &index);
	ll_remove(pArrayListEmployee, index);
	retorno = 0;
	}
    return retorno;
    }

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
    {
    int retorno = -1;
    Employee *pEmpleado;
    int length = ll_len(pArrayListEmployee);
    if (pArrayListEmployee != NULL)
	{
	printf(
		"-----------------------------------------------------------------\n");
	printf(
		"    ID            NOMBRE       HORAS TRABAJADAS        SUELDO\n");
	printf(
		"-----------------------------------------------------------------\n");
	for (int i = 0; i < length; i++)
	    {
	    pEmpleado = ll_get(pArrayListEmployee, i);
	    employee_print(pEmpleado);
	    retorno = 0;
	    }
	printf("\n\n");
	}

    return retorno;
    }

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
    {
    int retorno=-1;
    Employee* pEmpleado;
    if(pArrayListEmployee!=NULL)
	{

	employee_sort(pEmpleado, ll_len(pArrayListEmployee));
	printf("\ndespuesdel sort\n");
	retorno=0;
	}
    return retorno;
    }

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
    {

    FILE *pArch;
    int auxId;
    char auxNombre[51];
    int auxHs;
    int auxSueldo;
    Employee *pEmpleado;
    int retorno = -1;
    if (path != NULL && pArrayListEmployee != NULL)
	{
	if ((pArch = fopen(path, "w")) != NULL)
	    {
	    retorno = 0;
	    for (int i = 1; i < ll_len(pArrayListEmployee); i++)
		{
		pEmpleado = ll_get(pArrayListEmployee, i);
		if ((employee_getId(pEmpleado, &auxId) == 0)
			&& (employee_getNombre(pEmpleado, auxNombre) == 0)
			&& (employee_getHorasTrabajadas(pEmpleado,
				&auxHs) == 0)
			&& (employee_getSueldo(pEmpleado, &auxSueldo) == 0))
		    {
		    fprintf(pArch, "%d,%s,%d,%d\n", auxId, auxNombre,
			    auxHs, auxSueldo);
		    }
		}
	    }
	else
	    {
	    printf("El archivo no puede ser abierto");
	    exit(1);
	    }
	fclose(pArch);
	}
    return retorno;
    }

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
    {
    FILE* pFile;
    Employee *pEmpleado;
    int retorno = -1;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if (pFile != NULL){
            retorno = 0;
            for (int i = 0 ; i < ll_len(pArrayListEmployee) ; i++){
                pEmpleado = ll_get(pArrayListEmployee, i);
                fwrite(pEmpleado, sizeof(Employee), 1, pFile);
            }
        }
    }
    fclose(pFile);
    return retorno;

    }

