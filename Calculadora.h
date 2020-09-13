/*
 * Calculadora.h
 *
 *  Created on: 5 sep. 2020
 *      Author: Lucas Bracuto
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#endif /* CALCULADORA_H_ */



int menu();
/*
 * \brief    llama a la funcion menu
  *\return   devuelve 0 para correcto/ distinto de 0 para incorrecto.
 */
int suma(float* pCalculoResultSum,float operando1, float operando2);
/*
 *\brief   realiza la suma entre dos valores ingresados por teclado.
 *\param    valor de puntero de suma.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\return   devuelve 0 para correcto/ devuelve -1 para incorrecto.
 */
int resta(float* pCalculoResultRes, float operando1, float operando2);
/*
 *\brief   realiza la resta entre dos valores ingresados por teclado.
 *\param    valor de puntero de resta.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\return   devuelve 0 para correcto/ devuelve -1 para incorrecto.
 */
int division(float* pCalculoResultDiv, float operando1, float operando2);
/*
 *\brief   realiza la division entre dos valores ingresados por teclado.
 *\param    valor de puntero de division.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\param    valor ingresado por teclado que puede ser negativo,positivo pero no cero.
 *\return   devuelve 0 para correcto/ devuelve -1 para incorrecto.
 */
int multiplicacion(float* pCalculoResultMul,float operando1, float operando2);
/*
 *\brief   realiza la multiplicacion entre dos valores ingresados por teclado.
 *\param    valor de puntero de multiplicacion.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\return   devuelve 0 para correcto/ devuelve -1 para incorrecto.
 */
double factoreo(float* pCalculoResultFac, float operando1) ;
/*
 *\brief   realiza la factorizacion de un valor ingresado por teclado.
 *\param    valor de puntero de factorial.
 *\param    valor ingresado por teclado que puede ser negativo,positivo o cero.
 *\return   devuelve 0 para correcto/ devuelve -1 para incorrecto.
 */

