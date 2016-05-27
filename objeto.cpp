#include "objeto.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

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

void Objeto::setEsta(bool esta) {
    this->esta = esta;
}

bool Objeto::isEsta() const {
    return esta;
}

void Objeto::print_data()
{
    cout << "Peso: " << peso << endl;
    cout << "Valor: " << valor << endl;
}

void Objeto::print_esta()
{
    if(esta){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}

Objeto::Objeto(int peso, int valor)
{
    this->peso = peso;
    this->valor = valor;
}
