/*
 * valicacion.h
 *
 *  Created on: 23 sep. 2020
 *      Author: Lucasdamiann
 */

#ifndef VALICACION_H_
#define VALICACION_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "arrayEmployees.h"


#endif /* VALIDACION_H_ */
/*\brief Entrega un valor promediado por los datros recibidos.
 * \param Employee*list puntero a la estructura.
 * \param float *pCalculoResulProm puntero a variable donde se devuelve lo hecho por la funcion.
 * \param int len valor de largo del array.
 *\ return int retorno (-1) si hay Error [algun puntero == NULL y len <0] - (0) si está Ok
 */
float promedio(Employee*list, float *pCalculoResultProm,int len);
/*\brief Entrega la cantidad de usuarios que superan el promedio.
 * \param Employee*list puntero a la estructura.
 * \param float salaryProm recibe el valor del promedio hasta el momento.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [puntero == NULL y len <0] - (retorna por valor) si está Ok
 */
float superanPromedio(Employee *list,float salaryProm,int len);
/*\brief Entrega la cantidad de salarios acumulados.
 * \param Employee*list puntero a la estructura.
 * \param float * salary valor de puntero que recibe el valor del salario y lo devuelve por referencia.
 * \param int len valor de largo del array.
 *\ return int ret (-1) si hay Error [algun puntero == NULL y len <0] - (0) si está Ok
 */
float totalSalary(Employee* list,float * salary,int len);
/*\brief Recibe un numero,por teclado,muestra un mensaje,muestra un mensaje de error,recibe un minimo y un maximo para el numero que se ingrese, recibe cantidad de reintentos.
 * \param int* pResultado puntero a variable que recibe un valor por teclado y lo retorna por referencia.
 * \param char* mensaje array de caracteres con mensaje.
 * \param char* mensajeError array de caracteres con mensaje de error.
 * \param int minimo valor de minima que puede ingresarse.
 * \param int maximo valor de maxima que puede ingresarse.
 * \param int reintentos valor de cantidad de reintentos posibles.
 *\ return int retorno (-1) si hay Error [algun puntero == NULL, minimo mayor a maximo, reintentos negativos] - (0) si está Ok
 */
int getNumberEmp(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
/*\brief Recibe un numero,por teclado,muestra un mensaje,muestra un mensaje de error,recibe un minimo y un maximo para el numero que se ingrese, recibe cantidad de reintentos.
 * \param float* pResultado puntero a variable que recibe un valor por teclado y lo retorna por referencia.
 * \param char* mensaje array de caracteres con mensaje.
 * \param char* mensajeError array de caracteres con mensaje de error.
 * \param float minimo valor de minima que puede ingresarse.
 * \param float maximo valor de maxima que puede ingresarse.
 * \param int reintentos valor de cantidad de reintentos posibles.
 *\ return int retorno (-1) si hay Error [algun puntero == NULL, minimo mayor a maximo, reintentos negativos] - (0) si está Ok
 */
int getNumberFloatEmp(float *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos);

/*\brief Obtiene una cadena de caracteres, muestra un mensaje,muestra un mensaje de error,recibe un minimo y un maximo para la letras que ingrese, recibe cantidad de reintentos.
 * \param char *aResultado array de caracteres.
 * \param char *mensaje array de caracteres con mensaje.
 * \param char *mensajeError array de caracteres con mensaje de error.
 * \param int len valor de largo del array.
 * \param char minimo valor de minima que puede ingresarse.
 * \param char maximo valor de maxima que puede ingresarse.
 * \param int reintentos valor de cantidad de reintentos posibles.
 *\ return int retorno (-1) si hay Error [puntero == NULL o largo de array <0] - (0) si está Ok
 */

int getNameEmp(char *aResultado, char *mensaje, char *mensajeError,int len,char minimo, char maximo, int retries);
/*\brief Valida si el dato ingresado es una cadena de caracteres.
 * \param char *aResultado array de caracteres.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int isNameEmp(char *aResultado);
/*\brief Valida el largo y el final de un array de caracteres.
 * \param char *aResultado array de caracteres.
 * \param int longitud largo de array de caracteres.
 *\ return int retorno (-1) si hay Error [puntero == NULLy longitud <0] - (0) si está Ok
 */
int myGetsEmp(char *aResultado, int longitud);
/*\brief Valida si el dato ingresado es un numero(positivo o negativo) y  cuenta cantidad de puntos.
 * \param char *pResultado array de caracteres numericos.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int isNumberEmp(char *pResultado);
/*\brief Recibe un numero y lo convierte a float.
 * \param float *pResultado array de numeros, retorna por referencia.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int getFloatEmp(float *pResultado);
/*\brief Recibe un numero y lo convierte a int.
 * \param int *pResultado array de numeros, retorna por referencia.
 *\ return int retorno (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int getIntEmp(int *pResultado);
/*\brief Entrega un valor de ID en base a un contador.
 * \param int valorId valor actual de contador (asociado a ID)
 * \param int *id  valor de puntero de contador (asociado a ID)
 *\ return int ret (-1) si hay Error [puntero == NULL] - (0) si está Ok
 */
int identifyEmp(int valorId, int* id);
