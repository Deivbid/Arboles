#include "Lista.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
Lista<T>::Lista()
{
	this -> n = 0;
	this -> primero = NULL;
}

template <class T>
Lista<T>::Lista(const Lista<T> &L)
{
	this -> copiar(L);
}

template <class T>
bool Lista<T>::esVacia() const
{
	if(this -> primero == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


template <class T>
int Lista<T>::longitud() const
{
	return (this -> n);
}


template <class T>
bool Lista<T>::esta(T e) const
{
	Nodo<T> *aux;
	int i;
	bool j = false;

	aux = this -> primero;
	for(i = 0; i < (this->n) - 1 ; i++)
	{
		if(aux -> Obtinfo() == e )
		{
			j = true;
		}
		aux -> Modsig(aux -> Obtsig());
	}

	return j;
}


template <class T>
T Lista<T>::consultar(int pos) const
{
	Nodo<T> *aux;
	int i;

		aux = this -> primero;
		for(i = 1 ; i < pos ; i++)
		{
			aux = aux -> Obtsig();
		}

		return aux -> Obtinfo();
}


template <class T>
void Lista<T>::insertar(T e,int pos)
{
	Nodo<T> *aux, *act;
	int i;

	if(pos > 0 && pos <= (this -> n + 1))
	{
		aux = new Nodo<T> (e);
		act = primero;
		if(pos == 1)
		{
			aux -> Modsig(this -> primero);
			this -> primero = aux;
		}
		else
		{
			for( i = 1 ; i < pos-1 ; i++)
			{
				act = act -> Obtsig();
			}
			aux -> Modsig(act -> Obtsig());
			act -> Modsig(aux);
		}
		this -> n = this -> n + 1;

	}
}


template <class T>
void Lista<T>::eliminar(int pos)
{
	Nodo<T> *ant, *prox;
	int i;

	if(pos > 0 && pos <= this -> n)
	{
		ant = this -> primero;
		prox = ant -> Obtsig();
		if(pos == 1)
		{
			this -> primero = prox;
			delete ant;
		}
		else
		{
			for(i = 1 ; i < pos-1 ; i++)
			{
				ant = prox;
				prox = prox -> Obtsig();
			}
			ant -> Modsig(prox -> Obtsig());
			delete prox;
		}
		this -> n = this -> n - 1;
	}
}


template <class T>
void Lista<T>::modificar(T e, int pos)
{
	Nodo<T> *aux;
	int i;

	if(pos > 0 && pos < this -> n)
	{
		aux = this -> primero;
		for(i = 1 ; i < pos ; i++)
		{
			aux = aux -> Obtsig();
		}
		aux -> Modinfo(e);
	}
}


template <class T>
void Lista<T>::imprimir()
 {
 	Nodo<T> *aux;

 	aux = this -> primero;
 	if(aux == NULL)
 	{
 		cout << "La lista esta Vacia :c" << endl;
 	}
 	else
 	{
 		while(aux != NULL)
 		{
 			cout << aux -> Obtinfo();
 			if(aux -> Obtsig() != NULL)
 			{
 				cout << "";
 			}
 			aux = aux -> Obtsig();
 		}
 		cout << "\n" << endl;
 	}
 }


template <class T>
 void Lista<T>::invertir()
 {
 	Nodo<T> *ant,*prox;
 	ant = NULL;

 	while(this -> primero != NULL)
 	{
 		prox = this -> primero -> Obtsig();
 		this -> primero -> Modsig(ant);
 		ant = this -> primero;
 		this -> primero = prox;
 	}
 	this -> primero = ant;
 }


template <class T>
Lista<T>::~Lista()
{
	this -> borrar();
}


template <class T>
int Lista<T>::csublista(Lista x) const
{
	Nodo<T> *master,*aux1,*aux2;
	bool flag = true;
	int cont = 0;

	master = this -> primero;
	aux2 = x.primero;

	while(master != NULL)
	{
		aux1 = master;
		if(aux1 -> Obtinfo() == aux2 -> Obtinfo())
		{
			while(aux1 != NULL && aux2 != NULL)
			{
				if(aux1 -> Obtinfo() == aux2 -> Obtinfo())
				{
					aux1 = aux1 -> Obtsig();
					aux2 = aux2 -> Obtsig();
				}
				else
				{
					aux1 = NULL;
				}
			}

			if(aux2 == NULL)
			{
				cont++;
				aux2 = x.primero;
				master = master -> Obtsig();
			}
			else
			{
				aux2 = x.primero;
				master = master -> Obtsig();
			}
		}
		else
		{
			master = master -> Obtsig();
		}
	}

	return cont;
}

template <class T>
void Lista<T>::copiar(const Lista<T> &L)
{
	Nodo<T> *act, *aux, *ant;

	act = L.primero;

	if(L.primero != NULL)
	{

		aux = new Nodo<T> (act -> Obtinfo());
		act = act -> Obtsig();
		this -> primero = aux;
		ant = aux;

		while(act != NULL)
		{
			aux = new Nodo<T> (act -> Obtinfo());
			act = act -> Obtsig();
			ant -> Modsig(aux);
			ant = ant -> Obtsig();
		}
		this -> n = L.n;
	}

}

template <class T>
void Lista<T>::borrar()
{
	Nodo<T> *aux;

	aux = this -> primero;
	while(this -> primero != NULL)
	{
		this -> primero = this -> primero -> Obtsig();
		delete aux;
		aux = this -> primero;
	}
	this -> n = 0;
}


template <class T>
bool Lista<T>::esSublista(const Lista<T> L) const
{
	Nodo<T> *L1,*L2;
	bool p = false;

	/*L1 = this -> primero;
	L2 = L.primero;
	while(L2 != NULL && !p)
	{
		if(L1 -> Obtinfo() == L2 -> Obtinfo())
		{
			L1 = L1 -> Obtsig();
			if(L1 == NULL)
			{
				p = true;
			}
		}
		else
		{
			L1 = this -> primero;
		}

		L2 = L2 -> Obtsig();
	}
	L1 = this -> primero;*/

	if(this -> csublista() >= 1)
		p = true;


	return p;
}

template <class T>
void Lista<T>::compactar()
{
	Lista L;
	Nodo<T> *aux,*sig;
	int e,cont = 1;

	aux = this -> primero;
	//sig = aux -> Obtsig();

	while(aux != NULL)
	{
		sig = aux -> Obtsig();
		e = aux -> Obtinfo();
		while(sig != NULL && sig -> Obtinfo() == e)
		{
			cont ++;
			sig = sig -> Obtsig();
		}
		cout << e << " " << cont << endl;
		aux = sig;
		cont = 1;
	}

}

template <class T>
void Lista<T>::ordenar(bool tipo)
{
	Nodo<T> *p,*s;
	int i,j,aux;

	p = this -> primero;
	s = p -> Obtsig();

	if(tipo)
	{
		for(i = 0 ; i < this -> n - 1 ; i++)
		{
			for(j = 0 ; j < this -> n - 1 ; j++)
			{
				if(p -> Obtinfo() > s -> Obtinfo())
				{
					aux = p -> Obtinfo();
					p -> Modinfo(s -> Obtinfo());
					s -> Modinfo(aux);
				}
				p = p -> Obtsig();
				s = s -> Obtsig();
			}

			p = this -> primero;
			s = p -> Obtsig();
		}
	}
	else
	{
		for(i = 0 ; i < this -> n -1 ; i++)
		{
			for(j = 0 ; j < this -> n -1  ; j++)
			{
				if(p -> Obtinfo() < s -> Obtinfo())
				{
					aux = p -> Obtinfo();
					p -> Modinfo(s -> Obtinfo());
					s -> Modinfo(aux);
				}
				p = p -> Obtsig();
				s = s -> Obtsig();
			}

			p = this -> primero;
			s = p -> Obtsig();
		}
	}
}

template <class T>
void Lista<T>::insertarOrdenado(Nodo<T> **L1, Nodo<T> *L2)
{

	if(L2 != NULL)
	{
		this -> insertarOrdenado(L1,L2 -> Obtsig());

		while((*L1) != NULL && (*L1) -> Obtinfo() < L2 -> Obtinfo())
		{

			this -> insertar((*L1) -> Obtinfo(),1);
			*L1 = (*L1) -> Obtsig();
		}

		this -> insertar(L2 -> Obtinfo(),1);

	}
}

template <class T>
void Lista<T>::mergesort(const Lista<T> L1, const Lista<T> L2)
{
	Nodo<T> *aux;
	aux = L1.primero;
	this -> insertarOrdenado(&(aux),L2.primero);
	while(aux != NULL)
	{
		this -> insertar(aux -> Obtinfo(),1);
		aux = aux -> Obtsig();
	}
	this -> invertir();

}

template <class T>
Lista<T> Lista<T>::sublista(int posi, int posf)
{
	Lista<T> L;
	Nodo<T> *aux,*aux2;
	int i;
	if((posi > 0) && (posi <= (this -> n)) && (posf > 0) && (posf <= (this -> n)))
	{
		aux = this -> primero;
		aux2 = this -> primero;
		for(i = 1 ; i<posi ; i++)
		{
			aux = aux -> Obtsig();
		}

		for(i = 1 ; i<posf ; i++)
		{
			aux2 = aux2 -> Obtsig();
		}
		
		if(posi < posf)
		{
			while(aux != aux2 -> Obtsig())
			{
				L.insertar(aux -> Obtinfo(),1);
				aux = aux -> Obtsig();
			}
		}
		else
		{
			while(aux2 != aux-> Obtsig())
			{
				L.insertar(aux2 -> Obtinfo(),1);
				aux2 = aux2 -> Obtsig();
			}
		}

	}
	L.invertir();
	return L ;


}

template <class T>
Lista<T> &Lista<T>::operator =(const Lista<T> &L)
{
	this -> copiar(L);
}

template <class T>
void Lista<T>::Aleatoria(int longi)
{
	Nodo<T> *aux;
	srand(time(NULL));
	int num,i;

	for(i = 0 ; i < longi ; i++)
	{
		num = 1 + rand()% (101 - 1);
		this -> insertar(num,i + 1);
	}
}

template <class T>
void Lista<T>::insertarSort(T e)
{
	 Nodo<T> *aux,*tmp,*nuevo;

	  nuevo = new Nodo<T> (e);
	  if(this -> primero == NULL || e < this -> primero -> Obtinfo())
	  {
	    nuevo -> Modsig(this -> primero);
	    this -> primero = nuevo;
	  }
	  else
	  {
	    aux = NULL;
	    tmp = this -> primero;
	    while(tmp != NULL && e > tmp -> Obtinfo())
	    {
	      aux = tmp;
	      tmp = tmp -> Obtsig();
	    }
	    aux -> Modsig(nuevo);
	    nuevo -> Modsig(tmp);
	  }
	  this -> n = this -> n++;
}

template <class T>
void Lista<T>::invertirSublista(T a,T b)
{
	Nodo<T> *prim, *seg, *ant, *prox, *aux1, *aux2;
	T aux;

	prim = this -> primero;
	seg = this -> primero;
	ant = this -> primero;
	prox =  this -> primero;


	if(b < a)
	{
		aux = a;
		a = b;
		b = aux;
	}
	
	while(prim -> Obtinfo() != a)
	{
		prim = prim -> Obtsig();
	}

	while(seg -> Obtinfo() != b)
	{
		seg = seg -> Obtsig();
	}




		while(ant != NULL && ant -> Obtsig() != prim )
		{
			ant = ant -> Obtsig();
		}

		while(prox != seg -> Obtsig())
		{
			prox = prox -> Obtsig();
		}

		aux1 = prim -> Obtsig();
		aux2 = aux1 -> Obtsig();
		prim -> Modsig(prox);

		while(prim != seg)
		{
			aux1 -> Modsig(prim);
			prim = aux1;
			aux1 = aux2;
			aux2 = aux2 -> Obtsig();
		}

		if(ant != NULL)
			ant -> Modsig(seg);
		if(a == this -> primero -> Obtinfo())
			this -> primero = seg;
	
}

template <class T>
void Lista<T>::codificar(Lista<T> L)
{
	Nodo<T> *aux, *izq, *der;
	Lista<T> P;
	int i;

	aux = L.primero;
	izq = aux;

	
	for(i = 0 ; i < L.n/2 ; i++) // UBICO UN APUNTADOR EN EL MEDIO
	{
		aux = aux -> Obtsig();
	}
	


	this -> insertar(aux ->Obtinfo(),1);	//INSERTO

	
	der = aux -> Obtsig();
	
	while(izq != aux)						// "INVIERTO" LOS ELEMENTOS DE LA IZQUIERDA
	{
		P.insertar(izq -> Obtinfo(),1);
		izq = izq -> Obtsig();
	}

	while(!P.esVacia() && der != NULL)	// COMIENZO A INSERTAR, DERECHA E IZQUIERDA
	{

		
		this -> insertar(P.consultar(1),1);
		this -> insertar(der -> Obtinfo(),1);
		der = der -> Obtsig();
		P.eliminar(1);
	}

	while(!P.esVacia())						// REVISO QUE NO HAYA QUEDADO NADA POR FUERA
	{
		this -> insertar(P.consultar(1),1);
		P.eliminar(1);
	}

	while(der != NULL)
	{
		this -> insertar(der -> Obtinfo(),1);
		der = der -> Obtsig();
	}

	this -> invertir();				// INVIERTO Y LISTO!

}

template <class T>
int Lista<T>::obtPos(T e)
{
	Nodo<T> *aux;
	int i;
	aux = this -> primero;
	i = 1;
	while(aux -> Obtinfo() != e)
	{
		aux = aux -> Obtsig();
		i++;
	}

	return i;
}
