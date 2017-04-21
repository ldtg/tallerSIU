#ifndef TP3_APP_MATERIA_H
#define TP3_APP_MATERIA_H

#include <map>
#include <vector>
#include <string>
#include "IdMateria.h"
#include "IdUsuario.h"
class Materia {
 private:
  IdMateria id;
  unsigned short cupos;
  std::vector<IdUsuario> alumnosInscriptos;
  IdUsuario docente;
  std::string descripcion;
 public:
  explicit Materia(IdMateria id, unsigned short cupos, IdUsuario docente,
                   std::string descripcion);
  void inscribirAlumno(IdUsuario alumno);
  void desinscribirAlumno(IdUsuario alumno);
  bool tieneAlDocente(IdUsuario docente);
  std::string listarAlumnosInscriptos();
};

#endif //TP3_APP_MATERIA_H
