#include <stdio.h>
#include "colores.h"
#include "casilla.h"

void color(int x) {
	printf_color(x);
	if(x==(-1)) {
		printf(" ");
	}else {
		printf("%d",x);
	}
	printf_reset_color();
}


void imprimir_norte_casilla(t_casilla cas) {
	printf("║\\");
	color(cas.n);
	printf("/");

}

void imprimir_centro_casilla(t_casilla cas) {
	printf("║");
	color(cas.o);
	printf("X");
	color(cas.e);
}

void imprimir_sur_casilla(t_casilla cas) {
	printf("║/");
	color(cas.s);
	printf("\\");
}

void intercambiar_casillas(t_casilla *cas1, t_casilla *cas2) {
	/*
	Aqui intercambiamos las casillas
	 */
	t_casilla aux=*cas1;
	*cas1=*cas2;
	*cas2=aux;

}



