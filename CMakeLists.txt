cmake_minimum_required(VERSION 3.7)
project(TP3_APP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IdMateria.cpp IdMateria.h IdUsuario.cpp IdUsuario.h Materia.cpp Materia.h Usuario.cpp Usuario.h Alumno.cpp Alumno.h Docente.cpp Docente.h SIU.cpp SIU.h Comando.cpp Comando.h Admin.cpp Admin.h)
add_executable(TP3_APP ${SOURCE_FILES})