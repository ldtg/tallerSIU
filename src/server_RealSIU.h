#ifndef TP3_APP_SIU_H
#define TP3_APP_SIU_H
#include <string>
#include <map>
#include "server_IdMateria.h"
#include "server_Materia.h"
#include "server_Alumno.h"
#include "server_Docente.h"
#include "server_SIUGuaramini.h"
class RealSIU : public SIUGuaramini {
 private:
  std::map<IdMateria, Materia> materias;
  std::map<IdUsuario, Usuario *> usuarios;
  void parsearMaterias(const std::string &matf);
  void parsearUsuarios(const std::string &usrf);
  IdMateria buscarId(const IdUsuario &usuario);
  Usuario *obtenerUsuario(const IdUsuario &usuario);
  Materia *obtenerMateria(const IdMateria &materia);
  bool tieneMateria(IdUsuario usuario);
 public:
  RealSIU(const std::string &usuariosFileName, const std::string
  &materiasFileName);
  virtual std::string inscribir(const IdUsuario &idInscribidor, const IdUsuario
  &idAlumno, const IdMateria &idMateria) override;
  virtual std::string desinscribir(const IdUsuario &idDesinscribidor, const
  IdUsuario &idAlumno, const IdMateria &idMateria) override;
  virtual std::string listarMaterias() const override;
  virtual std::string listarInscripciones(const IdUsuario &usuario) const
  override;
  virtual bool existeElUsuario(const IdUsuario &id) const override;
  ~RealSIU();
};

#endif //TP3_APP_SIU_H
