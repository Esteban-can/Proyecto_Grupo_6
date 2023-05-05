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
	FILE *palabra = fopen((nombre_archivo, "r+b");
	if (!palabra){
		palabra = fopen((nombre_archivo,"w+b");	
	}
}
void leer(int buscar){
	//Si buscar es igual a "1" la funciï¿½n buscara un item; Si buscar es distinto a "1" mostrara todos los items
	FILE *archivo = fopen(nombre_archivo, "rb");
	//palabra pal;
	
	int id=1, bus;
	string kam;
	
	fread(&pal,sizeof(palabra),1,archivo);
	if(buscar == 1){
		cout<<"Ingrese el ID del objeto a buscar: ";
		cin>>bus;
		cout<<"\n\n";
	}

	do{	
		if(buscar == 1 && id == bus || buscar == 0){
			kam = pal.nombre;
			if(kam != "--"){
				cout<<"ID: "<<id<<"\nNombre: "<<pal.nombre<<"\nTraduccion: "<<pal.traduccion<<"\nSignificado: "<<pal.significado<<endl<<endl;
			}
		}
		fread(&pal,sizeof(palabra),1,archivo);
		id += 1;
	}while(feof(archivo)==0);
	
	fclose(archivo);
}

//Guarda los valores a remplazar en una variable
void ayuda_remplazar(int help){
	FILE *archivo = fopen(nombre_archivo, "rb");
	//palabra pal;
	int id = 1;
	fread(&pal,sizeof(palabra),1,archivo);
	do{	
		if(id == help){
			nombre_tem = pal.nombre;
			traduccion_tem = pal.traduccion;
			significado_tem = pal.significado;
		}
		fread(&pal,sizeof(palabra),1,archivo);
		id += 1;
	}while(feof(archivo)==0);
}


void ingreso(int cremo){
	//Si cremo es igual a "1" la funciÃ³n agregara valores; Si cremo es distingo a "1" la funciÃ³n modificara valores
	//palabra pal;
	FILE* archivo = fopen(nombre_archivo,"ab");	
	string str_nombre, str_traduccion, str_significado;

	fflush(stdin);
	if (cremo == 1){
		cout<<"Â¡--Ingreso de valores--!"<<endl<<endl;
	}else{
		fclose(archivo);
		FILE* palabra = fopen(nombre_archivo,"r+b");
		int id;
		//Si no se quiere modificar un campo colocar "0"
		cout<<"Ingrese el ID que desea Modificar: ";
		cin>>id;
		fseek(palabra,(id-1) * sizeof(palabra),SEEK_SET);
		ayuda_remplazar(id);
		cin.ignore();
	}
	
	//Si es verdadero se "borrara"
	if(borra_ese == 1){
		strcpy(pal.nombre, "--");
		strcpy(pal.traduccion, "--");
		strcpy(pal.significado, "--");
	}else{	
		
		//Si no es necesario remplazar un valor en especifico se ingresa 0; Al ingresar 0, este valor se remplaza por la variable temporal (Vease ayuda_remplazar()). 
		cout<<"Ingrese el nombre: ";
		getline(cin,str_nombre);
		if(str_nombre == "0"){
			strcpy(pal.nombre, nombre_tem.c_str());
		}else{
			strcpy(pal.nombre, str_nombre.c_str());
		}
		
		cout<<"Ingrese la traduccion: ";
		getline(cin,str_traduccion);
		if(str_traduccion == "0"){
			strcpy(pal.traduccion, traduccion_tem.c_str());
		}else{
			strcpy(pal.traduccion, str_traduccion.c_str());
		}
		
		
		cout<<"Ingrese el significado: ";
		getline(cin,str_significado);
		if(str_significado == "0"){
			strcpy(pal.significado, significado_tem.c_str());
		}else{
			strcpy(pal.significado, str_significado.c_str());
		}
		
		//cin.ignore();
		
		//leer(0);
	}
	
	fwrite(&pal,sizeof(palabra),1,archivo);
	fclose(archivo);
}
	
	void bannermotd(){
	cout<<"-----ALUMNOS:-----"<<endl;
	cout<<"Daniel Alejandro González Juarez       1290-22-4469"<<endl;
	cout<<"Pedro José Manuel Galindo Hernández    1290-22-9309"<<endl;
	cout<<"Juan Esteban Can Lopez                 1290-22-10376"<<endl;
	cout<<"Jorge José Hernández FLores            1290-22-799"<<endl;
	cout<<"Mauro Francisco Marroquin Azurdia      1290-22-3436 "<<endl;
	cout<<"Pablo Rafael ALvarez Farel             1290-22-3226"<<endl;
	
    
}

void menu(){
	system("color 02");
	int inp_gen;
	char inp_dicc;
		
	do{
		bannermotd();
		cout<<"|-------------------------------------------------------------------------|"<<endl;
		cout<<"|Entrar al traductor                                                    1 |"<<endl;
		cout<<"|-------------------------------------------------------------------------|"<<endl;
		cout<<"|Modificar diccionario                                                  2 |"<<endl;
		cout<<"|-------------------------------------------------------------------------|"<<endl;
		cout<<"|Mostrar palabras                                                       3 |"<<endl;
		cout<<"|-------------------------------------------------------------------------|"<<endl;
		cout<<"|Salir                                                                  4 |"<<endl;
		cout<<"|-------------------------------------------------------------------------|"<<endl<<endl;
		cout<<"Que deseas hacer? ";
		cin>>inp_gen;
		system("cls");
		switch (inp_gen){
			case 1:{
				ingreso_del_texto();
				break;
			}
			case 2:{
				borra_ese = 0;
				cout<<"|--------------------------Modificar diccionario--------------------------|\n\n"<<endl;
				cout<<"Desea modificar, agregar o eliminar (m/a/e)?.. ";
				cin>>inp_dicc;
				if(inp_dicc == 'a' || inp_dicc == 'A'){
					ingreso(1);
				}else if(inp_dicc == 'm' || inp_dicc == 'M'){
					ingreso(0);
				}else if(inp_dicc == 'e' || inp_dicc == 'E'){
					borra_ese = 1;
					ingreso(0);





