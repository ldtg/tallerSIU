#include <vector>
#include <sstream>
#include <string>
#include "server_Comando.h"
#include "server_ComandoListarMaterias.h"
#include "server_ComandoListarInscripciones.h"
#include "server_ComandoInscribir.h"
#include "server_ComandoDesinscribir.h"
Comando::Comando(SIUGuaramini &siu) : siu(siu) {}
Comando::~Comando() {}
Comando *Comando::makeComando(const std::string &cmdstr, SIUGuaramini &siu,
                              const IdUsuario &id) {
  if (cmdstr == "lm") {
    return new ComandoListarMaterias(siu);
  } else if (cmdstr == "li") {
    return new ComandoListarInscripciones(siu, id);
  } else {
    return makeInsDes(cmdstr, siu, id);
  }
}
Comando *Comando::makeInsDes(const std::string &cmdstr,
                             SIUGuaramini &siu,
                             const IdUsuario &id) {
  std::vector<std::string> tokens = obtenerTokens(cmdstr);
  std::string codComando = tokens[0];
  if (codComando == "in") {
    if (tokens.size() == 3 && id.getTipoDeUsuario() == ALUMNO)
      return new ComandoInscribir(siu, id, id, IdMateria(std::stoi
                                                             (tokens[1]),
                                                         std::stoi
                                                             (tokens[2])));
    if (tokens.size() == 4 && id.getTipoDeUsuario() != ALUMNO)
      return new ComandoInscribir(siu,
                                  id,
                                  IdUsuario(std::stoi(tokens[1]), ALUMNO),
                                  IdMateria(std::stoi(tokens[2]),
                                            std::stoi(tokens[3])));
  } else if (codComando == "de") {
    if (tokens.size() == 3 && id.getTipoDeUsuario() == ALUMNO)
      return new ComandoDesinscribir(siu, id, id, IdMateria(std::stoi
                                                                (tokens[1]),
                                                            std::stoi
                                                                (tokens[2])));
    if (tokens.size() == 4 && id.getTipoDeUsuario() != ALUMNO)
      return new ComandoDesinscribir(siu,
                                     id,
                                     IdUsuario(std::stoi(tokens[1]), ALUMNO),
                                     IdMateria(std::stoi(tokens[2]),
                                               std::stoi(tokens[3])));
  }
  throw std::runtime_error("Comando inválido\n");
}
std::vector<std::string> Comando::obtenerTokens(const std::string &cmdstr) {
  std::string aux;
  std::vector<std::string> tokens;
  std::istringstream auxss(cmdstr);
  while (getline(auxss, aux, '-'))
    tokens.push_back(aux);
  if (tokens.size() < 3 || !sonNumeros(tokens))
    throw std::runtime_error("Comando inválido\n");
  return tokens;
}
bool Comando::sonNumeros(const std::vector<std::string> &tokens) {
  // tiene que saltear el primer tok porque es el cod comando
  for (auto iterator = tokens.begin() + 1; iterator != tokens.end();
       ++iterator) {
    std::string token = *iterator;
    std::string::const_iterator it = token.begin();
    while (it != token.end() && isdigit(*it)) ++it;
    if (it != token.end())
      return false;
  }
  return true;
}
