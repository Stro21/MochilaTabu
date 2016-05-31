#include "mochila.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

Mochila::Mochila(int pm, Iteracion tabu)
{
    peso_max = pm;
    soluciones.push_back(tabu);
    cantidad_tipo_objeto = tabu.getCant_tipo_obj();
}

void Mochila::SetCantTipos_obj(int tipos_obj) {
    this->cantidad_tipo_objeto = tipos_obj;
}

int Mochila::GetCantTipos_obj() const {
    return cantidad_tipo_objeto;
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
    for(int i = 0; i < cantidad_tipo_objeto; i++){
        if(i == cantidad_tipo_objeto - 1){
            break;
        }
        soluciones.push_back(this->Swap(soluciones[i], i));
    }
}

int Mochila::tabu_search()
{
    Iteracion tabu = soluciones[0];
    int sol_optima = 0;
    int itera = soluciones.size();
    for(int i = 1; i < itera; i++){
        if(tabu.getValor_total() < soluciones[i].getValor_total()
            && menor_que_mochila(soluciones[i].getPeso_total())){
            tabu = soluciones[i];
            sol_optima = i;
        }
    }
    return sol_optima;
}

void Mochila::print_sol_optima(ofstream& salida)
{
    int tabu = this->tabu_search();
    salida << "La solución optima pertenece a la iteracion " << tabu;
    salida << " y su resultado es:" << endl;
    soluciones[tabu].print_solucion(salida);
    salida << endl;
}

void Mochila::print_soluciones(ofstream& salida)
{
    int itera = soluciones.size();
    for(int i = 0; i < itera; i++){
        salida << "Iteracion " << i+1 << endl;
        soluciones[i].print_solucion(salida);
        salida << endl;
    }
}

bool Mochila::menor_que_mochila(int peso)
{
    return peso_max >= peso;
}

Iteracion Mochila::Swap(Iteracion iter, int num_ite)
{
    int c = iter.getCant_tipo_obj();
    Iteracion iteracion(iter.swap_cant_obj(c, num_ite, iter.getObjetos()));
    return iteracion;
}