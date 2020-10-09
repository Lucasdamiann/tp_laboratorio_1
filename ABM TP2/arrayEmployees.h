/*
 * arrayEmployees.h
 *
 *  Created on: 26 sep. 2020
 *      Author: Lucasdamiann
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>



#define QTY_EMPLOYEES 1000
#define LRG_STRING 51
typedef  struct
{
 int id;
 char name[LRG_STRING];
 char lastName[LRG_STRING];
 float salary;
 int sector;
 int isEmpty;
} Employee;


/*\brief Busca espacios vacios en el array(isEmpty==1).
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (pasaje del i por valor) si está Ok
 */
int searchFreeSpace(Employee* list, int len);
/*\brief Busca si un ID recibido existe y si el espacio de ese ID esta ocupado(isEmpty==0)
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de id.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (pasaje del i por valor) si está Ok
 */
int findEmployeeById(Employee *list, int len, int id);
/*\brief Imprime apellido,nombre,id,sector y salario de todos los lugares ocupados(isEmpty==0).
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printEmployees(Employee* list, int len);
/*\brief Imprime apellido,nombre,id,sector y salario de uno los lugares ocupados (isEmpty==0) segun indice.
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int index valor de indice del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int printOneEmployee(Employee *list, int len, int index);
/*\brief Cambia el estado del isEmpty de 0 (FALSE) a 1 (TRUE) del ID ingresado[lo "borra"].
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de ID del usuario.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int removeEmployees(Employee *list, int len, int id);
/*\brief Ordena el array recibido en orden ascendente o descendente segun se ingrese 0 o 1.
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int order valor de orden ascendente 0 o descendente 1.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int sortEmployees(Employee* list, int len, int order);
/*\brief Recorre el array iniciando cada campo isEmpty en 1 (vacio).
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int initEmployees(Employee *list, int len);
/*\brief Agrega un usuario con sus datos (nombre, apellido,id,salario y sector).
 * \param Employee*list puntero a array de estructura.
 * \param int len valor de largo del array.
 * \param int id valor de ID del usuario asignado por el sistema.
 * \param char name estructura de caracteres del array.
 * \param char lasName estructura de caracteres del array.
 * \param float salary valor de salario del usuario.
 * \param int sector valor de sector del usuario.
 *\ return int ret (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

#endif /* ARRAYEMPLOYEES_H_ */
