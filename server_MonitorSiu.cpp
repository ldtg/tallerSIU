#include <string>
#include "server_MonitorSiu.h"
#include "server_Lock.h"
MonitorSiu::MonitorSiu(RealSIU &siu) : siu(siu) {
}
std::string MonitorSiu::inscribir(const IdUsuario &idInscribidor,
                                  const IdUsuario &idAlumno,
                                  const IdMateria &idMateria) {
  Lock lock(this->mutex);
  return this->siu.inscribir(idInscribidor, idAlumno, idMateria);
}
std::string MonitorSiu::desinscribir(const IdUsuario &idDesinscribidor,
                                     const IdUsuario &idAlumno,
                                     const IdMateria &idMateria) {
  Lock lock(this->mutex);
  return this->siu.desinscribir(idDesinscribidor, idAlumno, idMateria);
}
std::string MonitorSiu::listarMaterias() const{
  return this->siu.listarMaterias();
}
std::string MonitorSiu::listarInscripciones(const IdUsuario &usuario)
const{
  return this->siu.listarInscripciones(usuario);
}
bool MonitorSiu::existeElUsuario(const IdUsuario &id) const {
  return this->siu.existeElUsuario(id);
}
MonitorSiu::~MonitorSiu() {}
