#ifndef TP3_APP_IDMATERIA_H
#define TP3_APP_IDMATERIA_H

class IdMateria {
 private:
  unsigned short codigo;
  unsigned short curso;
 public:
  explicit IdMateria(unsigned short codigo, unsigned short curso);
  bool operator==(const IdMateria& otro);
  bool operator<(const IdMateria &otro);
};

#endif //TP3_APP_IDMATERIA_H
