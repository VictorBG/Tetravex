
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




void imprimir_norte_casilla(t_casilla cas) {
	printf("║\\");
	color(cas.n);
	//printf("%d",cas.n);
	printf("/");

}

void imprimir_centro_casilla(t_casilla cas) {
	printf("║");
	//printf("%d",cas.o);
	color(cas.o);
	printf("%c", (char)88);
	//printf("%d",cas.e);
	color(cas.e);
}

void imprimir_sur_casilla(t_casilla cas) {
	printf("║/");
	color(cas.s);
	//printf("%d",cas.s);
	printf("\\");
}