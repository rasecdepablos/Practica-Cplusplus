#include <iostream>
#include "Encriptador.h"
#include "Descifrador.h"


int main(int argc, char** argv) {
	
int opc;
	do{
	cout <<endl;
	cout <<"-------------------------------------------"<<endl;
	cout<<"Proyecto 1"<<endl;
	cout<<"Entra en el archivo Entrada.txt "<<endl;
	cout<<"opcion '1' : Encriptar mensaje"<<endl;
	cout<<"opcion '2' : Desencriptar mensaje"<<endl;
	cout<<"opcion '3' : Salir "<<endl;
	cout <<"-------------------------------------------"<<endl;
	cin.sync();
	cin>>opc;
	
		if(opc==1) Encriptador *e=new Encriptador();	
		
		if(opc==2)
		{
			Descifrador *d = new Descifrador();	
		}
		system("pause > NULL");
		system("cls");
	}while(opc!=3);


	


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
