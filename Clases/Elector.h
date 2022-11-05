#ifndef ELECTOR_H
#define ELECTOR_H

#include <iostream>

#include "Run.h"
#include "Fecha.h"
#include "Direccion.h"
#include "Persona.h"

using namespace std;

class Elector : public Persona
{
    private:
        int Sufragar;
        int Vocal;
        int Mesa;
    public:
        //Constructor
        Elector();
        Elector(string, string, string, RUN, Fecha, Direccion, int, int, int);

        //Sets
        void setSufragio(int x){Sufragar = x;}
        void setVocal(int x){Vocal = x;}
        void setMesa(int x){Mesa = x;}
        //Gets
        int getSufragio(){return Sufragar;}
        int getVocal(){return Vocal;}
        int getMesa(){return Mesa;}        

        void verElector();
};

#endif //ELECTOR_H