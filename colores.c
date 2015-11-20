// Todas las funciones de este fichero estan hechas.
#include <stdio.h>
#include "colores.h"

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// http://ascii-table.com/ansi-escape-sequences.php

void printf_color(int color) {
	switch (color) {
		case -1: printf(ANSI_COLOR_RESET  ); break;
		case  0: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_WHITE  ); break;
		case  1: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_RED    ); break;
		case  2: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_GREEN  ); break;
		case  3: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_YELLOW ); break;
		case  4: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_BLUE   ); break;
		case  5: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_MAGENTA); break;
		case  6: printf(ANSI_COLOR_BOLD   ); printf(ANSI_COLOR_CYAN   ); break;

		case  7: printf(ANSI_COLOR_RED    ); break;
		case  8: printf(ANSI_COLOR_GREEN  ); break;
		case  9: printf(ANSI_COLOR_YELLOW ); break;
	}
}

void printf_reset_color() {
	printf_color(-1);
}

