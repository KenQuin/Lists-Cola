#ifndef listaEnlazada_h
#define listaEnlazada_h
#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cstddef>

using namespace std;

namespace listaenlazada
{
    template <class T>
    struct Nodo
    {
        T elemento;
        Nodo<T> *siguiente;
    };
    
    template<class T>
    class Cola
    {
    public:
        Cola();
        Cola(const Cola& unaCola);
        ~Cola();
        typedef Nodo<T>* NodoPtr;
        bool vacia() const;
        
        void crear_cola();
        void copiar_cola();
        void invertir_cola();
        void escribir_cola();
        
    private:
        NodoPtr delantera;
        NodoPtr posterior;
    };
}
#endif