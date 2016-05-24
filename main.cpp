#include <iostream>
#include "soluciones.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  Objeto obj1(6, 7, 1, "Notebook");
  Objeto obj2(2, 3, 1, "Estuche");
  Objeto obj3(3, 5, 1, "Cuaderno");
  Mochila knapsack(41);
  vector<Objeto> obj(3);
  obj[0] = obj1;
  obj[1] = obj2;
  obj[2] = obj3;
  Solucion tabu1(obj[0].get_peso() * obj[0].get_cantidad(),
  obj[0].get_valor() * obj[0].get_cantidad(), 3, obj, knapsack);
  tabu1.print_solucion();
  cout << endl;
  for(int i = 0; i < 3; i++){
    obj[i].set_cantidad(0);
  }
  Soluciones tabu(7, knapsack, tabu1, 3, obj);
  tabu.llenar_soluciones();
  tabu.print_soluciones();
  cout << endl;
  Solucion tabu2 = tabu.tabu_search();
  tabu2.print_solucion();
  return 0;
}
