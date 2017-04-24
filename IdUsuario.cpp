#include <string>
#include <sstream>
#include "IdUsuario.h"
IdUsuario::IdUsuario(int num,
                     TipoDeUsuario tipoDeUsuario)
    : num(num), tipoDeUsuario(tipoDeUsuario) {}
bool IdUsuario::operator==(const IdUsuario &otro) const{
  return this->tipoDeUsuario == otro.tipoDeUsuario && this->num == otro.num;
}
bool IdUsuario::operator<(const IdUsuario &otro) const{
  return this->tipoDeUsuario < otro.tipoDeUsuario ||
      (this->tipoDeUsuario == otro.tipoDeUsuario && this->num < otro.num);
}
std::string IdUsuario::toString() const{
  std::string aux;
  if(tipoDeUsuario==alumno)
    aux = "alumno " +  std::to_string(this->num);
  if(tipoDeUsuario==docente)
    aux = "docente " +  std::to_string(this->num);
  if(tipoDeUsuario==admin)
    aux = "admin " +  std::to_string(this->num);
  return aux;
}

int IdUsuario::getNum() const{
  return this->num;
}
bool IdUsuario::operator!=(const IdUsuario &otro) const {
  return !this->operator==(otro);
}
