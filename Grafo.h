#ifndef GRAFO_H
#define GRAFO_H

#include "Lista.h"
#include "NodoAdy.h"
#include "NodoV.h"
#include <iostream>

// CUANTAS LINEAS TENDRA?    .-DAVID APARICIO 11:31PM, 20/04/2016

template <class T>
class Grafo
{
	protected:
		//APUNTADOR A NODO VERTICE, g CON n COMO NUMERO DE VERTICES
		NodoV<T> *g;
		int n;

		/*************** METODOS PRIVADITOS ********************/
		void eliminarVertice(NodoV<T> *); //DADO EL APUNTADOR D EUN VERTICE LO BORRA COMPLETO INCLUYENDO SUS ARCOS

	public:

		//CONSTRUCTOR Y DESTRUCTOR
		Grafo();
		~Grafo();

		//OBTENER DATA
		bool esVacio();// DETERMINA SI EL GRAFO ES VACIO
		bool existeVertice(T );//DETERMINA SI EXISTE UN VERTICE DADO EN EL GRAFO
		bool existeArco(T , T );//DETERMINA SI EXISTE UN ARCO ENTRE UN PAR DE VERTICES DADOS
		float costoArco(T , T);//RETORNA EL PESO O COSTO DEL ARCO DE DOS VERTICES DADOS
		int orden();//INDICA EL ORDEN DEL GRAGO, ES DECIR, EL NUMERO DE VERTICES QUE TIENE
		Lista<T> predecesores(T );//RETORNA UNA LISTA CON LOS PREDECESORES DE UN VERTICE DADO, DE NO EXISTIR LA LISTA ESTARA VACIA
		Lista<T> sucesores(T );//RETORNA UNA LISTA DE CON LOS SUCESORES DE UN VERTICE DADO, DE NO EXISTIR LA LISTA ESTARA VACIA


		//VOID'S
		void agregarVertice(T );//AGREGA UN VERTICE ORDENADAMENTE A LA LISTA DE ADYACENCIA
		void agregarArco(T , T , float ); //Agrega Arco entre un par de vertices, con su peso, DEBEN EXISTIR AMBOS VERTICES
		void eliminarVertice(T ); //ELIMINA UN VERTICE CON TODOS SUS ARCOS
		void eliminarArco(T, T );//ELIMINA UN ARCO ENTRE 2 VERTICES DADOS, ESTA PENSADO PARA GRAFO DIRIGIDOS, SI ES NO DIRIGIDO NECESITA OTRA IMPLEMENTACION
		void borrar();//BORRA EL GRAFO
		void imprimir();//IMPRIME EL GRAFO , A LA IZQUIERDA LOS VERTICES, A LA DERECHA SUS ARCOS
		void copiar(const Grafo<T> &A);//COPIA EL GRAFO





};

/************** CONSTRUCTOR Y DESTRUCTOR *****************/

template <class T>
Grafo<T>::Grafo()
{
	this -> g = NULL;
	this -> n = 0;
}

template <class T>
Grafo<T>::~Grafo()
{
	this -> borrar();
}

/*************** HASTA AQUI CONSTRUCOTR Y DESTRUCTOR ********/


/************** OBTENER DATA ****************/
template <class T>
bool Grafo<T>::esVacio()
{
	if(this -> g == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool Grafo<T>::existeVertice(T e)
{
	NodoV<T> *aux;

	if(this -> g == NULL)
	{
		return false;
	}
	else
	{
		aux = this -> g;

		while(aux != NULL && aux -> obtInfo() != e)
		{
			aux = aux -> obtSig();
		}

		if(aux == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

template <class T>
bool Grafo<T>::existeArco(T v, T w)
{
	NodoV<T> *aux;
	NodoAdy<T> *arco;

	aux = this -> g;

	while(aux != NULL && aux -> obtInfo() != v)
	{
		aux -> aux -> obtSig();
	}

	if(aux == NULL)
	{
		return false;
	}
	else
	{
		arco = aux -> obtAdy();
		while(arco != NULL && arco -> obtInfo() != w)
		{
			arco = arco -> obtProx();
		}

		if(arco == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
}

template <class T>
float Grafo<T>::costoArco(T v, T w)
{
	NodoV<T> *aux;
	NodoAdy<T> *arco;
	float result;

	aux = this -> g;

	while(aux != NULL && aux -> obtInfo() != v)
	{
		aux -> aux -> obtSig();
	}

	arco = aux -> obtAdy();
	
	while(arco != NULL && arco -> obtInfo() != w)
	{
		arco = arco -> obtProx();
	}

	return arco -> obtCosto();
	
}

template <class T>
int Grafo<T>::orden()
{
	NodoV<T> *aux;
	int i;

	if(this -> g == NULL)
	{
		return 0;
	}
	else
	{
		aux = this -> g;

		while(aux != NULL)
		{
			i++;
			aux = aux -> obtSig();
		}

		return i;
	}
}

template <class T>
Lista<T> Grafo<T>::predecesores(T e)
{
	NodoV<T> *aux;
	NodoAdy<T> *arco;
	Lista<T> pred;

	aux = this -> g;

	while(aux != NULL)
	{
		if(aux -> obtInfo() != e)
		{	
			arco = aux -> obtAdy();
			
			while(arco != NULL && arco -> obtInfo() != e)
			{
				arco = arco -> obtProx();
			}

			if(arco != NULL)
			{
				pred.insertar(aux -> obtInfo(), 1);
			}

		}

		aux = aux -> obtSig();
	}

	return pred;
}

template <class T>
Lista<T> Grafo<T>::sucesores(T e)
{
	NodoV<T> *aux;
	NodoAdy<T> *arco;
	Lista<T> suc;

	aux = this -> g;

	while( aux != NULL && aux -> obtInfo() != e)
	{
		aux = aux -> obtSig();
	}

	arco = aux -> obtAdy();
			
	while(arco != NULL && arco -> obtInfo() != e)
	{
		suc.insertar(arco -> obtInfo(), 1);
		arco = arco -> obtProx();
	}


	return suc;
}

/********************** FIN DE OBTENER DATA ***********/

/********************** VOID'S ***********************/
template <class T>
void Grafo<T>::agregarVertice(T e)
{
	NodoV<T> *ant, *nuevo, *sigi;

	if(this -> g == NULL)
	{
		this -> g = new NodoV<T> (e);
	}
	else
	{
		ant = NULL;
		sigi = this -> g;
		nuevo = new NodoV<T> (e);

		while(sigi != NULL && sigi -> obtInfo() < e)
		{
			ant = sigi;
			sigi = sigi -> obtSig();
		}

		 if(ant == NULL)
		 {
		 	nuevo -> modSig(this -> g);
		 	this -> g = nuevo;
		 }
		 else
		 {
		 	nuevo -> modSig(sigi);
		 	ant -> modSig(nuevo);
		 }
	}
}

template <class T>
void Grafo<T>::agregarArco(T v, T w, float costo)
{
	NodoV<T> *aux; 
	NodoAdy<T> *ady, *nuevo, *ant;

	aux = this -> g;
	nuevo = new NodoAdy<T> (w, costo);

	while(aux != NULL && aux -> obtInfo() != v)
	{
		aux = aux -> obtSig();
	}


	ant = NULL;
	ady = aux -> obtAdy();

		
	while(ady != NULL && ady -> obtInfo() < w)
	{
		ant = ady;
		ady = ady -> obtProx();
	}

	if(ant == NULL)
	{
		nuevo -> modProx(ady);
		aux -> modAdy(nuevo);
	}
	else
	{
		nuevo -> modProx(ady);
		ant -> modProx(nuevo);
	}
}

template <class T>
void Grafo<T>::eliminarVertice(T e)
{
	NodoV<T> *aux, *prev;
	NodoAdy<T> *ant, *act, *sigi;

	aux = this -> g;
	if(this -> g -> obtInfo() == e)
	{
		this -> g = aux -> obtSig();
		this -> eliminarVertice(aux);
		aux = this -> g;

		while(aux != NULL)
		{
			ant = NULL;
			act = aux -> obtAdy();

			while(act != NULL && act -> obtInfo() != e)
			{
				ant = act;
				act = act -> obtProx();
			}

			if(ant == NULL)
			{
				aux -> modAdy(act -> obtProx());
				delete act;
			}
			else
			{
				if(act != NULL)
				{
					ant -> modProx(act -> obtProx());
					delete act;
				}
			}

			aux = aux -> obtSig();
		}
	}
	else
	{
	

		while(aux != NULL)
		{
			if(aux -> obtInfo() == e)
			{
				prev -> modSig(aux -> obtSig());
				this -> eliminarVertice(aux);
				aux = prev;
			}
			else
			{
				ant = NULL;
				act = aux -> obtAdy();

				while(act != NULL && act -> obtInfo() != e)
				{
					ant = act;
					act = act -> obtProx();
				}

				if(ant == NULL)
				{
					aux -> modAdy(act -> obtProx());
					delete act;
				}
				else
				{
					if(act != NULL)
					{
						ant -> modProx(act -> obtProx());
						delete act;
					}
					
				}
			}

			prev = aux;
			aux = aux -> obtSig();		
		}	
	}
}

/************* ESTE METODO ELIMINA UN VERTICE COMPLETO PERO SOLO EL VERTICE CON SUS ARCOS *////////
template <class T>
void Grafo<T>::eliminarVertice(NodoV<T> *p)
{
	NodoAdy<T> *ant, *act;

	ant = NULL;
	act = p -> obtAdy();
	while(act != NULL)
	{
		ant = act;
		act = act -> obtProx();
		delete ant;
	}

	delete p;
}
/************ SOLO USADO POR ELIMINARVERTICE() *****************/

template <class T>
void Grafo<T>::eliminarArco(T v, T w) //ESTA PENSADO PARA GRAFO DIRIGIDO, SI ES NO DIRIGIDO NECESITA OTRA IMPLEMENTACION
{
	NodoV<T> *aux;					//SE PUEDE SOLVENTAR MANDAN A ELIMINAR HACIA UN SENTIDO Y LUEGO VICEVERSA JEJEJJE
	NodoAdy<T> *ant, *act;

	aux = this -> g;

	while(aux != NULL && aux -> obtInfo() != v)
	{
		aux = aux -> obtSig();
	}

	ant = NULL;
	act = aux -> obtAdy();

	while(act != NULL && act -> obtInfo() != w)
	{
		ant = act;
		act = act -> obtProx();
	}

	if(ant == NULL)
	{
		aux -> modAdy(act -> obtProx());
		delete act;
	}
	else
	{
		ant -> modProx(act -> obtProx());
		delete act;
	}
}

template <class T>
void Grafo<T>::borrar()
{
	NodoV<T> *aux;

	
	while( this -> g != NULL)
	{
		aux = this -> g;
		this -> g = this -> g ->obtSig();
		this -> eliminarVertice(aux);
	}

}

template <class T>
void Grafo<T>::imprimir() 
{
	NodoV<T> *aux;
	NodoAdy<T> *ady;

	if(this -> g == NULL)
	{
		cout << "Grafo vacio" << endl;
	}
	else
	{


		aux = this -> g;

		while(aux != NULL)
		{
			cout << aux -> obtInfo() << " -> " << " ";
			ady = aux -> obtAdy();

			while(ady != NULL)
			{
				cout << ady -> obtInfo() << " ";
				ady = ady -> obtProx();
			}

			cout << endl;
			aux = aux -> obtSig();
		}
	}
}

template <class T>
void Grafo<T>::copiar(const Grafo<T> &A) //OK HASTA EL MOMENTO FUNCIONA , PRUEBALO MAS
{
	NodoV<T> *nuevoV, *antV, *sigV, *copia;
	NodoAdy<T> *nuevoAdy, *copiaAdy, *antAdy;

	copia = A.g;
	if(copia == NULL)
	{
		this -> g = NULL;
	}
	else
	{
		this -> g = new NodoV<T> (copia -> obtInfo());
		nuevoV = this -> g;
		antV = nuevoV;
		while(copia != NULL)
		{
			copiaAdy = copia -> obtAdy();
			if(copiaAdy != NULL)
			{
				nuevoAdy = new NodoAdy<T> (copiaAdy -> obtInfo());
				nuevoV -> modAdy(nuevoAdy);
				antAdy = nuevoAdy;
				copiaAdy = copiaAdy -> obtProx();
				while(copiaAdy != NULL)
				{
					nuevoAdy = new NodoAdy<T> (copiaAdy -> obtInfo());
					antAdy -> modProx(nuevoAdy);
					antAdy = antAdy -> obtProx();
					copiaAdy = copiaAdy -> obtProx();
				}
			}
			
			if(copia -> obtSig() != NULL)
			{
				nuevoV = new NodoV<T> (copia -> obtSig() -> obtInfo());
				antV -> modSig(nuevoV);
				antV = antV -> obtSig();
			}

			copia = copia -> obtSig();
		}
	}
}	

/*template <class T>
NodoV<T> * Grafo<T>::copiar(NodoV<T> *p)
{
	NodoV<T> *nuevoV, *antV;
	NodoAdy<T> *nuevoAdy, *antAdy;

	if(p == NULL)
	{
		return NULL;
	}
	else
	{
		nuevoV = new NodoV<T> (p -> obtInfo());
		while(p != NULL)
		{
			
		}
}
	}*/

#endif
