#include <sstream>
#include <string>
#include "client_proxyServer.h"
ProxyServer::ProxyServer(const std::string &host, const std::string &port) {
  this->socket.connectToServer(host, port);
}
std::string ProxyServer::enviarComando(const std::string &cmd) {
  std::string comando = parsearComando(cmd);
  socket.send_str_preconcatenated(comando);
  return socket.rcv_str_preconcatenated();
}

void ProxyServer::login(const std::string &tipo, const std::string &id) {
  if (tipo == "admin") {
    socket.send_str_preconcatenated(tipo);
  } else {
    std::stringstream aux;
    aux << tipo << "-" << id;
    socket.send_str_preconcatenated(aux.str());
  }
}
std::string ProxyServer::parsearComando(const std::string &cmd) const {
  std::stringstream auxss(cmd);
  std::string tipoComando;
  std::stringstream comando;
  auxss >> tipoComando;
  if (tipoComando == "listarInscripciones") {
    comando << "li";
  } else if (tipoComando == "listarMaterias") {
    comando << "lm";
  } else if (tipoComando == "inscribir") {
    comando << "in";
    std::string arg;
    while (auxss >> arg) {
      comando << "-" << arg;
    }
  } else if (tipoComando == "desinscribir") {
    comando << "de";
    std::string arg;
    while (auxss >> arg) {
      comando << "-" << arg;
    }
  }
  return comando.str();
}
ProxyServer::~ProxyServer() {}

