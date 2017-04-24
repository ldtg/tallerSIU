#include <iostream>
#include "SIU.h"
int main() {
  SIU siu("usuarios.txt","materias.txt");
  std::cout << siu.listarMaterias();
  std::cout << siu.inscribir(IdUsuario(1,alumno),IdUsuario(1,alumno),
                             IdMateria(1003,5));
  std::cout << siu.inscribir(IdUsuario(1,alumno),IdUsuario(1,alumno),IdMateria(1003,1));
  std::cout << siu.desinscribir(IdUsuario(4,docente),IdUsuario(1,alumno),
                              IdMateria(1003,1));
  std::cout << siu.inscribir(IdUsuario(12,docente),IdUsuario(1,alumno),
                             IdMateria(1009,1));
  std::cout << siu.listarInscripciones(IdUsuario(12,docente));
  std::cout << siu.listarInscripciones(IdUsuario(1,alumno));
  return 0;
}