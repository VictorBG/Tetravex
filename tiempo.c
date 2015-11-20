// Todas las funciones de este fichero estan hechas
#include <time.h>	// time()
#include "tiempo.h"

time_t start,end; 

void empieza_tiempo() {
	time (&start);
}

double tiempo_transcurrido() {
	time (&end); 

	return difftime (end,start); 
}

