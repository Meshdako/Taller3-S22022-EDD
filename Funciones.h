#include <iostream>     //utilizada para la entrada y salida de datos
#include <fstream>      //relacionada al manejo de archivos
#include <sstream>      //relacionada a string stream https://www.cplusplus.com/reference/sstream/
#include <vector>       //relacionada al manejo de vectores dinámicos
#include <limits>       //relacionada a los límites de valores

//Clases
#include "Clases/Direccion.h"
#include "Clases/Fecha.h"
#include "Clases/Run.h"
#include "Clases/Persona.h"
#include "Clases/Elector.h"

using namespace std;

//Función que lee el archivo "servel" y guarda la información en un arreglo.
void archivoAVector(string nombreArchivo, Elector p[] , int &indice);

//Función que guarda la información de una línea en un vector, mediante un caracter delimitador.
vector<string> split(string lineaASeparar, char delimitador);