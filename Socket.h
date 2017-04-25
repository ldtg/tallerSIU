#ifndef TP3_APP_SOCKET_H
#define TP3_APP_SOCKET_H
#include <string>
#define MAX_CLIENTES_ESPERA 10
template<class T> class Socket {
  enum ShutdownMode{READ, WRITE, READWRITE};
 private:
  int socketfd;
  struct addrinfo *generarResultCliente(std::string basic_string,
                                        std::string basicString);
  void crearSocket(addrinfo *pAddrinfo);
  void conectarSocket(addrinfo *pAddrinfo);
  addrinfo *generar_result_server(std::string basic_string);
  void bindSocket(addrinfo *pAddrinfo);
  void listenSocket();
 public:
  Socket();
  explicit Socket(int fd);
  void connect(std::string host, std::string service);
  void bindandlisten(std::string service);
  Socket acceptConnection();
  void shutdownConnection(ShutdownMode mode);
  int send(T data);
  T receive();
  ~Socket();
  Socket<T>(const Socket<T>& otro) = delete;
  Socket<T> &operator=(const Socket<T> & otro) = delete;
  Socket<T>(Socket<T> &&otro);
  Socket<T> &operator=(Socket<T> &&otro);
};
#endif //TP3_APP_SOCKET_H
