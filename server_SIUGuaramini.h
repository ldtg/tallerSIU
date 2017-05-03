#ifndef TP3_APP_SIUGUARAMINI_H
#define TP3_APP_SIUGUARAMINI_H
#include <string>
#include "server_IdUsuario.h"
#include "server_IdMateria.h"
class SIUGuaramini { //Interfaz compartida entre monitorSIU y realSIU
 public:
  // El usuario inscribidor, inscribe al alumno idALumno en la materia idMateria
  // retorna la respuesta del sistema como string
  virtual std::string inscribir(const IdUsuario &idInscribidor, const IdUsuario
  &idAlumno, const IdMateria &idMateria) = 0;
  // El usuario desinscribidor, desinscribe al alumno idALumno
  // de la materia idMateria retorna la respuesta del sistema como string
  virtual std::string desinscribir(const IdUsuario &idDesinscribidor, const
  IdUsuario &idAlumno, const IdMateria &idMateria) = 0;
  // Lista las materias en el sistema
  virtual std::string listarMaterias() const = 0;
  // Lista las inscripciones para el usuario.
  virtual std::string listarInscripciones(const IdUsuario &usuario) const = 0;
  // Retorna true si el usuario existe en el sistema
  virtual bool existeElUsuario(const IdUsuario &id) const = 0;
};

#endif //TP3_APP_SIUGUARAMINI_H
