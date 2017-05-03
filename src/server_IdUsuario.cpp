#include <string>
#include <sstream>
#include "server_IdUsuario.h"
IdUsuario::IdUsuario() {}
IdUsuario::IdUsuario(int num, TipoDeUsuario tipoDeUsuario)
    : num(num), tipoDeUsuario(tipoDeUsuario) {}
IdUsuario::IdUsuario(const std::string &idstr) {
  if (idstr == "admin") {
    num = 0;
    this->tipoDeUsuario = ADMIN;
  } else {
    std::stringstream auxss(idstr);
    std::string tipoDeUsuario;
    std::string num;
    getline(auxss, tipoDeUsuario, '-');
    getline(auxss, num, '-');
    if (tipoDeUsuario == "alumno")
      this->tipoDeUsuario = ALUMNO;
    else if (tipoDeUsuario == "docente")
      this->tipoDeUsuario = DOCENTE;
    else
      throw std::runtime_error(tipoDeUsuario + " es un tipo de usuario "
          "inválido.\n");
    this->num = std::stoi(num);
  }
}
std::string IdUsuario::toString() const {
  std::string aux;
  if (tipoDeUsuario == ALUMNO)
    aux = "alumno " + std::to_string(this->num);
  if (tipoDeUsuario == DOCENTE)
    aux = "docente " + std::to_string(this->num);
  if (tipoDeUsuario == ADMIN)
    aux = "admin";
  return aux;
}
int IdUsuario::getNum() const {
  return this->num;
}
std::string IdUsuario::tipoDeUsuarioToStr() const{
  std::string aux;
  if (tipoDeUsuario == ALUMNO)
    aux = "alumno ";
  if (tipoDeUsuario == DOCENTE)
    aux = "docente ";
  if (tipoDeUsuario == ADMIN)
    aux = "admin ";
  return aux;
}
TipoDeUsuario IdUsuario::getTipoDeUsuario() const {
  return this->tipoDeUsuario;
}
IdUsuario::~IdUsuario() {}
bool IdUsuario::operator!=(const IdUsuario &otro) const {
  return !this->operator==(otro);
}
bool IdUsuario::operator==(const IdUsuario &otro) const {
  return this->tipoDeUsuario == otro.tipoDeUsuario && this->num == otro.num;
}
bool IdUsuario::operator<(const IdUsuario &otro) const {
  return this->tipoDeUsuario < otro.tipoDeUsuario ||
      (this->tipoDeUsuario == otro.tipoDeUsuario && this->num < otro.num);
}
