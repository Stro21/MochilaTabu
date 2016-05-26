#include "mochila.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Mochila::Mochila(int cant, int pm, Iteracion tabu, int tipo, std::vector<Objeto> obj)
{
    peso_max = pm;
    cant_soluciones = cant;
    soluciones.push_back(tabu);
    tipos_obj = tipo;
    for(int i = 0; i < tipo; i++){
        universo_obj.push_back(obj[i]);
    }
}

void Mochila::SetCant_soluciones(int cant_soluciones) {
    this->cant_soluciones = cant_soluciones;
}

int Mochila::GetCant_soluciones() const {
    return cant_soluciones;
}

void Mochila::SetUniverso_obj(std::vector<Objeto> universo_obj) {
    this->universo_obj = universo_obj;
}

std::vector<Objeto> Mochila::GetUniverso_obj() const {
    return universo_obj;
}

void Mochila::SetTipos_obj(int tipos_obj) {
    this->tipos_obj = tipos_obj;
}

int Mochila::GetTipos_obj() const {
    return tipos_obj;
}

void Mochila::SetSoluciones(std::vector<Iteracion> soluciones) {
    this->soluciones = soluciones;
}

std::vector<Iteracion> Mochila::GetSoluciones() const {
    return soluciones;
}

void Mochila::SetPeso_max(int peso_max) {
    this->peso_max = peso_max;
}

int Mochila::GetPeso_max() const {
    return peso_max;
}

void Mochila::llenar_soluciones ()
{
//    int peso = 0;
//    int random = 0;
//    for (int i = 1; i < cant_soluciones; i++){
//      while (peso < mochila.get_peso_max()) {
//        random = rand() % tipos_obj;
//        if(peso + lista_obj[random].get_peso() <= mochila.get_peso_max()){
//          peso = peso + lista_obj[random].get_peso();
//          soluciones[i].set_peso_total(peso);
//          soluciones[i].set_valor_total(soluciones[i].get_valor_total() + lista_obj[random].get_valor());
//          soluciones[i].incre_cantidad_obj(random);
//        }
//        else{
//          break;
//        }
//      }
}


Iteracion Mochila::tabu_search()
{
    Iteracion tabu = soluciones[0];
    for(int i = 1; i < cant_soluciones; i++){
        if(tabu.getValor_total() < soluciones[i].getValor_total()
            && this->menor_que_mochila(soluciones[i].getPeso_total())){
            tabu = soluciones[i];
        }
    }
    return tabu;
}

void Mochila::print_soluciones()
{
    for(int i = 0; i < cant_soluciones; i++){
      soluciones[i].print_solucion();
      cout << endl;
    }
}

bool Mochila::menor_que_mochila(int peso)
{
    return peso_max <= peso;
}

vector<Objeto> Mochila::Swap(std::vector<Objeto> obj)
{
    
}