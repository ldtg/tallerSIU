#include <string>
#include "server_Usuario.h"
Usuario::Usuario(IdUsuario id, std::string nombre) : id(id), nombre(nombre){}
IdUsuario Usuario::getId() {
  return id;
}
bool Usuario::operator==(const Usuario &otro) const {
  return this->id == otro.id;
}
Usuario::~Usuario() {}
