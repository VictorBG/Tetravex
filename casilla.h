#ifndef CASILLA_H
#define	CASILLA_H

#define CASILLA_VACIA		-1
#define POSICION_CASILLA_VACIA	-1

typedef struct {
	int	n, s, e, o;	// digitos norte, sur, este y oeste.
	int	fo, co;		// fila y col original (antes de mezclar)
} t_casilla;


/*
 * void imprimir_norte_casilla(t_casilla cas);
 * Imprime la linea superior de la casilla cas ("\n/|") donde 'n' es el digito
 * norte.
 */
void imprimir_norte_casilla(t_casilla cas);

/*
 * void imprimir_centro_casilla(t_casilla cas);
 * Imprime la linea central de la casilla cas ("oxe|") donde 'o' es el digito
 * oeste y 'e' el digito este.
 */
void imprimir_centro_casilla(t_casilla cas);

/*
 * void imprimir_sur_casilla(t_casilla cas);
 * Imprime la linea inferior de la casilla cas ("/s\|") donde 's' es el digito
 * sur.
 */
void imprimir_sur_casilla(t_casilla cas);

/*
 * void intercambiar_casillas(t_casilla *cas1, t_casilla *cas2);
 * Dados los punteros a casilla cas1 y cas2,
 * intercambia los valores de sus campos.
 */
void intercambiar_casillas(t_casilla *cas1, t_casilla *cas2);

#endif	/* CASILLA_H */

