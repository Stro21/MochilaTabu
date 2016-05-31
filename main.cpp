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
    ifstream peso_max("test/Test1/p01_c.txt");
    ifstream peso_objetos("test/Test1/p01_w.txt");
    ifstream valor_objetos("test/Test1/p01_p.txt");
    ofstream resultado("test/Test1/p01_resultados.txt");    
//    ifstream peso_max("test/Test2/p02_c.txt");
//    ifstream peso_objetos("test/Test2/p02_w.txt");
//    ifstream valor_objetos("test/Test2/p02_p.txt");
//    ofstream resultado("test/Test2/p02_resultados.txt");    
//    ifstream peso_max("test/Test3/p03_c.txt");
//    ifstream peso_objetos("test/Test3/p03_w.txt");
//    ifstream valor_objetos("test/Test3/p03_p.txt");
//    ofstream resultado("test/Test3/p03_resultados.txt");    
//    ifstream peso_max("test/Test4/p04_c.txt");
//    ifstream peso_objetos("test/Test4/p04_w.txt");
//    ifstream valor_objetos("test/Test4/p04_p.txt");
//    ofstream resultado("test/Test4/p04_resultados.txt");    
//    ifstream peso_max("test/Test5/p05_c.txt");
//    ifstream peso_objetos("test/Test5/p05_w.txt");
//    ifstream valor_objetos("test/Test5/p05_p.txt");
//    ofstream resultado("test/Test5/p05_resultados.txt");    
//    ifstream peso_max("test/Test6/p06_c.txt");
//    ifstream peso_objetos("test/Test6/p06_w.txt");
//    ifstream valor_objetos("test/Test6/p06_p.txt");
//    ofstream resultado("test/Test6/p06_resultados.txt");    
//    ifstream peso_max("test/Test7/p07_c.txt");
//    ifstream peso_objetos("test/Test7/p07_w.txt");
//    ifstream valor_objetos("test/Test7/p07_p.txt");
//    ofstream resultado("test/Test7/p07_resultados.txt");    
//    ifstream peso_max("test/Test8/p08_c.txt");
//    ifstream peso_objetos("test/Test8/p08_w.txt");
//    ifstream valor_objetos("test/Test8/p08_p.txt");
//    ofstream resultado("test/Test8/p08_resultados.txt");
//Lee el archivo del peso de la mochila y lo guarda en la variable peso_mochila.   
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
//Lee lee y guarda en un vector los pesos de cada objeto. 
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
//Lee lee y guarda en un vector los valores de cada objeto.
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
//Guarda ambos datos en vector de objetos.    
    for(int i = 0; i < cantidad_objetos; i++){
        tabu.push_back(Objeto(peso[i], valor[i]));
    }
    Iteracion sol_tabu(tabu, peso_mochila);
    Mochila knapsack(peso_mochila, sol_tabu);
    knapsack.llenar_soluciones();
    if(resultado.is_open()){
        resultado << "El peso maximo que soporta la mochila es de " << 
                peso_mochila << "." << endl;
        knapsack.print_soluciones(resultado);
        knapsack.print_sol_optima(resultado);
        t_fin = clock();
        segundos = (double) (t_fin - t_ini) / CLOCKS_PER_SEC;
        resultado << "Tiempo total de procesamiento: " << segundos << " segundos." << endl;
        resultado.close();
    }
    else{
        return -1;
    }
    return 0;
}
