#ifndef NODOV_H
#define NODOV_H
#include <iostream>
#include "NodoAdy.h"


template <class T>
class NodoV
{
	protected:
		T vertice;
		NodoV<T> *sig;
		NodoAdy<T> *ady;
	
	public:

		NodoV();
		NodoV(T e);
		NodoV(T e, NodoV<T>* s);
		NodoV(T e, NodoAdy<T> *l);
		NodoV(T e, NodoV<T> *s, NodoAdy<T> *l);
		~NodoV();

		T obtInfo();
		NodoAdy<T> * obtAdy();
		NodoV<T> * obtSig();

		void modVertice(T e);
		void modSig(NodoV<T> *s);
		void modAdy(NodoAdy<T> *l);
};

template <class T>
NodoV<T>::NodoV()
{
	this -> sig = NULL;
	this -> ady = NULL;
}

template <class T>
NodoV<T>::NodoV(T e)
{
	this -> vertice = e;
	this -> sig = NULL;
	this -> ady = NULL;
}

template <class T>
NodoV<T>::NodoV(T e, NodoV<T> *s)
{
	this -> vertice = e;
	this -> sig = s;
	this -> ady = NULL;
}

template <class T>
NodoV<T>::NodoV(T e, NodoAdy<T> *l)
{
	this -> vertice = e;
	this -> sig = NULL;
	this -> ady = l;
}

template <class T>
NodoV<T>::NodoV(T e, NodoV<T> *s, NodoAdy<T> *l)
{
	this -> vertice = e;
	this -> sig = s;
	this -> ady = l;
}

template <class T>
NodoV<T>::~NodoV() {}

template <class T>
T NodoV<T>::obtInfo()
{
	return this -> vertice;
}

template <class T>
NodoV<T> * NodoV<T>::obtSig()
{
	return this -> sig;
}

template <class T>
NodoAdy<T> * NodoV<T>::obtAdy()
{
	return this -> ady;
}

template <class T>
void NodoV<T>::modVertice(T e)
{
	this -> vertice = e;
}

template <class T>
void NodoV<T>::modAdy(NodoAdy<T> *l)
{
	this -> ady = l;
}

template <class T>
void NodoV<T>::modSig(NodoV<T> *s)
{
	this -> sig = s;
}




#endif