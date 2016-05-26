#include "mochila.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Mochila::Mochila(int cant, int pm, Iteracion tabu, int tipo, std::vector<Objeto> obj)
{
    peso_max = pm;
    cant_iteraciones = cant;
    soluciones.push_back(tabu);
    tipos_obj = tipo;
    for(int i = 0; i < tipo; i++){
        universo_obj.push_back(obj[i]);
    }
}

void Mochila::SetCant_iteraciones(int cant_soluciones) {
    this->cant_iteraciones = cant_soluciones;
}

int Mochila::GetCant_iteraciones() const {
    return cant_iteraciones;
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
    for(int i = 0; i < tipos_obj; i++){
        if(i == tipos_obj - 1){
            break;
        }
        soluciones.push_back(this->Swap(soluciones[i], i));
    }
}

Iteracion Mochila::tabu_search()
{
    Iteracion tabu = soluciones[0];
    for(int i = 1; i < soluciones.size(); i++){
        if(tabu.getValor_total() < soluciones[i].getValor_total()
            && this->menor_que_mochila(soluciones[i].getPeso_total())){
            tabu = soluciones[i];
        }
    }
    return tabu;
}

void Mochila::print_soluciones()
{
    for(int i = 0; i < soluciones.size(); i++){
      soluciones[i].print_solucion();
      cout << endl;
    }
}

bool Mochila::menor_que_mochila(int peso)
{
    return peso_max <= peso;
}

Iteracion Mochila::Swap(Iteracion iter, int num_ite)
{
    int c = iter.getCant_tipo_obj();
    Iteracion iteracion(c, iter.swap_cant_obj(c, num_ite, iter.getObjetos()));
    return iteracion;
}