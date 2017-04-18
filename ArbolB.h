#ifndef ARBOLB_H
#define ARBOLB_H

//LIBRERIA PROPIEDAD DE DAVID APARICIO 

#include "Cola.h"
#include "Lista.h"
#include "NodoA.h"
#include <string>
#include <iostream>

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
		NodoA<T> * lecturaPrIn(Lista<T> &Pre, Lista<T> In, int posi, int posf);//Utilizado en lecturaPrIn, lee a partir de 2 listas
		void destruirD(NodoA<T> *p);
		void print(int nivel, NodoA<T> *p);//Utilizado en imprimir, IMprime el arbol bien bonito
		int alturaArbol(NodoA<T> *p);// calcula la altura del arbol
		NodoA<T> * lecturaPosIn(Lista<T> &Pos, Lista<T> In, int posi, int posf);//Lectura con listas Posorden, Inorden
		void recorridoPreorden(NodoA<T> *p, Lista<T> &Pre);//Recorre y guarda el Preorden en una lista 
		void recorridoPosorden(NodoA<T> *p, Lista<T> &Pos);// Recorre y guarda el Posorden en una lista
		void recorridoInorden(NodoA<T> *p, Lista<T> &Pos);//Recorre y guarda el Inorden
		void recorridoNiveles(NodoA<T> *p, Lista<T> &Niv);//Recorre y guarda por niveles 
		void recorridoLimitado(NodoA<T> *p, Lista<T> &Lim, int nivel); // Recorre y guarda dependiendo de los limites si existen
		void _recorridoPosorden(NodoA<T> *p, Lista<T> &Pos);// Recorre y guarda el Posorden invertido en una lista
		void piramide(NodoA<T> *p, bool &band, int &suma);//Devuelve un booleano diciendo si es piramido o no, piramide = la suma de los hijos es igual al padre
		void frontera(NodoA<T> *p, Lista<T> &L);//Devuelve todos los nodos Hoja del arbol en la lista L
		int talla(NodoA<T> *p); //Calcula el numero de nodos de la rama mas larga
		void zurdo(NodoA<T> *p, bool &band, int &suma); //Determina si el arbol es Zurdo, unas reglas locas ahi 
		void esBB(NodoA<T> *p, bool &band, int &min, int &max);//Determina si es Binario de busqueda , mas reglas locas ahi
		void gordura(NodoA<T> *p, int &anchura); //Determina el nivel con mas nodos, es decir, la gordura del arbol
		void esAVL(NodoA<T> *p, bool &band, int &min, int &max, int &peso); //Determina si el arbol es BB y esta balanceado
		NodoA<T> * espejo(NodoA<T> *p);//Espejo pls
		bool esCompleto(NodoA<T> *p);//Determina si el arbol es completo es decir que todos los nodos tienen o 0 o 2 hijos exactamente
		void esLleno(NodoA<T> *p, bool &band, int &lim);//Determina si es complto y tambien tiene todos los nodos al mismo nivel
		void _recorridoNiveles(NodoA<T> *p, Lista<T> &L); // Recorre y almacena por niveles de derecha a izquierda
		void esDegenerado(NodoA<T> *p, bool &band); //Determina si cada nodo del arbol solo tiene un hijo
		void menol(NodoA<T> *p, T &menor);//Determina el elemento mas pequeño del arbol y lo guarda en menor
		void mayol(NodoA<T> *p, T &mayor);//Determina el elemento mas grande del arbol
		bool esMenor(NodoA<T> *p, T menor);//Determina si todos los elementos del arbol son menores que "Menor"
		void moverse(NodoA<T> *p, NodoA<T> **a1, T e);//Si p encuentra en el arbol el elemento "e" guarda la direccion en el apuntador a1
		bool ocurre(NodoA<T> *a1, NodoA<T> *a2);//Determina si a1 y a2 son iguales en estructura y elementos
		bool esIsomorfo(NodoA<T> *a1, NodoA<T> *a2);//Determina si son iguales en estructura solamente
		NodoA<T> * sinFronteras(NodoA<T> *p); //Elimina la frontera del arbol es decir todos sus nodos Hoja del momento
		void esMovil(NodoA<T> *p, bool &band, int &dif); //Determina si la diferencia de los elementos difieren en 1 , es como piramide pero distinto
		NodoA<T> * lecturaSintaxisPos(Lista<T> &Pos, Lista<T> In, int posi, int posf);//Lectura especial para el arbol de sintaxis
		//NodoA<T> * lecturaSintaxisPos(Lista<T> &Pos, Lista<T> In, Lista<T> P);//Errores con los indices, lo dejare porque inverti mucho tiempo en el
		NodoA<T> * lecturaSintaxisPre(Lista<T> &Pre, Lista<T> In, int posi, int posf);
		float operar(float op1, float op2, string operador); // Opera op1 y op2 con operador que son cadenas, para el arbol de sintaxis
		void evaluar(NodoA<T> *p, float &resultado);//evalua un arbol de sintaxis, asumiendo que el arbol es completo 
		bool estamos(NodoA<T> *p, T e);// si esta entonces true sino no

		//Las lecturas de los arboles de sintaxis me costaron mucho :( las dejare comentadas porque les inverti mucho tiempo
		//sin embargo solo ocupan lineas de codigo, no estan siendo utiles realmente esas primeras versiones, las recordare :)




	//Metodos para el usuario
	public:
		/*Cons / Des /tructor*/
		ArbolB();
		ArbolB(const ArbolB<T> &A);
		~ArbolB();

		//Retorno de data
		bool esPiramide(); //Determina si es piramide o no
		bool esNulo(); // Detemrina si el arbol es nulo o no
		bool esHoja(); //Determina si la raiz es hoja
		bool esZurdo(); //Determina si el arbol es zurdo o no
		bool esBB(); //Determina si el arbol es Binario de Busqueda
		bool esAVL();//Determina si es Binario de Busqueda Balanceado
		bool esCompleto();//Es completo si todos los nodos no terminales tienen exactamente 2 hijos
		bool esLleno();//Es lleno si es completo y aparte todos los nodos estan al mismo nivel
		bool esDegenerado();//Determina si todos los nodos tienen exactamente un hijo
		bool esMenor(const ArbolB<T> &A); // Determina si todos los elementos de THIS son menores que los elementos del arbol A
		bool ocurre(const ArbolB<T> &A); // Determina si el arbol THIS ocurre en el arbol A, es decir, que tdos los elementos son iguales
		bool esIsomorfo(const ArbolB<T> &A);//Determina si la raiz y el arbol A son isomorfos, es decir, que tienen la misma estructura
		bool esSemejante(const ArbolB<T> &A);//Determinasi dos arboles tienen los mismos elementos
		bool esIgual(const ArbolB<T> &A);//Determina si los arboles son iguales
		bool operator==(const ArbolB<T> &A);//PLS
		bool esMovil();//Evalua si la diferencia de la suma de todos los elementos del arbol es de 1
		bool esta(T e);//Retorna verdadero si el elemento esta en el arbol
		int peso(); //Retorna el numero de nodos del arbol
		int altura();//el numero de arcos desde la raiz a la hoja mas lejana
		int talla();//el numero de nodos de la rama mas larga
		int gordura();//Retorna el numero de nodos de el nivel mas "gordo" jeje 
		int diametro();//Retorna el numero de arcos del camino mas largo entre todos los pares de nodos
		T obtRaiz();// Retorna el contenido de la raiz
		T mayor();//Retorna el elemento mas "Grande" del arbol
		T menor();//Retorna el elemento mas "Pequeño" del arbol
		float evaluar();
		ArbolB<T> hijoIzq();//Retorna el subarbol izquierdo es decir su Hijo izquierdo 
		ArbolB<T> hijoDer();//Retorna el subarbol derecho es decir su Hijo Derecho
		ArbolB<T> operator=(const ArbolB<T> &A); // Pls
		ArbolB<T> espejo();//Retorna un Arbol espejo del pasado por parametro
		ArbolB<T> sinFronteras();//Retorna el mismo arbol sin ninguna de sus hojas
		Lista<T> frontera(); // Retorna lista con todos los nodos hoja del arbol
		//Recorridos
		Lista<T> Preorden();
		Lista<T> Posorden();
		Lista<T> Inorden();
		Lista<T> Niveles();
		Lista<T> Niveles_limites(int limi, int limif);
		Lista<T> Posorden_invertido();
		Lista<T> Niveles_invertido();//Devuelve La lista de niveles invertidos completamente de derecha a izquierda
		Lista<T> Niveles_invertidoEV();// Devuelve los niveles invertidos VERSION EXAMEN es decir de derecha a izquierda pero de fin a principio
		//void's
		void insertarHi(const ArbolB<T> A); //NO DEBE TENER HIJO IZQ ANTES DE INSERTAR
		void insertarHd(const ArbolB<T> A);	//LO MISMO PARA ESTE
		void eliminarHi();
		void eliminarHd();
		void borrar();
		void lecturaPrIn(Lista<T> L1, Lista<T> L2);// LECTURA DE LISTAS PREORDEN , INORDEN, NO DEBEN TENER ELEMENTOS REPETIDOS
		void lecturaPosIn(Lista<T> L1, Lista<T> L2);// LECTURA DE LISTAS POSORDEN, INORDEN, NO DEBEN TENER ELEMENTOS REPETIDOS
		void lecturaSintaxisPre(Lista<T> L1, Lista<T> L2);//Lectura especial para el arbol de sintaxis
		void lecturaSintaxisPos(Lista<T> L1, Lista<T> L2);
		void imprimir();

		

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
	if(!Pre.esVacia())
	{
		this -> n = Pre.longitud();
		this -> raiz = lecturaPrIn(Pre,In,1,Pre.longitud());
	}
}

template <class T>
NodoA<T> * ArbolB<T>::lecturaPrIn(Lista<T> &Pre, Lista<T> In, int posi, int posf)
{
	T aux;
	NodoA<T> *nuevo;
	
	if(posi <= posf && !Pre.esVacia())
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

template <class T>
int ArbolB<T>::altura()
{
	return this -> alturaArbol(this -> raiz);
}

template <class T>
int ArbolB<T>::alturaArbol(NodoA<T> *p)
{
	int pi,pd;
	
	if(p != NULL)
	{
		pi = 1 + this -> alturaArbol(p -> obtHi());
		pd = 1 + this -> alturaArbol(p -> obtHd());

		if(pi > pd)
		{
			return pi;
		}
		else
		{
			return pd;
		}
	}
	else
	{
		return -1;
	}
}

template <class T>
void ArbolB<T>::lecturaPosIn(Lista<T> L1, Lista<T> L2)
{
	if(!L1.esVacia())
	{

		L1.invertir();
		this -> n = L1.longitud();
		this -> raiz = this -> lecturaPosIn(L1,L2,1,L1.longitud());
	}
}

template <class T>
NodoA<T> * ArbolB<T>::lecturaPosIn(Lista<T> &Pos, Lista<T> In, int posi, int posf)
{
	T aux;
	NodoA<T> *nuevo;

	if(posi <= posf && !Pos.esVacia() )
	{
		aux = Pos.consultar(1);
		Pos.eliminar(1);
		nuevo = new NodoA<T> (aux);

		nuevo -> modHd(lecturaPosIn(Pos, In, In.obtPos(aux) + 1, posf));
		nuevo -> modHi(lecturaPosIn(Pos, In, posi, In.obtPos(aux) - 1));
		return nuevo;
	}
	else
	{
		return NULL;
	}
}


//RECORRIDOS

template <class T>
Lista<T> ArbolB<T>::Preorden()
{
	Lista<T> L;
	if(!this -> esNulo())
	{
		this -> recorridoPreorden(this -> raiz, L);
	}
	L.invertir();
	return L;
}

template <class T>
void ArbolB<T>::recorridoPreorden(NodoA<T> *p, Lista<T> &Pre)
{
	if(p != NULL)
	{
		Pre.insertar(p -> obtInfo(), 1);
		this -> recorridoPreorden(p -> obtHi(), Pre);
		this -> recorridoPreorden(p -> obtHd(), Pre);
	}
}

template <class T>
Lista<T> ArbolB<T>::Posorden()
{
	Lista<T> L;
	
	if(!this -> esNulo())
	{
		this -> recorridoPosorden(this -> raiz, L);
	}
	
	L.invertir();
	
	return L;
}

template <class T>
void ArbolB<T>::recorridoPosorden(NodoA<T> *p, Lista<T> &Pos)
{
	if(p != NULL)
	{
		this -> recorridoPosorden(p -> obtHi(), Pos);
		this -> recorridoPosorden(p -> obtHd(), Pos);
		Pos.insertar(p -> obtInfo(), 1);
	}
}

template <class T>
Lista<T> ArbolB<T>::Inorden()
{
	Lista<T> L;
	
	if(!this -> esNulo())
	{
		this -> recorridoInorden(this -> raiz, L);
	}
	
	L.invertir();
	
	return L;
}

template <class T>
void ArbolB<T>::recorridoInorden(NodoA<T> *p, Lista<T> &In)
{
	if(p != NULL)
	{
		this -> recorridoInorden(p -> obtHi(), In);
		In.insertar(p -> obtInfo(), 1);
		this -> recorridoInorden(p -> obtHd(), In);
	}
}

template <class T>
Lista<T> ArbolB<T>::Niveles()
{
	Lista<T> L;
	
	if(!this -> esNulo())
	{
		this -> recorridoNiveles(this -> raiz, L);
	}
	
	L.invertir();

	return L;
}

template <class T>
void ArbolB<T>::recorridoNiveles(NodoA<T> *p, Lista<T> &Niv)
{
	Cola< NodoA<T> * > C;
	NodoA<T> *aux;

	C.Encolar(p);

	while(!C.esVacia())
	{
		aux = C.Obtfrente();
		C.Desencolar();

		if(aux -> obtHi() != NULL)
		{
			C.Encolar(aux -> obtHi());
		}

		if(aux -> obtHd() != NULL)
		{
			C.Encolar(aux -> obtHd());
		}

		Niv.insertar(aux -> obtInfo(), 1);
	}
}

template <class T>
Lista<T> ArbolB<T>::Niveles_limites(int posi, int posf)
{
	int alt, i;
	Lista<T> L;

	alt = this -> altura();

	if(posi <= alt && posf <= alt && !this -> esNulo())
	{
		if(posi > posf)
		{
			for(i = posf ; i <= posi; i++)
			{
				this -> recorridoLimitado(this -> raiz, L, i);
			}
		
		}
		else
		{
			for(i = posi ; i <= posf; i++)
			{
				this -> recorridoLimitado(this -> raiz, L, i);
			}
		}
	}

	L.invertir();

	return L;
}

template <class T>
void ArbolB<T>::recorridoLimitado(NodoA<T> *p, Lista<T> &Lim, int nivel) //LA VERSION ORIGINAL TENIA UN PROBLEMA CON LA ESTRUCTURA DEL ARBOL
{																					//ESTA ES MAS IEFICIENTE PERO FUNCIONA SEGURO
	if(p != NULL)
	{
		if(nivel == 0)
		{
			Lim.insertar( p -> obtInfo(), 1);
		}
		else
		{
			this -> recorridoLimitado(p -> obtHi(), Lim, nivel - 1);
			this -> recorridoLimitado(p -> obtHd(), Lim, nivel - 1);
		}
	}
}

template <class T>
Lista<T> ArbolB<T>::Posorden_invertido()
{
	Lista<T> L;

	if(!this -> esNulo())
	{
		this -> _recorridoPosorden(this -> raiz, L);
	}

	L.invertir();

	return L;
}

template < class T>
void ArbolB<T>::_recorridoPosorden(NodoA<T> *p, Lista<T> &Pos)
{
	if(p != NULL)
	{
		this -> _recorridoPosorden(p -> obtHd(), Pos);
		this -> _recorridoPosorden(p -> obtHi(), Pos);
		Pos.insertar(p -> obtInfo(), 1);
	}
}

template <class T>
bool ArbolB<T>::esPiramide()
{
	bool band;
	int suma;

	this -> piramide(this -> raiz, band, suma);

	return band;
}

template <class T>
void ArbolB<T>::piramide(NodoA<T> *p, bool &band, int &suma)
{
	int pi,pd;

	if(p == NULL)
	{
		band = true;
		suma = 0;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			band = true;
			suma = p -> obtInfo();
		}
		else
		{
			this -> piramide(p -> obtHi(), band, pi);
			if(band)
			{
				this -> piramide(p -> obtHd(), band, pd);
			}

			band = (pi + pd) == p -> obtInfo();
			suma = pi + pd;
		}
	}
}

template <class T>
Lista<T> ArbolB<T>::frontera()
{
	Lista<T> L;
	
	if(!this -> esNulo())
	{
		this -> frontera(this -> raiz, L);
	}

	L.invertir();

	return L;
}

template <class T>
void ArbolB<T>::frontera(NodoA<T> *p, Lista<T> &L)
{
	if(p != NULL)
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			L.insertar(p -> obtInfo(),1);
		}
		else
		{
			frontera(p -> obtHi(), L);
			frontera(p -> obtHd(), L);
		}
	}
}

template <class T>
int ArbolB<T>::talla()
{
	return this -> talla(this -> raiz);
}

template <class T>
int ArbolB<T>::talla(NodoA<T> *p)
{
	int pi, pd;
	
	if(p != NULL)
	{
		pi = this -> talla(p -> obtHi()) + 1;
		pd = this -> talla(p -> obtHd()) + 1;

		if(pi > pd)
		{
			return pi;
		}
		else
		{
			return pd;
		}
	}
	else
	{
		return 0;
	}
}

template <class T>
bool ArbolB<T>::esZurdo()
{
	bool band;
	int suma;

	this -> zurdo(this -> raiz, band, suma);

	return band;
}

template <class T>
void ArbolB<T>::zurdo(NodoA<T> *p, bool &band, int &suma)
{
	bool bi, bd;
	int si, sd;

	if(p == NULL)
	{
		band = true;
		suma = 0;
	}
	else
	{
		if( p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			band = true;
			suma = 1;
		}
		else
		{
			this -> zurdo(p -> obtHi(), bi, si);
			if(bi)
			{
				this -> zurdo(p -> obtHd(), bd, sd);
			}

			band = bi && bd && si > sd;
			suma = si + sd + 1;
		}
	}
}

template <class T>
bool ArbolB<T>::esBB()
{
	bool band;
	int min, max;

	this -> esBB(this -> raiz, band, min, max);


	return band;
}

template <class T>
void ArbolB<T>::esBB(NodoA<T> *p, bool &band, int &min, int &max)
{
	int mini, mind, maxi, maxd;
	bool bi, bd;

	if(p == NULL)
	{
		band = true;
		min = 9999;
		max = -9999;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			band = true;
			min = p -> obtInfo();
			max = p -> obtInfo();
		}
		else
		{
			this -> esBB(p -> obtHi(), bi, mini, maxi);
			if(bi)
			{
				this -> esBB(p -> obtHd(), bd, mind, maxd);
			}

			band = bi && bd && p -> obtInfo() > maxi && p -> obtInfo() < mind;
			min = mini;
			max = maxd;
		}
	}
}

template <class T>
int ArbolB<T>::gordura()
{
	int anchura;

	this -> gordura(this -> raiz, anchura);

	return anchura;
}

template <class T>
void ArbolB<T>::gordura(NodoA<T> *p, int &anchura)
{
	Cola< NodoA<T> * > C;
	int i, pot, acum, alt;

	C.Encolar(p);
	pot = 1;
	acum = 0;
	anchura = 1;
	alt = this -> altura();
	while(alt != 0)
	{
		for(i = 0 ; i < pot ; i++)
		{
			p = C.Obtfrente();

			if(p -> obtHi() != NULL)
			{
				C.Encolar(p -> obtHi());
				acum++;
			}

			if(p -> obtHd() != NULL)
			{
				C.Encolar(p -> obtHd());
				acum++;
			}
			
			C.Desencolar();
			
		}

		if(acum > anchura)
		{
			anchura = acum;
		}

		acum = 0;
		pot = pot * 2;
		alt--;

	}
}

template <class T>
bool ArbolB<T>::esAVL()
{
	bool band;
	int min, max, peso;

	this -> esAVL(this -> raiz, band, min, max, peso);

	return band;
}

template <class T>
void ArbolB<T>::esAVL(NodoA<T> *p, bool &band, int &min, int &max, int &peso)
{
	bool bi,bd;
	int mini, mind, maxi, maxd, pi, pd;

	if(p == NULL)
	{
		band = true;
		min = 9999;
		max = -9999;
		peso = 0;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			band = true;
			min = p -> obtInfo();
			max = p -> obtInfo();
			peso = 1;
		}
		else
		{
			this -> esAVL(p -> obtHi(), bi, mini, maxi, pi);
			if(bi)
			{
				this -> esAVL(p -> obtHd(), bd, mind, maxd, pd);
			}
	
			band = bi && bd && p -> obtInfo() > maxi && p -> obtInfo() < mind && abs(pi - pd) <= 1;
			min = mini;
			max = maxd;
			peso = pi + pd;
		}
	}
}

template <class T>
ArbolB<T> ArbolB<T>::espejo()
{
	ArbolB<T> nuevo;

	nuevo.raiz = this -> espejo(this -> raiz);
	nuevo.n = this -> n;

	return nuevo;
}

template <class T>
NodoA<T> * ArbolB<T>::espejo(NodoA<T> *p)
{
	NodoA<T> *nuevo;

	if(p != NULL)
	{
		nuevo = new NodoA<T> (p -> obtInfo(), espejo(p -> obtHd()), espejo(p -> obtHi()));
		return nuevo;
	}
	else
	{
		return NULL;
	}
}

template <class T>
bool ArbolB<T>::esCompleto()
{
	return this -> esCompleto(this -> raiz);
}

template <class T>
bool ArbolB<T>::esCompleto(NodoA<T> *p)
{
	if(p == NULL)
	{
		return true;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			return true;
		}
		else
		{
			if(p -> obtHi() != NULL && p -> obtHd() != NULL)
			{
				return this -> esCompleto(p -> obtHi()) && this -> esCompleto(p -> obtHd());
			}
			else
			{
				return false;
			}
		}
	}
}

template <class T>
bool ArbolB<T>::esLleno()
{
	bool band;
	int lim;

	this -> esLleno(this -> raiz, band, lim);

	return band;
}

template <class T>
void ArbolB<T>::esLleno(NodoA<T> *p, bool &band, int &lim)
{
	bool bi, bd;
	int si, sd;

	if(p == NULL)
	{
		band = false;
		lim = 0;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			band = true;
			lim = 1;
		}
		else
		{
			this -> esLleno(p -> obtHi(), bi, si);
			if(bi)
			{
				this -> esLleno(p -> obtHd(), bd, sd);
			}

			band = bi && bd && si == sd;
			lim = si + 1;
		}
	}
}

template <class T>
Lista<T> ArbolB<T>::Niveles_invertido()
{
	Lista<T> L;

	if(!this -> esNulo())
	{
		this -> recorridoNiveles(this -> raiz, L);
	}

	return L;
}

template <class T>
Lista<T> ArbolB<T>::Niveles_invertidoEV()
{
	Lista<T> L;

	if(!this -> esNulo())
	{
		this -> _recorridoNiveles(this -> raiz, L);
	}

	return L;
}

template <class T>
void ArbolB<T>::_recorridoNiveles(NodoA<T> *p, Lista<T> &L)
{
	Cola< NodoA<T> * > C;
	NodoA<T> *aux;

	C.Encolar(p);

	while(!C.esVacia())
	{
		aux = C.Obtfrente();
		C.Desencolar();

		if(aux -> obtHd() != NULL)
		{
			C.Encolar(aux -> obtHd());
		}

		if(aux -> obtHi() != NULL)
		{
			C.Encolar(aux -> obtHi());
		}

		L.insertar(aux -> obtInfo(), 1);
	}
}

template <class T>
bool ArbolB<T>::esDegenerado()
{
	bool band;

	this -> esDegenerado(this -> raiz, band);

	return band;
}

template <class T>
void ArbolB<T>::esDegenerado(NodoA<T> *p, bool &band)
{
	bool bi, bd;
	if(p == NULL)
	{
		band = true;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			band = true;
		}
		else
		{
			if(p -> obtHi() != NULL && p -> obtHd() != NULL)
			{
				band = false;
			}
			else
			{
				this -> esDegenerado(p -> obtHi(), bi);
				if(bi)
				{
					this -> esDegenerado(p -> obtHd(), bd);
				}

				band = bi && bd;
			}
		}
	}
}

template <class T>
bool ArbolB<T>::esMenor(const ArbolB<T> &A)
{
	bool band;
	T menor;

	menor = A.raiz -> obtInfo(); 
	this -> menol(A.raiz, menor);
	return this -> esMenor(this -> raiz, menor);
}

template <class T>
void ArbolB<T>::menol(NodoA<T> *p, T &menor)
{
	if(p != NULL)
	{
		if(p -> obtInfo() < menor)
		{
			menor = p -> obtInfo();
		}

		this -> menol(p -> obtHi(), menor);
		this -> menol(p -> obtHd(), menor);

	}
}

template <class T>
void ArbolB<T>::mayol(NodoA<T> *p, T &mayor)
{
	if(p != NULL)
	{
		if(p -> obtinfo() > mayor)
		{
			mayor = p -> obtInfo();
		}

		this -> menol(p -> obtHi(), mayor);
		this -> menol(p -> obtHd(), mayor);
		
	}
}

template <class T>
bool ArbolB<T>::esMenor(NodoA<T> *p, T menor)
{
	if(p != NULL)
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			if(p -> obtInfo() < menor)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return esMenor(p -> obtHi(), menor) && esMenor(p -> obtHd(), menor) && p -> obtInfo() < menor;
		}
	}
	else
	{
		return true;
	}
}

template <class T>
bool ArbolB<T>::ocurre(const ArbolB<T> &A)
{
	NodoA<T> *a1;

	a1 = NULL;
	this -> moverse(A.raiz, &a1, this -> obtRaiz());

	if( a1 == NULL)
	{
		return false;
	}
	else
	{
		return this -> ocurre(this -> raiz, a1);
	}
}

template <class T>
void ArbolB<T>::moverse(NodoA<T> *p, NodoA<T> **a1, T e)
{
	if(p != NULL)
	{
		if(p -> obtInfo() == e)
		{
			*a1 = p;
		}
		else
		{
			this -> moverse(p -> obtHi(), a1, e);
			this -> moverse(p -> obtHd(), a1, e);
		}
	}
}

template <class T>
bool ArbolB<T>::ocurre(NodoA<T> *a1, NodoA<T> *a2)
{
	if(a1 == NULL || a2 == NULL)
	{
		if(a1 == NULL && a2 == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return this -> ocurre(a1 -> obtHi(), a2 -> obtHi()) && this -> ocurre(a1 -> obtHd(), a2 -> obtHd()) && a1 -> obtInfo() == a2 -> obtInfo();	
	}
}

template <class T>
int ArbolB<T>::diametro()
{
	int si, sd;

	si = this -> alturaArbol(this -> raiz -> obtHi());
	sd = this -> alturaArbol(this -> raiz -> obtHd());

	return si + sd;
}

template <class T>
T ArbolB<T>::mayor()
{
	T e;

	e = -999999;

	this -> mayol(this -> raiz, e);

	return e;

}

template <class T>
T ArbolB<T>::menor()
{
	T e;

	e = 999999;

	this -> menol(this -> raiz, e);

	return e;

}

template <class T>
bool ArbolB<T>::esIsomorfo(const ArbolB<T> &A)
{
	if(this -> raiz == NULL && A.raiz == NULL)
	{
		return true;
	}
	else
	{
		return this -> esIsomorfo(this -> raiz, A.raiz);
	}

}

template <class T>
bool ArbolB<T>::esIsomorfo(NodoA<T> *a1, NodoA<T> *a2)
{
	if(a1 == NULL || a2 == NULL)
	{
		if(a1 == NULL && a2 == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return this -> esIsomorfo(a1 -> obtHi(), a2 -> obtHi()) && this -> esIsomorfo(a1 -> obtHd(), a2 -> obtHd());
	}
}

template <class T>
bool ArbolB<T>::esSemejante(const ArbolB<T> &A)
{
	Lista<T> L1, L2;
	bool flag;
	T e;
	
	if(this -> raiz == NULL && A.raiz == NULL)
	{
		return true;
	}
	else
	{
		this -> _recorridoPosorden(this -> raiz, L1);
		this -> _recorridoPosorden(A.raiz, L2);

		
		if(L1.longitud() == L2.longitud()) //INTERPRETACION , ES DECIR PUDIESE "OCURRIR", PREGUNTAR
		{
			flag = true;

			while(flag && !L2.esVacia() )
			{
				e = L2.consultar(1);
				
				if(!L1.esta(e))
				{
					flag = false;
				}

				L2.eliminar(1);
			}

			return !flag;
		}
		else
		{
			return false;
		}
	}
}

template <class T>
bool ArbolB<T>::esIgual(const ArbolB<T> &A)
{
	return this -> ocurre(this -> raiz, A.raiz);
}

template <class T>
bool ArbolB<T>::operator==(const ArbolB<T> &A)
{
	return this -> esIgual(A);
}

template <class T>
ArbolB<T> ArbolB<T>::sinFronteras()
{
	ArbolB<T> Copia;


	
		Copia.raiz = this -> sinFronteras(this -> raiz);
		Copia.n = this -> n;
		return Copia;
	
}

/*template <class T>
void ArbolB<T>::sinFronteras(NodoA<T> *p)
{
	if(p != NULL)
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			delete p;
			p = NULL;
		}
		else
		{
			this -> sinFronteras(p -> obtHi());
			this -> sinFronteras(p -> obtHd());
		}
	}
}*/

template <class T>
NodoA<T> * ArbolB<T>::sinFronteras(NodoA<T> *p)
{	
	NodoA<T> *nuevo;

	if(p != NULL)
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			return NULL;
		}
		else
		{
			nuevo = new NodoA<T> (p -> obtInfo(), sinFronteras(p -> obtHi()), sinFronteras(p -> obtHd()));
			return nuevo;
		}
	}
	else
	{
		return NULL;
	}
}

template <class T>
bool ArbolB<T>::esMovil()
{
	bool band;
	int dif;

	this -> esMovil(this -> raiz, band, dif);

	return band;
}

template <class T>
void ArbolB<T>::esMovil(NodoA<T> *p, bool &band, int &dif)
{
	int si, sd;
	bool bi, bd;

	if(p == NULL)
	{
		band = true;
		dif = 0;
	}
	else
	{
		if(p -> obtHi() == NULL && p -> obtHd() == NULL)
		{
			band = true;
			dif = p -> obtInfo();
		}
		else
		{
			this -> esMovil(p -> obtHi(), bi, si);

			if(bi)
			{
				this -> esMovil(p -> obtHd(), bd, sd);
			}

			band = bi && bd && abs(si - sd) == 1;
			dif = si + sd + p -> obtInfo();
		}
	}
}

template <class T>
void ArbolB<T>::lecturaSintaxisPre(Lista<T> L1, Lista<T> L2)
{
	Lista<T> Pizq, Pder, Iizq, Ider;
	T e;
	if(!L1.esVacia())
	{

		
		e = L1.consultar(1);
		
		this -> n = L1.longitud();
		this -> raiz = new NodoA<T> (e);
		
		Iizq = L2.sublista(1, L2.obtPos(e) - 1);
		Ider = L2.sublista(L2.obtPos(e) + 1, L2.longitud());

		Pizq = L1.sublista(2, Iizq.longitud() + 1);
		Pder = L1.sublista(Pizq.longitud() + 2, L1.longitud());

		this -> raiz -> modHi(lecturaSintaxisPre(Pizq, Iizq, 1, Pizq.longitud()));
		this -> raiz -> modHd(lecturaSintaxisPre(Pder, Ider, 1, Pder.longitud()));

	}
}

template <class T>
NodoA<T> * ArbolB<T>::lecturaSintaxisPre(Lista<T> &Pre, Lista<T> In, int posi, int posf)
{
	T aux;
	NodoA<T> *nuevo;
	int save;
	
	if(posi <= posf && !Pre.esVacia())
	{
		aux = Pre.consultar(1);
		Pre.eliminar(1);
		save = In.obtPos(aux);
		nuevo = new NodoA<T> (aux, lecturaSintaxisPre(Pre,In,posi,save - 1), lecturaSintaxisPre(Pre,In, save + 1, posf));
		return nuevo;
	}
	else
	{
		return NULL;
	}	
}


template <class T>
void ArbolB<T>::lecturaSintaxisPos(Lista<T> L1, Lista<T> L2)
{
	Lista<T> Pizq, Pder, Iizq, Ider;
	T e;
	if(!L1.esVacia())
	{

		L1.invertir();
		e = L1.consultar(1);
		
		this -> n = L1.longitud();
		this -> raiz = new NodoA<T> (e);
		
		Iizq = L2.sublista(1, L2.obtPos(e) - 1);
		Ider = L2.sublista(L2.obtPos(e) + 1, L2.longitud());

		Pizq = L1.sublista(2, Ider.longitud() + 1);
		Pder = L1.sublista(Pizq.longitud() + 2, L1.longitud());

		

		this -> raiz -> modHd(lecturaSintaxisPos(Pizq, Ider, 1, Pizq.longitud()));
		this -> raiz -> modHi(lecturaSintaxisPos(Pder, Iizq, 1, Pder.longitud()));

	}
}

template <class T>
NodoA<T> * ArbolB<T>::lecturaSintaxisPos(Lista<T> &Pos, Lista<T> In, int posi, int posf)
{
	T aux;
	NodoA<T> *nuevo;
	int save;

	if(posi <= posf && !Pos.esVacia() )
	{
		aux = Pos.consultar(1);
		Pos.eliminar(1);
		nuevo = new NodoA<T> (aux);
		save = In.obtPos(aux);
		

		nuevo -> modHd(lecturaSintaxisPos(Pos, In, save + 1, posf));
		nuevo -> modHi(lecturaSintaxisPos(Pos, In, posi, save - 1));
		return nuevo;
	}
	else
	{
		return NULL;
	}
}

/*template <class T>
void ArbolB<T>::lecturaSintaxisPos(Lista<T> L1, Lista<T> L2)
{
	Lista<T> Pizq, Pder, Iizq, Ider;
	T rais;

	rais = L1.consultar(L1.longitud());
	this -> raiz -> modInfo(rais);
	Iizq = L2.sublista(1, L2.obtPos(rais) - 1);
	Ider = L2.sublista(L2.obtPos(rais) + 1, L2.longitud());

	this -> raiz = this -> lecturaSintaxisPos(L1, L2, Pizq);
	
}

template <class T>
NodoA<T> * ArbolB<T>::lecturaSintaxisPos(Lista<T> &Pos, Lista<T> In, Lista<T> P)
{
	NodoA<T> *nuevo;
	T aux;
	int lim;
	Lista<T> izq, der;

	if(!In.esVacia())
	{
		aux = Pos.consultar(1);
		Pos.eliminar(1);

		lim = In.obtPos(aux);
		izq = In.sublista(1, lim - 1);
		der = In.sublista(lim + 1, In.longitud());

		nuevo = new NodoA<T> (aux);
		nuevo -> modHd(lecturaSintaxisPos(Pos, der, izq));
		nuevo -> modHi(lecturaSintaxisPos(Pos, izq, der));
		return nuevo;


	}
	else
	{
		return NULL;
	}
}*/


template <class T>
float ArbolB<T>::evaluar()
{
	float resultado;

	if(this -> esNulo())
	{
		return 0;
	}
	else
	{
		this -> evaluar(this -> raiz, resultado);

		return resultado;
	}
}

template <class T>
void ArbolB<T>::evaluar(NodoA<T> *p, float &resultado) //ASUMIENDO QUE EL ARBOL ES COMPLETO
{
	float si, sd;

	if(p -> obtHi() == NULL && p -> obtHd() == NULL)
	{
		resultado = atof(p -> obtInfo().c_str());//INCREIBLE ESTA FUNCION CAMBIA DE STRING A FLOAT 
	}
	else
	{
		this -> evaluar(p -> obtHi(), si);
		this -> evaluar(p -> obtHd(), sd);

		resultado = operar(si, sd, p -> obtInfo());
	}
}

template <class T>
float ArbolB<T>::operar(float op1, float op2, string operador)
{
	float p1, p2, aux;

	/*p1 = atof(op1.c_str());
	p2 = atof(op2.c_str());*/

	if(operador == "+")
	{
		aux = op1 + op2;
	}

	if(operador == "-")
	{
		aux = op1 - op2;
	}

	if(operador == "/")
	{
		aux = op1 / op2;
	}

	if(operador == "*")
	{
		aux = op1 * op2;
	}

	return aux;
}

template <class T>
bool ArbolB<T>::esta(T e)
{
	bool band;

	if(this -> esNulo())
	{
		
		return false;
	}
	else
	{
		return this -> estamos(this -> raiz, e);
	}
	
	
}

template <class T>
bool ArbolB<T>::estamos(NodoA<T> *p, T e)
{
	if(p != NULL)
	{
		if(p -> obtInfo() == e)
		{
			return true;
		}
		else
		{

			return this -> estamos(p -> obtHi(), e) || this -> estamos(p -> obtHd(), e);
		}
	}
	else
	{
		return false;
	}
}

#endif

