/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "archivo.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void Archivo::Elegir_Test(int i)
{
    string line;
    this->Peso(i);
    this->Valor(i);
    this->Peso_Max(i);
    this->Resultado(i);
    if(this->peso_max.is_open()){
        while(getline(this->peso_max, line)){
            this->SetPeso_mochila(atoi(line.c_str()));
        }
        this->peso_max.close();
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        exit (EXIT_FAILURE);
    }
//Lee el archivo del peso de la mochila y lo guarda en la variable peso_mochila.
    if(this->peso_objetos.is_open()){
        while(getline(peso_objetos, line)){
            this->pesos.push_back(atoi(line.c_str()));
        }
        this->peso_objetos.close();
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        exit (EXIT_FAILURE);
    }
//Lee lee y guarda en un vector los pesos de cada objeto.   
    if(this->valor_objetos.is_open()){
        while(getline(valor_objetos, line)){
            this->valores.push_back(atoi(line.c_str()));
        }
        this->valor_objetos.close();
    }
    else{
        cout << "No se pudo abrir el archivo." << endl;
        exit (EXIT_FAILURE);        
    }
    if(this->pesos.size() != this->valores.size()){
        cout << "Tienen tamaños distintos." << endl;
        exit (EXIT_FAILURE);
    }
    this->SetCantidad_objetos(this->pesos.size());
//Lee lee y guarda en un vector los valores de cada objeto.
    for(int j = 0; j < this->cantidad_objetos; j++){
        this->tabu.push_back(Objeto(this->pesos[j], this->valores[j]));
    }
}

void Archivo::Peso(int i)
{
    if(i == 1){
        this->peso_objetos.open("test/Test1/p01_w.txt");
    }
    if(i == 2){
        this->peso_objetos.open("test/Test2/p02_w.txt");
    }
    if(i == 3){
        this->peso_objetos.open("test/Test3/p03_w.txt");
    }
    if(i == 4){
        this->peso_objetos.open("test/Test4/p04_w.txt");
    }
    if(i == 5){
        this->peso_objetos.open("test/Test5/p05_w.txt");
    }
    if(i == 6){
        this->peso_objetos.open("test/Test6/p06_w.txt");
    }
    if(i == 7){
        this->peso_objetos.open("test/Test7/p07_w.txt");
    }
    if(i == 8){
        this->peso_objetos.open("test/Test8/p08_w.txt");
    }
    else{
        exit (EXIT_FAILURE);
    }        
}

void Archivo::Valor(int i)
{
    if(i == 1){
        this->valor_objetos.open("test/Test1/p01_p.txt");
    }
    if(i == 2){
        this->valor_objetos.open("test/Test2/p02_p.txt");
    }
    if(i == 3){
        this->valor_objetos.open("test/Test3/p03_p.txt");
    }
    if(i == 4){
        this->valor_objetos.open("test/Test4/p04_p.txt");
    }
    if(i == 5){
        this->valor_objetos.open("test/Test5/p05_p.txt");
    }
    if(i == 6){
        this->valor_objetos.open("test/Test6/p06_p.txt");
    }
    if(i == 7){
        this->valor_objetos.open("test/Test7/p07_p.txt");
    }
    if(i == 8){
        this->valor_objetos.open("test/Test8/p08_p.txt");
    }
    else{
        exit (EXIT_FAILURE);
    }        
}

void Archivo::Peso_Max(int i)
{
    if(i == 1){
        this->peso_max.open("test/Test1/p01_c.txt");
    }
    if(i == 2){
        this->peso_max.open("test/Test2/p02_c.txt");

    }
    if(i == 3){
        this->peso_max.open("test/Test3/p03_c.txt");
    }
    if(i == 4){
        this->peso_max.open("test/Test4/p04_c.txt");
    }
    if(i == 5){
        this->peso_max.open("test/Test5/p05_c.txt");
    }
    if(i == 6){
        this->peso_max.open("test/Test6/p06_c.txt");
    }
    if(i == 7){
        this->peso_max.open("test/Test7/p07_c.txt");
    }
    if(i == 8){
        this->peso_max.open("test/Test8/p08_c.txt");
    }
    else{
        exit (EXIT_FAILURE);
    }        
}

void Archivo::Resultado(int i)
{
    if(i == 1){
        this->resultado.open("test/Test1/p01_resultados.txt");
    }
    if(i == 2){
        this->resultado.open("test/Test2/p02_resultados.txt");
    }
    if(i == 3){
        this->resultado.open("test/Test3/p03_resultados.txt");
    }
    if(i == 4){
        this->resultado.open("test/Test4/p04_resultados.txt");
    }
    if(i == 5){
        this->resultado.open("test/Test5/p05_resultados.txt");
    }
    if(i == 6){
        this->resultado.open("test/Test6/p06_resultados.txt");
    }
    if(i == 7){
        this->resultado.open("test/Test7/p07_resultados.txt");
    }
    if(i == 8){
        this->resultado.open("test/Test8/p08_resultados.txt");
    }
    else{
        exit (EXIT_FAILURE);
    }
}

void Archivo::Ejecutar_Test(clock_t t_ini)
{
    clock_t t_fin;
    double segundos;
    Iteracion sol_tabu(this->tabu, this->peso_mochila);
    Mochila knapsack(peso_mochila, sol_tabu);
    knapsack.llenar_soluciones();
    if(this->resultado.is_open()){
        this->resultado << "El peso maximo que soporta la mochila es de " << 
                peso_mochila << "." << endl;
        knapsack.print_soluciones(this->resultado);
        knapsack.print_sol_optima(this->resultado);
        t_fin = clock();
        segundos = (double) (t_fin - t_ini) / CLOCKS_PER_SEC;
        this->resultado << "Tiempo total de procesamiento: " << segundos << " segundos." << endl;
        this->resultado.close();
    }
    else{
        exit (EXIT_FAILURE);
    }
}