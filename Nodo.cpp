#include "Nodo.h"
#include <iostream>

template <class T>
Nodo<T>::Nodo()
{
	this -> sig = NULL;
}

template <class T>
Nodo<T>::Nodo(T e)
{
	this -> info = e;
	this -> sig = NULL;
}

template <class T>
Nodo<T>::Nodo(T e,Nodo* sigi)
{
	this -> info = e;
	this -> sig = sigi;
}

template <class T>
T Nodo<T>::Obtinfo()
{
	return (this -> info);
}

template <class T>
void Nodo<T>::Modinfo(T e)
{
	this -> info = e;
}

template <class T>
Nodo<T> * Nodo<T>::Obtsig()
{
	return (this -> sig);
}

template <class T>
void Nodo<T>::Modsig(Nodo* aux)
{
	this -> sig = aux;
}

