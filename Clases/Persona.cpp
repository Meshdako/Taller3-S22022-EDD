#include "Persona.h"

Persona::Persona()
{
    nombres = "-";
    paterno = "-";
    materno = "-";
}

Persona::Persona(string names, string f_name, string m_name, RUN su_rut, Fecha su_fecha, Direccion su_direccion)
{
    nombres = names;
    paterno = f_name;
    materno = m_name;
    miRUN = su_rut;
    miFecha = su_fecha;
    miDireccion = su_direccion;
}

void Persona::verPersona()
{
    //\e[1m Bold \e[0m
    cout << "*****************************" << endl;
    miRUN.verRun();
    cout << "\e[1mNombres:\e[0m " << nombres << endl;
    cout << "\e[1mApellido paterno:\e[0m " << paterno << endl;
    cout << "\e[1mApellido materno:\e[0m " << materno << endl;
    miFecha.verFecha();
    miDireccion.verDireccion();
}