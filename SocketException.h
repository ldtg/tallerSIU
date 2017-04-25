#ifndef TP3_APP_SOCKETEXCEPTION_H
#define TP3_APP_SOCKETEXCEPTION_H
#include <string>
#include <exception>
#include <sstream>
class SocketException : std::exception{
 private:
  const std::string msg;
 public:
  explicit SocketException(const std::string msg);
  virtual const char * what() const throw();
};

#endif //TP3_APP_SOCKETEXCEPTION_H
