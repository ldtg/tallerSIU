#ifndef TP3_APP_ADMIN_H
#define TP3_APP_ADMIN_H

#include "Usuario.h"
class Admin : public Usuario{
 public:
  virtual std::string listarInscripciones();
  virtual void inscribir(IdUsuario usuarioaInscribir, IdMateria materia);
  virtual void desInscribir(IdUsuario usuarioaDesinscribir, IdMateria
  materia);
};

#endif //TP3_APP_ADMIN_H
