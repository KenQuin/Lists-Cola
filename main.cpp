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
#include "listaEnlazada.cpp"


using namespace std;
using namespace listaenlazada;

void menu(int Choice)
{
    
    Cola<int> num_entero;
    Cola<double> num_double;
    Cola<char> sea_char;
    
    int Opcion;
    
    do
    {
        cout << "1) CREAR COLA" << endl;
        cout << "2) COPIAR COLA " << endl;
        cout << "3) INVERTIR COLA" << endl;
        cout << "4) ESCRIBIR COLA" << endl;
        cout << "0) VOLVER A ENTEROS DOBLES O CARACTERS" << endl;
        cout << "Opcion: ";
        
        cin >> Opcion;
        cout << endl;
        
        switch(Opcion)
        {
            case 1:
                if(Choice == 1)
                {
                    num_entero.crear_cola();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.crear_cola();
                    break;
                }
                else
                {
                    sea_char.crear_cola();
                    break;
                }
            case 2:
                if(Choice == 1)
                {
                    num_entero.copiar_cola();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.copiar_cola();
                    break;
                }
                else
                {
                    sea_char.copiar_cola();
                    break;
                }
            case 3:
                if(Choice == 1)
                {
                    num_entero.invertir_cola();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.invertir_cola();
                    break;
                }
                else
                {
                    sea_char.invertir_cola();
                    break;
                }
            case 4:
                if(Choice == 1)
                {
                    num_entero.escribir_cola();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.escribir_cola();
                    break;
                }
                else
                {
                    sea_char.escribir_cola();
                    break;
                }
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        
        cout << endl;
        
    }while(Opcion != 0);
    
}

void Menu_Numero()
{
    int Choice;
    do{
        cout << "ESCOGER NUMERO ENTERO O REAL" << endl;
        cout << "1) ENTERO" << endl;
        cout << "2) REAL" << endl;
        cout << "3) CARACTER" << endl;
        cout << "0) TERMINAR EL PROGRAMA" << endl;
        cout << "Opcion: ";
        cin >> Choice;
        
        switch(Choice)
        {
            case 1:
                cout << endl;
                menu(Choice);
                break;
            case 2:
                cout << endl;
                menu(Choice);
                break;
            case 3:
                cout << endl;
                menu(Choice);
            case 0:
                cout << "FIN DEL PROGRAMA" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        
    }while(Choice != 0);
}

int main()
{
    Menu_Numero();
    
    return 0;
}
