#ifndef NOMBRE_H
#define NOMBRE_H

#include <iostream>

#include "Run.h"
#include "Fecha.h"
#include "Direccion.h"

using namespace std;

class Persona
{
    private:
        string nombres;
        string paterno;
        string materno;
        RUN miRUN;
        Fecha miFecha;
        Direccion miDireccion;
    public:
        //Constructor
        Persona();
        Persona(string, string, string, RUN, Fecha, Direccion);

        //Sets
        void setNombres(string x){nombres = x;}
        void setPaterno(string x){paterno = x;}
        void setMaterno(string x){materno = x;}
        void setRUN(RUN x){miRUN = x;}
        void setFecha(Fecha x){miFecha = x;}
        void setDireccion(Direccion x){miDireccion = x;}

        //Gets
        string getNombres(){return nombres;}
        string getPaterno(){return paterno;}
        string getMaterno(){return materno;}
        RUN getRUN(){return miRUN;}
        Fecha getFecha(){return miFecha;}
        Direccion getDireccion(){return miDireccion;}

        void verPersona();
};

#endif  //NOMBRE_h