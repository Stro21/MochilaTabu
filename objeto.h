#ifndef OBJETO_H
#define OBJETO_H

#include <string>

using namespace std;

class Objeto
{
private:
  int peso;
  int valor;
  int cantidad;
  string nombre;
public:
  Objeto (int p, int v, int c, string nombre);
  int get_peso();
  int get_valor();
  int get_cantidad();
  void set_cantidad(int c);
  void print_objeto();
  void print_data();
  Objeto();
  void inc_cantidad();
};

#endif
