#include "Encriptador.h"
#include <iostream>
#include "String.h"
#include "stdlib.h"
#include <fstream>
#include <vector>
using namespace std;

void Encriptador::MetodoEncriptante(vector<char> Mensaje,vector<unsigned int> MensajeCode){
	
	int aux3=0;
	int cont=0;
	unsigned int res;
	unsigned int check=0;
	int aux=Mensaje.size();
	ofstream g("Enteros.txt");
	for(int i=0;i<aux;i++)
	{
		res=0;
		res=(int)res|Mensaje.at(i);
		//cout<<"check "<<check<<endl;//valor de la letra en decimal
		check=check|res;
		//cout<<"res es : "<<res<<endl;
	cont++;
	//cout<<cont<<endl;	
	//cout<<"este es check : "<<check<<endl;//numero despues de correrse en 8bits y hacer o con el siguiente	
		if(cont<4){
		if(aux%4!=0){
		aux3=check;		
		}	
		check=check<<8;
			
		}
		else{
			//cout<<check<<endl;
			MensajeCode.push_back(check);
			check=0;
			cont=0;	
		}
	}	
	//cout<<"residuos "<<aux3<<endl;
		if(aux3!=0){
		MensajeCode.push_back(aux3);	
		}
		int aux2=MensajeCode.size();
	//cout<<"tam de MensajeCode "<<aux2<<endl;
	
		for(int y=0; y<MensajeCode.size();y++)
		{
			g << MensajeCode.at(y) << endl;
		}
		g.close();
}
char* Encriptador::Entrada(){
	
 fstream ficheroEntrada;
 char letra;
 vector<char> mensaje;

 ficheroEntrada.open ("Entrada.txt", ios::in);
 if (ficheroEntrada.is_open()) {
 while (! ficheroEntrada.eof() ) {
 ficheroEntrada >> letra;
 //cout << letra;
 mensaje.push_back(letra);
 }
 ficheroEntrada.close();
 }
 else cout << "Fichero inexistente" << endl;
 
 int aux=mensaje.size();
 	mensaje.pop_back();
  	aux=mensaje.size();

 
 char *entrada=new char[aux];
 //char* entrada=(char*) malloc(sizeof(char)*aux);
 
 for(int j=0;j<aux;j++){
 	
 	*(entrada+j)=mensaje.at(j);

 }
 cout<<"Cadena: "<<entrada<<endl;
 
 return entrada;
 
}//fin de entrada
void Encriptador::Enmascarador(char*mensaje){

int aux=strlen(mensaje);
vector<char> Mensaje;//aqui almaceno las carateres 1x1 antes de hacer el enmascaramiento
vector<unsigned int>	MensajeCode;//aqui almaceno las salidas
for(int i=0;i<aux;i++){
	Mensaje.push_back(*(mensaje+i));
}

MetodoEncriptante(Mensaje,MensajeCode);

}//lave de entrada
Encriptador::Encriptador(){

	Enmascarador(Entrada());
	
}
