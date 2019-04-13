#include "AdministradorDeTareas.hpp"

namespace carlos_faundez {
    class Computador : public AdministradorDeTareas {
        private:
            bool estadoComputador;
        public:
            bool endencerComputador();
            bool apagarComputador(); 
            bool getEstadoComputador();
            void switchEstadoComputador();     
    };
}
