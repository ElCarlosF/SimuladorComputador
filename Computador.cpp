#include <iostream>
#include "Computador.hpp"

using namespace carlos_faundez;

void Computador::switchEstadoComputador() {
    estadoComputador = !estadoComputador;
}

bool Computador::getEstadoComputador() {
    return estadoComputador;
}

bool Computador::apagarComputador() {
    bool _return;
    if(_return = estadoComputador) {
        switchEstadoComputador();
    }
    return _return;
}

bool Computador::endencerComputador() {
    bool _return;
    if(_return = !estadoComputador) {
        switchEstadoComputador();
    }
    return _return;
}