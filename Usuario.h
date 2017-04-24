#ifndef TP3_APP_USUARIO_H
#define TP3_APP_USUARIO_H
#include <string>
#include "IdUsuario.h"
#include "IdMateria.h"
#include "Materia.h"
class Usuario {
 protected:
  IdUsuario id;
  std::string nombre;
  Usuario(IdUsuario id, std::string nombre);
 public:
  virtual void inscribir(Usuario &alumno, Materia *materia)=0;
  virtual void desInscribir(Usuario &usuarioaDesinscribir, Materia *materia)=0;
  virtual std::string listarInscripciones()const =0;
  virtual std::string toString() const = 0;
  virtual IdUsuario getId();
  bool operator==(const Usuario& otro) const;
};

#endif //TP3_APP_USUARIO_H
