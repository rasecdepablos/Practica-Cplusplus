#include "Descifrador.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void Descifrador::Salida(){
	
	char aux;
	ofstream archivo("salida.txt");

	cout <<"Cadena:"<<endl;
	for(int i=0;i<this->salida.size();i++){
		aux=(char)this->salida.at(i);
		archivo<<aux;
		cout << aux;
	}
	cout<<endl<<endl;
	archivo.close();		
}
void Descifrador::Metodo(){
	
	int aux,aux2,aux3,aux4;
	int mascaras[]={255,65280,16711680,4278190080};
	int temp;
	int tam;
	tam=entrada.size();
	cout << "Mensaje Codificado:"<<endl;
	for(int i=0;i<tam;i++){
	 aux=0;aux2=0;aux3=0;aux4=0;	
		
		temp=entrada.at(i);
		cout<<temp<<endl;
		
		aux=mascaras[0]&entrada.at(i);
		
		aux2=mascaras[1]&entrada.at(i);
		aux2=aux2>>8;
		
		aux3=mascaras[2]&entrada.at(i);
		aux3=aux3>>16;
		
		aux4=mascaras[3]&entrada.at(i);
		aux4=aux4>>24;
		
		//cout<<aux4<<" 4 "<<aux3<<" 3 "<<aux2<<" 2 "<<aux<<" 1 "<<endl;
		//system("pause");
		
		if(aux4!=0){
			salida.push_back(aux4);
		}
		if(aux3!=0){
		salida.push_back(aux3);
		}
		if(aux2!=0){
		salida.push_back(aux2);	
		}
		if(aux!=0){
		salida.push_back(aux);
		}
		
	}

	Salida();
}
Descifrador::Descifrador(){
	Entrada();
}

void Descifrador::Entrada(){
	
	ifstream archivo;
	int aux;
	string line;
	archivo.open("Enteros.txt",ios::in);
	if(archivo.fail()){
		cout<<"error";
			exit(1);
	}

	while(!archivo.eof()){
		
		getline(archivo,line);
		
		//cout<<line<<endl;
		
		aux=atoi(line.c_str());
		//cout<<aux<<endl;;
		
		entrada.push_back(aux);
		
	}
		
	Metodo();
}
