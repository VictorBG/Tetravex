#include <stdio.h>
//#include "colores.h"
#include "casilla.h"

void color(int x) {
	//printf_color(x);
	if(x==(-1)) {
		printf(" ");
	}else {
		printf("%d",x);
	}
	//printf_reset_color();
}

void imprimir_norte_casilla(t_casilla cas) {
	printf("%c\\", (char)186);
	color(cas.n);
	//printf("%d",cas.n);
	printf("/");

}

void imprimir_centro_casilla(t_casilla cas) {
	printf("%c", (char)186);
	//printf("%d",cas.o);
	color(cas.o);
	printf("%c", (char)88);
	//printf("%d",cas.e);
	color(cas.e);
}

void imprimir_sur_casilla(t_casilla cas) {
	printf("%c/", (char)186);
	color(cas.s);
	//printf("%d",cas.s);
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



