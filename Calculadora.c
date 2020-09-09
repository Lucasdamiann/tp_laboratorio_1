/*
 * Calculadora.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Lucasdamiann
 */
#include <stdio.h>
#include <stdlib.h>

int suma(float operando1, float operando2) {
	float resultado;
	resultado = operando1 + operando2;
	return resultado;
}

int resta(float operando1, float operando2) {
	float resultado;
	resultado = operando1 - operando2;
	return resultado;
}
int division(float *pCalculoResultado, float operando1, float operando2) {
	float resultado;
	int retorno = -1;
	if (pCalculoResultado != NULL && operando2 != 0) {
		resultado = (float) operando1 / operando2;
		*pCalculoResultado = resultado;
		retorno = 0;
	}
	return retorno;

}
int multiplicacion(float operando1, float operando2) {
	float resultado;
	resultado = operando1 * operando2;
	return resultado;
}
double factoreoA(float operando1) {
	float resultado;
	if (operando1 == 0 || operando1 == 1) {
		return 1;
	}
	resultado = operando1 * factoreoA(operando1 - 1);
	return resultado;
}

