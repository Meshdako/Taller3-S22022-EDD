#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>

using namespace std;

class Direccion
{
    private:
        string calle;
        int numero;
        string comuna;
    public:
        //Constructor
        Direccion();
        Direccion(string, int, string);

        //Sets
        void setCalle(string x){calle = x;}
        void setNumero(int x){numero = x;}
        void setComuna(string x){comuna = x;}

        //Gets
        string getCalle(){return calle;}
        int getNumero(){return numero;}
        string getComuna(){return comuna;}

        void verDireccion();
};

#endif  //DIRECCION_h