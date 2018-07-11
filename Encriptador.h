#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H
#include <vector>
using namespace std;

class Encriptador
{

	public:
		void MetodoEncriptante(vector<char>,vector<unsigned int>);	
		char* Entrada();
		void Enmascarador(char*);
		Encriptador();
		
	
	protected:
};

#endif
