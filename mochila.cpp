#include "mochila.h"
#include <string>
#include <iostream>

using namespace std;

Mochila::Mochila(int pm)
{
  peso_max = pm;
}

int Mochila::get_peso_max()
{
  return peso_max;
}
