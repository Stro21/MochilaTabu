#include "objeto.h"
#include <string>
#include <iostream>

using namespace std;

Objeto::Objeto(){

}

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

Objeto::Objeto(int p, int v, int c, string name)
{
  peso = p;
  valor = v;
  cantidad = c;
  nombre = name;
}

void Objeto::print_objeto()
{
  cout << "Tiene " << cantidad << " " << nombre << endl;
}

void Objeto::print_data()
{
  cout << "Nombre: " << nombre << endl;
  std::cout << "Peso: " << peso << std::endl;
  std::cout << "Valor: " << valor << std::endl;
  std::cout << "Cantidad: " << cantidad << std::endl;
}

void Objeto::inc_cantidad()
{
  cantidad = cantidad + 1;
}
