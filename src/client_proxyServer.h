#ifndef TP3_APP_CLIENT_SERVERPROXY_H
#define TP3_APP_CLIENT_SERVERPROXY_H
#include <string>
#include "common_Socket.h"
class ProxyServer {
 private:
  Socket socket;
  //parsea el comando y retorna el comando para enviar por el socket
  std::string parsearComando(const std::string &cmd) const;
 public:
  explicit ProxyServer(const std::string &host, const std::string &port);
  //Envía al server los datos de login recibe el tipo de usuario y id como str
  void login(const std::string &tipo, const std::string &id);
  //Envia el comando al server y retorna la respusta
  std::string enviarComando(const std::string &cmd);
  ~ProxyServer();
};

#endif //TP3_APP_CLIENT_SERVERPROXY_H
