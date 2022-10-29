#include "pch.h"
#include "Playlist.h"
#include "Reciente.h"
#define Archivo "playlist inicial"
#include<string>
#include <iostream>
#include <fstream>


using namespace System;
using namespace System::IO;
using namespace std;



Reciente reziente = Reciente();
Playlist play = Playlist();

int leerr() {
    
    std::string line;
    ifstream myfile("example.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            
            reziente.push(line);
            play.push(line);
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
}

int imprimir() {
    if (reziente.Count() == 0) {
        cout << "Cola terminada";
        std::string line;
        ifstream myfile("example.txt");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {

                reziente.push(line);
                
            }
            myfile.close();
        }

        else cout << "Unable to open file";
        imprimir();
        return 0;
    }
    cout << "Playlist"<< "\n";
    for (int i = 0; i < 10;i++)
    {
        
        cout << play.pop() << "\n";
        
        i++;
    }
    cout<< "                        "<< "\n";
    cout << "Fila de reproduccion"<< "\n";
    for (int i = 0; i < 10;i++)
    {
        cout << reziente.pop() <<"\n";
        i++;
    }
    while (reziente.Count() > 0) {
        cout << "                        " << "\n";
        cout << "Desea agregar una cancion?";
        string ellecion;
        string artista, cancion;
        cin >> ellecion;
        if (ellecion == "Si") {
            cout << "Ingrese el artista";
            cin >> artista;
            if (artista == " ") {
                artista = "Desconocido";
            }
            cout << "Ingrese la cancion";
            cin >> cancion;
            string rola;
            rola = cancion + "-" + artista;
            reziente.push(rola);

        }

        string elleccion;
        cout << "                        " << "\n";
        cout << "Desea ordenar ? S=SI, N=NO";
        cin >> elleccion;
        if (elleccion == "Si") {
            //contacts_by_name->merge_sort(new ContactNameComparator());
        }
        
        string eleccion;
        cout << "                        " << "\n";
        cout << "Desea reproducir una cancion ? S=SI, N=NO";
        cin >> eleccion;
        if (eleccion=="Si") {
            cout << play.pop() << endl;
            imprimir();
            eleccion = " ";
        }
       std::cout<<"Valor Incorrecto";
       cout << "                        " << "\n";
       cout << "Desea eliminar una cancion?";
       string elcccion;
       cin >> eleccion;
       if (eleccion == "Si") {
           int i;
           cout << "Ingrese el numero de la cancion a eliminar";
           cin >> i;
           
           reziente.RemoveAt(i);

       }
       string elexion;
       cout << "Desea exportar la cola";
       cin >> elexion;
       if (elexion == "Si") {
           String^ fileName = "coladereproduccion.txt";

           StreamWriter^ sw = gcnew StreamWriter(fileName);
           sw->WriteLine("Fila de reproduccion");
           for (int i = 0; i < 10;i++)
           {
               sw->WriteLine("reziente.pop()");
               i++;
           };
           sw->WriteLine(DateTime::Now);
           sw->Close();
           Console::WriteLine("a new file ('{0}') has been written", fileName);

           return 0;
       }
       

        


    }
    return 0;
};


int main()
{
    leerr();
    imprimir();
    return 0;
    
}
