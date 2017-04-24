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
  IdUsuario idDocente;
  int vacantes;
  std::map<IdUsuario, std::string> alumnosInscriptos;
  std::string nombreDocente;
  std::string descripcion;
 public:
  explicit Materia(IdMateria id, int vacantes,
                   std::string descripcion, IdUsuario idDoc);
  void inscribirAlumno(IdUsuario alumno, std::string nombre);
  void desinscribirAlumno(IdUsuario alumno);
  bool tieneElId(IdMateria id);
  void setNombreDocente(std::string nombreDocente);
  std::string toString() const;
  std::string toStringConVacantes();
  std::string listarAlumnosInscriptos();
  bool tieneAlDocente(IdUsuario idDoc);
  IdMateria getId();
};

#endif //TP3_APP_MATERIA_H
