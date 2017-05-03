#ifndef TP3_APP_MONITORSIU_H
#define TP3_APP_MONITORSIU_H

#include <mutex>
#include <string>
#include "server_RealSIU.h"
class MonitorSiu : public SIUGuaramini {
 private:
  std::mutex mutex;
  RealSIU &siu;
 public:
  explicit MonitorSiu(RealSIU &siu);
  virtual std::string inscribir(const IdUsuario &idInscribidor, const IdUsuario
  &idAlumno, const IdMateria &idMateria) override;
  virtual std::string desinscribir(const IdUsuario &idDesinscribidor, const
  IdUsuario &idAlumno, const IdMateria &idMateria) override;
  virtual std::string listarMaterias() const override;
  virtual std::string listarInscripciones(const IdUsuario &usuario)
  const override;
  virtual bool existeElUsuario(const IdUsuario &id) const override;
  ~MonitorSiu();
};

#endif //TP3_APP_MONITORSIU_H
