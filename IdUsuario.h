#ifndef TP3_APP_IDUSUARIO_H
#define TP3_APP_IDUSUARIO_H
#include <string>
enum TipoDeUsuario {alumno, docente, admin};
class IdUsuario {
 private:
  TipoDeUsuario tipoDeUsuario;
  std::string nombre;
  unsigned short num;
 public:
  explicit IdUsuario(std::string nombre, unsigned short num, TipoDeUsuario
  tipoDeUsuario);
  bool operator==(const IdUsuario& otro);
  bool operator<(const IdUsuario &otro);
};

#endif //TP3_APP_IDUSUARIO_H
