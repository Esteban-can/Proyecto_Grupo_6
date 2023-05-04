#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat"; 
struct Palabra 
{
	int op;
	char nomb[50];
	char def[150];
	char tra[150];
};
void leer();
main()
{
	leer();	
   
    scanf("");
    return(0);
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
	do
	{
		cout<<id<<"|"<<palabra.nomb<<endl;
		fread(&palabra,sizeof(Palabra),1,archivo);
	id+=1;	
	}while (feof(archivo)==0);
	fclose(archivo);
}
