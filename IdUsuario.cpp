#include "IdUsuario.h"
IdUsuario::IdUsuario(std::string nombre,
                     unsigned short num,
                     TipoDeUsuario tipoDeUsuario)
    : nombre(nombre), num(num), tipoDeUsuario(tipoDeUsuario) {}
bool IdUsuario::operator==(const IdUsuario &otro) {
  return this->tipoDeUsuario == otro.tipoDeUsuario && this->nombre == otro
      .nombre && this->num == otro.num;
}
bool IdUsuario::operator<(const IdUsuario &otro) {
  return this->tipoDeUsuario < otro.tipoDeUsuario || (this->tipoDeUsuario ==
      otro.tipoDeUsuario && this->nombre < otro.nombre) ||
      (this->tipoDeUsuario == otro.tipoDeUsuario && this->nombre == otro
          .nombre && this->num < otro.num);
}
