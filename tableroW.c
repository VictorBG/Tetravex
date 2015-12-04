
/*

	THIS FILE IS ONLY FOR WindowsNT SYSTEMS, NOT FOR UNIX SYSTEMS

 */


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


	printf("\n\nTiempo transcurrido: %.2lf",tiempo_transcurrido());
}


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