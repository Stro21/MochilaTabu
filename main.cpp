#include <iostream>
#include "mochila.h"
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    vector<Objeto> tabu;
    for(int i = 0; i < 2000; i++){
        tabu.push_back(Objeto(rand() % 8 + 1, rand() % 8 + 1, rand() % 8));
    }
    Iteracion sol_tabu(tabu.size(), tabu);
    Mochila knapsack(40000, sol_tabu);
    knapsack.llenar_soluciones();
    sol_tabu = knapsack.tabu_search();
    cout << "La solución optima es:" << endl;
    sol_tabu.print_sol_resu();
    return 0;
}
