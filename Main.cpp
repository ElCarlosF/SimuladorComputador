#include <iostream>
#include <stdlib.h>
#include <limits>
#include "Computador.hpp"

enum opciones {encender = 1,abrir,cerrar,enlistar,apagar,salir};

using namespace std;
using namespace carlos_faundez;

int main(){
    system("clear");
    string textinicio = "*****************************************************\n";
    textinicio +="*              BIENVENIDO A PC SIMULATOR            *\n";
    textinicio +="*                por Carlos Faundez M.              *\n";
    textinicio +="*****************************************************\n\n\n";

    string textdurante = "*****************************************************\n";
    textdurante += "*                    PC SIMULATOR                   *\n";
    textdurante += "*                por Carlos Faundez M.              *\n";
    textdurante += "*****************************************************\n\n";

    string textfin = "*****************************************************\n";
    textfin += "*              HA SALIDO DE PC SIMULATOR            *\n";
    textfin += "*                por Carlos Faundez M.              *\n";
    textfin += "*****************************************************\n\n\n";

    string textopciones = "Seleccione una opción\n\n";
    textopciones += "1 - Encender computador\n";
    textopciones += "2 - Abrir programa\n";
    textopciones += "3 - Cerrar programa\n";
    textopciones += "4 - Mostrar lista de programas abiertos\n";
    textopciones += "5 - Apagar computador\n";
    textopciones += "6 - Salir simulacion\n";
    textopciones += "\nIngrese opcion: ";

    Computador *pc = nullptr;
    
    cout << textinicio;

    do{
        unsigned short int op = 0;
        do{
            cout << "Estado: ";
            if(pc == nullptr) {
                cout << "El computador esta apagado" << endl;
            }else {
                cout << "El computador esta encendido";
                if(pc->getCantidadProgramasAbiertos() > 0) {
                    cout << ", con programa/s corriendo/s";
                }
            }
            cout << endl << endl;
            cout << textopciones;
            cin >> op;
            system("clear");
            cout << textdurante;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingresar solo numeros!!" << endl;
            }
        }while(op < encender || op > salir);
        switch (op)
        {
        
        case encender:
            if(pc == nullptr) {
                pc = new Computador();
                cout << "El computador se encendio" << endl;
            }else{
                cout << "El computador ya se encuentra encendido" << endl;
            }
            break;
        
        case salir:
            if(pc != nullptr) { 
                cout << "Deberias apagar el computador antes de salir de la simulacion" << endl;
                break;
            }
            system("clear");
            cout << textfin;
            return 0;
            break;
        
        case abrir:
            if(pc == nullptr) {
                cout << "No se puede realizar la operacion: computador apagado" << endl;
            }else {
                string nombrePrograma;
                cout << "Ingrese nombre del programa a ejecutar: ";
                cin >> nombrePrograma;
                if(pc->abrirPrograma(nombrePrograma)) {
                    cout << nombrePrograma << " se esta ejecutando" << endl;
                }else {
                    cout << nombrePrograma << " ya esta en ejecucion" << endl;
                }
            }
            break;

        case cerrar:
            if(pc == nullptr) {
                cout << "No se puede realizar la operacion: computador apagado" << endl;
            }else if (pc->getCantidadProgramasAbiertos() > 0){
                string nombrePrograma;
                cout << "Ingrese nombre del programa a cerrar o id del programa: ";
                cin >> nombrePrograma;
                if(pc->cerrarPrograma(nombrePrograma)) {
                    cout << nombrePrograma << " se ha cerrado" << endl;
                }else if(pc->cerrarPrograma(atoi(nombrePrograma.c_str()) - 1)){
                    cout << "Programa con ID: " << nombrePrograma << " se ha cerrado" << endl;
                }else {
                    cout << nombrePrograma << " no se encontro" << endl;
                }
            }else {
                cout << "No hay programas ejecutandose" << endl;
            }
            break;
        
        case enlistar:
            if(pc == nullptr) {
                cout << "No se puede realizar la operacion: computador apagado" << endl;
            }else {
            pc->mostrarProgramasAbiertos();
            }
            break;
        
        case apagar:
            if(pc != nullptr) {
                if(pc->getCantidadProgramasAbiertos() > 0) {
                    cout << "Deberias cerrar todos los programas antes de apagar el computador" << endl;
                    break;
                }
                pc->~Computador();
                pc = nullptr;
                cout << "El computador se ha apagado" << endl;
            }else {
                cout << "El computador se encuentra apagado" << endl;
            }
            break;
        }
        cout << endl;
    }while (1);

    return -1;
}