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
    ifstream peso_max("p01_c.txt");
    ifstream peso_objetos("p01_w.txt");
    ifstream valor_objetos("p01_p.txt");
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
//    int peso, valor;
//    bool esta;
//    for(int i = 0; i < 2000; i++){
//        peso = rand() % 8 + 1;
//        valor = rand() % 8 + 1;
//        if((rand() % 2) == 1){
//            esta = true;
//        }
//        else{
//            esta = false;
//        }
//        tabu.push_back(Objeto(peso, valor, esta));
//    }
    
    Iteracion sol_tabu(tabu.size(), tabu);
    Mochila knapsack(peso_mochila, sol_tabu);
    knapsack.llenar_soluciones();
    sol_tabu = knapsack.tabu_search();
    cout << "La solución optima es:" << endl;
    sol_tabu.print_solucion();
    return 0;
}
