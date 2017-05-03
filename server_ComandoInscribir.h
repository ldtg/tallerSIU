#ifndef TP3_APP_COMANDOINSC_H
#define TP3_APP_COMANDOINSC_H
#include <string>
#include "server_Comando.h"
class ComandoInscribir : public Comando {
 private:
  IdUsuario idEjecutante;
  IdUsuario idAlumno;
  IdMateria materia;
 public:
  ComandoInscribir(SIUGuaramini &siu, const IdUsuario &idej, const
  IdUsuario &idAlumno, const IdMateria &idMateria);
  virtual std::string ejecutar() override;
  virtual std::string toString() const;
  ~ComandoInscribir();
};

#endif //TP3_APP_COMANDOINSC_H
