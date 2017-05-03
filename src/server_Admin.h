#ifndef TP3_APP_ADMIN_H
#define TP3_APP_ADMIN_H
#include <string>
#include <map>
#include "server_Usuario.h"
class Admin : public Usuario {
 private:
  std::map<IdMateria, Materia> &materias;
  std::map<IdUsuario, Usuario *> &usuarios;
 public:
  explicit Admin(int num, std::string nombre,
                 std::map<IdMateria, Materia> &materias,
                 std::map<IdUsuario, Usuario *> &usuarios);
  virtual void inscribir(Usuario &usuarioaInscribir, Materia *materia)
  override;
  virtual void desInscribir(Usuario &usuarioaDesinscribir, Materia *
  materia) override;
  virtual std::string listarInscripciones() const override;
  ~Admin();
};

#endif //TP3_APP_ADMIN_H
