#ifndef ARBOLB_H
#define ARBOLB_H

#include "Cola.h"
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
		NodoA<T> * lecturaPrIn(Lista<T> &Pre, Lista<T> In, int posi, int posf);//Utilizado en lecturaPrIn, lee a partir de 2 listas
		void destruirD(NodoA<T> *p);
		void print(int nivel, NodoA<T> *p);//Utilizado en imprimir, IMprime el arbol bien bonito
		int alturaArbol(NodoA<T> *p);// calcula la altura del arbol
		NodoA<T> * lecturaPosIn(Lista<T> &Pos, Lista<T> In, int posi, int posf);//Lectura con listas Posorden, Inorden
		void recorridoPreorden(NodoA<T> *p, Lista<T> &Pre);//Recorre y guarda el Preorden en una lista 
		void recorridoPosorden(NodoA<T> *p, Lista<T> &Pos);// Recorre y guarda el Posorden en una lista
		void recorridoInorden(NodoA<T> *p, Lista<T> &Pos);//Recorre y guarda el Inorden
		void recorridoNiveles(NodoA<T> *p, Lista<T> &Niv);//Recorre y guarda por niveles 
		void recorridoLimitado(NodoA<T> *p, Lista<T> &Lim, int inicio, int fin); // Recorre y guarda dependiendo de los limites si existen
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
		int peso(); //Retorna el numero de nodos del arbol
		int altura();//el numero de arcos desde la raiz a la hoja mas lejana
		int talla();//el numero de nodos de la rama mas larga
		int gordura();//Retorna el numero de nodos de el nivel mas "gordo" jeje 
		T obtRaiz();// Retorna el contenido de la raiz
		ArbolB<T> hijoIzq();//Retorna el subarbol izquierdo es decir su Hijo izquierdo 
		ArbolB<T> hijoDer();//Retorna el subarbol derecho es decir su Hijo Derecho
		ArbolB<T> operator=(const ArbolB<T> &A); // Pls
		ArbolB<T> espejo();//Retorna un Arbol espejo del pasado por parametro
		Lista<T> frontera(); // Retorna lista con todos los nodos hoja del arbol 
		
		
		

		//Recorridos
		Lista<T> Preorden();
		Lista<T> Posorden();
		Lista<T> Inorden();
		Lista<T> Niveles();
		Lista<T> Niveles_limites(int limi, int limif);
		Lista<T> Posorden_invertido();


		//void's
		void insertarHi(const ArbolB<T> A); //NO DEBE TENER HIJO IZQ ANTES DE INSERTAR
		void insertarHd(const ArbolB<T> A);	//LO MISMO PARA ESTE
		void eliminarHi();
		void eliminarHd();
		void borrar();
		void lecturaPrIn(Lista<T> L1, Lista<T> L2);// LECTURA DE LISTAS PREORDEN , INORDEN, NO DEBEN TENER ELEMENTOS REPETIDOS
		void lecturaPosIn(Lista<T> L1, Lista<T> L2);// LECTURA DE LISTAS POSORDEN, INORDEN, NO DEBEN TENER ELEMENTOS REPETIDOS
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
	this -> n = Pre.longitud();
	this -> raiz = lecturaPrIn(Pre,In,1,Pre.longitud());
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
	L1.invertir();
	this -> n = L1.longitud();
	this -> raiz = this -> lecturaPosIn(L1,L2,1,L1.longitud());
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
	int alt;
	Lista<T> L;

	alt = this -> altura();

	if(posi <= alt && posf <= alt && !this -> esNulo())
	{
		if(posi > posf)
		{
			this -> recorridoLimitado(this -> raiz, L, posf, posi);
		}
		else
		{
			this -> recorridoLimitado(this -> raiz, L, posi, posf);
		}
	}

	L.invertir();

	return L;
}

template <class T>
void ArbolB<T>::recorridoLimitado(NodoA<T> *p, Lista<T> &Lim, int inicio, int fin)
{
	Cola< NodoA<T> * > C;
	int i, aux, j;

	i = 0;
	aux = 1;

	C.Encolar(p);
	while(i < inicio)
	{
		for(j = 0 ; j < aux ; j++)
		{
			p = C.Obtfrente();

			if(p -> obtHi() != NULL)
			{
				C.Encolar(p -> obtHi());
			}

			if(p -> obtHd() != NULL)
			{
				C.Encolar(p -> obtHd());
			}

			C.Desencolar();
		}

		aux = aux * 2;
		i++;
	}

	i = fin - inicio ;
	
	while(i != 0)
	{
		for(j = 0 ; j < aux ; j++)
		{
			p = C.Obtfrente();
			
			Lim.insertar(p -> obtInfo(), 1);

			if(p -> obtHi() != NULL)
			{
				C.Encolar(p -> obtHi());
			}

			if(p -> obtHd() != NULL)
			{
				C.Encolar(p -> obtHd());
			}

			C.Desencolar();
		}

		aux = aux * 2;
		i--;
	}

	while(!C.esVacia())
	{
		p = C.Obtfrente();
		Lim.insertar(p -> obtInfo(), 1);
		C.Desencolar();
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

#endif

