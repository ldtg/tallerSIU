#ifndef TP3_APP_IDUSUARIO_H
#define TP3_APP_IDUSUARIO_H
#include <string>
enum TipoDeUsuario {ALUMNO, DOCENTE, ADMIN};
class IdUsuario {
 private:
  int num;
  TipoDeUsuario tipoDeUsuario;
 public:
  IdUsuario();
  explicit IdUsuario(int num, TipoDeUsuario tipoDeUsuario);
  explicit IdUsuario(const std::string &idstr);
  std::string toString() const;
  int getNum() const;
  std::string tipoDeUsuarioToStr() const;
  TipoDeUsuario getTipoDeUsuario() const;
  ~IdUsuario();
  bool operator==(const IdUsuario& otro) const;
  bool operator!=(const IdUsuario& otro) const;
  bool operator<(const IdUsuario &otro) const;
};

#endif //TP3_APP_IDUSUARIO_H
