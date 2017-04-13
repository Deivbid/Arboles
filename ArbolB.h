#ifndef ARBOLB_H
#define ARBOLB_H

#include "NodoA.h"

template <class T>
class ArbolB
{
	protected:
		NodoA<T> *raiz;
		int n;
	
	public:
		/*Cons / Des /tructor*/
		ArbolB();
		~ArbolB();

		/*T obtRaiz();

		void insertarHi(T e);
		void insertarHd(T e);

		void eliminarElemento(T e);*/


};

template <class T>
ArbolB<T>::ArbolB()
{
	this -> raiz = NULL;
	this -> n = 0;
}

template <class T>
ArbolB<T>::~ArbolB() {}

#endif

