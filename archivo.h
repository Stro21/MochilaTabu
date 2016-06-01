/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   archivo.h
 * Author: eduar
 *
 * Created on 31 de mayo de 2016, 15:10
 */

#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "mochila.h"
#include <vector>
#include <fstream>
#include <ctime>

class Archivo
{
private:
    std::ifstream peso_max;
    std::ifstream peso_objetos;
    std::ifstream valor_objetos;
    std::ofstream resultado;
    int peso_mochila;
    int cantidad_objetos;
    std::vector<int> pesos;
    std::vector<int> valores;
    std::vector<Objeto> tabu;
public:
    Archivo(){}
    void Elegir_Test(int i);
    void Ejecutar_Test(std::clock_t t_ini);
    void SetResultado(std::ofstream resultado) {
        this->resultado = resultado;
    }
    std::ofstream GetResultado() const {
        return resultado;
    }
    void SetValor_objetos(std::ifstream valor_objetos) {
        this->valor_objetos = valor_objetos;
    }
    std::ifstream GetValor_objetos() const {
        return valor_objetos;
    }
    void SetPeso_objetos(std::ifstream peso_objetos) {
        this->peso_objetos = peso_objetos;
    }
    std::ifstream GetPeso_objetos() const {
        return peso_objetos;
    }
    void SetPeso_max(std::ifstream peso_max) {
        this->peso_max = peso_max;
    }
    std::ifstream GetPeso_max() const {
        return peso_max;
    }

    void SetTabu(std::vector<Objeto> tabu) {
        this->tabu = tabu;
    }

    std::vector<Objeto> GetTabu() const {
        return tabu;
    }

    void SetValores(std::vector<int> valores) {
        this->valores = valores;
    }

    std::vector<int> GetValores() const {
        return valores;
    }

    void SetPesos(std::vector<int> pesos) {
        this->pesos = pesos;
    }

    std::vector<int> GetPesos() const {
        return pesos;
    }

    void SetCantidad_objetos(int cantidad_objetos) {
        this->cantidad_objetos = cantidad_objetos;
    }

    int GetCantidad_objetos() const {
        return cantidad_objetos;
    }

    void SetPeso_mochila(int peso_mochila) {
        this->peso_mochila = peso_mochila;
    }

    int GetPeso_mochila() const {
        return peso_mochila;
    }
    void Peso(int i);
    void Valor (int i);
    void Peso_Max (int i);
    void Resultado(int i);
};

#endif /* ARCHIVO_H */

