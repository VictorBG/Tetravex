#ifndef AZAR_H 
#define	AZAR_H

/*
 * inicializar_azar() se tiene que ejecutar una vez al principio del main
 * para inicializar la generación de números aleatorios
 */
void inicializar_azar();

/*
 * numero_al_azar(max) devuelve un número entero al azar entre 0 y max-1
 */
int numero_al_azar(int max);

#endif	/* AZAR_H */

