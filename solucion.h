#ifndef SOLUCION_H
#define SOLUCION_H

#include "objeto.h"
#include "mochila.h"

class Solucion
{
private:
  int peso_total;
  int valor_total;
  int cant_tipo_obj;
  Objeto *objetos;
  Mochila mochila;
public:
  Solucion(int p, int v, int c, Objeto obj[], Mochila k);
  int get_peso_total();
  void set_peso_total(int p);
  int get_valor_total();
  void set_valor_total(int v);
  int get_cant_tipo_obj();
  void set_cantidad_de_obj(int c, int i);
  void print_solucion();
  int peso_max();
  Solucion();
  void incre_cantidad_obj(int i);
  Solucion(Objeto obj[], Mochila m, int cant_ti);
};

#endif
