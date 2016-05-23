#include "soluciones.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

Soluciones::Soluciones(int cant, Mochila bag, Solucion tabu, int tipo, Objeto obj[])
{
  cant_soluciones = cant;
  mochila = bag;
  soluciones = new Solucion[cant];
  Solucion sol(obj, bag, tipo);
  soluciones[0] = tabu;
  for(int j = 1; j < cant; j++){
    soluciones[j] = sol;
  }
  lista_obj = new Objeto[tipo];
  for(int i = 0; i < tipo; i++){
    lista_obj[i] = obj[i];
  }
  tipos_obj = tipo;
}

void Soluciones::llenar_soluciones ()
{
  int peso = 0;
  int random = 0;
  for (int i = 0; i < cant_soluciones; i++){
    while (peso < mochila.get_peso_max()) {
      random = rand() % tipos_obj;
      if(peso + lista_obj[random].get_peso() <= mochila.get_peso_max()){
        peso = peso + lista_obj[random].get_peso();
        soluciones[i].set_peso_total(peso);
        soluciones[i].set_valor_total(soluciones[i].get_valor_total() + lista_obj[random].get_valor());
        soluciones[i].incre_cantidad_obj(random);
      }
      else{
        break;
      }
    }
  }
}

Solucion Soluciones::tabu_search()
{
  Solucion tabu = soluciones[0];
  for(int i = 1; i < cant_soluciones; i++){
    if(tabu.get_valor_total() < soluciones[i].get_valor_total()){
      tabu = soluciones[i];
    }
  }
  return tabu;
}
