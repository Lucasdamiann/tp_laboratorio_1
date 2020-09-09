/*
 * Calculadora.c
 *
 *  Created on: 5 sep. 2020
 *      Author: Lucas Bracuto
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

int main() {
	setbuf(stdout, NULL);
	char respuesta = 'n';
	int numero1, numero2, valorNumero1, comando, valorNumero2, bandera1 = 0,
			bandera2 = 0, bandera3 = 0;
	float calculoSuma, calculoResta, calculoDivision, calculoResultado,
			calculoMultiplicacion, calculoFactorialA, calculoFactorialB;
	printf("MENU\n");
	//se establece 'n' como valor de variable respuesta que se usara para comprobar y continuar ejecutando.
	while (respuesta == 'n') {
		printf(
				"\n#1)Ingresar un operando. \n#2)Ingresar segundo operando. \n#3)Realizar calculos. \n#4)Mostrar resultados. \n#5)Salir\n");
		printf("\nIngrese un comando: ");
		fflush(stdin);
		scanf("%d", &comando);

		while (comando != 1 && comando != 2 && comando != 3 && comando != 4
				&& comando != 5) {
			printf("\nIngrese un comando correcto 1,2,3,4 o 5: \n");
			fflush(stdin);
			scanf("%d", &comando);
		}
		if (comando == 1) {
			do {
				printf("\nIngrese operando: "); //se comprueba que el valor ingresado sea numero.
				fflush(stdin); //si no lo es, vuelve a pedir ingreso de un valor numerico
				valorNumero1 = scanf("%d", &numero1);  //de manera indeterminada
			} while (valorNumero1 == 0);
			bandera1 = 1;
		}
		if (comando == 2 && bandera1 == 1) {
			do {
				printf("\nIngrese otro operando para calcular: "); //se comprueba que el valor ingresado sea numero.
				fflush(stdin); //si no lo es, vuelve a pedir ingreso de un valor numerico,
				valorNumero2 = scanf("%d", &numero2);  //de manera indeterminada
			} while (valorNumero2 == 0);              //hasta que sea numerico//

			printf("\nLos valores seleccionados son: %.1d y %.1d\n", numero1,
					numero2); //se muestran los valores que se seleccionaron//
			bandera2 = 1;
		} else if (comando == 2 && bandera2 == 0) {
			printf("\nDebe ingresar el primer operando antes que el segundo\n");
		}

		if (comando == 3 && bandera1 == 0) {
			printf(
					"\nDebe ingresar el primer operando antes de realizar calculos\n");
		} else if (comando == 3 && bandera2 == 0) {
			printf(
					"\nDebe ingresar el segundo operando antes de realizar calculos\n");

		} else if (comando == 3 && bandera1 == 1 && bandera2 == 1) {
			bandera3 = 1;
			printf("\nCalculos realizados.\n");
		}
		if (comando == 4 && bandera1 == 1 && bandera2 == 1 && bandera3 == 1) {

			calculoSuma = suma(numero1, numero2); //se llama a la funcion suma para realizar el calculo//
			calculoResta = resta(numero1, numero2); //se llama a la funcion resta para realizar el calculo//
			calculoDivision = division(&calculoResultado, numero1, numero2); //se llama a la funcion division para realizar el calculo//
			calculoMultiplicacion = multiplicacion(numero1, numero2); //se llama a la funcion multiplicacion para realizar el calculo//
			calculoFactorialA = factoreoA(numero1); //se llama a la funcion factoreo para realizar el calculo//
			calculoFactorialB = factoreoA(numero2); //se llama a la funcion factoreo para realizar el calculo//
			printf("\nEl resultado de %d + %d es %.1f: ", numero1, numero2,
					calculoSuma); //se imprime el resultado//
			printf("\nEl resultado de %d - %d es %.1f: ", numero1, numero2,
					calculoResta); //se imprime el resultado//
			if (calculoDivision == 0) { //se comprueba que el valor del denominador no sea 0
				printf("\nEl resultado de %d / %d es %.1f: ", numero1, numero2,
						calculoResultado);
			} else {                //si llegase a ser 0 se imprime por pantalla
				printf(
						"\nEl resultado de %d / %d es: No se puede dividir por 0",
						numero1, numero2); //el mensaje "No se puede dividir por 0"//
			}
			printf("\nEl resultado de %d * %d es %.1f: ", numero1, numero2,
					calculoMultiplicacion); //se imprime el resultado//
			printf("\nEl factorial de %d es: %.1f ", numero1,
					calculoFactorialA);
			printf("\nEl factorial de %d es: %.1f \n", numero2,
					calculoFactorialB); //se imprime el resultado//
			bandera1 = 0;
			bandera2 = 0;
			bandera3 = 0;

		} else if (comando == 4 && bandera3 == 0) {
			printf("\nDebe calcular para solicitar resultados\n");
		}

		if (comando == 5) {
			respuesta = printf("Esta seguro que desea salir? s/n: ");
			fflush(stdin);
			scanf("%c", &respuesta);
		}
	}
	return 0;
}

