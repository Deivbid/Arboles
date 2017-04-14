#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

template <class tipo>
class Cola
{
	private:
		Nodo<tipo> *frente,*final;
	public:
		//Tores
		Cola();
		Cola(const Cola<tipo> &C);
		~Cola();

		//GETS
		bool esVacia() const;
		tipo Obtfrente() const;
		int longitud() const;
		
		//SETS
		void Encolar(tipo e);
		void Desencolar();	
		void imprimir();
		void invertir();
		void copiar(const Cola<tipo> &C);
		void borrar();
		
};
#include "Cola.cpp"





#endif