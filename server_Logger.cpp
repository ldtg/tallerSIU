#include <iostream>
#include <string>
#include "server_Logger.h"
Logger::Logger() : output(std::cerr) {}
Logger::Logger(std::ostream &out) : output(out) {}
void Logger::clienteDesconectado(const IdUsuario &id) {
  output << id.toString() << " desconectado." << std::endl;
}
void Logger::clienteConectado(const IdUsuario &id) {
  output << id.toString() << " conectado." << std::endl;
}
void Logger::clienteInvalido(const IdUsuario &id) {
  output << id.getNum() << " es un " << id.tipoDeUsuarioToStr() <<
         " inválido." << std::endl;
}
void Logger::clienteEjecuta(const IdUsuario &id, const std::string &cmd) {
  output << id.toString() << " ejecuta " << cmd << "." << std::endl;
}
void Logger::imprimirStr(const std::string &str) {
  output << str;
}
Logger::~Logger() {}
