#include "Funciones.h"

#define MAX_VECTOR 1001

/* Función 3: Inhabilitados para Sufragar */

typedef struct n_Nodo{
    RUN su_RUT;
    string Nombres;
    n_Nodo *Link;
}n_Nodo;

typedef n_Nodo * n_Lista;

n_Nodo* CrearNuevoNodo(RUN r, string n)
{
    n_Nodo* Aux = new n_Nodo();
    Aux->su_RUT = r;
    Aux->Nombres = n;
    Aux->Link = NULL;
    return Aux;
}

void AgregarNuevaLista(n_Lista &NL, RUN r, string n)
{
    n_Nodo* Aux = CrearNuevoNodo(r, n);
    Aux->Link = NL;
    NL = Aux;
}

int MostrarNuevaLista(n_Lista &NL)
{
    int cont = 0;
    n_Nodo* Aux = NL;

    //Recorremos la lista con un Nodo Auxiliar.
    while(Aux != NULL){
        cont++;

        Aux->su_RUT.verRun();
        cout << "\tNombre/s: " << Aux->Nombres << endl;

        Aux = Aux->Link;
    }
    
    return cont;
}

/* Estructura de la Lista */

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
    system("clear");

    vector<Elector> misElectores;
    Elector el_Aux;
    Nodo* Aux = L.Cabeza;

    // Guardamos los electores de la comuna buscada en un Vector.
    while(Aux != NULL){
        if(in_Comuna == Aux->Info.getDireccion().getComuna()){
            misElectores.push_back(Aux->Info);
        }

        Aux = Aux->Link;
    }

    // Ordenamos con el método burbuja y utilizamos la función Swap de la librería Utility.
    for(int i = 0; i < misElectores.size(); i++){
        for(int j = 0; j < misElectores.size(); j++){
            // Priorizamos no avanzar más allá del tamaño de nuestro Vector.
            if((j + 1) < misElectores.size()){
                if(misElectores[j].getNombres() > misElectores[j + 1].getNombres()){
                    swap(misElectores[j], misElectores[j + 1]);
                }
            }
        }
    }

    // Imprimimos nuestro Vector.
    for(int i = 0; i < misElectores.size(); i++){
        misElectores[i].verElector();
    }
    PressEnterToContinue();
}

void InhabilitadosSufragio(Lista &L)
{
    int cont;
    Nodo* Aux = L.Cabeza;
    
    // Creamos la Nueva Lista.
    n_Lista miNuevaLista;

    while(Aux != NULL){
        if(Aux->Info.getSufragio() == 0){            
            // Agregamos a la Nueva Lista, por la izquierda.
            AgregarNuevaLista(miNuevaLista, Aux->Info.getRUN(), Aux->Info.getNombres());
        }

        Aux = Aux->Link;
    }

    cout << "Personas inhabilitadas para votar agregadas a la nueva lista." << endl;
    cout << "Se mostrarán las personas agregadas." << endl;
    PressEnterToContinue();

    system("clear");

    // Imprimimos la Nueva Lista.
    cont = MostrarNuevaLista(miNuevaLista);

    cout << "Total de personas inhabilitadas para votar: " << cont << endl;
}

bool EliminarVotante(Lista &L, int in_Run)
{
    Nodo* Aux = L.Cabeza;
    Nodo* Prev = NULL;

    // Buscamos el RUT o llegamos al final de la Lista.
    while(Aux != NULL && in_Run != Aux->Info.getRUN().getRun()){
        Prev = Aux;
        Aux = Aux->Link;
    }

    // Si la Lista está vacía, es que el RUT no se encontró o no existe.
    if(Aux == NULL)
        return false;
    
    // En caso contrario, el Nodo previo apunta al siguiente del Nodo actual. Luego, eliminamos el Nodo actual.
    Prev->Link = Aux->Link;
    delete Aux;

    return true;

    /* Método alternativo */
    
    /* int sePudo = 0;

    // Mientras exista un siguiente, recorremos la Lista.
    while(Aux->Link){
        if(in_Run == Aux->Link->Info.getRUN().getRun()){
            // Cuando encontramos el rut, el siguente de nuestro Nodo actual, apunta al siguiente del Nodo siguiente. Luego, eliminamos el Nodo siguiente.
            Aux->Link = Aux->Link->Link;
            delete Aux->Link;

            // Asignamos como 1 la variable.
            sePudo = 1;
        }
        Aux = Aux->Link;
    }

    // Dependiendo del resultado, devolvemos Verdadero o Falso.
    if(sePudo == 1)
        return true;
    else
        return false; */
}

Elector CrearElector(Elector e)
{
    int Resp, in_Run, Fecha_Cumpleanhos, in_Numero;
    char in_DV;
    string Data;

    RUN Run_Aux;
    Fecha Fecha_Aux;
    Direccion Dir_Aux;

    Resp = 0;

    do{
        cout << "Ingrese el RUT (sin puntos y sin DV), de la persona: ";
        cin >> in_Run;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        Run_Aux.setRun(in_Run);

        cout << "Ingrese el DV: ";
        cin >> in_DV;

        Run_Aux.setDv(in_DV);
        
        e.setRUN(Run_Aux);

        cout << "Ingrese el/los Nombre/s de la persona: ";
        getline(cin >> ws, Data);

        e.setNombres(Data);

        cout << "Ingrese el Apellido Paterno de la persona: ";
        getline(cin >> ws, Data);

        e.setPaterno(Data);

        cout << "Ingrese el Apellido Materno de la persona: ";
        getline(cin >> ws, Data);

        e.setMaterno(Data);

        cout << "Ingrese la Fecha de Nacimiento." << endl;
        cout << "Día: ";
        cin >> Fecha_Cumpleanhos;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');
        
        Fecha_Aux.setDia(Fecha_Cumpleanhos);

        cout << "Mes: ";
        cin >> Fecha_Cumpleanhos;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        Fecha_Aux.setMes(Fecha_Cumpleanhos);

        cout << "Año: ";
        cin >> Fecha_Cumpleanhos;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        Fecha_Aux.setAnho(Fecha_Cumpleanhos);
        
        e.setFecha(Fecha_Aux);

        cout << "Ingrese la Dirección Particular." << endl;
        cout << "Calle: ";
        getline(cin >> ws, Data);

        Dir_Aux.setCalle(Data);

        cout << "Número: ";
        cin >>  in_Numero;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        Dir_Aux.setNumero(in_Numero);

        cout << "Comuna: ";
        getline(cin >> ws, Data);

        /* Pequeña función */
        for(int i = 0; Data[i]; i++){
            Data[i] = toupper(Data[i]);
        }

        Dir_Aux.setComuna(Data);

        e.setDireccion(Dir_Aux);

        cout << "Ingrese los Datos Electorales." << endl;
        cout << "¿Está habilitado para sufragar? Sí = 1 / No = 0" << endl;
        cin >> in_Numero;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        e.setSufragio(in_Numero);

        cout << "¿Es Vocal de Mesa? Sí = 1 / No = 0" << endl;
        cin >> in_Numero;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        e.setVocal(in_Numero);

        cout << "¿En qué Mesa le tocó votar? ";
        cin >> in_Numero;
        cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

        e.setMesa(in_Numero);
        
        cout << "Se mostrarán los datos ingresados..." << endl;
        PressEnterToContinue();

        system("clear");
        e.verElector();

        cout << "Los datos ingresados, ¿Son correctos?" << endl;
        cout << "Sí = 1 / No = 0" << endl;
        cin >> Resp;

        if(Resp == 0){
            cout << "Se volverán a preguntar los datos." << endl;
            PressEnterToContinue();
        }
    }while(Resp != 1);

    return e;
}

void AgrearVotante(Lista &L, Elector e)
{
    int Resp;
    Elector Aux = CrearElector(e);

    cout << "¿Desea agregar al nuevo Elector al Inicio de la Lista?" << endl;
    cout << "Sí = 1 / No = 0" << endl;
    cin >> Resp;
    cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

    if(Resp == 1){
        system("clear");
        cout << "Agregando Elector por la Izquierda..." << endl;
        AgregarIzq(L, Aux);
        cout << "Elector agregado." << endl;
        PressEnterToContinue();
    }
    else{
        system("clear");
        cout << "Agregando Elector por la Derecha..." << endl;
        AgregarDer(L, Aux);
        cout << "Elector agregado." << endl;
        PressEnterToContinue();
    }
}

void Menu(Lista &L)
{
    int opcion;

    string in_Comuna;
    int in_Run;
    bool resp;

    Elector e;

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
            case 0:
                cout << "\t\t\e[1mSee You Space Cowboy...\e[0m" << endl;
                PressEnterToContinue();
                break;
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
                InhabilitadosSufragio(L);
                PressEnterToContinue();
                break;
            case 4:
                cout << "Ingrese el RUT que desea eliminar: ";
                cin >> in_Run;
                cin.ignore(numeric_limits <std::streamsize> ::max(), '\n');

                resp = EliminarVotante(L, in_Run);

                (resp == true) ? cout << "El Elector fue eliminado con éxito." << endl : cout << "El Elector no fue encontrado. Intente de nuevo." << endl;
                PressEnterToContinue();
                break;
            case 5:
                AgrearVotante(L, e);
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