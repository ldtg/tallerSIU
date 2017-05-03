#include "server_MovimientoInvalido.h"
#include <string>
MovimientoInvalido::MovimientoInvalido(const std::string msg) : msg(msg){}
const char *MovimientoInvalido::what() const throw(){
  return msg.c_str();
}
