mostrar_tiempo() {
	int sec,min,hour;
	hour=(int)tiempo_transcurrido()/3600;
	min=(int)tiempo_transcurrido()/60;
	sec=(int)tiempo_transcurrido()-hour*3600-min*60;
	printf("\nTiempo transcurrido %.2d h:%.2d m:%.2d s",hour,min,sec);
}