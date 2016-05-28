#include <iostream>
#include "mochila.h"
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string line;
    int peso_mochila, cantidad_objetos;
    vector<int> peso, valor;
    vector<Objeto> tabu;
//    ifstream peso_max("test/p01_c.txt");
//    ifstream peso_objetos("test/p01_w.txt");
//    ifstream valor_objetos("test/p01_p.txt");
//    ifstream peso_max("test/p02_c.txt");
//    ifstream peso_objetos("test/p02_w.txt");
//    ifstream valor_objetos("test/p02_p.txt");
//    ifstream peso_max("test/p03_c.txt");
//    ifstream peso_objetos("test/p03_w.txt");
//    ifstream valor_objetos("test/p03_p.txt");
//    ifstream peso_max("test/p04_c.txt");
//    ifstream peso_objetos("test/p04_w.txt");
//    ifstream valor_objetos("test/p04_p.txt");
//    ifstream peso_max("test/p05_c.txt");
//    ifstream peso_objetos("test/p05_w.txt");
//    ifstream valor_objetos("test/p05_p.txt");
//    ifstream peso_max("test/p06_c.txt");
//    ifstream peso_objetos("test/p06_w.txt");
//    ifstream valor_objetos("test/p06_p.txt");
//    ifstream peso_max("test/p07_c.txt");
//    ifstream peso_objetos("test/p07_w.txt");
//    ifstream valor_objetos("test/p07_p.txt");
    ifstream peso_max("test/p08_c.txt");
    ifstream peso_objetos("test/p08_w.txt");
    ifstream valor_objetos("test/p08_p.txt");
    if(peso_max.is_open()){
        while(getline(peso_max, line)){
            peso_mochila = atoi(line.c_str());
        }
        peso_max.close();
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        return -1;
    }
    if(peso_objetos.is_open()){
        while(getline(peso_objetos, line)){
            peso.push_back(atoi(line.c_str()));
        }
        peso_objetos.close();
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        return -1;
    }
    cantidad_objetos = peso.size();
    if(valor_objetos.is_open()){
        while(getline(valor_objetos, line)){
            valor.push_back(atoi(line.c_str()));
        }
        valor_objetos.close();
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        return -1;        
    }
    if(peso.size() != valor.size()){
        cout << "Tienen tamaños distintos." << endl;
        return -1;
    }
    for(int i = 0; i < cantidad_objetos; i++){
        tabu.push_back(Objeto(peso[i], valor[i]));
    }
    Iteracion sol_tabu(tabu, peso_mochila);
    Mochila knapsack(peso_mochila, sol_tabu);
    knapsack.llenar_soluciones();
    sol_tabu = knapsack.tabu_search();
    cout << "La solución optima es:" << endl;
    sol_tabu.print_solucion(peso_mochila);
    return 0;
}
