#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
        int anho;
    public:
        //Constructor
        Fecha();
        Fecha(int, int, int);
        
        //Sets
        void setDia(int x){dia = x;}
        void setMes(int x){mes = x;}
        void setAnho(int x){anho = x;}

        //Gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnho(){return anho;}

        void verFecha();
};

#endif  //FECHA_H