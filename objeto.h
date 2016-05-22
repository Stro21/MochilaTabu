#ifndef OBJETO_H
#define OBJETO_H

#include <string>

class Objeto
{
private:
  int peso;
  int valor;
  int cantidad;
  std::string nombre;
public:
  Objeto (int p, int v, int c, std::string nombre);
  int get_peso();
  int get_valor();
  int get_cantidad();
  void set_cantidad(int c);
  void print_objeto();
};

#endif
