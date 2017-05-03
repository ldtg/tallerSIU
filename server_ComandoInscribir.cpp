#include <string>
#include "server_ComandoInscribir.h"
ComandoInscribir::ComandoInscribir(SIUGuaramini &siu,
                                     const IdUsuario &idej,
                                     const IdUsuario &idAlumno,
                                     const IdMateria &idMateria) :
Comando(siu), idEjecutante(idej), idAlumno(idAlumno), materia(idMateria){}
std::string ComandoInscribir::ejecutar() {
  return this->siu.inscribir(idEjecutante, idAlumno, materia);
}
std::string ComandoInscribir::toString() const {
  return "inscribir";
}
ComandoInscribir::~ComandoInscribir() {}
