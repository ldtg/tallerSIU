#ifndef TP3_APP_SEVER_LOGGER_H
#define TP3_APP_SEVER_LOGGER_H

#include <iosfwd>
#include <ostream>
#include <string>
#include "server_IdUsuario.h"
class Logger {
 private:
  std::ostream &output;
 public:
  //Crea el logger con std::cerr como salida
  Logger();
  // Crea el logger con out como salida
  explicit Logger(std::ostream &out);
  // Imprime en la salida el mensaje para un cliente desconectado
  void clienteDesconectado(const IdUsuario &id);
  // Imprime en la salida el mensaje para un cliente conectado
  void clienteConectado(const IdUsuario &id);
  // Imprime en la salida el mensaje para un cliente invalido
  void clienteInvalido(const IdUsuario &id);
  // Imprime en la salida el mensaje para la ejecucion de un comando
  void clienteEjecuta(const IdUsuario &id, const std::string &cmd);
  // Imprime en la salida el mensaje str
  void imprimirStr(const std::string &str);
  ~Logger();
};

#endif //TP3_APP_SEVER_LOGGER_H
