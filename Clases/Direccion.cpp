#include "Direccion.h"

Direccion::Direccion()
{
    calle = "";
    numero = 0;
    comuna = "";
}

Direccion::Direccion(string su_calle, int su_num, string su_comuna)
{
    calle = su_calle;
    numero = su_num;
    comuna = su_comuna;
}

void Direccion::verDireccion()
{
    cout << "\e[1mDirección:\e[0m" << endl;
    cout << calle << ", #" << numero << ", " << comuna << endl;
}