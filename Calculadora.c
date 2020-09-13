/*
 * Calculadora.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Lucas Bracuto
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Calculadora.h"

int menu() {
	printf("\n<<BIENVENIDO AL MENU>>\n");
	setbuf(stdout, NULL);
	char respuesta = 'r';
	int comando, bandera1 = 0, bandera2 = 0, bandera3 = 0;
	float numero1, numero2, calculoSuma, calculoResta, calculoMultip,
			calculoDiv, calculoFact;
	do {
		printf("\n#1-Ingresar 1° operando.\n");
		printf("#2-Ingresar 2° operando.\n");
		printf("#3-Realizar calculos.\n");
		printf("#4-Mostrar resultados.\n");
		printf("#5-Salir.\n");
		fflush(stdin);
		printf("\n>Ingrese una opcion: ");
		scanf("%d", &comando);

		switch (comando) {
		case 1:
			printf("\n>Ingrese el 1° valor:");
			fflush(stdin);
			scanf("%f", &numero1);
			if (numero1 < 0) {
				printf("¡El valor debe ser positivo!\n");
			} else {
				printf("\n> Seleccionó: %.1f <\n", numero1);
				bandera1 = 1;
			}
			break;
		case 2:
			if (bandera1 == 1) {
				printf("\n>Ingrese el 2° valor:");
				fflush(stdin);
				scanf("%f", &numero2);
				if (numero2 < 0) {
					printf("¡El valor debe ser positivo!\n");
				} else {
					printf("\n> Seleccionó: %.1f <\n", numero2);
					bandera2 = 1;
				}
			} else {
				printf("\n¡Debe ingresar el primer operando!\n");
			}
			break;
		case 3:
			if (bandera1 == 0) {
				printf("¡Debe ingresar el primer operando!");
			} else if (bandera2 == 0) {
				printf("¡Debe ingresar el segundo operando!");
			} else if (bandera1 == 1 && bandera2 == 1) {
				printf("\n¡Calculos realizados!\n");
				bandera3 = 1;
			}
			break;
		case 4:
			if (bandera3 == 1) {
				if (suma(&calculoSuma, numero1, numero2) == 0) {
					;
					printf("\nEl resultado de %.1f + %.1f es %.1f: ", numero1,
							numero2, calculoSuma);
				}
				resta(&calculoResta, numero1, numero2);
				printf("\nEl resultado de %.1f - %.1f es %.1f: ", numero1,
						numero2, calculoResta);
				division(&calculoDiv, numero1, numero2);
				if (numero2 != 0) {
					printf("\nEl resultado de %.1f / %.1f es %.1f: ", numero1,
							numero2, calculoDiv);
				} else {
					printf("\nNo se puede dividir por 0");
				}
				multiplicacion(&calculoMultip, numero1, numero2);
				printf("\nEl resultado de %.1f * %.1f es %.1f: ", numero1,
						numero2, calculoMultip);
				factoreo(&calculoFact, numero1);
				printf("\nEl factorial de %.1f es: %.1f", numero1, calculoFact);
				factoreo(&calculoFact, numero2);
				printf("\nEl factorial de %.1f es: %.1f\n", numero2, calculoFact);

			    printf("\n[Ingrese 'r' para reiniciar]\n"
			    		"[Cualquier tecla para salir]: ");
				fflush(stdin);
				scanf("%c", &respuesta);
				bandera1 = 0;
				bandera2 = 0;
				bandera3 = 0;

			} else {
				printf("Debe calcular antes de mostrar");
			}

			break;
		case 5:
			printf("\n¡Adios, hasta luego!");
			respuesta='j';
			break;
		default:
			printf("Ingrese opcion valida\n");
			break;
		}

	} while (respuesta == 'r');

	return 0;
}

int suma(float *pCalculoResultSum, float operando1, float operando2) {
	int retorno = -1;
	if (pCalculoResultSum != NULL) {
		*pCalculoResultSum = operando1 + operando2;
		retorno = 0;
	}
	return retorno;
}

int resta(float *pCalculoResultRes, float operando1, float operando2) {
	int retorno =-1;
	if (pCalculoResultRes != NULL) {
		*pCalculoResultRes = operando1 - operando2;
		retorno=0;
	}
	return retorno;
}
int division(float *pCalculoResultDiv, float operando1, float operando2) {

	int retorno = -1;
	if (pCalculoResultDiv != NULL && operando2 != 0) {
		*pCalculoResultDiv = (float) operando1 / operando2;
		retorno = 0;
	}
	return retorno;

}
int multiplicacion(float *pCalculoResultMul, float operando1, float operando2) {
	int retorno=-1;
	if(pCalculoResultMul != NULL){
		*pCalculoResultMul = operando1 * operando2;
		retorno=0;
	}
	return retorno;
}
double factoreo(float *pCalculoResultFac, float operando1) {
	int i;
	double resultFact = 1;
	int retorno = -1;

	if (pCalculoResultFac != NULL) {
		if (operando1 == (int) operando1) {
			if (operando1 > 0) {
				for (i = operando1; i > 1; i--) {
					resultFact *= i;
				}
				retorno = 0;
				*pCalculoResultFac = resultFact;

			} else if (operando1 == 0) {
				*pCalculoResultFac = 1;
				retorno = 0;
			} else {
				printf("Ingrese un valor positivo\n");
			}
		} else {
			printf("Ingrese un numero entero\n");
		}
	}
	return retorno;
}

