#include "solucion.h"
#include <string>
#include <iostream>

using namespace std;

Solucion::Solucion(int p, int v, int c, Objeto *obj)
{
  peso_total = p;
  valor_total = v;
  cant_tipo_obj = c;
  objetos = obj;
}

int Solucion::get_peso_total()
{
  return peso_total;
}

void Solucion::set_peso_total(int p)
{
  peso_total = p;
}

int Solucion::get_valor_total()
{
  return valor_total;
}

void Solucion::set_valor_total(int v)
{
  valor_total = v;
}

int Solucion::get_cant_tipo_obj()
{
  return cant_tipo_obj;
}

void Solucion::set_cantidad_de_obj(int i, int c)
{
  objetos[i].set_cantidad(c);
}
