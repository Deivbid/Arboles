#ifndef ARBOLBB_H
#define ARBOLBB_H


#include "ArbolB.h"
#include <iostream>
using namespace std;

template <class T>
class ArbolBB : public ArbolB<T>
{
	protected:
		void print(int nivel, NodoA<T> *p); // LLAMADA POR "IMPRIMIR", IMPRIME EL ARBOL
		void menol(NodoA<T> *p, NodoA<T> **menor, NodoA<T> **anterior, T e); // LLAMADA POR "ELIMINAR", ENCUENTRA EL ELEMENTO MAS PEQUEÑO
		void swap(NodoA<T> **a, NodoA<T> **b);//LLAMADA POR "ELIMINAR", INTERCAMBIA EL CONTENIDO DE 2 APUNTADORES
		void recorrer(NodoA<T> *p, NodoA<T> **elim, NodoA<T> **ant, T e);//LLAMADA POR "ELIMINAR", RECORRE EL ARBOL Y TE DEJA UN APUNTADOR DONDE TU QUIERAS
	public:
	/*	ArbolBB();
		~ArbolBB();*/

		void insertar(T e);
		void eliminar(T e);
		void imprimir();
};

/*template <class T>
ArbolBB<T>::ArbolBB() : ArbolB()
{

}*/

template <class T>
void ArbolBB<T>::insertar(T e)
{
	NodoA<T> *nuevo, *aux, *ant;;


	nuevo = new NodoA<T> (e);
	if(this -> raiz == NULL)
	{
		this -> raiz = nuevo;
	}
	else
	{
		aux = this -> raiz;
		while(aux != NULL)
		{
			ant = aux;
			if(e < aux -> obtInfo())
			{
				aux = aux -> obtHi();
			}
			else
			{
				aux = aux -> obtHd();
			}
		}
		
		if(e < ant -> obtInfo())
		{
			ant -> modHi(nuevo);
		}
		else
		{
			ant -> modHd(nuevo);
		}

	}

}

template <class T>
void ArbolBB<T>::imprimir()
{
	this -> print(0,this -> raiz);
	cout << endl;
}

template <class T>
void ArbolBB<T>::print(int nivel, NodoA<T> *p)
{
	int i;
	if(p != NULL)
	{
		this -> print(nivel + 1, p -> obtHd());

		for(i = 0 ; i < nivel ; i++)
		{
			cout << "  ";
		}
		cout << p -> obtInfo() << endl;

		this -> print(nivel + 1, p -> obtHi());


	}
}

/*template <class T>
ArbolBB<T>::~ArbolBB()
{}*/
template <class T>
void ArbolBB<T>::recorrer(NodoA<T> *p, NodoA<T> **elim,NodoA<T> **ant, T e)
{
	if(p != NULL)
	{
		if(p -> obtHi() != NULL && p -> obtHi() -> obtInfo() == e)
		{
			*ant = p;
		}
		else
		{
			if(p -> obtHd() != NULL && p -> obtHd() -> obtInfo() == e)
			{
				*ant = p;
			}
		}

		if(p -> obtInfo() == e)
		{
			*elim = p;
		}
		else
		{
			recorrer(p -> obtHi(),elim,ant,e);
			recorrer(p -> obtHd(),elim,ant,e);
		}
	}
}

template <class T>
void ArbolBB<T>::menol(NodoA<T> *p,NodoA<T> **menor,NodoA<T> **anterior, T e)	// 	ARREGLAR , AUN NO WORKEA 
{
	if(p != NULL)
	{
		
		if(p -> obtInfo() < e)
		{
			*menor = p;
			e = p -> obtInfo();
		}
		
		menol(p -> obtHi(),menor,anterior,e);
		
		if(p -> obtHi() != NULL && p -> obtHi() == *menor)
		{
			*anterior = p;
		}
		
		menol(p -> obtHd(),menor,anterior,e);
		
		if(p -> obtHd() != NULL && p -> obtHd() == *menor)
		{
			*anterior = p;
		}

		
	}
}

template <class T>
void ArbolBB<T>::swap(NodoA<T> **a,NodoA<T> **b)
{
	T aux;

	aux = (*a) -> obtInfo();
	(*a) -> modInfo((*b) -> obtInfo());
	(*b) -> modInfo(aux);

}

template <class T>
void ArbolBB<T>::eliminar(T e) // PROBLEMA AL DELETEAR 
{
	NodoA<T> *aux, *elim, *menor, *ant;

	aux = this -> raiz;
	this -> recorrer(aux,&elim,&ant,e); 
	
	if(elim -> obtHi() == NULL && elim -> obtHd() == NULL)
	{
		delete elim;
	}
	else
	{
		if(elim -> obtHi() != NULL && elim -> obtHd() != NULL)
		{
			aux = elim;
			menor = elim -> obtHd();
			this -> menol(elim -> obtHd(),&menor,&aux,menor -> obtInfo());
			if(menor -> obtHd() != NULL)
			{
				aux -> modHi(menor -> obtHd());
				swap(&elim,&menor);
				delete menor;
			}
			else
			{
				swap(&elim,&menor);
				delete menor;
			}

		}
		else
		{
			if(ant -> obtHi() -> obtInfo() == e)
			{
				if(elim -> obtHi() == NULL)
				{
					ant -> modHi(elim -> obtHd());
					delete elim;
				}
				else
				{
					ant -> modHi(elim -> obtHi());
					delete elim;
				}

			}
			else
			{
				if(elim -> obtHd() == NULL)
				{
					ant -> modHd(elim -> obtHi());
					delete elim;
				}
				else
				{
					ant -> modHd(elim -> obtHd());
					delete elim;
				}
			}
		}
	}
}


#endif