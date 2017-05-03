#ifndef TP3_APP_MATERIA_H
#define TP3_APP_MATERIA_H

#include <map>
#include <vector>
#include <string>
#include "server_IdMateria.h"
#include "server_IdUsuario.h"
class Materia {
 private:
  IdMateria id;
  int vacantes;
  std::map<IdUsuario, std::string> alumnosInscriptos;
  std::string descripcion;
  std::string nombreDocente;
  IdUsuario idDocente;
  void comprobarVacantes();

 public:
  explicit Materia(const IdMateria &id, int vacantes,
                   const std::string &descripcion, const IdUsuario &idDoc);
  //Inscribe al alumno en la materia
  void inscribirAlumno(const IdUsuario &alumno, const std::string &nombre);
  //Desinscribe al alumno en la materia
  void desinscribirAlumno(const IdUsuario &alumno);
  //Retora true si la materia tiene el id
  bool tieneElId(const IdMateria &id) const;
  // Cambia el nombre del docente a cargo, necesario para leer separadamente
  // usuarios de materias y que la materia pueda imprimir su informacion en
  // tostring sin guardar referencia al docente
  void setNombreDocente(const std::string &nombreDocente);
  // Retorna string que representa a la materia con los datos para imprimirlo
  std::string toString() const;
  // Retorna string que representa a la materia con los datos para imprimirlo
  // mas la cantidad de vacantes
  std::string toStringConVacantes() const;
  // Lista los alumnos inscriptos
  std::string listarAlumnosInscriptos() const;
  // Retorna true si tiene al docente idDoc
  bool tieneAlDocente(const IdUsuario &idDoc) const;
  // Retorna el id
  IdMateria getId() const;
  ~Materia();
};

#endif //TP3_APP_MATERIA_H
