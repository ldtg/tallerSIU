#include <algorithm>
#include "Materia.h"
Materia::Materia(IdMateria id,
                 unsigned short cupos,
                 IdUsuario docente,
                 std::string descripcion) : id(id), cupos(cupos), docente
    (docente), descripcion(descripcion) {}
void Materia::inscribirAlumno(IdUsuario alumno) {
  if(std::find(this->alumnosInscriptos.begin(), this->alumnosInscriptos.end()
      , alumno) == this->alumnosInscriptos.end()){
    this->cupos--;
    this->alumnosInscriptos.push_back(alumno);
  }
}
void Materia::desinscribirAlumno(IdUsuario alumno) {
  std::vector<IdUsuario>::iterator it;
  it = std::find(this->alumnosInscriptos.begin(), this->alumnosInscriptos.end()
      , alumno);
  if(it != this->alumnosInscriptos.end()){
    this->cupos++;
    this->alumnosInscriptos.erase(it);
  }
}
