#include "Fecha.h"

Fecha::Fecha()
{
    dia = 1;
    mes = 1;
    anho = 1900;
}

Fecha::Fecha(int un_dia, int un_mes, int un_anho)
{
    dia = un_dia;
    mes = un_mes;
    anho = un_anho;
}

void Fecha::verFecha()
{
    cout << "\e[1mFecha de nacimiento:\e[0m  " << dia << "/" << mes << "/" << anho << endl;
}