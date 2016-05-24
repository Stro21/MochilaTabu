#ifndef SOLUCIONES_H
#define SOLUCIONES_H

#include "solucion.h"
#include "mochila.h"
#include <vector>

class Soluciones
{
private:
  int cant_soluciones;
  Mochila mochila;
  std::vector<Solucion> soluciones;
  int tipos_obj;
  std::vector<Objeto> lista_obj;
public:
  Soluciones(int cant, Mochila bag, Solucion tabu, int tipo, std::vector<Objeto> obj);
  void llenar_soluciones();
  Solucion tabu_search();
  void print_soluciones();
};

#endif
