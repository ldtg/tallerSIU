#ifndef TP3_APP_ALUMNO_H
#define TP3_APP_ALUMNO_H

#include <vector>
#include "Usuario.h"
#include "IdMateria.h"
class Alumno : public Usuario {
 private:
  std::vector<IdMateria> materiasInscripto;
 public:
  Alumno(std::string nombre, unsigned short num);
  virtual void inscribir(IdUsuario usuarioaInscribir, IdMateria materia);
  virtual void desInscribir(IdUsuario usuarioaDesinscribir, IdMateria
  materia);
  virtual std::string listarInscripciones();
};

#endif //TP3_APP_ALUMNO_H
