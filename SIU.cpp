#include "SIU.h"
#include "Admin.h"
#include "MovimientoInvalido.h"
#include <sstream>
#include <fstream>
SIU::SIU(std::string usuariosFileName, std::string materiasFileName) {
  parsearMaterias(materiasFileName);
  parsearUsuarios(usuariosFileName);
  Admin *admin = new Admin(0, "admin", materias, usuarios);
  this->usuarios.emplace(admin->getId(), admin);
}
std::string SIU::inscribir(IdUsuario idInscribidor,
                           IdUsuario idAlumno,
                           IdMateria idMateria) {
  try {
    Usuario *auxUsr = obtenerUsuario(idInscribidor);
    Usuario *alumno = obtenerUsuario(idAlumno);
    Materia *auxMateria = obtenerMateria(idMateria);
    auxUsr->inscribir(*alumno, auxMateria);
  } catch (const MovimientoInvalido &e) {
    return e.what();
  }
  return "Inscripción exitosa. \n";

}
std::string SIU::desinscribir(IdUsuario idDesinscribidor,
                              IdUsuario idAlumno,
                              IdMateria idMateria) {
  try {
    Usuario *auxUsr = obtenerUsuario(idDesinscribidor);
    Usuario *alumno = obtenerUsuario(idAlumno);
    Materia *auxMateria = obtenerMateria(idMateria);
    auxUsr->desInscribir(*alumno, auxMateria);
  } catch (const MovimientoInvalido &e) {
    return e.what();
  }
  return "Desinscripción exitosa. \n";

}
std::string SIU::listarMaterias() {//deberia ser ts
  std::stringstream aux;
  for (auto &&par : materias) {
    aux << par.second.toStringConVacantes();
  }
  return aux.str();
}
std::string SIU::listarInscripciones(IdUsuario usuario) {//deberia ser ts
  return usuarios.at(usuario)->listarInscripciones();
}
void SIU::parsearMaterias(std::string matf) {
  std::string line, aux;
  std::vector<std::string> tokens;
  std::ifstream materiasFile;
  materiasFile.open(matf);
  while (getline(materiasFile, line)) {
    std::istringstream auxss(line);
    while(getline(auxss, aux, '\t'))
      tokens.push_back(aux);
  }
  for (int i = 0; i < tokens.size(); i += 5) {
    IdUsuario idDocente(std::stoi(tokens[i + 3]), DOCENTE);
    IdMateria id(std::stoi(tokens[i]), std::stoi(tokens[i + 1]));
    this->materias.emplace(id,
                           Materia(id,
                                   std::stoi(tokens[i + 4]),
                                   tokens[i + 2], idDocente));
  }
  materiasFile.close();
}
void SIU::parsearUsuarios(std::string usrf) {
  std::string line, aux;
  std::vector<std::string> tokens;
  std::ifstream usrFile;
  usrFile.open(usrf);
  while (getline(usrFile, line)) {
    std::stringstream auxss(line);
    while(getline(auxss, aux, '\t'))
      tokens.push_back(aux);
  }
  for (int i = 0; i < tokens.size(); i += 3) {
    if (tokens[i] == "alumno") {
      Alumno *alumno = new Alumno(std::stoi(tokens[i + 1]), tokens[i + 2]);
      this->usuarios.emplace(alumno->getId(), alumno);
    }
    if (tokens[i] == "docente") {
      IdUsuario idDoc(std::stoi(tokens[i + 1]), DOCENTE);
      IdMateria idMat = buscarId(idDoc);
      this->usuarios.emplace(idDoc, new Docente(std::stoi(tokens[i + 1]),
                                            tokens[i + 2], materias.at(idMat)));
    }
  }
  usrFile.close();
}
IdMateria SIU::buscarId(IdUsuario usuario) {
  for (auto &&materia : materias) {
    if (materia.second.tieneAlDocente(usuario))
      return materia.second.getId(); //Que siempre lo encuentre es hipot del
  }                                 // enunciado
}
Usuario *SIU::obtenerUsuario(IdUsuario usuario) {
  try {
    Usuario *aux = usuarios.at(usuario);
    return aux;
  } catch (const std::out_of_range &e) {
    std::stringstream aux;
    aux << "El "<< usuario.toString() << "es inválido."<<std::endl;
    throw MovimientoInvalido(aux.str());
  }
}
Materia *SIU::obtenerMateria(IdMateria materia) {
  try {
    Materia *aux = &materias.at(materia);
    return aux;
  } catch (const std::out_of_range &e) {
    std::stringstream aux;
    aux << "La materia " << materia.getCodigo() << " no es válida."<<std::endl;
    for (auto &&materiaPar : materias) {
      if (materiaPar.first.getCodigo() == materia.getCodigo()){
        aux.str("");
        aux << "El curso " << materia.getCurso() << " en la materia " <<
            materia.getCodigo() << " no es válido."<< std::endl;
      }
    }
    throw MovimientoInvalido(aux.str());
  }
}
SIU::~SIU() {
  for (auto &&usuario : usuarios) {
    delete usuario.second;
  }
}
