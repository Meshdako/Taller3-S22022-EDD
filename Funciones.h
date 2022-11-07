#include <iostream>     //utilizada para la entrada y salida de datos
#include <fstream>      //relacionada al manejo de archivos
#include <sstream>      //relacionada a string stream https://www.cplusplus.com/reference/sstream/
#include <vector>       //relacionada al manejo de vectores dinámicos
#include <limits>       //relacionada a los límites de valores
#include <utility>      //relacionada al intercambio entre dos elementos.
#include <cctype>

//Clases
#include "Clases/Direccion.h"
#include "Clases/Fecha.h"
#include "Clases/Run.h"
#include "Clases/Persona.h"
#include "Clases/Elector.h"

using namespace std;

/* Función 3: Inhabilitados para Sufragar */

typedef struct n_Nodo n_Nodo;

typedef n_Nodo * n_Lista;

n_Nodo* CrearNuevoNodo(RUN r, string n);

void AgregarNuevaLista(n_Lista &NL, RUN r, string n);

int MostrarNuevaLista(n_Lista &NL);

/* Estructura de la Lista */

typedef struct Nodo Nodo;

typedef struct Lista Lista;

// Crea un Nodo con el Elector enviado.
Nodo* CrearNodo(Elector e);

// Agrega al inicio de la Lista.
void AgregarIzq(Lista &L, Elector e);

// Agrega al final de la Lista.
void AgregarDer(Lista &L, Elector e);

// Muestra la Lista completa.
void MostrarLista(Lista &L);

/* Funciones del Taller 3. */

void PressEnterToContinue();

// Implementa una función cuyo parámetro de entrada es una LLS de objetos y realiza el procesamiento para mostrar la cantidad de electores, total de personas habilitadas para votar y la cantidad de vocales de mesa.
void CantidadElectores(Lista &L);

// Implementa una función cuyos parámetros de entrada es una LLS de objetos y una variable string que utilizará para comparar por comunas y mostrar los datos ordenados de forma ascendente
void ElectoresXComuna(Lista &L, string in_Comuna);

// Implementa correctamente una función que a partir de la información contenida en la LLS, genera otra lista lineal simple que solo contenga RUN y Nombre de cada persona inhabilitada para votar. Debe mostrar la nueva lista generada
void InhabilitadosSufragio(Lista &L);

// Implementa una función que dado un RUT, deberá eliminar dicha información desde la LLS y retornar true si lo pudo eliminar correctamente y false si no lo encontró. Luego en base al valor retornado por la función deberá mostrar un mensaje apropiado.
bool EliminarVotante(Lista &L, int in_Run);

// Implementa correctamente una función o dos funciones que tienen como parámetros una LLS y un objeto de tipo Elector, el que deberá agregar a la LLS. El usuario indicará si se agrega al comienzo o al final de la lista y se deberá llamar a la función correspondiente
Elector CrearElector(Elector e);
void AgrearVotante(Lista &L, Elector e);

/* Menú de opciones */

void Menu(Lista &L);

/* Funciones para leer el archivo */

// Pasamos el Vector creado a la Lista de Objetos.
void vectorALista(Elector p[], Lista &L, int indice);

// Función que lee el archivo "servel" y guarda la información en un Vector.
void archivoAVector(string nombreArchivo, Elector p[] , int &indice);

// Función que guarda la información de una línea en un Vector, mediante un caracter Delimitador.
vector<string> split(string lineaASeparar, char delimitador);