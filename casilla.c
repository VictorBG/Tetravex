#include <stdio.h>
#include "colores.h"
#include "casilla.h"


void imprimir_norte_casilla(t_casilla cas) {
	printf("%c\\", (char)186);
	//color(cas.n);
	printf("%d",cas.n);
	printf("/");

}

void imprimir_centro_casilla(t_casilla cas) {
	printf("%c", (char)186);
	printf("%d",cas.o);
	//olor(board[i][i3].l);
	printf("%c", (char)88);
	printf("%d",cas.e);
	//color(board[i][i3].r);
}

void imprimir_sur_casilla(t_casilla cas) {
	printf("%c/", (char)186);
	//color(board[i][i3].b);
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


