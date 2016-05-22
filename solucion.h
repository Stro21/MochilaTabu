#ifndef SOLUCION_H
#define SOLUCION_H

#include "objeto.h"

class Solucion
{
private:
  int peso_total;
  int valor_total;
  int cant_tipo_obj;
  Objeto *objetos;
public:
  Solucion(int p, int v, int c, Objeto *obj);
  int get_peso_total();
  void set_peso_total(int p);
  int get_valor_total();
  void set_valor_total(int v);
  int get_cant_tipo_obj();
  Objeto *get_objetos()
  {
    return objetos;
  }
  void set_cantidad_de_obj(int c, int i);
};

#endif
