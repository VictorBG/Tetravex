#ifndef TABLERO_H
#define	TABLERO_H

#include "casilla.h"

#define FALSE	0
#define TRUE	1

#define TABLERO_SIMPLE	's'
#define TABLERO_DOBLE	'd'

#define MIN_SIZE	2
#define MAX_SIZE	6

typedef struct {
	char	tipo;	// 's'imple o 'd'oble
	int	size;	// 2 -> 2x2, 3 -> 3x3, 4 -> 4x4, 5 -> 5x5, 6 -> 6x6
	int	max_f;	// Fila max: si (size==3) max_f = 2
	int	max_c;	// Col max: si  (size==3 && tipo=='d') max_c = 5
                        //          si (size==3 && tipo=='s') max_c=2
	t_casilla	c[MAX_SIZE][2*MAX_SIZE];
	double tiempo;
	int	pistas;	// Pistas que quedan
	int resolver;
} t_tablero;

// Una fila siempre tiene que estar dentro del rango [0..max_f]
// Una col  siempre tiene que estar dentro del rango [0..max_c]

/*
 * void inicializar_tablero(t_tablero *tablero);
 * En la implementacion basica:
 * Llama a inicializar_azar() para que el tablero sea diferente cada vez.
 * Pide al usuario el tamaño del tablero (verificando que el valor sea 
 * correcto). Inicializa los campos size y tipo del tablero (a TABLERO_SIMPLE).
 * Inicializa los campos max_f y max_c en funcion de size.
 * Inicializa todas las casillas de tal forma que sean un puzle resuelto 
 * al azar.
 * Finalmente, mezcla el tablero.
 * 
 * En la implementacion del extra 1 se debe añadir:
 * Pedir al usuario el tipo del tablero (simple o doble), verificando
 * que el tipo introducido sea correcto. 
 * Inicializa los campos max_f y max_c en funcion de size y tipo.
 * Si el tablero es doble, inicializa las casillas en la mitad izquierda del 
 * tablero de tal forma que sean un puzle resuelto al azar.
 * Despues de mezclar el tablero, si este es doble, desplaza las casillas a la 
 * mitad derecha a la vez que marca las de la mitad izquierda como casillas 
 * vacias.

 * En la implementacion del extra 2 se debe añadir:
 * Llamar a empieza_tiempo() para que empieze a contar el tiempo
 * que tarda el jugador a resolver el puzle.

 * En la implementacion del extra 3 se debe añadir:
 * Inicializa el campo pistas a el tamaño al cuadrado dividido entre 5.
 */
void inicializar_tablero(t_tablero *tablero);


/*
 * void imprimir_tablero(t_tablero tablero);
 * En la implementacion basica:
 * Imprime el tablero.
 *
 * En la implementación del extra 1: 
 * considerar que el tablero puede ser doble y contiene casillas vacías.
 *
 * En la implementacion del extra 2 se debe añadir:
 * Imprimir el tiempo transcurrido.
 */
void imprimir_tablero(t_tablero tablero);


/*
 * void realizar_jugada(t_tablero *tablero);
 * En la implementacion basica:
 * Pide al jugador casillas a intercambiar:
 *	"\nCasillas a intercambiar (ej: [A0B1]): "
 * Verifica que las dos casillas esten dentro de los rangos permitidos 
 * Si las dos casillas son validas y no son la misma las intercambia.
 *
 * En la implementacion del extra 1 se debe añadir:
 * Al pedir al jugador las casillas a intercambiar, se debe verificar que las 
 * dos casillas esten dentro de los rangos permitidos (teniendo en cuenta que 
 * el tablero puede ser doble) 
 * Si las dos casillas son validas y no son la misma las intercambia.
 *
 * En la implementacion del extra 3 se debe añadir:
 * Al pedir al jugador las casillas a intercambiar (verificando que las 
 * dos casillas esten dentro de los rangos permitidos), si las dos casillas 
 * son la misma, entonces: 
 *	Si le quedan pistas al usuario, da la posicion correcta de la casilla 
 *      y decrementa el numero de  pistas (no intercambia las casillas).
 *      Si la casilla estuviera vacia (esto puede ocurrir en tableros dobles)
 *      indica que la casilla esta vacia y decrementa el numero de pistas (se
 *      ha perdido una pista tontamente)
 *	Si no quedan pistas indica que no te quedan pistas.
 *
 * En la implementacion del extra 4 se debe añadir:
 * Al pedir al jugador las casillas a intercambiar, se debe verificar que las 
 * dos casillas esten dentro de los rangos permitidos o que sean iguales y la 
 * primera columna sea 'z' (o 'Z').
 * Si las dos casillas son la misma y la columna es 'z' soluciona el 
 * tablero (extra 4).
 */
void realizar_jugada(t_tablero *tablero);

/*
 * int esta_resuelto(t_tablero tablero);
 * En la implementacion basica:
 * Dado un tablero simple devuelve si esta resuelto 
 * Si lo esta imprime "\nPuzzle resuelto!!!\n" antes de retornar.
 *
 * En la implementacion del extra 1 se debe tener en cuenta:
 * Si el tablero es doble devuelve si esta resuelto en la mitad izquierda.
 */
int esta_resuelto(t_tablero tablero);

#endif	/* TABLERO_H */

