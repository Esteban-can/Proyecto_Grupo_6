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
	FILE *archivo = fopen(nombre_archivo, "rb");
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
void identificar_palabra(string prueba, int cont){//Daniel*
	string pal_sep;
	int line, espacios = 0, i = 0, pinicio, pfin, pmed=0;
	
	line = prueba.length();
	prueba = " " + prueba;
	
	while(i<=line){
		if(prueba.substr(i,1) == " "){
			pfin = i;
			if(i>0){
				pal_sep = prueba.substr(pinicio+1,pfin-(pinicio+1));
				comparar(pal_sep, cont);
			}
			pinicio = pfin;
		}
		if(i == line){
			pal_sep = prueba.substr(pfin+1,line);
			comparar(pal_sep, cont);
		}
		i++;
	}
}
//Daniel**
//Jorge*
void ingreso_del_texto(){
	string *lineas;
	lineas = new string [lineas_total];
	int juls, i;
	
	cout<<"|----------------------------Su Codigo Aqui-------------------------------|\n\n"<<endl;
	cout<<"|----------------------------Ingrese 'Fin.' para traducir-------------------------------|\n\n"<<endl;

	cin.ignore();
	for(i=0;i<lineas_total;i++){
		lineas_temp[i] = "";
		cout<<i+1<<"| ";
		getline(cin, lineas[i]);
		identificar_palabra(lineas[i], i);
		if(lineas[i] == "Fin."){
			juls = i;
			i = 501;
		}
	}
	
	for(i=0;i<=100;i+=10){
		if(i<40){
			system("color 09");
		}else if(i<70){
			system("color 09");
		}else if(i<101){
			system("color 09");
		}
		system("cls");
		cout<<"Traduciendo %"<<i;
	}
	
	system("cls");
	cout<<"|-------------------------------Resultado---------------------------------|\n\n"<<endl;
	for(i=0;i<juls;i++){
		cout<<i+1<<"| "<<lineas_temp[i]<<endl;
	
	}
	};
