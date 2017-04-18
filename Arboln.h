#ifndef ARBOLN_H
#define ARBOLN_H

#include "Lista.h"
#include "NodoA.h"


template <class T>
class Arboln
{
  protected:
    NodoA<T> *raiz;
    int _altura(NodoA<T> *);
    NodoA<T> * copiar(NodoA<T> *);//COPIA TODOS LOS NODOS PARTIENDO DE LA RAIZ QUE SE ENVIE
    void destruir(NodoA<T> *&);//ENVOLTURA DEL TESTRUCTOR
    void destruirr(NodoA<T> *);//DESTRUYE TODO 
    void grado(NodoA<T> *, int &);//DETERMINA EL GRADO DEL ARBOL
    void print(NodoA<T> *p);//IMPRIME EL ARBOL
    void recorrer(NodoA<T> *p, NodoA<T> **save, T e);//RECORRE HASTA DONDE ESTE EL "e" Y LO GUARDA EN SAVE


//CONSTRUCTORES
  public:
    Arboln();
    Arboln(T e);
    Arboln(T e, Lista<Arboln> L);
    Arboln(const Arboln<T> &A);
    ~Arboln();

//GETS
    bool esNulo();        // TRUE SI ES NULO, FALSE SINO
    T obtRaiz();             //RETORNA ELEMENTO RAIZ
    Lista<Arboln> hijos();// RETORNA LISTA DE HIJOS ADYACENTES
    int grado(T e);       //RETORNA GRADO DEL NODO "e", ESTE DEBE EXISTIR EN EL ARBOL
    int grado();          //RETORNA GRADO DEL ARBOL, ES DECIR EL NUMERO DE HIJOS DEL NODO QUE TENGAS MAS HIJO<
    int altura();         //RETORNA LA ALTURA DEL ARBOL, ES NUMERO DE ARCOS DESDE LA RAIZ A LA HOJA MAS LEHANA

    void copiar(const Arboln<T> &A);  // COPIA UN arbol
    void insertarSubarbol(const Arboln<T> &Arbol); //INSERTA UN SUB ARBOL
    void eliminarSubarbol(int pos);//ELIMINA UN SUB ARBOL ADYACENTE A LA RAIZ POR SU POSICION
    void lecturaPrin(Lista<T> L1, Lista<T> L2);//Estoy a punto de fumarmela, 
    void imprimir();//IMPRIME EL ARBOL EN PREORDEN
    void borrar();

};

template <class T>
Arboln<T>::Arboln()
{
  this -> raiz = NULL;
}

template <class T>
Arboln<T>::Arboln(T e)
{
  this -> raiz = new NodoA<T> (e);
}

template <class T>
Arboln<T>::Arboln(T e, Lista<Arboln> L)
{
  NodoA<T> *aux;

  aux = new NodoA<T> (e);
  
  this -> raiz = aux;
  
  if(!L.esVacia())
  {
    aux -> modHi(L.consultar(1).raiz);
   
    L.eliminar(1);
    aux = aux -> obtHi();
   
    while(!L.esVacia())
    {
      aux -> modHd(L.consultar(1).raiz);
      L.eliminar();
      aux = aux -> obtHd();
    }

  }
}

template <class T>
Arboln<T>::Arboln(const Arboln<T> &A)
{
  this -> raiz = copiar(A.raiz);
}

template <class T>
Arboln<T>::~Arboln()
{
  this -> destruir(this -> raiz);
}

template <class T>
bool Arboln<T>::esNulo()
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
T Arboln<T>::obtRaiz()
{
  return this -> raiz -> obtInfo();
}

template <class T>
Lista< Arboln<T> > Arboln<T>::hijos()
{ 
  Lista<Arboln> L;
  Arboln<T> aux;
  NodoA<T> *hijo;

  hijo = this -> raiz -> obtHi();

  while(hijo != NULL)
  {
    aux.raiz = hijo;
    L.insertar(aux, 1);

    hijo = hijo -> obtHd();
  }

  L.invertir();

  return L;

}

template <class T>
int Arboln<T>::altura()
{
  int mayor;
  mayor = -9999;

  return  this -> _altura(this -> raiz);
}

template <class T>
int Arboln<T>::_altura(NodoA<T> *p)//PRUEBA BIEN ESTA SHIT
{
  int aux,mayor;
  NodoA<T> *hi;
  mayor = -9999;
  if(p == NULL)
  {
    return -1;
  }
  else
  {
    if(p -> obtHi() == NULL)
    {
      return 0;
    }
    else
    {
      p = p -> obtHi();
      while(p != NULL)
      {
        aux = this -> _altura(p) + 1;
        
        
        if(aux > mayor)
        {
          mayor = aux;
        }

        p = p -> obtHd();
      }

      return mayor;
    }
  }
}

template <class T>
int Arboln<T>::grado(T e)
{
  int acum;
  NodoA<T> *elemento;

  elemento = NULL;
  this -> recorrer(this -> raiz, &elemento, e);

  
  acum = 0;
  if(elemento == NULL)
  {
    cout << e << " No esta en el arbol " << endl;
    
  }
  else
  {
    elemento = elemento -> obtHi();
    
    while(elemento != NULL)
    {
      acum++;
      elemento = elemento -> obtHd();
    }
  }

  return acum;
}

template <class T>
void Arboln<T>::recorrer(NodoA<T> *p, NodoA<T> **save, T e)
{
    while(p != NULL)
    {
      if(p -> obtInfo() == e)
      {
        *save = p;
      }
     
      this -> recorrer(p -> obtHi(), save, e);
      p = p -> obtHd();
    }
}


/*template <class T>
void Arboln<T>::lecturaPrin(Lista<T> L1, Lista<T> L2)
{
  Lista<T> Pizq, Pder, Iizq, Ider;
  T aux;
  int save;

  aux = L1.consultar(1);
  save = L2.obtPos(aux);

  this -> raiz = new NodoA<T> (aux);

  Iizq = L2.sublista(1, save - 1);
  Ider = L2.sublista(save + 1, L2.longitud());

  Pizq = L1.sublista(2, Iizq.longitud() + 1);
  Pder = L1.sublista(Iizq.longitud() + 2, L1.longitud());

  this -> raiz -> modHi(lecturaPrin(Pizq, Iizq, 1, L1.longitud()));
  this -> raiz -> modHd(lecturaPrin(Pder, Ider, 1, L1.longitud()));


}

template <class T>
NodoA<T> * lecturaPrin(Lista<T> &Pre, Lista<T> In, int inicio, int final)
{
  NodoA<T> *nuevo;
  T aux;
  int save;

  if(inicio <= final && !Pre.esVacia())
  {
    aux = Pre.consultar(1);
    Pre.eliminar(1);

    save = In.obtPos(aux);

    nuevo = new NodoA<T> (aux);
    nuevo -> modHi(lecturaPrin(Pre, In, 1, save - 1));
    nuevo -> modHd(lecturaPrin(Pre, In, save + 1, In.longitud()));
    return nuevo;
  }
  else
  {
    return NULL;
  }
}*/

template <class T>
void Arboln<T>::insertarSubarbol(const Arboln<T> &Arbol)
{
  NodoA<T> *aux;

  aux = this -> raiz -> obtHi();
  
  if(this -> raiz -> obtHi() == NULL)
  {
    this -> raiz -> modHi(copiar(Arbol.raiz));
  }
  else
  {
    while(aux -> obtHd() != NULL)
    {
      aux = aux -> obtHd();
    }

    aux -> modHd(copiar(Arbol.raiz));
  }
}

template <class T>
NodoA<T> * Arboln<T>::copiar(NodoA<T> *p)
{
  NodoA<T> *nuevo;

  if(p != NULL)
  {
    nuevo = new NodoA<T> (p -> obtInfo(), copiar(p -> obtHi()), copiar(p -> obtHd()));
    return nuevo;
  }
  else
  {
    return NULL;
  }
}

template <class T>
void Arboln<T>::destruirr(NodoA<T> *p)
{
  if(p != NULL)
  {
    if(p -> obtHd() != NULL)
    {
      destruirr(p -> obtHd());
    }

    if(p -> obtHi() != NULL)
    {
      destruirr(p -> obtHi());
    }
  }
  delete p;
  p = NULL;

}

template <class T>
void Arboln<T>::destruir(NodoA<T> *&p)
{
  this -> destruirr(p);
  p = NULL;
}

template <class T>
void Arboln<T>::eliminarSubarbol(int pos)
{
  NodoA<T> *aux, *elim;
  int i;

  if(pos == 1)
  {
    elim = this -> raiz -> obtHi();
    this -> raiz -> modHi(elim -> obtHd());
  }
  else
  {
    aux = this -> raiz -> obtHi();
    for(i = 2 ; i < pos ; i++)
    {
      aux = aux -> obtHd();
    }

    elim = aux -> obtHd();
    aux -> modHd(elim -> obtHd());

  }

  elim -> modHd(NULL);
  this -> destruir(elim);

}

template <class T>
int Arboln<T>::grado()
{
  int acum, mayor;
  Lista<T> h;

  if(this -> esNulo())
  {
    return 0;
  }
  else
  { 
    mayor = -999999;
    this -> grado(this -> raiz, mayor);
    return mayor;
  }
}

template <class T>
void Arboln<T>::grado(NodoA<T> *p, int &mayor)
{
  NodoA<T> *aux;
  int acum;

  if(p != NULL)
  {
    aux = p -> obtHi();
    acum = 0;

    while(aux != NULL)
    {
      acum++;
      aux = aux -> obtHd();
    }

    if(acum > mayor)
    {
      mayor = acum;
    }

    while(p != NULL)
    {
      this -> grado(p -> obtHi(), mayor);
      p = p -> obtHd();
    }
  }
}

template <class T>
void Arboln<T>::copiar(const Arboln<T> &A)
{
  this -> copiar(A.raiz);
}

template <class T>
void Arboln<T>::imprimir()
{
  this -> print(this -> raiz);
}

template <class T>
void Arboln<T>::print(NodoA<T> *p)
{    
    while(p != NULL)
    {
      cout << p -> obtInfo() << " ";
      this -> print(p -> obtHi());
      p = p -> obtHd();

    }
  
}

template <class T>
void Arboln<T>::borrar()
{
  this -> destruir(this -> raiz);
}

#endif
