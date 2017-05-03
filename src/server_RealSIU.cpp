#include "server_RealSIU.h"
#include "server_Admin.h"
#include "server_MovimientoInvalido.h"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
RealSIU::RealSIU(const std::string &usuariosFileName,
                 const std::string &materiasFileName) {
  parsearMaterias(materiasFileName);
  parsearUsuarios(usuariosFileName);
  Admin *admin = new Admin(0, "admin", materias, usuarios);
  this->usuarios.emplace(admin->getId(), admin);
}
std::string RealSIU::inscribir(const IdUsuario &idInscribidor,
                               const IdUsuario &idAlumno,
                               const IdMateria &idMateria) {
  try {
    Usuario *auxUsr = obtenerUsuario(idInscribidor);
    Usuario *alumno = obtenerUsuario(idAlumno);
    Materia *auxMateria = obtenerMateria(idMateria);
    auxUsr->inscribir(*alumno, auxMateria);
  } catch (const MovimientoInvalido &e) {
    return e.what();
  }
  return "Inscripción exitosa.\n";
}
std::string RealSIU::desinscribir(const IdUsuario &idDesinscribidor,
                                  const IdUsuario &idAlumno,
                                  const IdMateria &idMateria) {
  Usuario *auxUsr, *alumno;
  Materia *auxMateria;
  try {
    auxUsr = obtenerUsuario(idDesinscribidor);
    alumno = obtenerUsuario(idAlumno);
    auxMateria = obtenerMateria(idMateria);
  } catch (const MovimientoInvalido &e) {
    return "Desinscripción inválida\n";
  }
  try {
    auxUsr->desInscribir(*alumno, auxMateria);
  } catch (const MovimientoInvalido &e) {
    return e.what();
  }
  return "Desinscripción exitosa.\n";
}
std::string RealSIU::listarMaterias() const {
  std::stringstream aux;
  for (auto &par : materias) {
    aux << par.second.toStringConVacantes();
  }
  return aux.str();
}
std::string RealSIU::listarInscripciones(const IdUsuario &usuario) const {
  return usuarios.at(usuario)->listarInscripciones();
}

bool RealSIU::existeElUsuario(const IdUsuario &id) const {
  return usuarios.find(id) != usuarios.end();
}

RealSIU::~RealSIU() {
  for (auto &usuario : usuarios) {
    delete usuario.second;
  }
}

void RealSIU::parsearMaterias(const std::string &matf) {
  std::string line, aux;
  std::vector<std::string> tokens;
  std::ifstream materiasFile;
  materiasFile.open(matf);
  while (getline(materiasFile, line)) {
    std::istringstream auxss(line);
    while (getline(auxss, aux, '\t'))
      tokens.push_back(aux);
  }
  for (size_t i = 0; i < tokens.size(); i += 5) {
    IdUsuario idDocente(std::stoi(tokens[i + 3]), DOCENTE);
    IdMateria id(std::stoi(tokens[i]), std::stoi(tokens[i + 1]));
    this->materias.emplace(id,
                           Materia(id,
                                   std::stoi(tokens[i + 4]),
                                   tokens[i + 2], idDocente));
  }
  materiasFile.close();
}
void RealSIU::parsearUsuarios(const std::string &usrf) {
  std::string line, aux;
  std::vector<std::string> tokens;
  std::ifstream usrFile;
  usrFile.open(usrf);
  while (getline(usrFile, line)) {
    std::stringstream auxss(line);
    while (getline(auxss, aux, '\t'))
      tokens.push_back(aux);
  }
  for (size_t i = 0; i < tokens.size(); i += 3) {
    if (tokens[i] == "alumno") {
      Alumno *alumno = new Alumno(std::stoi(tokens[i + 1]), tokens[i + 2]);
      this->usuarios.emplace(alumno->getId(), alumno);
    }
    if (tokens[i] == "docente") {
      IdUsuario idDoc(std::stoi(tokens[i + 1]), DOCENTE);
      if (tieneMateria(idDoc)) {
        IdMateria idMat = buscarId(idDoc);
        this->usuarios.emplace(idDoc, new Docente(std::stoi(tokens[i + 1]),
                                                  tokens[i + 2],
                                                  materias.at(idMat)));
      }
    }
  }
  usrFile.close();
}
IdMateria RealSIU::buscarId(const IdUsuario &usuario) {
  for (auto &par : materias) {
    if (par.second.tieneAlDocente(usuario))
      return par.second.getId();
  }
  return IdMateria(0, 0);
}
Usuario *RealSIU::obtenerUsuario(const IdUsuario &usuario) {
  try {
    Usuario *aux = usuarios.at(usuario);
    return aux;
  } catch (const std::out_of_range &e) {
    std::stringstream aux;
    aux << "El " << usuario.toString() << " es inválido." << std::endl;
    throw MovimientoInvalido(aux.str());
  }
}
Materia *RealSIU::obtenerMateria(const IdMateria &materia) {
  try {
    Materia *aux = &materias.at(materia);
    return aux;
  } catch (const std::out_of_range &e) {
    std::stringstream aux;
    aux << "La materia " << materia.getCodigo() << " no es válida."
        << std::endl;
    for (auto &materiaPar : materias) {
      if (materiaPar.first.getCodigo() == materia.getCodigo()) {
        aux.str("");
        aux << "El curso " << materia.getCurso() << " en la materia " <<
            materia.getCodigo() << " no es válido." << std::endl;
      }
    }
    throw MovimientoInvalido(aux.str());
  }
}
bool RealSIU::tieneMateria(IdUsuario usuario) {
  for (auto &par : materias) {
    if (par.second.tieneAlDocente(usuario))
      return true;
  }
  return false;
}
