#ifndef NODOA_H
#define NODO_H


template <class T>
class NodoA
{
	protected:
		NodoA<T> *hi, *hd;
		T info;
	
	public:
		NodoA();
		NodoA(T e);
		NodoA(T e, NodoA<T> *izq, NodoA<T> *der);
		~NodoA();

		T obtInfo();
		NodoA<T> * obtHi();
		NodoA<T> * obtHd();

		void modInfo(T e);
		void modHi(NodoA<T> *izq);
		void modHd(NodoA<T> *der);


};

template <class T>
NodoA<T>::NodoA()
{
	this -> hi = NULL;
	this -> hd = NULL;
} 

template <class T> 
NodoA<T>::NodoA(T e)
{
	this -> info = e;
	this -> hi = NULL;
	this -> hd = NULL;
}

template <class T> 
NodoA<T>::NodoA(T e, NodoA<T> *izq, NodoA<T> *der)
{
	this -> info = e;
	this -> hi = izq;
	this -> hd = der;
}

template <class T> 
T NodoA<T>::obtInfo()
{
	return this -> info;
}

template <class T> 
NodoA<T> * NodoA<T>::obtHi()
{
	return this -> hi;
}

template <class T> 
NodoA<T> * NodoA<T>::obtHd()
{
	return this -> hd;
}

template <class T> 
void NodoA<T>::modInfo(T e)
{
	this -> info = e;
}

template <class T> 
void NodoA<T>::modHi(NodoA<T> *izq)
{
	this -> hi = izq;
}

template <class T> 
void NodoA<T>::modHd(NodoA<T> *der)
{
	this -> hd = der;
}

template <class T> 
NodoA<T>::~NodoA()
{}

#endif




