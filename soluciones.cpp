#include "soluciones.h"
#include <string>
#include <iostream>

using namespace std;

Soluciones::Soluciones(int cant, Mochila bag, Solucion tabu)
{
  cant_soluciones = cant;
  mochila = bag;
  soluciones = new *Solucion();
  soluciones[0] = tabu;
}

Soluciones::llenar_soluciones ()
{
  int peso = 0;
  int random = 0;
  for (int i = 0; i < cant_soluciones; i++){
    while (peso < mochila.get_peso_max()) {
      random = rand() % total_tipos_objetos;
      if(peso + lista_obj[random].get_peso() <= mochila.get_peso_max()){
        peso = peso + lista_obj[random].get_peso();
        total_soluciones[i].set_peso_total(peso);
        total_soluciones[i].set_valor_total(total_soluciones[i].get_valor_total() + lista_obj[random].get_valor());
      }
      else{
        break;
      }
    }
  }
}

soluciones::tabu_search()
{
  Solucion tabu = total_soluciones[0];
  for(int i = 1; i < cant_soluciones; i++){
    if(tabu.get_valor_total() < total_soluciones[i].get_valor_total()){
      tabu = total_soluciones[i];
    }
  }
  return tabu;
}
