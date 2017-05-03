#ifndef TP3_APP_ALUMNO_H
#define TP3_APP_ALUMNO_H

#include <vector>
#include <memory>
#include <string>
#include "server_Usuario.h"
#include "server_IdMateria.h"
#include "server_Materia.h"
class Alumno : public Usuario {
 private:
  std::vector<Materia*> materiasInscripto;
 public:
  explicit Alumno(int num, std::string nombre);
  virtual void inscribir(Usuario &usuarioaInscribir,Materia *materia)
  override;
  virtual void desInscribir(Usuario &usuarioaDesinscribir,Materia
  *materia) override;
  virtual std::string listarInscripciones()const override;
  ~Alumno();
};

#endif //TP3_APP_ALUMNO_H
