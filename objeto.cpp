#include "objeto.h"
#include <string>
#include <iostream>

using namespace std;

int Objeto::get_peso()
{
  return peso;
}

int Objeto::get_valor()
{
  return valor;
}

int Objeto::get_cantidad()
{
  return cantidad;
}

void Objeto::set_cantidad(int c)
{
  cantidad = c;
}

Objeto::Objeto(int p, int v, int c)
{
  peso = p;
  valor = v;
  cantidad = c;
}
