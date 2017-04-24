#include <algorithm>
#include <sstream>
#include "Docente.h"
#include "MovimientoInvalido.h"
Docente::Docente(int num, std::string nombre, Materia &materia) :
    Usuario(IdUsuario(num, docente), nombre), materia(materia) {
  materia.setNombreDocente(nombre);
}

void Docente::inscribir(Usuario &usuarioaInscribir, Materia *materia) {
  comprobarId(materia->getId());
  usuarioaInscribir.inscribir(usuarioaInscribir,materia);
  alumnosInscriptos.push_back(usuarioaInscribir.getId());
}
void Docente::desInscribir(Usuario &usuarioaDesinscribir,
                           Materia *materia) {
  comprobarId(materia->getId());
  usuarioaDesinscribir.desInscribir(usuarioaDesinscribir,materia);
  std::vector<IdUsuario>::iterator it;
  it = find(alumnosInscriptos.begin(), alumnosInscriptos.end
      (), usuarioaDesinscribir.getId());
  alumnosInscriptos.erase(it);
}
std::string Docente::listarInscripciones() const {
  std::string aux;
  aux.append(materia.toString());
  for (auto &&alumno : alumnosInscriptos) {
    aux.append(materia.listarAlumnosInscriptos());
  }
  return aux;
}
void Docente::comprobarId(IdMateria id) {
  if (!this->materia.tieneElId(id)) {
    std::stringstream aux;
    aux << "No tiene permisos para operar sobre " << id.getCodigo()
        << ", curso " << id.getCurso() << ".";
    throw MovimientoInvalido(aux.str());
  }
}
std::string Docente::toString() const {
  return "";
}

