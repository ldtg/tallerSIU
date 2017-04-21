#ifndef TP3_APP_DOCENTE_H
#define TP3_APP_DOCENTE_H

#include <vector>
#include <string>
#include "IdUsuario.h"
#include "Usuario.h"
#include "IdMateria.h"
class Docente : public Usuario{
 private:
  IdMateria materia;
  std::vector<IdUsuario> alumnosInscriptos;
 public:
  virtual std::string listarInscripciones();
  virtual void inscribir(IdUsuario usuarioaInscribir, IdMateria materia);
  virtual void desInscribir(IdUsuario usuarioaDesinscribir, IdMateria
  materia);
};

#endif //TP3_APP_DOCENTE_H
