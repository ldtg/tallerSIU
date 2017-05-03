#ifndef TP3_APP_COMANDOLISTARINSCRIPCIONES_H
#define TP3_APP_COMANDOLISTARINSCRIPCIONES_H
#include <string>
#include "server_Comando.h"
class ComandoListarInscripciones : public Comando{
 private:
  IdUsuario id;
 public:
  ComandoListarInscripciones(SIUGuaramini &siu, const IdUsuario& id);
  virtual std::string ejecutar() override;
  virtual std::string toString() const;
  ~ComandoListarInscripciones();
};

#endif //TP3_APP_COMANDOLISTARINSCRIPCIONES_H
