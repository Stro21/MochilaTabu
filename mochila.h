#ifndef MOCHILA_H
#define MOCHILA_H

#include "iteracion.h"
#include <vector>

class Mochila
{
private:
    int peso_max;
    int cant_iteraciones;
    std::vector<Iteracion> soluciones;
    int tipos_obj;
    std::vector<Objeto> universo_obj;
public:
    Mochila(int cant, int pm, Iteracion tabu, int tipo, std::vector<Objeto> obj);
    void SetUniverso_obj(std::vector<Objeto> universo_obj);
    std::vector<Objeto> GetUniverso_obj() const;
    void SetTipos_obj(int tipos_obj);
    int GetTipos_obj() const;
    void SetSoluciones(std::vector<Iteracion> soluciones);
    std::vector<Iteracion> GetSoluciones() const;
    void SetPeso_max(int peso_max);
    int GetPeso_max() const;
    void llenar_soluciones();
    Iteracion tabu_search();
    void print_soluciones();
    void SetCant_iteraciones(int cant_soluciones);
    int GetCant_iteraciones() const;
    bool menor_que_mochila(int peso);
    Iteracion Swap(Iteracion iter, int num_ite);    
};

#endif
