#ifndef TP3_APP_INSCRIPCIONINVALIDA_H
#define TP3_APP_INSCRIPCIONINVALIDA_H

#include <exception>
#include <string>
class MovimientoInvalido : std::exception{
 private:
  const std::string msg;
 public:
  explicit MovimientoInvalido(const std::string msg);
  virtual const char * what() const throw();
};

#endif //TP3_APP_INSCRIPCIONINVALIDA_H
