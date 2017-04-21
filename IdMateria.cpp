#include "IdMateria.h"
IdMateria::IdMateria(unsigned short codigo, unsigned short curso) :
    codigo(codigo), curso(curso) {}
bool IdMateria::operator==(const IdMateria &otro) {
  return this->codigo == otro.codigo && this->curso == otro.curso;
}
bool IdMateria::operator<(const IdMateria &otro) {
  return (this->codigo < otro.codigo) || (this->codigo == otro.codigo &&
  this->curso < otro.curso);
}