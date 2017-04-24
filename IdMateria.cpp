#include "IdMateria.h"
IdMateria::IdMateria(int codigo, int curso) :
    codigo(codigo), curso(curso){}
bool IdMateria::operator==(const IdMateria &otro) const{
  return this->codigo == otro.codigo && this->curso == otro.curso;
}
bool IdMateria::operator<(const IdMateria &otro) const{
  return (this->codigo < otro.codigo) || (this->codigo == otro.codigo &&
  this->curso < otro.curso);
}
int IdMateria::getCodigo() const{
  return codigo;
}
int IdMateria::getCurso() const{
  return curso;
}

