// Todas las funciones de este fichero estan hechas.
#include <time.h>	// time()
#include <stdlib.h>	// rand(), srand()
#include <stdio.h>	// printf()
#include "azar.h"

void inicializar_azar() {
	/*
	 * Para que la sequencia de numeros aleatorios sea igual en cada
	 * ejecucion usad el srand (0) en lugar del srand(time).
	 */
	//srand(0);
	srand( (unsigned)time( NULL ) );
}

int numero_al_azar(int max) {
	return ( rand() % max); 
}

