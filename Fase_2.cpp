#include <iostream>
#include <string.h>
#include "Proyecto.cpp"
using namespace std;

//const char *nombre_archivo = "archivo.dat";

struct palabra_2{
	char nombre_2[50];
	char traduccion_2[50];
	char significado_2[150];
};

palabra_2 pal_2;

//Variables que ayudaran a no modificar un campo en especifico
string nombre_2tem, traduccion_2tem, significado2_tem;

//Variable de improvisto para eliminar :v
int borra_ese;

void crear_archivo(){
	FILE *archivo = fopen((palabras.txt, "r+b");
	if (!archivo){
		archivo = fopen((palabras.txt,"w+b");	
	}
}



