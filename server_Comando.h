#ifndef TP3_APP_COMANDO_H
#define TP3_APP_COMANDO_H

#include<string>
#include<vector>
#include "server_SIUGuaramini.h"
class Comando { //Clase abstracta representa comando
 protected:
  SIUGuaramini &siu;
  explicit Comando(SIUGuaramini &siu);
  static bool sonNumeros(const std::vector<std::string> &tokens);
  static std::vector<std::string> obtenerTokens(const std::string &cmdstr);
  static Comando *makeInsDes(const std::string &basic_string,
                             SIUGuaramini &guaramini,
                             const IdUsuario &usuario);
 public:
  //Factory de comandos
  static Comando *makeComando(const std::string &cmdstr, SIUGuaramini &siu,
                              const IdUsuario &id);
  //Ejecuta el comando
  virtual std::string ejecutar() = 0;
  //Retorna el nombre del comando para imprimir
  virtual std::string toString() const = 0;
  virtual ~Comando();
};

#endif //TP3_APP_COMANDO_H
