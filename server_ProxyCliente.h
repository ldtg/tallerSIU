#ifndef TP3_APP_PROXYCLIENTE_H
#define TP3_APP_PROXYCLIENTE_H

#include "server_Thread.h"
#include "common_Socket.h"
#include "server_MonitorSiu.h"
#include "server_Logger.h"
#include <string>
class ProxyCliente : public Thread {
 private:
  Socket clienteSocket;
  SIUGuaramini &siu;
  bool open;
  IdUsuario idCliente;
  Logger logger;
  void login();
  std::string ejecutarComando(const std::string &comando_str);
  IdUsuario obtenerIdUsuario(const std::string &usr);
 public:
  ProxyCliente(Socket &clienteSocket, SIUGuaramini &siu);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~ProxyCliente();
};

#endif //TP3_APP_PROXYCLIENTE_H
