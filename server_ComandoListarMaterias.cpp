#include <string>
#include "server_ComandoListarMaterias.h"
ComandoListarMaterias::ComandoListarMaterias(SIUGuaramini &siu) : Comando(siu) {
}
std::string ComandoListarMaterias::ejecutar() {
  return siu.listarMaterias();
}
std::string ComandoListarMaterias::toString() const {
  return "listarMaterias";
}
ComandoListarMaterias::~ComandoListarMaterias() {}
