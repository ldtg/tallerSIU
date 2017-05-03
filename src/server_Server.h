#ifndef TP3_APP_SERVER_H
#define TP3_APP_SERVER_H
#include <vector>
#include <string>
#include "server_Thread.h"
#include "common_Socket.h"
#include "server_ProxyCliente.h"
#include "server_MonitorSiu.h"
class Server : public Thread {
 private:
  std::vector<ProxyCliente *> clientes;
  SIUGuaramini &siu;
  std::string service;
  Socket aceptador;
  bool open;
  void recolectarClientesInactivos();
 public:
  explicit Server(const std::string &service, SIUGuaramini &siu);
  virtual void run() override;
  void stop();
  ~Server();
};

#endif //TP3_APP_SERVER_H
