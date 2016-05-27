#include <iostream>
#include "mochila.h"
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    int peso, valor;
    bool esta;
    vector<Objeto> tabu;
    for(int i = 0; i < 2000; i++){
        peso = rand() % 8 + 1;
        valor = rand() % 8 + 1;
        if((rand() % 2) == 1){
            esta = true;
        }
        else{
            esta = false;
        }
        tabu.push_back(Objeto(peso, valor, esta));
    }
    Iteracion sol_tabu(tabu.size(), tabu);
    Mochila knapsack(5000, sol_tabu);
    knapsack.llenar_soluciones();
    sol_tabu = knapsack.tabu_search();
    cout << "La solución optima es:" << endl;
    sol_tabu.print_solucion();
    return 0;
}
