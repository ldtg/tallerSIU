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
  //std::map<IdUsuario, Alumno> alumnos;
  //std::map<IdUsuario, Docente> docentes;
  std::map<IdUsuario, Usuario> usuarios;
 public:
  //SIU(files)
  //void inscribir(IdUsuario idAlumno, IdMateria idMateria);
  void inscribir(IdUsuario idInscribidor, IdUsuario idAlumno, IdMateria
  idMateria);
 // void desinscribir(IdUsuario idAlumno, IdMateria idMateria);
  void desinscribir(IdUsuario idDesinscribidor, IdUsuario idAlumno, IdMateria
  idMateria);
  std::string listarMaterias();
  std::string listarInscripciones(IdUsuario usuario);
};

#endif //TP3_APP_SIU_H
