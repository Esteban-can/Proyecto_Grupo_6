#include <iostream>
#include <string.h>


using namespace std;

const char *nombre_archivo = "archivo.dat";

//De momento la cantidad de lineas se define aca
int lineas_total = 500;
string *lineas_temp = new string[lineas_total];


struct palabra_2{
	char nombre_2[50];
	char traduccion_2[50];
	char significado_2[150];
};

palabra_2 pal_2;

void comparar(string texto_2, int contador){
	FILE *archivo = fopen(archivo.dat, "rb");
	int id=1, encontrado=0;
	
	fread(&pal_2,sizeof(palabra_2),1,archivo);
	do{		
		if (texto_2 == pal_2.nombre_2){
			lineas_temp[contador] = lineas_temp[contador] + ' ' + pal_2.traduccion_2;
			encontrado = 1;
		}
		fread(&pal_2,sizeof(palabra_2),1,archivo);
		id += 1;
	}while(feof(archivo)==0);
	fclose(archivo);
	if (encontrado != 1){
		lineas_temp[contador] = lineas_temp[contador] + ' ' + texto_2;
	}
}
