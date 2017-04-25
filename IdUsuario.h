#ifndef TP3_APP_IDUSUARIO_H
#define TP3_APP_IDUSUARIO_H
#include <string>
enum TipoDeUsuario {ALUMNO, DOCENTE, ADMIN};
class IdUsuario {
 private:
  TipoDeUsuario tipoDeUsuario;
  int num;
 public:
  explicit IdUsuario(int num, TipoDeUsuario tipoDeUsuario);
  std::string toString() const;
  int getNum() const;
  bool operator==(const IdUsuario& otro) const;
  bool operator!=(const IdUsuario& otro) const;
  bool operator<(const IdUsuario &otro) const;
};

#endif //TP3_APP_IDUSUARIO_H
