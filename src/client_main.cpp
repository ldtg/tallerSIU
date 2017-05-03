#include <iostream>
#include <sstream>
#include <string>
#include "common_Socket.h"
#include "client_proxyServer.h"
int main(int argc, char *argv[]) {
  std::string line;
  if (argc < 4)
    return 1;
  std::string id;
  if (argc == 5)
    id = argv[4];
  try {
    ProxyServer server(argv[1], argv[2]);
    server.login(argv[3], id);
    while (std::getline(std::cin, line)) {
      std::cout << server.enviarComando(line);
    }
  } catch (const SocketException &e) {
    std::cerr << "Desconectado" << std::endl;
  }
}
