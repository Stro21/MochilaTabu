#include "solucion.h"
#include <iostream>
#include <vector>

using namespace std;

Solucion::Solucion(int c, vector<Objeto> obj)
{
    int peso = 0; 
    int valor = 0;
    cant_tipo_obj = c;
    for(int i = 0; i < c; i++){
      objetos.push_back(obj[i]);
      peso = peso + obj[i].getPeso();
      valor = valor + obj[i].getValor();
    }
    peso_total = peso;
    valor_total = valor;
}

void Solucion::print_solucion() {
    cout << "El peso de la solucion tabu es de " << peso_total << endl;
    cout << "El valor de la solucion tabu es de " << valor_total << endl;
    for (int i = 0; i < cant_tipo_obj; i++) {
      objetos[i].print_objeto();
    }
}


void Solucion::incre_cantidad_obj(int i) {
    objetos[i].inc_cantidad();
}

void Solucion::setObjetos(std::vector<Objeto> objetos) {
    this->objetos = objetos;
}

std::vector<Objeto> Solucion::getObjetos() const {
    return objetos;
}

void Solucion::setCant_tipo_obj(int cant_tipo_obj) {
    this->cant_tipo_obj = cant_tipo_obj;
}

int Solucion::getCant_tipo_obj() const {
    return cant_tipo_obj;
}

void Solucion::setValor_total(int valor_total) {
    this->valor_total = valor_total;
}

int Solucion::getValor_total() const {
    return valor_total;
}

void Solucion::setPeso_total(int peso_total) {
    this->peso_total = peso_total;
}

int Solucion::getPeso_total() const {
    return peso_total;
}

