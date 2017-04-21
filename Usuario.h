#ifndef TP3_APP_USUARIO_H
#define TP3_APP_USUARIO_H
#include <string>
#include "IdUsuario.h"
#include "IdMateria.h"
class Usuario {
 protected:
  IdUsuario id;
 public:
  virtual std::string listarInscripciones() = 0;
  virtual void inscribir(IdUsuario usuarioaInscribir, IdMateria materia) = 0;
  virtual void desInscribir(IdUsuario usuarioaDesinscribir, IdMateria
  materia) = 0;
};

#endif //TP3_APP_USUARIO_H
