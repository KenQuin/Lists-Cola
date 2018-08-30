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
#include "listaEnlazada.h"

using namespace std;

namespace listaenlazada
{
    template<class T>
    Cola <T>::Cola():delantera(NULL), posterior(NULL)
    {
        
    }
    
    template<class T>
    Cola <T>::Cola(const Cola& unaCola)
    {
        if(unaCola.vacia())
        {
            delantera = posterior = NULL;
        }
        else
        {
            NodoPtr temp_ptr_antiguo = unaCola.delantera;
            NodoPtr temp_ptr_nuevo;
            
            posterior = new Nodo<T>;
            posterior->elemento = temp_ptr_antiguo->elemento;
            posterior->siguiente = NULL;
            delantera = posterior;
            
            temp_ptr_antiguo = temp_ptr_antiguo->enlace;
            
            while(temp_ptr_antiguo != NULL)
            {
                temp_ptr_nuevo = new Nodo<T>;
                temp_ptr_nuevo->elemento = temp_ptr_antiguo->datos;
                temp_ptr_nuevo->siguiente = NULL;
                posterior->siguiente = temp_ptr_nuevo;
                posterior = temp_ptr_nuevo;
                temp_ptr_antiguo = temp_ptr_antiguo->siguiente;
            }
        }
    }
    
    template<class T>
    Cola <T>::~Cola()
    {
        
    }
    
    template<class T>
    bool Cola <T>::vacia() const
    {
        return (posterior==NULL);
    }
    
    template<class T>
    void Cola <T>::crear_cola()
    {
        T escribe;
        char Cont = 'S';
        
        
        while (Cont != 'N' && Cont != 'n')
        {
            cout << "Escriba dato a ingresar: " << endl;
            cin >> escribe;
            
            if (vacia())
            {
                delantera = new Nodo<T>;
                delantera->elemento = escribe;
                delantera->siguiente = NULL;
                posterior = delantera;
            }
            else {
                NodoPtr temp_ptr;
                temp_ptr = new Nodo<T>;
                temp_ptr->elemento = escribe;
                temp_ptr->siguiente = NULL;
                posterior->siguiente = temp_ptr;
                posterior = temp_ptr;
            }
            
            cout << "Desea agragar mas?" << endl;
            cin >> Cont;
            
            while(Cont != 'N' && Cont != 'S' && Cont != 'n' && Cont != 's')
            {
                cout << "Favor indicar S para continuear o N para terminar" << endl;
                cin >> Cont;
            }
            
        }
    }
    
    template<class T>
    void Cola <T>::escribir_cola()
    {
        if(vacia())
        {
            cout << "La cola esta vacia" << endl;
        }
        else
        {
            cout << "Usted escribio: " << endl;
            while(!vacia())
            {
                if (vacia())
                {
                    cout << "Cola vacia. No se puede extraer un elemento";
                }
                T resultado = delantera->elemento;
                
                NodoPtr descarta;
                descarta = delantera;
                delantera = delantera->siguiente;
                if (delantera == NULL)
                {
                    posterior = NULL;
                }
                delete descarta;
                
                cout << resultado << endl;
            }

        }
    }
    
    template<class T>
    void Cola <T>::invertir_cola()
    {
        if(vacia())
        {
            cout << "La cola esta vacia" << endl;
        }
        else
        {
            NodoPtr nuevodelantera = NULL;
            NodoPtr nuevotrasera = NULL;
            T arreglotmp[50];
            int i = 0;
            
            cout << "Resultado del Primera Cola" << endl;
            while(!vacia())
            {
                T resultado = delantera->elemento;
                
                NodoPtr descarta;
                descarta = delantera;
                delantera = delantera->siguiente;
                if (delantera == NULL)
                {
                    posterior = NULL;
                }
                delete descarta;
                arreglotmp[i] = resultado;
                i++;
                
                cout << resultado << endl;
                
                if(vacia())
                {
                    for(int q = i - 1; q >= 0 ; q--)
                    {
                        if(nuevodelantera == NULL)
                        {
                            nuevodelantera = new Nodo<T>;
                            nuevodelantera->elemento = arreglotmp[q];
                            nuevodelantera->siguiente = NULL;
                            nuevotrasera = nuevodelantera;
                        }
                        else
                        {
                            NodoPtr temp_ptr;
                            temp_ptr = new Nodo<T>;
                            temp_ptr->elemento = arreglotmp[q];
                            temp_ptr->siguiente = NULL;
                            nuevotrasera->siguiente = temp_ptr;
                            nuevotrasera = temp_ptr;
                        }
                    }
                    cout << "Resultado de la nueva cola" << endl;
                    while(nuevodelantera != NULL)
                    {
                        if (nuevodelantera == NULL)
                        {
                            cout << "Cola vacia. No se puede extraer un elemento";
                        }
                        T resultado = nuevodelantera->elemento;
                        
                        NodoPtr descarta;
                        descarta = nuevodelantera;
                        nuevodelantera = nuevodelantera->siguiente;
                        if (nuevodelantera == NULL)
                        {
                            nuevotrasera = NULL;
                        }
                        delete descarta;
                        cout << resultado << endl;
                    }
                }
            }

        }
    }
    
    template<class T>
    void Cola <T>::copiar_cola()
    {
        if(vacia())
        {
            cout << "La cola esta vacia" << endl;
        }
        else
        {
            NodoPtr nuevodelantera = NULL;
            NodoPtr nuevotrasera = NULL;
            
            cout << "Elementos de Cola 1" << endl;
            while(!vacia())
            {
                T resultado = delantera->elemento;
                
                NodoPtr descarta;
                descarta = delantera;
                delantera = delantera->siguiente;
                if (delantera == NULL)
                {
                    posterior = NULL;
                }
                delete descarta;
                
                cout << resultado << endl;
                
                if(nuevodelantera == NULL)
                {
                    nuevodelantera = new Nodo<T>;
                    nuevodelantera->elemento = resultado;
                    nuevodelantera->siguiente = NULL;
                    nuevotrasera = nuevodelantera;
                }
                else
                {
                    NodoPtr temp_ptr;
                    temp_ptr = new Nodo<T>;
                    temp_ptr->elemento = resultado;
                    temp_ptr->siguiente = NULL;
                    nuevotrasera->siguiente = temp_ptr;
                    nuevotrasera = temp_ptr;
                }
            }
            cout << "Resultado de la nueva cola" << endl;
            while(nuevodelantera != NULL)
            {
                T nresultado = nuevodelantera->elemento;
                
                NodoPtr ndescarta;
                ndescarta = nuevodelantera;
                nuevodelantera = nuevodelantera->siguiente;
                if (nuevodelantera == NULL)
                {
                    nuevotrasera = NULL;
                }
                delete ndescarta;
                
                cout << nresultado << endl;
            }
        }
        }
    }