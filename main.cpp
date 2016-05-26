#include <iostream>
#include "mochila.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    Objeto obj1(2, 3, 4, 1);
    Objeto obj2(1, 2, 3, 2);
    Objeto obj3(3, 4, 2, 3);
    Objeto obj4(4, 5, 1, 4);
    vector<Objeto> universo;
    universo.push_back(obj1);
    universo.push_back(obj2);
    universo.push_back(obj3);
    universo.push_back(obj4);
    vector<Objeto> tabu;
    tabu.reserve(4);
    tabu = universo;
    tabu[0].setCantidad(0);
    Solucion sol_tabu(4, tabu);
    Mochila knapsack(7, 12, sol_tabu, 4, universo);
    cout << knapsack.GetPeso_max() << endl;
    return 0;
}
