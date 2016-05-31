#ifndef MOCHILA_H
#define MOCHILA_H

#include "iteracion.h"
#include <vector>
#include <fstream>

class Mochila
{
private:
    int peso_max;
    std::vector<Iteracion> soluciones;
    int cantidad_tipo_objeto;
public:
    Mochila(int pm, Iteracion tabu);
    void SetCantTipos_obj(int tipos_obj);
    int GetCantTipos_obj() const;
    void SetSoluciones(std::vector<Iteracion> soluciones);
    std::vector<Iteracion> GetSoluciones() const;
    void SetPeso_max(int peso_max);
    int GetPeso_max() const;
    void llenar_soluciones();
    int tabu_search();
    void print_soluciones(std::ofstream& salida);
    bool menor_que_mochila(int peso);
    Iteracion Swap(Iteracion iter, int num_ite);
    void print_sol_optima(std::ofstream& salida);
};

#endif
