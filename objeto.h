#ifndef OBJETO_H
#define OBJETO_H

class Objeto
{
private:
  int peso;
  int valor;
  int cantidad;
public:
  Objeto (int p, int v, int c);
  int get_peso();
  int get_valor();
  int get_cantidad();
  void set_cantidad(int c);
};

#endif
