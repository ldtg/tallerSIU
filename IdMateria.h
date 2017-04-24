#ifndef TP3_APP_IDMATERIA_H
#define TP3_APP_IDMATERIA_H
#include <string>
#include "IdUsuario.h"
class IdMateria {
 private:
  int codigo;
  int curso;
 public:
  explicit IdMateria(int codigo, int curso);
  int getCodigo() const;
  int getCurso() const;
  bool operator==(const IdMateria& otro) const;
  bool operator<(const IdMateria &otro) const;
};

#endif //TP3_APP_IDMATERIA_H
