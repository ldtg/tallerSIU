#include <string>
#include "server_ComandoDesinscribir.h"
ComandoDesinscribir::ComandoDesinscribir(SIUGuaramini &siu,
                                   const IdUsuario &idej,
                                   const IdUsuario &idAlumno,
                                   const IdMateria &idMateria) :
    Comando(siu), idEjecutante(idej), idAlumno(idAlumno), materia(idMateria){}
std::string ComandoDesinscribir::ejecutar() {
  return this->siu.desinscribir(idEjecutante, idAlumno, materia);
}
std::string ComandoDesinscribir::toString() const {
  return "desinscribir";
}
ComandoDesinscribir::~ComandoDesinscribir() {}
