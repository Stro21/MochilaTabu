#ifndef OBJETO_H
#define OBJETO_H

#include <fstream>

class Objeto
{
private:
    int peso;
    int valor;
    bool esta;
public:
    Objeto(int peso, int valor);
    Objeto(){}
    Objeto(int peso, int valor, bool esta) :
    peso(peso), valor(valor), esta(esta) {
    }
    void setValor(int valor);
    int getValor() const;
    void setPeso(int peso);
    int getPeso() const;
    void setEsta(bool esta);
    bool isEsta() const;
    void print_data();
    void print_esta(std::ofstream& salida);
    bool objeto_factible();
};

#endif
