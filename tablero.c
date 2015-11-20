#include <stdio.h>
#include "azar.h"
#include "tiempo.h"
#include "tablero.h"


/* Víctor
	
Este método se encarga de devolver un numero aleatorio
comprendido entre 0-9

*/

int randNum() {
	return (numero_al_azar(9));
}

void inicializar_tablero(t_tablero *tablero) {
	  inicializar_azar();
	  /*Víctor

	  	Primero preguntamos por la dimension y la guardamos en la
	  	variable "size"

		Aquí debemos crear el tablero ordenado.
		Para ello hay que guardar la posicion ((i,j) o (x,y),
		depende de como las llameis) en tablero->fo (fila original)
		y tablero->co (columna original). Esto nos servira para los extras también.

		Al final llamar al método desorganize(tablero)

	  */

		//Recuerda siempre entrar al struct con tablero->(nombre variable dentro del struct)
}

void desorganize(t_tablero *tablero) {
	//Por hacer
}


void imprimir_tablero(t_tablero tablero) {
	/* +---(4)
	   |\0/  
	   |0x0
	   |/0\
	*/

	//Cambio de variable
	t_tablero board=tablero;
	char c='A';
	int i,i3;
	printf("\n");
	for (i=0;i<max;i++) { 
			if(i==0)for(i3=0;i3<max;i3++)printf("  %c ",(c+i3));
			printf("\n");
			for(i3=0;i3<max;i3++)printf("+---");
			printf("+");								 
			printf("\n");
			for(i3=0;i3<max;i3++){printf("|\\");color(board[i][i3].t);printf("/");}
			printf("|");
			printf("\n");
			for(i3=0;i3<max;i3++){printf("|");color(board[i][i3].l);printf("x");color(board[i][i3].r);}
			printf("|");
			printf("  %d",i);
			printf("\n");
			for(i3=0;i3<max;i3++){printf("|/");color(board[i][i3].b);printf("\\");}
			printf("|");
			if(i==(max-1)) {
				printf("\n");
				for(i3=0;i3<max;i3++)printf("+---");
				printf("+");	
			}
	}
}

void color(int x) {
	printf_color(x);
	printf_reset_color();
}

void realizar_jugada(t_tablero *tablero) {
	/*Víctor

	En este metodo lo que hay que hacer es intercambiar dos casillas de tablero.
	Para eso nos ayudamos del método intercambiar_casillas(&casilla1, &casilla2)
	del archivo casilla.c (no olvidar pasarlo por referencia).

	Guarda las dos casillas a intercambiar en dos variables, las intercambias y
	vuelves a introducir las variables en el mismo sitio donde estaban 
	(ejemplo: si tienes que cambiar a0-b1 sacas la casilla en la posicion 00 y la de 11,
	llamas al método y las vuelves a introducir en la misma posicion!!)

	No olvidar pedir al usuario las casillas a intercambiar, comprobar que sean correctos
	(En caso de los chars mirar que el char sea menor o igual a 'A'+tablero->size) e 
	intercambiarlas después.

	*/
}

int esta_resuelto(t_tablero tablero) {
	/* Víctor

	Mirar que tablero.c[i][j].co sea igual que en la columna que esta
	y lo mismo con la fila. En caso de encontrar uno que no sea uno igual 
	realizar un "return (0)". Lo que hace esto es parar el for y salir del método
	devolviendo un 0. En caso contrario devolver un 1 al final del archivo.

	*/
}

