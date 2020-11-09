#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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
    setbuf(stdout, NULL);
    printf("MENU OPCIONES\n");
    int option = 0;
    int flag1 = 0;
    int flag2 = 0;
    int contAdd = 0;
    LinkedList *listaEmpleados = ll_newLinkedList();
    do
	{
	printf(
		"\n"
			"#1-Cargar los datos de los empleados desde archivo de texto \n"
			"#2-Cargar los datos de los empleados desde archivo binario\n"
			"#3-Alta de empleado\n"
			"#4-Modificar datos de empleado\n"
			"#5-Baja de empleado\n"
			"#6-Lista empleados\n"
			"#7-Ordenar empelados\n"
			"#8-Guardar los datos de los empleados en el archivo (modo texto) \n"
			"#9-Guardar los datos de los empleados en el archivo (modo binario)\n"
			"#10-Salir"
			"\n");
	getNumberEmp(&option, "\nElija una opcion: ", "\nOpcion inexistente\n",
		1, 10, 2);
	switch (option)
	    {
	case 1:
	    if (flag2 == 0)
		{
		if (flag1 == 0)
		    {
		    controller_loadFromText("data.csv", listaEmpleados);
		    flag1 = 1;
		    contAdd = 1000;
		    }
		else
		    {
		    printf("\nImposible cargar archivo modo texto\n"
			    "\nMotivo: Fue cargado 1 vez anteriormente\n");

		    }
		}
	    else
		{
		printf(
			"\nImposible cargar archivo modo texto\n"
				"\nMotivo: Fue cargado en modo binario anteriormente\n");

		}
	    break;
	case 2:
	    if (flag1 == 0)
		{
		if (flag2 == 0)
		    {
		    controller_loadFromBinary("data.bin", listaEmpleados);
		    flag2 = 1;
		    contAdd = 1000;
		    }
		else
		    {
		    printf("\nImposible cargar archivo modo binario\n"
			    "\nMotivo: Fue cargado 1 vez anteriormente\n");
		    }
		}
	    else
		{
		printf("\nImposible cargar archivo modo binario\n"
			"\nMotivo: Fue cargado desde texto anteriormente\n");
		}
	    break;
	case 3:
	    if ((flag1 || flag2) == 1)
		{
		if (controller_addEmployee(listaEmpleados) == 0)
		    {
		    printf("\nEmpleado agregado correctamente\n");
		    contAdd++;
		    }
		else
		    {
		    printf(
			    "\nImposible agregar empleado\n"
				    "[Motivo]: Al menos un dato no pudo ser guardado\n");
		    }
		}
	    else
		{
		printf("\nImposible agregar empleados\n"
			"[Motivo]: No se cargo ninguna lista de empleados\n");
		}
	    break;
	case 4:
	    if ((flag1 || flag2) == 1)
		{
		if (contAdd > 0)
		    {
		    if (controller_editEmployee(listaEmpleados) == 0)
			{
			printf("\nEmpleado editado correctamente\n");
			}
		    }
		else
		    {
		    printf("\nImposible editar empleado\n"
			    "[Motivo]: No existen empleados\n");
		    }
		}
	    else
		{
		printf("\nImposible editar empleado\n"
			"[Motivo]: No se cargo ninguna lista de empleados\n");
		}
	    break;
	case 5:
	    if ((flag1 || flag2) == 1)
		{
		if (contAdd > 0)
		    {
		    if (controller_removeEmployee(listaEmpleados) == 0)
			{
			printf("\nEmpleado dado de baja correctamente\n");
			contAdd--;
			}
		    }
		else
		    {
		    printf("\nImposible dar de baja empleado\n"
			    "[Motivo]: No existen empleados\n");
		    }
		}
	    else
		{
		printf("\nImposible dar de baja empleado\n"
			"[Motivo]: No se cargo ninguna lista de empleados\n");
		}
	    break;
	case 6:
	    if ((flag1 || flag2) == 1)
		{
		if (contAdd > 0)
		    {
		    if (controller_ListEmployee(listaEmpleados) == 0)
			{
			printf("\nEmpleados listados correctamente\n");
			}
		    }
		else
		    {
		    printf("\nImposible listar empleados\n"
			    "[Motivo]: No existen empleados\n");
		    }
		}
	    else
		{
		printf("\nImposible listar empleados\n"
			"[Motivo]: No se cargo ninguna lista de empleados\n");
		}

	    break;
	case 7:
	    if ((flag1 || flag2) == 1)
		{
		if (contAdd > 0)
		    {
		    if (controller_sortEmployee(listaEmpleados) == 0)
			{
			printf("\nEmpleados ordenados correctamente\n");
			}
		    }
		else
		    {
		    printf("\nImposible ordenar empleados\n"
			    "[Motivo]: No existen empleados\n");
		    }
		}
	    else
		{
		printf("\nImposible ordenar empleados\n"
			"[Motivo]: No se cargo ninguna lista de empleados\n");
		}

	    break;
	case 8:
	    if(flag1 == 1 || flag2 == 1)
		{
		if (controller_saveAsText("data.csv", listaEmpleados) == 0)
		    {
		    printf("\nArchivo de texto guardado con exito\n");
		    }
		}
	    else
		{
		printf("\nImposible guardar archivo\n"
			"[Motivo]: No se cargo el ningun archivo\n");
		}

	    break;
	case 9:
	    if (flag1 == 1 || flag2 == 1)
		{
		if (controller_saveAsBinary("data.bin", listaEmpleados) == 0)
		    {
		    printf("\nArchivo binario guardado con exito\n");

		    }
		}
	    else
		{
		printf("\nImposible guardar archivo\n"
			"[Motivo]: No se cargo el ningun archivo \n");
		}
	    break;
	case 10:
	    printf("\nSaliendo del programa\n");
	    break;

	    }
	}
    while (option != 10);
    return 0;
    }

