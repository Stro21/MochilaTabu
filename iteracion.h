#ifndef ITERACION_H
#define ITERACION_H

#include "objeto.h"
#include <vector>
#include <fstream>

class Iteracion
{
private:
    int peso_total;
    int valor_total;
    int cant_tipo_obj;
    std::vector<Objeto> objetos;
public:
    Iteracion(std::vector<Objeto> obj, int peso_max);
    void print_solucion(std::ofstream& salida);
    Iteracion(){}
    void setObjetos(std::vector<Objeto> objetos);
    std::vector<Objeto> getObjetos() const;
    void setCant_tipo_obj(int cant_tipo_obj);
    int getCant_tipo_obj() const;
    void setValor_total(int valor_total);
    int getValor_total() const;
    void setPeso_total(int peso_total);
    int getPeso_total() const;
    std::vector<Objeto> swap_cant_obj(int cantidad, int indice, std::vector<Objeto> obj);
    std::vector<Objeto> asignar_esta(std::vector<Objeto> obj, int peso_max);
    void print_sol_resu(std::ofstream& salida);
};

#endif
