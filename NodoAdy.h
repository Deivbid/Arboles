#ifndef NODOADY_H
#define NODOADY_H

#include <iostream>


template <class T>
class NodoAdy
{
	protected:
		T info;
		float costo;
		NodoAdy<T> *prox;

	public:

		NodoAdy();
		NodoAdy(T e);
		NodoAdy(T e, float c);
		NodoAdy(T e, float c, NodoAdy<T> *p);
		~NodoAdy();

		T obtInfo();
		float obtCosto();
		NodoAdy<T> * obtProx();

		void modInfo(T e);
		void modCosto(float c);
		void modProx(NodoAdy<T> *p);

};

template <class T>
NodoAdy<T>::NodoAdy()
{
	this -> costo = 0;
	this -> prox = NULL;
}

template <class T>
NodoAdy<T>::NodoAdy(T e)
{
	this -> info = e;
	this -> costo = 0;
	this -> prox = NULL;
}

template <class T>
NodoAdy<T>::NodoAdy(T e, float c)
{
	this -> info = e;
	this -> costo = c;
	this -> prox = NULL;
}

template <class T>
NodoAdy<T>::NodoAdy(T e, float c, NodoAdy<T> *p)
{
	this -> info = e;
	this -> costo = c;
	this -> prox = p;
}

template <class T>
NodoAdy<T>::~NodoAdy() {}

template <class T>
T NodoAdy<T>::obtInfo()
{
	return this -> info;
}

template <class T>
float NodoAdy<T>::obtCosto()
{
	return this -> costo;
}

template <class T>
NodoAdy<T> * NodoAdy<T>::obtProx()
{
	return this -> prox;
}

template <class T>
void NodoAdy<T>::modInfo(T e)
{
	this -> info = e;
}

template <class T>
void NodoAdy<T>::modCosto(float c)
{
	this -> costo = c;
}

template <class T>
void NodoAdy<T>::modProx(NodoAdy<T> *p)
{
	this -> prox = p;
}




#endif