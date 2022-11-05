#include "Funciones.h"

#define MAX_VECTOR 1000

typedef struct Nodo{
    Elector Info;
    struct Nodo *Link;
}Nodo;

typedef struct Lista{
    Nodo *Cabeza;
}Lista;

Nodo* CrearNodo(Elector e)
{
    Nodo* Aux = new Nodo();
    Aux->Info = e;
    Aux->Link = NULL;
    return Aux;
}

void AgregarIzq(Lista &L, Elector e)
{
    Nodo* Aux = CrearNodo(e);
    Aux->Link = L.Cabeza;
    L.Cabeza = Aux;
}

void AgregarDer(Lista &L, Elector e)
{
    Nodo* Aux = CrearNodo(e);

    if(L.Cabeza == NULL){
        L.Cabeza = Aux;
    }
    else{
        Nodo* Aux_L = L.Cabeza;

        while(Aux_L->Link){
            Aux_L = Aux_L->Link;
        }
        Aux_L->Link = Aux;
    }
}

void MostrarLista(Lista &L)
{
    Nodo* Aux = L.Cabeza;

    //Recorremos la lista con un Nodo Auxiliar.
    while(Aux != NULL){
        Aux->Info.verElector();
        Aux = Aux->Link;
    }
}

void PressEnterToContinue()
{
    cout << "Presiona Enter para continuar... " << flush;
    cin.ignore(numeric_limits <std::streamsize> ::max(), '\n' ); 
}

void CantidadElectores(Lista &L)
{
    int cont_1, cont_2, cont_3;
    Nodo* Aux = L.Cabeza;

    cont_1 = cont_2 = cont_3 = 0;

    while(Aux != NULL){
        if(Aux->Info.getSufragio() == 1)
            cont_2++;

        if(Aux->Info.getVocal() == 1)
            cont_3++;

        cont_1++;

        Aux = Aux->Link;
    }

    cout << "Total de electores: " << cont_1 << endl;
    cout << "Total de personas habilitadas para votar: " << cont_2 << endl;
    cout << "Total de vocales de mesa: " << cont_3 << endl;
}

void ElectoresXComuna(Lista &L, string in_Comuna)
{
    int n = 0;

    Elector misElectores[MAX_VECTOR];
    Elector el_Aux;
    Nodo* Aux = L.Cabeza;

    while(Aux != NULL){
        if(in_Comuna == Aux->Info.getDireccion().getComuna()){
            misElectores[n] = Aux->Info;
            n++;
        }

        Aux = Aux->Link;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(misElectores[j].getNombres() > misElectores[j + 1].getNombres()){
                el_Aux = misElectores[j];
                misElectores[j] = misElectores[j + 1];
                misElectores[j + 1] = el_Aux;
            }
        }
    }

    for(int i = 0; i < n; i++){
        misElectores[i].verElector();
    }

    PressEnterToContinue();
}

void Menu(Lista &L)
{
    int opcion;

    string in_Comuna;

    do{
        system("clear");
        cout << "\e[1mSeleccione una opción:\e[0m" << endl;
        cout << "1.- Cantidad de Electores." << endl;
        cout << "2.- Electores por Comuna." << endl;
        cout << "3.- Inhabilitados para Sufragar." << endl;
        cout << "4.- Eliminar Votante." << endl;
        cout << "5.- Agregar Votante" << endl;
        cout << "0.- Salir" << endl;
        cout << ">> ";
        cin >> opcion;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        switch(opcion){
            case 1:
                CantidadElectores(L);
                PressEnterToContinue();
                break;
            case 2:
                cout << "Ingrese la comuna que desea buscar (ej: LA CISTERNA): ";
                getline(cin >> ws, in_Comuna);

                ElectoresXComuna(L, in_Comuna);
                break;
            case 3:
                cout << "Estamos trabajando para usted." << endl;
                PressEnterToContinue();
                break;
            case 4:
                cout << "Estamos trabajando para usted." << endl;
                PressEnterToContinue();
                break;
            case 5:
                cout << "Estamos trabajando para usted." << endl;
                PressEnterToContinue();
                break;
            default:
                cout << "Seleccione una opción válida." << endl;
                PressEnterToContinue();
                break;
        }
    }while(opcion != 0);
}

void vectorALista(Elector p[], Lista &L, int indice)
{
    for(int i = 0; i < indice; i++){
        AgregarDer(L, p[i]);
    }
}

void archivoAVector(string nombreArchivo, Elector p[] , int &indice){
    ifstream archivo;
    string lineaObtenida;
    string palabra;

    archivo.open(nombreArchivo, ios::in);

    if(archivo.is_open() == true) {

        while( getline(archivo, lineaObtenida, '\n')){
            //ahora recorremos la línea
            vector<string> data = split(lineaObtenida, ';');

            if(indice > 0) {
                RUN Run_Aux(stol(data[0]), data[1].front());

                Fecha Fecha_Aux(stoi(data[5]), stoi(data[6]), stoi(data[7]));
                
                Direccion Dir_Aux(data[8], stoi(data[9]), data[10]);
                
                Elector Elector_Aux(data[2], data[3], data[4], Run_Aux, Fecha_Aux, Dir_Aux, stoi(data[11]), stoi(data[12]), stoi(data[13]));

                p[indice] = Elector_Aux;
            }
            indice++;
        }
    }
    archivo.close();
}

vector<string> split(string lineaASeparar, char delimitador) {
    vector<string> vector_interno;      //#include <vector>
    stringstream linea(lineaASeparar);  //#include <sstream>
    string parteDelString;

    while(getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}