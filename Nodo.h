#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

template <class T>
class Nodo
{
	private:
		T info;
		Nodo<T> *sig;

	public:
		Nodo();
		Nodo(T e);
		Nodo(T e, Nodo* sigi);
		T Obtinfo();
		void Modinfo(T e);
		Nodo* Obtsig();
		void Modsig(Nodo* aux);

};
#include "Nodo.cpp"
#endif 