#include <algorithm>
#include <sstream>
#include "Alumno.h"
#include "MovimientoInvalido.h"
Alumno::Alumno(int num, std::string nombre) : Usuario(IdUsuario
                                                          (num,
                                                           alumno),
                                                      nombre) {}
void Alumno::inscribir(Usuario &usuarioaInscribir, Materia *materia) {
  materia->inscribirAlumno(this->getId(), this->nombre);
  this->materiasInscripto.push_back(materia);
}

void Alumno::desInscribir(Usuario &usuarioaDesinscribir,
                          Materia *materia) {
  materia->desinscribirAlumno(this->getId());
  std::vector<Materia *>::iterator it;
  it = std::find(this->materiasInscripto.begin(),
                 this->materiasInscripto.end(),
                 materia);
  this->materiasInscripto.erase(it);

}

std::string Alumno::listarInscripciones() const {
  std::string aux;
  for (auto &&materia : materiasInscripto) {
    aux.append(materia->toString());
  }
  return aux;
}
std::string Alumno::toString() const {
  std::stringstream aux;
  aux << id.toString() << " " << this->nombre << std::endl;
  return aux.str();
}
