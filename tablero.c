#include <stdio.h>
#include <stdlib.h>
#include "azar.h"
#include "tiempo.h"
#include "tablero.h"


/* Víctor

Este método se encarga de devolver un numero aleatorio
comprendido entre 0-9

*/

void casilla_norte(t_tablero *tablero, int i,int j);
void casilla_sur(t_tablero *tablero, int i,int j);
void casilla_este(t_tablero *tablero, int i,int j);
void casilla_oeste(t_tablero *tablero, int i,int j);

int randNum() {
	return (numero_al_azar(10));
}

void inicializar_tablero(t_tablero *tablero) {
	empieza_tiempo();
	inicializar_azar();

	for(i=0;i<6;i++) {
		for (j=0;j<12;j++) {
			t.c[i][j].n=-1;
			t.c[i][j].s=-1;
			t.c[i][j].e=-1;
			t.c[i][j].o=-1;
			t.c[i][j].fo=i;
			t.c[i][j].co=j;
		}
	}

	//Preguntamos dimension
	printf("\nTamaño del tablero (entre 2 y 6): ");
	scanf("%d%*c", &tablero->size);

	while(tablero->size<0 || tablero->size > 6) {
	  	printf("\nTamañno incorrecto, vuelva a introducirlo (min 2, max 6): ");
	  	scanf("%d%*c", &tablero->size);
	}

	printf("\nTablero doble o simple (d o s): ");
	scanf("%c%*c", &tablero->tipo);
	while (tablero->tipo != 's' || tablero->tipo!= 'S'
		|| tablero->tipo!='d' || tablero->tipo!='D') {
		printf("\nVariable incorrecta, vuelva a introducirla (c o d): ");
	  	scanf("%c%*c", &tablero->tipo);
	}

	//Inicializamos variables
	//Tablero simple por ahora

	/*tablero->tipo='s'; //Simple, de momento*/
	tablero->max_f=tablero->size-1;
	tablero->max_c=(tablero->tipo=='d' || tablero->tipo=='D')?tablero->max_f*2:max_f;

	/*
	max_c indica el número máximo de columnas (en caso de que el tamaño sea
	3 este valor almacena un 0, por lo tanto los fors van hasta <=max_c);

	max_f lo mismo pero con las filas

	*/


	/*
		Víctor

	  	Primero preguntamos por la dimension y la guardamos en la
	  	variable "size".

		Aquí debemos crear el tablero ordenado.
		Para ello hay que guardar la posicion ((i,j) o (x,y),
		depende de como las llameis) en tablero->fo (fila original)
		y tablero->co (columna original). Esto nos servira para los extras también.

		Al final llamar al método desorganize(tablero)

	*/

	//Recuerda siempre entrar al struct con tablero->(nombre variable dentro del struct)
	crear_tablero(tablero);
	desorganize(tablero);
}

void crear_tablero(t_tablero *tablero) {
	//Crear tablero aqui
	int i, j;
	for (i=0; i<tablero->size; i++){
         	for (j=0; j<tablero->size; j++){
				casilla_norte(tablero, i, j);
				casilla_sur(tablero, i, j);
				casilla_este(tablero, i, j);
	 			casilla_oeste(tablero, i, j);
				tablero->c[i][j].fo=i;
				tablero->c[i][j].co=j;
       		}
	}
}

void casilla_norte(t_tablero *tablero, int i,int j){
	if (i==0)
 	  tablero->c[i][j].n=randNum();
	else
	  tablero->c[i][j].n=tablero->c[i-1][j].s;
}
void casilla_sur(t_tablero *tablero, int i, int j){
	tablero->c[i][j].s=randNum();
}
void casilla_este(t_tablero *tablero, int i, int j){
	tablero->c[i][j].e=randNum();
}
void casilla_oeste(t_tablero *tablero, int i, int j){
	if (j==0)
	  tablero->c[i][j].o=randNum();
	else
	  tablero->c[i][j].o=tablero->c[i][j-1].e;
}

void desorganize(t_tablero *tablero) {

	t_tablero t; //Aqui guardamos el tablero desorganizado, despues lo pondremos en su struct
	int matrix [6][6];
	int i,j,n,x,y;
	for(i=0;i<6;i++){for(j=0;j<6;j++)matrix[i][j]=0;}

	for(i=0;i<tablero->size;i++) {
		n=0;
		for (j=0;j<tablero->size;j++) {
			//Desorganizar aqui
			n=0;
			while(n!=1) {
				x=numero_al_azar(tablero->size);
				y=numero_al_azar(tablero->size);
				if(matrix[x][y]==0) {
					//Poner aqui la casilla
					t.c[x][y]=tablero->c[i][j];
					n=1;
					matrix[x][y]=1;
				}
			}
		}
	}

	//Poner tablero t.c en tablero-c (el t.c ya esta desorganizado);
	for(i=0;i<tablero->size;i++) {
		for (j=0;j<tablero->size;j++) {
				tablero->c[i][j]=t.c[i][j];
		}
	}

	/*
	Ya tenemos el tablero desorganizado. Las posiciones originales se
	guardan en los valores de "co" y "fo" de cada casilla
	 */
}


void imprimir_tablero(t_tablero tablero) {
	/* +---(4)
	   |\0/
	   |0x0
	   |/0\
	*/

	int col, fil;

	if(tablero.tipo== 's' || tablero.tipo == 'S') {
		//Simple
		fil=tablero.max_f;
		col=fil;
	} else {
		fil=tablero.max_f;
		col=fil*2;
	}
	//Letra a mostrar
	char c='A';

	int i,j;
	printf("\n");
	for (i=0;i<fil;i++) {
		//Imprimimos letras
		//Imprimimos letras
		if(i==0) {
			for(j=0;j<col;j++) {
				printf("  %c ",(c+j));
			}
			printf("\n");
		}
		//Imprimimos parte superior tablero
		for(j=0;j<col;j++) {
			//printf("+---");
			if(j==0 && i==0) {
				printf("╔═══");
			} else  if (j==0) {
				printf("╠═══");
			} else if (i==0) {
				printf("╦═══");
			} else {
				printf("╬═══");
			}
		}
		//printf("+\n");
		if(i==0) {
			printf("╗\n");
		} else {
			printf("╣\n");
		}

		//Imprimimos norte tablero
		for(j=0;j<col;j++) {
			imprimir_norte_casilla(tablero.c[i][j]);
		}
		//printf("|\n");
		printf("║\n");

		//Imprimimos centro tablero
		for(j=0;j<col;j++) {
			imprimir_centro_casilla(tablero.c[i][j]);
		}
		//printf("|  %d\n",i);
		printf("║  %d\n", i);

		//Imprimimos sur tablero
		for(j=0;j<col;j++) {
			imprimir_sur_casilla(tablero.c[i][j]);
		}
		//printf("|\n");
		printf("║\n");
	}
	for(j=0;j<col;j++) {
		//printf("+---");
		if(j==0) {
			printf("╚═══");
		} else {
			printf("╩═══");
		}
	}
	//printf("+");
	printf("╝");
	printf("\n\nTiempo transcurrido: %.2lf",tiempo_transcurrido());


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

	/*

	if(letra1=='z' || letra1 == 'Z') {
		resolver_tablero(tablero);
	}
	*/
}

int esta_resuelto(t_tablero tablero) {
	/* Víctor

	Mirar que tablero.c[i][j].co sea igual que en la columna que esta
	y lo mismo con la fila. En caso de encontrar uno que no sea uno igual
	realizar un "return (0)". Lo que hace esto es parar el for y salir del método
	devolviendo un 0. En caso contrario devolver un 1 al final del archivo.

	*/
	int i,j;
	for (i=0;i<tablero.size;i++){
		for(j=0;j<tablero.size;j++){
			if(i!= tablero.c[i][j].fo || j!= tablero.c[i][j].co){
				return 0;
			}
		}
	}
	return 1;


}

void resolver_tablero(t_tablero *tablero) {
	int i,j,y;
	t_casilla aux;
	int fil,col;
	int start=0;

	if(tablero->tipo == 'D' || tablero->tipo == 'd') start=tablero->size;


	for(fil=0;fil<tablero->size;fil++) {
		for(col=0;col<tablero->size;col++) {
			//Search element
			y=0;
			for(i=0;i<tablero->max_f; i++) {
				if(y==0) {
					for(j=0;j<tablero->max_c;j++) {
						//printf("\nfil %d col %d i%d j%d",fil,col,i,j);
						if (tablero->c[i][j].co == col && tablero->c[i][j].fo == fil && y==0) {
							//Swap element
							aux=tablero->c[i][j];
							tablero->c[i][j]=tablero->c[fil][col];
							tablero->c[fil][col]=aux;
							system("cls");
							printf("\nCasilla %c%d a posicion %c%d\n\n",(char)j+'A',i,(char)col+'A',fil);
							imprimir_tablero(*tablero);
							double t=tiempo_transcurrido();
							//Delay to show the changes
							while(t==tiempo_transcurrido());
							y=1;
						}
					}
				}
			}
		}
	}


}


