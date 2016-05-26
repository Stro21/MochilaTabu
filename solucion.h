#ifndef SOLUCION_H
#define SOLUCION_H

#include "objeto.h"
#include <vector>

class Solucion
{
private:
    int peso_total;
    int valor_total;
    int cant_tipo_obj;
    std::vector<Objeto> objetos;
public:
    Solucion(int c, std::vector<Objeto> obj);
    void print_solucion();
    Solucion(){}
    void incre_cantidad_obj(int i);
    void setObjetos(std::vector<Objeto> objetos);
    std::vector<Objeto> getObjetos() const;
    void setCant_tipo_obj(int cant_tipo_obj);
    int getCant_tipo_obj() const;
    void setValor_total(int valor_total);
    int getValor_total() const;
    void setPeso_total(int peso_total);
    int getPeso_total() const;
};

#endif
