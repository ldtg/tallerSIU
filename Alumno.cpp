#include <algorithm>
#include "Alumno.h"
Alumno::Alumno(std::string nombre, unsigned short num) : id(nombre,
                                                            num,
                                                            alumno) {}
void Alumno::inscribir(IdUsuario usuarioaInscribir, IdMateria materia) {
  if (std::find(this->materiasInscripto.begin(),
                this->materiasInscripto.end(),
                materia) == this->materiasInscripto.end()
      && this->id == usuarioaInscribir) {
      
  }
}
