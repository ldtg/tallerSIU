#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "server_Server.h"
Server::Server(const std::string &service, SIUGuaramini &siu) :
    siu(siu), service(service), open(true) {}
void Server::run() {
  aceptador.bindandlisten(service);
  try {
    while (this->open) {
      Socket cliSocket = aceptador.acceptConnection();
      if (cliSocket.isValid()) {
        clientes.push_back(new ProxyCliente(cliSocket, siu));
        clientes.back()->start();
        recolectarClientesInactivos();
      }
    }
  } catch (const SocketException &e) {
    if (this->open)
      this->stop();
  }
}
void Server::recolectarClientesInactivos() {
  std::vector<ProxyCliente *>::iterator iterator;
  for (iterator = clientes.begin(); iterator != clientes.end();) {
    if (!(*iterator)->isOpen()) {
      (*iterator)->stop();
      (*iterator)->join();
      delete (*iterator);
      iterator = clientes.erase(iterator);
    } else {
      ++iterator;
    }
  }
}
void Server::stop() {
  this->open = false;
  this->aceptador.shutdownConnection(READWRITE);
  this->aceptador.closeSocket();
  for (ProxyCliente *cliente : clientes) {
    cliente->stop();
    cliente->join();
    delete cliente;
  }
  clientes.clear();
}
Server::~Server() {
  if (this->open)
    this->stop();
}
