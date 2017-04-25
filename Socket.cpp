#include "Socket.h"
#include "SocketException.h"
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <sstream>
template<class T>
Socket<T>::Socket(int fd): socketfd(fd) {}
template<class T>
Socket<T>::Socket() {
  this->socketfd = -1;
}
template<class T>
void Socket<T>::connect(std::string host, std::string service) {
  bool seConecto = false;
  struct addrinfo *result = generarResultCliente(host, service);
  struct addrinfo *ptr = NULL;
  for (ptr = result; ptr != NULL && !seConecto; ptr = ptr->ai_next) {
    crearSocket(ptr);
    conectarSocket(ptr);
    seConecto = true;
  }
  freeaddrinfo(result);
  if (!seConecto) {
    throw SocketException("No se pudo conectar");
  }
}
template<class T>
void Socket<T>::bindandlisten(std::string service) {
  struct addrinfo *result = generar_result_server(service);
  crearSocket(result);
  bindSocket(result);
  freeaddrinfo(result);
  listenSocket();
}
template<class T>
Socket<T> Socket<T>::acceptConnection() {
  int aux = accept(this->socketfd, NULL, NULL);
  if(aux == -1){
    std::stringstream auxstr;
    auxstr << "Error en accept  " << strerror(errno) << std::endl;
    throw SocketException(auxstr.str());
  }
}
template<class T>
void Socket<T>::shutdownConnection(Socket::ShutdownMode mode) {
  if(shutdown(this->socketfd, mode) == -1){
    throw SocketException("Error shutdown");
  }
}
template<class T>
int Socket<T>::send(T data) {
  int bytes_eviados = 0;
  int s = -1;
  int data_len = sizeof(T);
  while (bytes_eviados < data_len) {
    s = send(this->socketfd,
             (char *) data + bytes_eviados,
             data_len - bytes_eviados,
             MSG_NOSIGNAL);

    if (s < 0) {
      std::stringstream auxstr;
      auxstr << "Error send  " << strerror(errno) << std::endl;
      throw SocketException(auxstr.str());
    } else if (s == 0) {
      return 0;
    } else {
      bytes_eviados += s;
    }
  }
  return bytes_eviados;
}
template<class T>
T Socket<T>::receive() {
  int bytes_recibidos = 0;
  int s = 0;
  int data_len = sizeof(T);
  T data;
  while (bytes_recibidos < data_len) {
    s = recv(this->socketfd,
             (char *) data + bytes_recibidos,
             data_len - bytes_recibidos,
             MSG_NOSIGNAL);

    if (s <= 0){
      throw SocketException("Error rcv");
    }
    else
      bytes_recibidos += s;
  }
  return data;
}
template<class T>
struct addrinfo *Socket<T>::generarResultCliente(std::string host,
                                              std::string service) {
  struct addrinfo hints;
  struct addrinfo *result;
  memset(&hints, 0, sizeof(struct addrinfo));//Inicializa 0 la estructura
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  int s = getaddrinfo(host.c_str(), service.c_str(), &hints, &result);
  if (s != 0) {
    std::stringstream aux;
    aux << "Error en getaddrinfo " << gai_strerror(s) << std::endl;
    throw SocketException(aux.str());
  }
  return result;
}
template<class T>
void Socket<T>::crearSocket(addrinfo *pAddrinfo) {
  int enable = 1;

  this->socketfd = socket(pAddrinfo->ai_family, pAddrinfo->ai_socktype,
                          pAddrinfo->ai_protocol);

  if (this->socketfd == -1) {
    std::stringstream aux;
    aux << "Error al crear " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }

  if (setsockopt(this->socketfd,
                 SOL_SOCKET,
                 SO_REUSEPORT,
                 &enable,
                 sizeof(int)) < 0) {

    close(this->socketfd);
    freeaddrinfo(pAddrinfo);
    std::stringstream aux;
    aux << "Error en setsockop " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}
template<class T>
void Socket<T>::conectarSocket(addrinfo *pAddrinfo) {
  if (connect(this->socketfd, pAddrinfo->ai_addr, pAddrinfo->ai_addrlen)
      == -1) {
    close(this->socketfd);
    std::stringstream aux;
    aux << "Error en connect " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}
template<class T>
addrinfo *Socket<T>::generar_result_server(std::string service) {
  struct addrinfo hints;
  struct addrinfo *result;
  memset(&hints, 0, sizeof(struct addrinfo));//Inicializa 0 la estructura

  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int s = getaddrinfo(NULL,
                  service.c_str(),
                  &hints,
                  &result);//NULL porque es en la maquina local

  if (s != 0) {
    std::stringstream aux;
    aux << "Error en getaddrinfo " << gai_strerror(s) << std::endl;
    throw SocketException(aux.str());
  }
}
template<class T>
void Socket<T>::bindSocket(addrinfo *pAddrinfo) {
  if(bind(this->socketfd, pAddrinfo->ai_addr, pAddrinfo->ai_addrlen) == -1){
    std::stringstream aux;
    aux << "Error en bind " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}
template<class T>
void Socket<T>::listenSocket() {
  if(listen(this->socketfd, MAX_CLIENTES_ESPERA) == -1){
    std::stringstream aux;
    aux << "Error en listen " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}
template<class T>
Socket<T>::~Socket() {
  close(this->socketfd);
}
template<class T>
Socket<T>::Socket(Socket<T> &&otro) {
  this->socketfd = otro.socketfd;
  otro.socketfd = -1;
}
template<class T>
Socket<T> &Socket<T>::operator=(Socket<T> &&otro) {
  this->socketfd = otro.socketfd;
  otro.socketfd = -1;
  return *this;
}





