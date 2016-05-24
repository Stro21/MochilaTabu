#include "solucion.h"
#include <string>
#include <iostream>

using namespace std;

Solucion::Solucion(int p, int v, int c, Objeto obj[], Mochila k)
{
  peso_total = p;
  valor_total = v;
  cant_tipo_obj = c;
  mochila = k;
  objetos = new Objeto[cant_tipo_obj];
  for(int i = 0; i < c; i++){
    objetos[i] = obj[i];
  }
}

Solucion::Solucion(){

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

void Solucion::print_solucion() {
  cout << "El peso de la solucion tabu es de " << peso_total << endl;
  cout << "El valor de la solucion tabu es de " << valor_total << endl;
  cout << "Peso maximo de la mochila es de " << peso_max() << endl;
  for (int i = 0; i < cant_tipo_obj; i++) {
    objetos[i].print_objeto();
  }
}

int Solucion::peso_max(){
  return mochila.get_peso_max();
}

void Solucion::incre_cantidad_obj(int i) {
  objetos[i].inc_cantidad();
}

Solucion::Solucion(Objeto obj[], Mochila m, int cant_ti)
{
  peso_total = 0;
  valor_total = 0;
  cant_tipo_obj = cant_ti;
  objetos = new Objeto[cant_ti];
  objetos = obj;
  mochila = m;
}
