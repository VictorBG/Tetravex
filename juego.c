#include <stdio.h>
#include "tablero.h"
#include "tiempo.h"
#include <string.h>

/*
 * El fichero juego.c solo tiene la funcion: int main()
 * Dicha funcion:
 * Declara una variable de tipo t_tablero
 * Inicializa dicho tablero, lo imprime por pantalla, y
 * mientras el tablero no este resuelto: llama a realizar_jugada() e imprime el
 * tablero.
 */

typedef struct {
	char nombre[20];
}tnombre;

typedef struct {
	int tablero;
	tnombre n;
	int puntuacion;
}tjugador;

typedef struct {
	tjugador ranking[5];
}tranking;


void ranking(double tiempo, t_tablero t, tranking *r);
void mostrar_ranking(int size);
void menu_ranking();
void modificar_ranking(tranking *r);
void inicializar_ranking(tranking *r);
int partida_guardada();

main() {
  t_tablero tablero;
  unsigned int opcion_menu=0;
  tranking r;
  inicializar_ranking(&r);

  /*

  Creamos menu por si el usuario quiere volver a jugar al finalizar

   */

  char op[1000];

  do {
  		if(!partida_guardada(&tablero)) {
  			inicializar_tablero(&tablero);
  		}
  		empieza_tiempo();
		imprimir_tablero(tablero);

		while (!esta_resuelto(tablero)) {
			realizar_jugada(&tablero);
			//Erase cmd shell on unix
			//system("clear");
			//Erase cmd shell on windows
		//	system("cls");
			imprimir_tablero(tablero);
		}

		printf("\nPuzzle resuelto!!!\n");
		if(tablero.resolver==1) {
			printf("\nLo sentimos, no puede optar al ranking si utiliza un extra");
		} else {
			ranking(tiempo_transcurrido(), tablero, &r);
		}
		do {
			do {
				printf("\n\nMenu:\n1.Volver a jugar\n2.Ranking\n3.Salir\n");
				gets(op);
				if(strlen(op)==1) {
					opcion_menu=op[0];
					opcion_menu-='0';
				}else opcion_menu=0;
			}while(opcion_menu<1 || opcion_menu>3);
			if(opcion_menu==2)menu_ranking(r);

		}while(opcion_menu==2);
  }while(opcion_menu!=3);

}


int partida_guardada(t_tablero *t) {
	int opcion;
	char dimension[1000];
	int i,j,n=0;
	do {
		printf("\nDesea cargar una partida guardada? [1]si [2]no: ");
		gets(dimension);
		if(strlen(dimension)==1) {
			opcion=dimension[0];
			opcion-='0';
		}else opcion=0;
	}while(opcion!=1 && opcion!=2);


	if(opcion==2) {
		return 0;
	} else {
		FILE *fp;

		fp=fopen("partida_guardada.txt", "r");
		if(fp==NULL) {
			//No existe
			printf("\nNo existe una partida guardad\n");
			return 0;
		} else {
			//Leemos el archivo y lo almacenamos en los structs
			fscanf(fp,"%d:%d:%d:%c:%d:%lf", &t->size, &t->max_f,&t->max_c,&t->tipo,&t->pistas, &t->tiempo);
			for(i=0;i<6;i++) {
				for (j=0;j<12;j++) {
					fscanf(fp,"%d:%d:%d:%d:%d:%d", &t->c[i][j].n,&t->c[i][j].s,&t->c[i][j].o,&t->c[i][j].e,&t->c[i][j].fo,&t->c[i][j].co);
				}
			}
			fclose(fp);
			return(1);
		}
	}
}

void menu_ranking(tranking r) {
	char dimension[1000];
	int size,i;
	int count=0;
	fflush(stdin);
	do {
		printf("\nEscoga el tamaño de tablero que desea ver su ranking (7 para verlo entero) : ");
		gets(dimension);
		if(strlen(dimension)==1) {
			size=dimension[0];
			size-='0';
		}else size=0;
	}while(size<2 || size > 7);
	i=size-2;
	if(size==7) {
		int j;
		for (j=0;j<5;j++) {
			if(r.ranking[j].puntuacion!=-1) {
				printf("\n%s con %d puntos en el tablero de %dx%d",r.ranking[j].n.nombre,r.ranking[j].puntuacion,r.ranking[j].tablero,r.ranking[j].tablero);
				count++;
			}
		}
		if(count==0) {
			printf("\nNo hay ningún dato en los rankings");
		}
	}else {
		if (r.ranking[i].puntuacion==-1) {
			printf("\nNo hay ningun dato guardado en el ranking");
		} else {
			printf("\n%s con %d puntos",r.ranking[i].n.nombre,r.ranking[i].puntuacion);
		}
	}

}


void inicializar_ranking(tranking *r) {
	char nombre[20]="AwesomeString";
	FILE *fp;
	fp=fopen("ranking.txt", "r");
	if(fp==NULL) {
		//Creamos el archivo si no existe
		fp=fopen("ranking.txt", "w+");
		int i;
		for(i=0;i<5;i++) {
			fprintf(fp,"%d:%d:%s\n",i+2,-1,nombre);
		}
		fclose(fp);
	} else {
		//Leemos el archivo y lo almacenamos en los structs
		int i;
		for(i=0;i<5;i++) {
			fscanf(fp,"%d:%d:%[^\n]",&r->ranking[i].tablero,&r->ranking[i].puntuacion,r->ranking[i].n.nombre);
		}
		fclose(fp);
	}
}

void modificar_ranking(tranking *r) {
	FILE *fp;
	fp=fopen("ranking.txt", "w+");
	if(fp!=NULL) {
		int i;
		for(i=0;i<5;i++) {
			fprintf(fp,"%d:%d:%s\n",r->ranking[i].tablero,r->ranking[i].puntuacion,r->ranking[i].n.nombre);
		}
		fclose(fp);
	}
}

void ranking(double tiempo, t_tablero t, tranking *r) {
	int size=t.size;
	//Buscamos elemento. Llamamos a inicializar ranking para que lo lea todo
	inicializar_ranking(r);
	if (r->ranking[size-2].puntuacion==-1 || tiempo<r->ranking[size-2].puntuacion) {
		printf("\nEnhorabuena, ha conseguido entrar en el ranking.\nCual es su nombre: ");
		gets(r->ranking[size-2].n.nombre);
		r->ranking[size-2].puntuacion=tiempo;
		modificar_ranking(r);
	} else {
		printf("\nLo sentimos, no ha conseguido entrar en el ranking");
	}
}








