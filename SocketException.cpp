#include "SocketException.h"
SocketException::SocketException(const std::string msg) :msg(msg){}
const char *SocketException::what() const throw(){
  return msg.c_str();
}