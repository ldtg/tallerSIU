#include "Admin.h"
#include <string>
#include <sstream>
Admin::Admin(int num,
             std::string nombre,
             std::map<IdMateria, Materia> &materias,
             std::map<IdUsuario, Usuario*> &usuarios) : Usuario(IdUsuario(num,
                                                                         ADMIN
                                                               ),
                                                               nombre),
                                                       materias(materias),
                                                       usuarios(usuarios) {}

void Admin::inscribir(Usuario &usuarioaInscribir, Materia *materia) {
  usuarioaInscribir.inscribir(usuarioaInscribir, materia);
}
void Admin::desInscribir(Usuario &usuarioaDesinscribir,
                         Materia *materia) {
  usuarioaDesinscribir.desInscribir(usuarioaDesinscribir, materia);
}
std::string Admin::listarInscripciones() const {
  std::stringstream aux;
  for (auto &&par : materias) {
    aux << par.second.toString();
    aux << par.second.listarAlumnosInscriptos();
  }
  return aux.str();
}
std::string Admin::toString() const {
  return "";
}

