#include "objeto.h"
#include <iostream>

using namespace std;

void Objeto::print_objeto()
{
  cout << "Tiene " << cantidad << " de objetos de id " << id << endl;
}

void Objeto::print_data()
{
  cout << "ID: " << id << endl;
  cout << "Peso: " << peso << endl;
  cout << "Valor: " << valor << endl;
  cout << "Cantidad: " << cantidad << endl;
}

void Objeto::inc_cantidad()
{
  cantidad = cantidad + 1;
}

void Objeto::setId(int id) {
    this->id = id;
}

int Objeto::getId() const {
    return id;
}

void Objeto::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Objeto::getCantidad() const {
    return cantidad;
}

void Objeto::setValor(int valor) {
    this->valor = valor;
}

int Objeto::getValor() const {
    return valor;
}

void Objeto::setPeso(int peso) {
    this->peso = peso;
}

int Objeto::getPeso() const {
    return peso;
}
