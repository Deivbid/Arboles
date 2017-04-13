#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

template <class T>
class Lista
{
	protected:

		Nodo<T> *primero;
		int n;
		void insertarOrdenado(Nodo<T> **L1, Nodo<T> *L2);

	public:

		//Los Tores
		Lista();
		Lista(const Lista<T> &L);
		~Lista();



		//Los gets
		bool esVacia() const;
		int longitud() const;
		bool esta(T e) const;
		int csublista(const Lista<T> x) const;
		T consultar(int pos) const ;
		bool esSublista(const Lista<T> L) const;
		int obtPos(T e); //Debe estar el elemento sino no 


		//Los mods
		void insertar(T e,int pos);
		void insertarSort(T e);
		void eliminar(int pos);
		void modificar(T e,int pos);
		void imprimir();
		void invertir();
		void copiar(const Lista<T> &L);
		void borrar();
		void compactar();
		void ordenar(bool tipo);
		void mergesort(const Lista<T> L1, const Lista<T> L2);
		Lista<T> sublista(int posi, int posf);
		Lista<T> &operator =(const Lista<T> &L);
		void Aleatoria(int longi);
		void invertirSublista(T a,T b);
		void codificar(Lista<T> L);


};
#include "Lista.cpp"

#endif
