#ifndef TP3_APP_COMANDOLISTARMATERIAS_H
#define TP3_APP_COMANDOLISTARMATERIAS_H
#include <string>
#include "server_Comando.h"
class ComandoListarMaterias : public Comando{
 public:
  explicit ComandoListarMaterias(SIUGuaramini &siu);
  virtual std::string ejecutar();
  virtual std::string toString() const;
  ~ComandoListarMaterias();
};

#endif //TP3_APP_COMANDOLISTARMATERIAS_H
