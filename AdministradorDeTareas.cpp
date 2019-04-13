#include "AdministradorDeTareas.hpp"
#include <algorithm>
#include <iostream>

using namespace carlos_faundez;
using namespace std;

AdministradorDeTareas::AdministradorDeTareas() {
    programasAbiertos = new std::vector <string>;
}

AdministradorDeTareas::~AdministradorDeTareas() {
    for (int i = 0 ; i < programasAbiertos->size() ; i++) {
        delete &programasAbiertos->at(i);
    } 
    programasAbiertos->clear();
    delete programasAbiertos;
}

bool AdministradorDeTareas::abrirPrograma(string nombrePrograma) {
    unsigned short int pos = find(programasAbiertos->begin(),programasAbiertos->end(),nombrePrograma) - programasAbiertos->begin();
    if(pos >= programasAbiertos->size()) {
        programasAbiertos->push_back(nombrePrograma);
        return true;
    }
    return false;
}

bool AdministradorDeTareas::cerrarPrograma(string nombrePrograma) {
    unsigned short int pos = find(programasAbiertos->begin(),programasAbiertos->end(),nombrePrograma) - programasAbiertos->begin();
    if(pos < programasAbiertos->size()) {
        programasAbiertos->erase(programasAbiertos->begin() + pos);
        return true;
    }
    return false;
}

bool AdministradorDeTareas::cerrarPrograma(unsigned short int idPrograma) {
    if(idPrograma < programasAbiertos->size()) {
        programasAbiertos->erase(programasAbiertos->begin() + idPrograma);
        return true;
    }
    return false;
}

void AdministradorDeTareas::mostrarProgramasAbiertos() {
    cout << "ID - Nombre del programa" << endl;
    if(programasAbiertos->size() > 0) {
        for(int i = 0 ; i < programasAbiertos->size() ; i++) {
            cout << i + 1 << " - " << programasAbiertos->at(i) << endl;
        }
    }else {
        cout << "No hay programas en ejecucion" << endl;
    }
}

unsigned short int AdministradorDeTareas::getCantidadProgramasAbiertos() {
    return programasAbiertos->size();
}