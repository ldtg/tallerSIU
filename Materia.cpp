#include <algorithm>
#include <sstream>
#include <string>
#include "Materia.h"
#include "MovimientoInvalido.h"
Materia::Materia(IdMateria id,
                 int vacantes,
                 std::string descripcion, IdUsuario idDoc)
    : id(id), vacantes(vacantes), descripcion(descripcion), idDocente(idDoc) {}

void Materia::inscribirAlumno(IdUsuario alumno, std::string nombre) {
  if (this->vacantes < 1) {
    std::stringstream aux;
    aux << "El curso " << this->id.getCurso() << "de la materia " << this->id
        .getCodigo() << " no posee más vacantes." << std::endl;
    throw MovimientoInvalido(aux.str());
  }
  if (alumnosInscriptos.find(alumno) == this->alumnosInscriptos.end()) {
    this->vacantes--;
    this->alumnosInscriptos.emplace(alumno, nombre);
  } else
    throw MovimientoInvalido("Inscripción ya realizada. \n");
}

void Materia::desinscribirAlumno(IdUsuario alumno) {
  std::map<IdUsuario, std::string>::iterator it;
  it = this->alumnosInscriptos.find(alumno);
  if (it != this->alumnosInscriptos.end()) {
    this->vacantes++;
    this->alumnosInscriptos.erase(it);
  } else
    throw MovimientoInvalido("Desincripción Inválida. \n");
}

std::string Materia::toString() const {
  std::stringstream aux;
  aux << id.getCodigo() << " - " << this->descripcion << ", Curso " << id
      .getCurso() << " " << nombreDocente << "." << std::endl;
  return aux.str();
}
bool Materia::tieneElId(IdMateria id) {
  return this->id == id;
}

std::string Materia::toStringConVacantes() {
  std::string aux;
  aux = toString();
  aux.resize(aux.size() - 2);
  aux.append(", " + std::to_string(this->vacantes) + " vacantes. \n");
  return aux;
}
std::string Materia::listarAlumnosInscriptos() {
  std::stringstream aux;
  if (!alumnosInscriptos.empty()) {
    for (auto &&alumno : alumnosInscriptos) {
      aux << alumno.first.getNum() << " " << alumno.second << std::endl;
    }
  }
  return aux.str();
}
void Materia::setNombreDocente(std::string nombreDocente) {
  this->nombreDocente = nombreDocente;
}
bool Materia::tieneAlDocente(IdUsuario idDoc) {
  return this->idDocente == idDoc;
}
IdMateria Materia::getId() {
  return this->id;
}
