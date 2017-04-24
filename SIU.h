#ifndef TP3_APP_SIU_H
#define TP3_APP_SIU_H
#include <string>
#include "IdMateria.h"
#include "Materia.h"
#include "Alumno.h"
#include "Docente.h"
class SIU {
 private:
  std::map<IdMateria, Materia> materias;
  std::map<IdUsuario, Usuario*> usuarios;
  void parsearMaterias(std::string matf);
  void parsearUsuarios(std::string usrf);
  IdMateria buscarId(IdUsuario usuario);
  Usuario *obtenerUsuario(IdUsuario usuario);
  Alumno &validarAlumno(IdUsuario usuario);
 public:
  SIU(std::string usuariosFileName, std::string materiasFileName);
  std::string inscribir(IdUsuario idInscribidor, IdUsuario idAlumno, IdMateria
  idMateria);
  std::string desinscribir(IdUsuario idDesinscribidor, IdUsuario idAlumno, IdMateria
  idMateria);
  std::string listarMaterias();
  std::string listarInscripciones(IdUsuario usuario);
  ~SIU();

  Materia *obtenerMateria(IdMateria materia);
};

#endif //TP3_APP_SIU_H
