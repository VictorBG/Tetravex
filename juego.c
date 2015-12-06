#include <stdio.h>
#include "tablero.h"
#include "tiempo.h"

/*
 * El fichero juego.c solo tiene la funcion: int main()
 * Dicha funcion:
 * Declara una variable de tipo t_tablero
 * Inicializa dicho tablero, lo imprime por pantalla, y
 * mientras el tablero no este resuelo: llama a realizar_jugada() e imprime el
 * tablero.
 */


 /*Víctor:
	Para imprimir solo llamamos al metodo "imprimir_tablero()", los metodos para imprimir
	el norte, el centro y el sur de momento estarán en desuso, a no ser que bea me lo prohiba.

	Recordad este struct, es el que se utilizara (está en el archivo tablero.h) :

	typedef struct {
		char	tipo;	// 's'imple o 'd'oble
		int	size;	// 2 -> 2x2, 3 -> 3x3, 4 -> 4x4, 5 -> 5x5, 6 -> 6x6
		int	max_f;	// Fila max: si (size==3) max_f = 2
		int	max_c;	// Col max: si  (size==3 && tipo=='d') max_c = 5
                        //          si (size==3 && tipo=='s') max_c=2
		t_casilla	c[MAX_SIZE][2*MAX_SIZE];
		int	pistas;	// Pistas que quedan
	} t_tablero;

	Y este (es la casilla, archivo casilla.h) :

	typedef struct {
		int	n, s, e, o;	// digitos norte, sur, este y oeste.
		int	fo, co;		// fila y col original (antes de mezclar)
	} t_casilla;

	De momento no os preocupeis por lo de simple o doble, yo ya modificaré el programa
	para adaptarlo (es un extra)

 */



main() {
  t_tablero tablero;
  unsigned int opcion_menu=0;

  /*

  Creamos menu por si el usuario quiere volver a jugar al finalizar
  Añadiremos dificultad, no se como pero lo haremos

   */

  do {
		inicializar_tablero(&tablero);
		imprimir_tablero(tablero);

		while (!esta_resuelto(tablero)) {
			realizar_jugada(&tablero);
			//Erase cmd shell on unix
			//system("clear");
			//Erase cmd shell on windows
			system("cls");
			imprimir_tablero(tablero);
		}

		printf("\nPuzzle resuelto!!!\n");

		printf("\n\nMenu:\n1.Volver a jugar\n2.Salir\n");
		scanf("%u%*c",&opcion_menu);

		while (opcion_menu<1 || opcion_menu>2) {
			printf("\nOpción incorrecta, escoga otra vez: ");
			scanf("%u%*c",&opcion_menu);
		}

  }while(opcion_menu!=2);

}


