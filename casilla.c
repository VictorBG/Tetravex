#include <stdio.h>
#include "colores.h"
#include "casilla.h"


void imprimir_norte_casilla(t_casilla cas) {
	printf("|\\");
	//color(cas.n);
	printf("%d",cas.n);
	printf("/");

}

void imprimir_centro_casilla(t_casilla cas) {
	printf("|");
	printf("%d",cas.o);
	//color(cas.o);
	printf("x");
	printf("%d",cas.e);
	//color(cas.e);
}

void imprimir_sur_casilla(t_casilla cas) {
	printf("|/");
	//color(cas.s);
	printf("%d",cas.s);
	printf("\\");
}

void intercambiar_casillas(t_casilla *cas1, t_casilla *cas2) {
	/*
	Aqui intercambiamos las casillas
	 */

}

void color(int x) {
	printf_color(x);
	printf_reset_color();
}


