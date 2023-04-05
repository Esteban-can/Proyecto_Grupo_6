#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat"; 
struct Palabra 
{
	int op;
	char nomb[50];
	char def[150];
};

void leer();
void crear();
void Actualizar();
void Borrar();
main()
{
	leer();
	crear();
    Actualizar();
    Borrar();
	system ("pause");
}
void leer()
{
	system("cls");	
	FILE* archivo = fopen(nombre_archivo,"rb ");
	if (!archivo)
	{
	archivo = fopen(nombre_archivo,"w+b ");	
	}
	Palabra palabra;
	int id=0;
	fread(&palabra,sizeof(Palabra),1,archivo);
	cout<<"Opciones: "<<endl;
	cout<<"1.Crear: "<<endl;
	cout<<"2.Actualizar: "<<endl;
	cout<<"3.Borrar: "<<endl;
	do
	{
		cout<<id<<"|"<<palabra.nomb<<endl;
		fread(&palabra,sizeof(Palabra),1,archivo);
	id+=1;	
	}while (feof(archivo)==0);
	fclose(archivo);
}

void crear()

{
FILE* archivo = fopen(nombre_archivo,"a+b");
char res;
Palabra palabra;
do
{
	fflush(stdin);
	cin.ignore();
	cout<<"Ingrese Palabra: ";
	cin.getline(palabra.nomb,50);

	fwrite(&palabra,sizeof(Palabra),1,archivo);
	cout <<"Desea ingresar otra palabra (s/n):";
	cin>>res;
}while(res == 's'|| res == 'S');
fclose(archivo);
leer();
	
	system ("pause");
} 
void Actualizar()
{
FILE* archivo = fopen(nombre_archivo,"r+b"); 
Palabra palabra;
	int id=0;
	cout<<"Ingrese el Numero  que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Palabra),SEEK_SET); 
	cout<<"Ingrese Palabra: ";
	cin.getline(palabra.nomb,50);
	fwrite(&palabra,sizeof(Palabra),1,archivo);
	cout <<"Desea ingresar otra palabra (s/n):";
	

fclose(archivo);
leer();	
}
void Borrar()
{
	
	const char *nombre_archivo_temp = "archivo_temp.dat";
	system("cls");	
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb ");
	Palabra palabra;
	int id=0,id_n=0;
	cout<<"Ingrese el Numero a eliminar:";
	cin>>id;
	while(fread(&palabra,sizeof(Palabra),1,archivo))
	{
		if (id_n!=id)
		{ 
				fwrite(&palabra,sizeof(Palabra),1,archivo_temp);
		}
		id_n++;
	} 
	fclose(archivo);
	fclose(archivo_temp);
	 archivo_temp = fopen(nombre_archivo_temp,"rb");
	 archivo = fopen(nombre_archivo,"wb ");
	 	while(fread(&palabra,sizeof(Palabra),1,archivo_temp))
	 	{
	 	  	fwrite(&palabra,sizeof(Palabra),1,archivo);
		 }
		 fclose(archivo);
	fclose(archivo_temp);
leer();	
}
