#ifndef OBJETO_H
#define OBJETO_H

class Objeto
{
private:
    int peso;
    int valor;
    int cantidad;
    int id;
public:
    Objeto(int peso, int valor, int cantidad, int id) :
    peso(peso), valor(valor), cantidad(cantidad), id(id) {
    }
    Objeto(int peso, int valor, int cantidad) :
    peso(peso), valor(valor), cantidad(cantidad) {
    }
    void print_objeto();
    void print_data();
    Objeto(){}
    void setId(int id);
    int getId() const;
    void setCantidad(int cantidad);
    int getCantidad() const;
    void setValor(int valor);
    int getValor() const;
    void setPeso(int peso);
    int getPeso() const;
    int PesoTotal() const;
    int ValorTotal() const;
};

#endif
