#ifndef TP3_APP_DOCENTE_H
#define TP3_APP_DOCENTE_H

#include <vector>
#include <string>
#include "server_IdUsuario.h"
#include "server_Usuario.h"
#include "server_IdMateria.h"
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
  ~Docente();
};

#endif //TP3_APP_DOCENTE_H
