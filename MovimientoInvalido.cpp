#include "MovimientoInvalido.h"
MovimientoInvalido::MovimientoInvalido(const std::string msg) : msg(msg){}
const char *MovimientoInvalido::what() const throw(){
  return msg.c_str();
}
