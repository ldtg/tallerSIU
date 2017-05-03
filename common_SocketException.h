#ifndef TP3_APP_SOCKETEXCEPTION_H
#define TP3_APP_SOCKETEXCEPTION_H
#include <string>
#include <exception>
#include <sstream>
class SocketException : std::exception{
 private:
  const std::string msg;
  const ssize_t bytesTransferidos;
 public:
  explicit SocketException(const std::string msg);
  explicit SocketException(const std::string msg, ssize_t bytesTrasferidos);
  virtual const char * what() const throw();
  ssize_t getBytesTransferidos() const;
};

#endif //TP3_APP_SOCKETEXCEPTION_H
