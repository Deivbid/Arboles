#include "Cola.h"
#include <iostream>
using namespace std;


template <class tipo>
Cola<tipo>::Cola()
{
	this -> frente = NULL;
	this -> final = NULL;
}

template <class tipo>
Cola<tipo>::Cola(const Cola<tipo> &C)
{
	this -> copiar(C);
}

template <class tipo>
Cola<tipo>::~Cola()
{
	this -> borrar();

}



template <class tipo>
bool Cola<tipo>::esVacia() const
{
	if(this -> frente == NULL || this -> final == NULL )
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class tipo>
void Cola<tipo>::Encolar(tipo e)
{
	Nodo<tipo> *aux;

	aux = new Nodo<tipo> (e);

	if(this -> frente == NULL)
	{
		this -> frente = aux;
		this -> final = aux;
	}
	else
	{
		final -> Modsig(aux);
		final = aux;
	}
}

template <class tipo>
void Cola<tipo>::Desencolar()
{
	Nodo<tipo> *aux;

	aux = this -> frente; 
	this -> frente = this -> frente -> Obtsig();

	delete aux;
}

template <class tipo>
tipo Cola<tipo>::Obtfrente() const
{
	return this -> frente -> Obtinfo();
	
}

template <class tipo>
void Cola<tipo>::imprimir()
{
	Nodo<tipo> *aux;
	aux = this -> frente;

	while(aux != NULL)
	{
		
		if(aux -> Obtsig() == NULL)
		{
			cout << aux -> Obtinfo() << "";
		}
		else
		{
			cout << aux -> Obtinfo() << "";
		}
		aux = aux -> Obtsig();
	}

	cout << endl;

}

template <class tipo>
int Cola<tipo>::longitud() const
{
	Nodo<tipo> *aux;
	int i = 0;
	aux = this -> frente;
	while(aux != NULL)
	{
		i++;
		aux = aux -> Obtsig();
	}

	return i;
}

template <class tipo>
void Cola<tipo>::invertir()
{
	Nodo<tipo> *act,*ant,*prox;

	ant = NULL;
	act = this -> frente;
	prox = act -> Obtsig();
	while(prox != NULL)
	{
		act -> Modsig(ant);
		ant = act;
		act = prox;
		prox = prox -> Obtsig();
	}
 	act -> Modsig(ant);

	prox = this -> frente;
	this -> frente = this -> final;
	this -> final = prox;


}

template <class tipo>
void Cola<tipo>::copiar(const Cola<tipo> &C)
{
	Nodo<tipo> *act, *aux, *ant;

	act = C.frente;

	if(C.frente != NULL)
	{

		aux = new Nodo<tipo> (act -> Obtinfo());
		act = act -> Obtsig();
		this -> frente = aux;
		ant = aux;

		while(act != NULL)
		{
			aux = new Nodo<tipo> (act -> Obtinfo());
			act = act -> Obtsig();
			ant -> Modsig(aux);
			ant = ant -> Obtsig();
		}
		
	}
}

template <class tipo>
void Cola<tipo>::borrar()
{
	Nodo<tipo> *aux;
	while(this -> frente != NULL)
	{
		aux = this -> frente;
		this -> frente = this -> frente -> Obtsig();
		delete aux;
	}
	this -> final = NULL;
}


