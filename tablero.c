#include <stdio.h>
#include "azar.h"
#include "tiempo.h"
#include "tablero.h"


/* Víctor

Este método se encarga de devolver un numero aleatorio
comprendido entre 0-9

*/

int randNum() {
	return (numero_al_azar(10));
}

void inicializar_tablero(t_tablero *tablero) {
	empieza_tiempo();
	inicializar_azar();

	//Preguntamos dimension
	printf("\nTamaño del tablero (entre 2 y 6): ");
	scanf("%d%*c", &tablero->size);
	while(tablero->size<0 || tablero->size > 6) {
	  	printf("\nTamañno incorrecto, vuelva a introducirlo (min 2, max 6): ");
	  	scanf("%d%*c", &tablero->size);
	 }

	//Inicializamos variables
	//Tablero simple por ahora

	 tablero->max_f=tablero->size-1;
	 tablero->max_c=tablero->size-1;
	 tablero->tipo='s'; //Simple

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
}

void desorganize(t_tablero *tablero) {

	t_tablero t; //Aqui guardamos el tablero desorganizado, despues lo pondremos en su struct
	int matrix [6][12];
	int i,j,n,x,y;

	for(i=0;i<=tablero->max_f;i++) {
		for (j=0;j<=tablero->max_c;j++) {
			//Desorganizar aqui
			n=0;
			while(n!=1) {
				x=numero_al_azar(tablero->size);
				y=numero_al_azar(tablero->size);
				if(matrix[x][y]==0 && x!=i && y!=j) {
					//Poner aqui la casilla
					t.c[x][y]=tablero->c[i][j];
					n=1;
					matrix[x][y]=1;
				}
			}
		}
	}

	//Poner tablero t.c en tablero-c (el t.c ya esta desorganizado);

	for(i=0;i<=tablero->mac_f;i++) {
		for (j=0;j<=tablero->max_c;j++) {
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

	//Cambio de variable
	t_tablero board=tablero;
	int max=tablero->size;

	//Este método lo reharé para los extras

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
			printf("\n\nTiempo transcurrido: %lf",tiempo_transcurrido());
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


}

//Extra
void resolver_tablero(t_tablero *tablero) {
	int i,j;
	t_tablero aux;
	int fil,col;
	for(fil=0;fil<=tablero->max_f;fil++) {
		for(col=0;col<=tablero->max_c;col++) {
			//Search element
			for(i=0;i<=tablero->max_f; i++) {
				for(j=0;j<=tablero->max_c;j++) {
					if (tablero->c[i][j].co == col && tablero->c[i][j].fo == fil) {
						//Swap element
						printf("\nCasilla %c%d a posicion %c%d",(char)j+'A',i,(char)col+'A',fil);
						aux=tablero->c[i][j];
						tablero->c[i][j]=tablero->c[fil][col];
						tablero->c[fil][col]=aux;
					}
				}
			}
		}
	}
}


