#include <exception>
#include <iostream>
#include <string>
#include "server_ProxyCliente.h"
#include "server_Comando.h"
ProxyCliente::ProxyCliente(Socket &clienteSocket, SIUGuaramini &siu) :
    clienteSocket(std::move(clienteSocket)), siu(siu), open(true) {}
void ProxyCliente::run() {
  try {
    login();
    while (open) {
      std::string comando_str = clienteSocket.rcv_str_preconcatenated();
      std::string respuesta = ejecutarComando(comando_str);
      clienteSocket.send_str_preconcatenated(respuesta);
    }
  } catch (const SocketException &e) {
    logger.clienteDesconectado(idCliente);
    this->stop();
  }
}
void ProxyCliente::stop() {
  open = false;
  clienteSocket.closeSocket();
}
bool ProxyCliente::isOpen() const {
  return open;
}
ProxyCliente::~ProxyCliente() {}
void ProxyCliente::login() {
  std::string login = clienteSocket.rcv_str_preconcatenated();
  IdUsuario id = obtenerIdUsuario(login);
  if (this->siu.existeElUsuario(id)) {
    this->idCliente = id;
    logger.clienteConectado(id);
  } else {
    logger.clienteInvalido(id);
    this->stop();
  }
}
std::string ProxyCliente::ejecutarComando(const std::string &comando_str) {
  Comando *cmd;
  try {
    cmd = Comando::makeComando(comando_str, siu, idCliente);
  } catch (const std::runtime_error &e) {
    return e.what();
  }
  std::string respuesta = cmd->ejecutar();
  logger.clienteEjecuta(idCliente, cmd->toString());
  delete cmd;
  return respuesta;
}
IdUsuario ProxyCliente::obtenerIdUsuario(const std::string &usr) {
  IdUsuario aux;
  try {
    aux = IdUsuario(usr);
  }
  catch (const std::runtime_error &e) {
    logger.imprimirStr(e.what());
    this->stop();
  }
  return aux;
}
