#ifndef TP3_APP_DOCENTE_H
#define TP3_APP_DOCENTE_H

#include <vector>
#include <string>
#include "IdUsuario.h"
#include "Usuario.h"
#include "IdMateria.h"
class Docente : public Usuario {
 private:
  Materia &materia;
  void comprobarId(IdMateria id);
 public:
  Docente(int num, std::string nombre, Materia &materia);
  virtual void inscribir(Usuario &usuarioaInscribir, Materia *materia)
  override;
  virtual void desInscribir(Usuario &usuarioaDesinscribir, Materia *
  materia) override;
  virtual std::string listarInscripciones() const override;
  virtual std::string toString() const override;
};

#endif //TP3_APP_DOCENTE_H
