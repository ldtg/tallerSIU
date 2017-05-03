#ifndef TP3_APP_COMANDODESINSCRIBIR_H
#define TP3_APP_COMANDODESINSCRIBIR_H
#include <string>
#include "server_Comando.h"
class ComandoDesinscribir : public Comando{
 private:
  IdUsuario idEjecutante;
  IdUsuario idAlumno;
  IdMateria materia;
 public:
  ComandoDesinscribir(SIUGuaramini &siu, const IdUsuario &idej, const
  IdUsuario &idAlumno, const IdMateria &idMateria);
  virtual std::string toString() const;
  virtual std::string ejecutar() override;
  ~ComandoDesinscribir();
};

#endif //TP3_APP_COMANDODESINSCRIBIR_H
