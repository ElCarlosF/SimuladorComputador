#include <vector>
#include <iostream>

namespace carlos_faundez{
    class AdministradorDeTareas{
        private:
            std::vector<std::string> *programasAbiertos;
        public:
            AdministradorDeTareas();
            ~AdministradorDeTareas();
            bool abrirPrograma(std::string nombrePrograma);
            bool cerrarPrograma(std::string nombrePrograma);
            bool cerrarPrograma(unsigned short int idPrograma);
            void mostrarProgramasAbiertos();
            unsigned short int getCantidadProgramasAbiertos();
    };
}