#ifndef ARBOLB_H
#define ARBOLB_H

#include "Lista.h"
#include "NodoA.h"

template <class T>
class ArbolB
{
	//Atributos y Metodos Protejidos
	protected:
		NodoA<T> *raiz;
		int n;

		NodoA<T> * copiar(NodoA<T> *p);// Utilizado en el Constructor Copia, copia el arbol
																						//void copy(NodoA<T> *original, NodoA<T> *&copia);
		int calculoPeso(NodoA<T> *p);//utilizado en "hijoIzq y Der", calcula el peso del arbol
																						//void destruir(NodoA<T> *&p);//Utilizado en borrar y destructor, destruye todo
		NodoA<T> * lecturaPrIn(Lista<T> &Pre, Lista<T> In, int posi, int posf);//
		void destruirD(NodoA<T> *p);
		void print(int nivel, NodoA<T> *p);//Utilizado en imprimir, IMprime el arbol bien bonito
	
	public:
		/*Cons / Des /tructor*/
		ArbolB();
		ArbolB(const ArbolB<T> &A);
		~ArbolB();


		bool esNulo();
		int peso();
		T obtRaiz();
		ArbolB<T> hijoIzq();
		ArbolB<T> hijoDer();
		bool esHoja();

		void insertarHi(const ArbolB<T> A); //NO DEBE TENER HIJO IZQ ANTES DE INSERTAR
		void insertarHd(const ArbolB<T> A);	//LO MISMO PARA ESTE
		void eliminarHi();
		void eliminarHd();
		void borrar();
		void lecturaPrIn(Lista<T> L1, Lista<T> L2);
		void imprimir();
		ArbolB<T> operator=(const ArbolB<T> &A);

};

template <class T>
ArbolB<T>::ArbolB()
{
	this -> raiz = NULL;
	this -> n = 0;
}

template <class T>
ArbolB<T>::ArbolB(const ArbolB<T> &A)// *
{
	this -> raiz = this -> copiar(A.raiz);
	this -> n = A.n;
}

template <class T>
NodoA<T> * ArbolB<T>::copiar(NodoA<T> *p)// *
{
	NodoA<T> *nuevo;

	if( p != NULL )
	{
		return nuevo = new NodoA<T> (p -> obtInfo(),copiar(p -> obtHi()),copiar(p -> obtHd()));
	}
	else
	{
		return NULL;
	}
}

template <class T>
bool ArbolB<T>::esNulo()
{
	if(this -> raiz == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
int ArbolB<T>::peso()
{
	return n;
}

template <class T>
T ArbolB<T>::obtRaiz()
{
	return this -> raiz -> obtInfo();
}

template <class T>
int ArbolB<T>::calculoPeso(NodoA<T> *p) //*
{
	if( p == NULL)
	{
		return 0;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			return 1;
		}
		else
		{
			return 1 + calculoPeso(p -> obtHi()) + calculoPeso(p -> obtHd());
		}
	}
}

template <class T>
ArbolB<T> ArbolB<T>::hijoIzq() //*
{
	ArbolB nuevo;
	nuevo.raiz = this -> raiz -> obtHi();
	nuevo.n = this -> calculoPeso(nuevo.raiz);

	return nuevo;
}

template <class T>
ArbolB<T> ArbolB<T>::hijoDer() //*
{
	ArbolB nuevo;
	nuevo.raiz = this -> raiz -> obtHd();
	nuevo.n = this -> calculoPeso(nuevo.raiz);

	return nuevo;
}

template <class T>
bool ArbolB<T>::esHoja()
{
	if(this -> raiz -> obtHi() == NULL && this -> raiz -> obtHd() == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void ArbolB<T>::insertarHi(const ArbolB<T> A)
{
	this -> raiz -> modHi(A.raiz);
}

template <class T>
void ArbolB<T>::insertarHd(const ArbolB<T> A)
{
	this -> raiz -> modHd(A.raiz);
}

/*template <class T>
void ArbolB<T>::destruir(NodoA<T> *&p) //*
{
	if(p != NULL)
	{
		if( p  -> obtHd() != NULL)
		{
			this -> destruir(p -> obtHd());
		}

		if( p  -> obtHi() != NULL)
		{
			this -> destruir(p -> obtHi());
		}

		delete  p ;
		 p  = NULL;
	}
}*/

template <class T>
void ArbolB<T>::eliminarHi()
{
	this -> destruirD(this -> raiz -> obtHi());
	this -> raiz -> modHi(NULL);
}

template <class T>
void ArbolB<T>::eliminarHd()
{
	this -> destruirD(this -> raiz -> obtHd());
	this -> raiz -> modHd(NULL);
}

template <class T>
void ArbolB<T>::borrar()
{
	this -> destruirD(this -> raiz);
	this -> raiz = NULL;
}




template <class T>
ArbolB<T>::~ArbolB()
{
	this -> borrar();
}

template <class T>
void ArbolB<T>::lecturaPrIn(Lista<T> Pre, Lista<T> In)
{
	this -> n = Pre.longitud();
	this -> raiz = lecturaPrIn(Pre,In,1,Pre.longitud());
}

template <class T>
NodoA<T> * ArbolB<T>::lecturaPrIn(Lista<T> &Pre, Lista<T> In, int posi, int posf)
{
	T aux;
	NodoA<T> *nuevo;
	
	if(posi <= posf)
	{
		aux = Pre.consultar(1);
		Pre.eliminar(1);
		nuevo = new NodoA<T> (aux, lecturaPrIn(Pre,In,posi,In.obtPos(aux) - 1),lecturaPrIn(Pre,In,In.obtPos(aux) + 1, posf));
		return nuevo;
	}
	else
	{
		return NULL;
	}
}

template <class T>
void ArbolB<T>::destruirD(NodoA<T> *p)
{
	if(p != NULL)
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			delete p;
		}
		else
		{
			this -> destruirD(p -> obtHi());
			this -> destruirD(p -> obtHd());
			delete p;
		}
	}
}

template <class T>
void ArbolB<T>::imprimir()
{
	if( this -> raiz == NULL )
	{
		cout << "El arbol esta vacio" << endl;
	}
	else
	{
		this -> print(0,this -> raiz);
		cout << endl;
	}
}

template <class T>
void ArbolB<T>::print(int nivel, NodoA<T> *p)
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

template <class T>
ArbolB<T> ArbolB<T>::operator=(const ArbolB<T> &A)
{
	this -> raiz = this -> copiar(A.raiz);
	this -> n = A.n;


	return A;
}

/*template <class T>
void ArbolB<T>::copy(NodoA<T> *original, NodoA<T> *&copia)
{
	if(original != NULL)
	{
		copia = new NodoA<T> (original -> obtInfo(), copy(original -> obtHi(), copia -> obtHi()), copy(original -> obtHd(), copia -> obtHd()));
	}
	else
	{
		copia = NULL;
	}
}*/
#endif

