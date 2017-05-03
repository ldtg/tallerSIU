#include <algorithm>
#include <sstream>
#include <string>
#include "server_Docente.h"
#include "server_MovimientoInvalido.h"
Docente::Docente(int num, std::string nombre, Materia &materia) :
    Usuario(IdUsuario(num, DOCENTE), nombre), materia(materia) {
  materia.setNombreDocente(nombre);
}

void Docente::inscribir(Usuario &usuarioaInscribir, Materia *materia) {
  comprobarId(materia->getId());
  usuarioaInscribir.inscribir(usuarioaInscribir, materia);
}
void Docente::desInscribir(Usuario &usuarioaDesinscribir,
                           Materia *materia) {
  comprobarId(materia->getId());
  usuarioaDesinscribir.desInscribir(usuarioaDesinscribir, materia);
}
std::string Docente::listarInscripciones() const {
  std::string aux;
  aux.append(materia.toString());
  aux.append(materia.listarAlumnosInscriptos());
  return aux;
}
void Docente::comprobarId(IdMateria id) {
  if (!this->materia.tieneElId(id)) {
    std::stringstream aux;
    aux << "No tiene permisos para operar sobre " << id.getCodigo()
        << ", curso " << id.getCurso() << "." << std::endl;
    throw MovimientoInvalido(aux.str());
  }
}
Docente::~Docente() {}

