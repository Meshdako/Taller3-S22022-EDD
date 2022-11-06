#include "Elector.h"

Elector::Elector()
{
    Sufragar = 0;
    Vocal = 0;
    Mesa = 0;    
}

Elector::Elector(string names, string f_name, string m_name, RUN su_rut, Fecha su_fecha, Direccion su_direccion, int habilitado, int es_vocal, int su_mesa) : Persona(names, f_name, m_name, su_rut, su_fecha, su_direccion)
{
    Sufragar = habilitado;
    Vocal = es_vocal;
    Mesa = su_mesa;
}

void Elector::verElector()
{
    verPersona();
    cout << "\e[1m¿Está habilitado para sufragar?\e[0m ";
    (Sufragar == 1) ? cout << "Sí" << endl : cout << "No" << endl;
    
    cout << "\e[1m¿Es vocal de mesa?\e[0m ";
    (Vocal == 1) ? cout << "Sí" << endl : cout << "No" << endl;
    
    cout << "\e[1mMesa de votación:\e[0m " << Mesa << endl;
}