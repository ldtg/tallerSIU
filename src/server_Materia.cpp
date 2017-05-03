#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include "server_Materia.h"
#include "server_MovimientoInvalido.h"
Materia::Materia(const IdMateria &id, int vacantes,
                 const std::string &descripcion, const IdUsuario &idDoc)
    : id(id), vacantes(vacantes), descripcion(descripcion), idDocente(idDoc) {}

void Materia::inscribirAlumno(const IdUsuario &alumno, const std::string
&nombre) {
  if (alumnosInscriptos.find(alumno) == this->alumnosInscriptos.end()) {
    comprobarVacantes();
    this->vacantes--;
    this->alumnosInscriptos.emplace(alumno, nombre);
  } else {
    throw MovimientoInvalido("Inscripción ya realizada.\n");
  }
}
void Materia::desinscribirAlumno(const IdUsuario &alumno) {
  std::map<IdUsuario, std::string>::iterator it;
  it = this->alumnosInscriptos.find(alumno);
  if (it != this->alumnosInscriptos.end()) {
    this->vacantes++;
    this->alumnosInscriptos.erase(it);
  } else {
    throw MovimientoInvalido("Desinscripción inválida.\n");
  }
}
std::string Materia::toString() const {
  std::stringstream aux;
  aux << id.getCodigo() << " - " << this->descripcion << ", Curso " << id
      .getCurso() << ", " << nombreDocente << "." << std::endl;
  return aux.str();
}
bool Materia::tieneElId(const IdMateria &id) const {
  return this->id == id;
}
std::string Materia::toStringConVacantes() const {
  std::string aux;
  aux = toString();
  aux.resize(aux.size() - 2);
  aux.append(", " + std::to_string(this->vacantes) + " vacantes.\n");
  return aux;
}
std::string Materia::listarAlumnosInscriptos() const {
  std::stringstream aux;
  for (auto &alumno : alumnosInscriptos) {
    aux << alumno.first.getNum() << " " << alumno.second << std::endl;
  }
  return aux.str();
}
void Materia::setNombreDocente(const std::string &nombreDocente) {
  this->nombreDocente = nombreDocente;
}
bool Materia::tieneAlDocente(const IdUsuario &idDoc) const {
  return this->idDocente == idDoc;
}
IdMateria Materia::getId() const {
  return this->id;
}
void Materia::comprobarVacantes() {
  if (this->vacantes < 1) {
    std::stringstream aux;
    aux << "El curso " << this->id.getCurso() << " de la materia " << this->id
        .getCodigo() << " no posee mas vacantes." << std::endl;
    throw MovimientoInvalido(aux.str());
  }
}
Materia::~Materia() {}
