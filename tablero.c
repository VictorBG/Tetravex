#include <stdio.h>
#include <stdlib.h>
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

void crear_tablero(t_tablero *tablero) {
	//Crear tablero aqui
	int i, j;
	for (i=0; i<tablero->size; i++){
         	for (j=0; j<tablero->size; j++){
				casilla_norte(tablero, i, j);
				casilla_sur(tablero, i, j);
				casilla_este(tablero, i, j);
	 			casilla_oeste(tablero, i, j);
       		}
	}
}

void tablero_doble(t_tablero *t) {
	int i,j, n=t->size;
	t_casilla cas1, cas2;
	if(t->tipo== 'd' || t->tipo=='D') {
		//Doble
		for(i=0;i<t->size;i++) {
			for (j=0;j<t->size;j++) {
				intercambiar_casillas(&(t->c[i][j]), &(t->c[i][j+n]));
			}
		}
	}
}


void inicializar_tablero(t_tablero *tablero) {
	inicializar_azar();
	int i,j;

	tablero->resolver=1;
	tablero->tiempo=0;

	for(i=0;i<6;i++) {
		for (j=0;j<12;j++) {
			tablero->c[i][j].n=-1;
			tablero->c[i][j].s=-1;
			tablero->c[i][j].e=-1;
			tablero->c[i][j].o=-1;
			tablero->c[i][j].fo=i;
			tablero->c[i][j].co=j;
		}
	}

	//Preguntamos dimension
	char dimension[100];
	char size;
	//Preguntamos dimension
	do {
		printf("\nTamaño del tablero (entre 2 y 6): ");
		gets(dimension);
		if (strlen(dimension)==1) {
			size=dimension[0];
			size-='0';
		}else size=0;
	}while(size<2 || size > 6);

	tablero->size=size;

	char tipo[100];
	char t;
	do {
		printf("\nTablero doble o simple (Simple[s] o Doble[d]): ");
		gets(tipo);
		if(strlen(tipo)==1) {
			t=tipo[0];
		}else t='F';

	}while(t != 's' && t!= 'S'
		&& t!='d' && t!='D');

	tablero->tipo=t;



	//Inicializamos variables
	tablero->pistas=tablero->size*tablero->size/5;
	tablero->max_f=tablero->size;
	tablero->max_c=(tablero->tipo=='d' || tablero->tipo=='D')?tablero->max_f*2:tablero->max_f;

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
	tablero_doble(tablero);
}

mostrar_tiempo(t_tablero t) {
	int sec,min,hour;
	hour=(int)(tiempo_transcurrido()+t.tiempo)/3600;
	min=(int)(tiempo_transcurrido()+t.tiempo)/60;
	sec=(int)(tiempo_transcurrido()+t.tiempo)-hour*3600-min*60;
	printf("\nTiempo transcurrido %.2d h:%.2d m:%.2d s",hour,min,sec);
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
		col=tablero.max_c;
	}
	//Letra a mostrar
	char c='A';

	int i,j;
	printf("\n");
	for (i=0;i<fil;i++) {
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
				printf("%c%c%c%c", (char)201, (char)205,(char)205,(char)205);
			} else  if (j==0) {
				printf("%c%c%c%c", (char)204, (char)205,(char)205,(char)205);
			} else if (i==0) {
				printf("%c%c%c%c", (char)203, (char)205,(char)205,(char)205);
			} else {
				printf("%c%c%c%c", (char)206, (char)205,(char)205,(char)205);
			}
		}
		//printf("+\n");
		if(i==0) {
			printf("%c\n", (char)187);
		} else {
			printf("%c\n", (char)185);
		}

		//Imprimimos norte tablero
		for(j=0;j<col;j++) {
			imprimir_norte_casilla(tablero.c[i][j]);
		}
		//printf("|\n");
		printf("%c\n", (char)186);

		//Imprimimos centro tablero
		for(j=0;j<col;j++) {
			imprimir_centro_casilla(tablero.c[i][j]);
		}
		//printf("|  %d\n",i);
		printf("%c  %d\n", (char)186, i);

		//Imprimimos sur tablero
		for(j=0;j<col;j++) {
			imprimir_sur_casilla(tablero.c[i][j]);
		}
		//printf("|\n");
		printf("%c\n", (char)186);
	}
	for(j=0;j<col;j++) {
		//printf("+---");
			if(j==0) {
				printf("%c%c%c%c", (char)200, (char)205,(char)205,(char)205);
			} else {
				printf("%c%c%c%c", (char)202, (char)205,(char)205,(char)205);
			}
		}
	//printf("+");
	printf("%c", (char)188);
	mostrar_tiempo(tablero);
	printf("\n\n");


}




void pista(t_tablero *tablero, char c, int n, char c2, int n2) {
	double t=tiempo_transcurrido();
	double long_time=1; //Retardo del bucle (1 menos de lo que realmente es)

	if(tablero->pistas!=0) {
		if(tablero->c[n][(int)c-'A'].n==-1) {
			printf("\nCasilla vacia");
		} else if (c==c2 && n==n2) {
			printf("\nPosicion correcta de %c%d -> %c%d", c,n, (char)tablero->c[n][(int)c-'A'].co + 'A' ,tablero->c[n][(int)c-'A'].fo);
		}
		tablero->pistas--;
		printf("\nPistas restantes: %d", tablero->pistas);
	} else printf("\nNo te quedan pistas");

	while(t+long_time>tiempo_transcurrido());//Bucle de 2 segundos
}

void resolver_tablero(t_tablero *tablero) {
	int i,j,y;
	int fil,col;
	double t;
	tablero->resolver=1;

	for(fil=0;fil<tablero->size;fil++) {
		for(col=0;col<tablero->size;col++) {
			//Search element
			y=0;
			for(i=0;i<tablero->max_f; i++) {
				if(y==0) {
					for(j=0;j<tablero->max_c;j++) {
						if (tablero->c[i][j].co == col && tablero->c[i][j].fo == fil && y==0) {
							//Swap element
							intercambiar_casillas(&tablero->c[i][j], &tablero->c[fil][col]);
							system("cls");
							printf("\nCasilla %c%d a posicion %c%d\n\n",(char)j+'A',i,(char)col+'A',fil);
							imprimir_tablero(*tablero);
							t=tiempo_transcurrido();
							//Delay to show the changes
							while(t==tiempo_transcurrido());//Bucle de 1 segundo
							y=1;
						}
					}
				}
			}
		}
	}
	system("cls");
}

void guardar_tablero(t_tablero *t) {
	FILE *fp;
	int i,j, size;
	double tiempo;

	fp=fopen("partida_guardada.txt", "w+");
	if(fp!=NULL) {
		fprintf(fp,"%d:%d:%d:%c:%d:%lf\n", t->size, t->max_f,t->max_c,t->tipo,t->pistas, tiempo_transcurrido());//falta h m y s
		for(i=0;i<6;i++) {
			for (j=0;j<12;j++) {
				fprintf(fp,"%d:%d:%d:%d:%d:%d\n", t->c[i][j].n,t->c[i][j].s,t->c[i][j].o,t->c[i][j].e,t->c[i][j].fo,t->c[i][j].co);
			}
		}
		fclose(fp);
		printf("\nPartida guardada");
		tiempo=tiempo_transcurrido();
		while(tiempo==tiempo_transcurrido());//Bucle de 1 segundo
	}
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
	intercambiarlas después.*/

	char movimiento[100];
	char numero1,letra1,letra2,numero2;
	int repetir;
	int col=tablero->max_c-1;
	int fil=tablero->max_f-1;

	do {
		printf("\nSeleccione movimiento [ej: A0B1, s1s1 para guardar]: ");
		gets(movimiento);

		repetir=1;
		if(strlen(movimiento)==4) {
			numero1=movimiento[1];
			numero2=movimiento[3];
			letra1=movimiento[0];
			letra2=movimiento[2];
			numero1-='0';
			numero2-='0';

			if(letra1<='z' && letra1 >='a')letra1-=32;
			if(letra2<='z' && letra2 >='a')letra2-=32;

			if(letra1-'A'<col && (numero1>=0 && numero1<fil) && (numero2>=0 && numero2<fil)
				&& (letra2-'A'<col))repetir=0;

			if(letra1=='S' && letra2=='S')repetir=0;

			if(letra1=='Z' && letra2=='Z')repetir=0;
		} else repetir=1;

	}while(repetir);


	if((letra1==letra2 && numero1==numero2) || (tablero->c[numero1][letra1-'A'].n==-1) || (letra1=='S' && letra2=='S')) {
		if(letra1 == 'Z' && letra2=='Z') {
			resolver_tablero(tablero);
		}else if (letra1=='S' && letra2=='S') {
			guardar_tablero(tablero);
		}else{
			pista(tablero, letra1, numero1, letra2, numero2);
		}
	}else {
		intercambiar_casillas(&(tablero->c[numero1][letra1-'A']), &(tablero->c[numero2][letra2-'A']));
	}
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