#include <iostream>
#include "mochila.h"
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
    clock_t t_ini, t_fin;
    t_ini = clock();
    double segundos;
    string line;
    int peso_mochila, cantidad_objetos;
    vector<int> peso, valor;
    vector<Objeto> tabu;
//    ifstream peso_max("test/Test1/p01_c.txt");
//    ifstream peso_objetos("test/Test1/p01_w.txt");
//    ifstream valor_objetos("test/Test1/p01_p.txt");
//    ifstream peso_max("test/Test2/p02_c.txt");
//    ifstream peso_objetos("test/Test2/p02_w.txt");
//    ifstream valor_objetos("test/Test2/p02_p.txt");
//    ifstream peso_max("test/Test3/p03_c.txt");
//    ifstream peso_objetos("test/Test3/p03_w.txt");
//    ifstream valor_objetos("test/Test3/p03_p.txt");
//    ifstream peso_max("test/Test4/p04_c.txt");
//    ifstream peso_objetos("test/Test4/p04_w.txt");
//    ifstream valor_objetos("test/Test4/p04_p.txt");
//    ifstream peso_max("test/Test5/p05_c.txt");
//    ifstream peso_objetos("test/Test5/p05_w.txt");
//    ifstream valor_objetos("test/Test5/p05_p.txt");
//    ifstream peso_max("test/Test6/p06_c.txt");
//    ifstream peso_objetos("test/Test6/p06_w.txt");
//    ifstream valor_objetos("test/Test6/p06_p.txt");
//    ifstream peso_max("test/Test7/p07_c.txt");
//    ifstream peso_objetos("test/Test7/p07_w.txt");
//    ifstream valor_objetos("test/Test7/p07_p.txt");
    ifstream peso_max("test/Test8/p08_c.txt");
    ifstream peso_objetos("test/Test8/p08_w.txt");
    ifstream valor_objetos("test/Test8/p08_p.txt");
    ofstream resultado("test/Test8/p08_r");
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
    t_fin = clock();
    segundos = (double) (t_fin - t_ini) / CLOCKS_PER_SEC;
    cout << "Tiempo total de procesamiento: " << segundos << " segundos." << endl << endl;
    return 0;
}
