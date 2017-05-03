#include <string>
#include "server_ComandoListarInscripciones.h"
ComandoListarInscripciones::ComandoListarInscripciones(SIUGuaramini &siu,
                                                       const IdUsuario &id) :
    Comando(siu), id(id){
}
std::string ComandoListarInscripciones::ejecutar() {
  return siu.listarInscripciones(id);
}
std::string ComandoListarInscripciones::toString() const {
  return "listarInscripciones";
}
ComandoListarInscripciones::~ComandoListarInscripciones() {}
