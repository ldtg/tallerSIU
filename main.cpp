#include <iostream>
#include "SIU.h"
#include "Socket.h"
int main() {
  /*SIU siu("usuarios.txt","materias.txt");
  std::cout << siu.listarInscripciones(IdUsuario(0,ADMIN));
  std::cout << siu.inscribir(IdUsuario(1,ALUMNO),IdUsuario(1,ALUMNO),
                             IdMateria(1003,5));
  std::cout << siu.inscribir(IdUsuario(1,ALUMNO),IdUsuario(1,ALUMNO),IdMateria(1003,1));
  std::cout << siu.desinscribir(IdUsuario(4,DOCENTE),IdUsuario(1,ALUMNO),
                              IdMateria(1003,1));
  std::cout << siu.inscribir(IdUsuario(4,DOCENTE),IdUsuario(1,ALUMNO),
                             IdMateria(1003,1));
  std::cout << siu.inscribir(IdUsuario(0,ADMIN),IdUsuario(2,ALUMNO),IdMateria
      (1009,1));
  std::cout << siu.listarInscripciones(IdUsuario(4,DOCENTE));
  std::cout << siu.listarInscripciones(IdUsuario(2,ALUMNO));*/
  Socket<int> socket;
  socket.bindandlisten("27015");
  return 0;
}