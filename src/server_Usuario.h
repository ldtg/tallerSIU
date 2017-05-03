#ifndef TP3_APP_USUARIO_H
#define TP3_APP_USUARIO_H
#include <string>
#include "server_IdUsuario.h"
#include "server_IdMateria.h"
#include "server_Materia.h"
class Usuario { //Clase abstracta representa un usuario
 protected:
  IdUsuario id;
  std::string nombre;
  Usuario(IdUsuario id, std::string nombre);
 public:
  // Inscribe al alumno en una materia
  virtual void inscribir(Usuario &alumno, Materia *materia)=0;
  // desinscribe al alumno en una materia
  virtual void desInscribir(Usuario &alumno, Materia *materia)=0;
  // lista las inscripciones del usuario
  virtual std::string listarInscripciones()const =0;
  // retorna el id
  virtual IdUsuario getId();
  virtual ~Usuario();
  bool operator==(const Usuario& otro) const;
};

#endif //TP3_APP_USUARIO_H
