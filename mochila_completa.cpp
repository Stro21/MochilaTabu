class Objeto
{
  private:
    int peso;
    int valor;
  public:
    int get_peso(){
      return peso;
    }
    int get_valor(){
      return valor;
    }
}

Class Mochila
{
  private:
    int peso_max;
  public:
    int get_peso_max(){
      return peso_max;
    }
}

class Solucion
{
  private:
    int peso_total;
    int valor_total;
    Mochila mochila;
    int cant_tipo_obj;
    Objeto objetos[];
  public:
    int get_cant_tipo_obj(){
      return cant_tipo_obj;
    }
    Objeto get_objetos[](){
      return objetos;
    }
    int get_peso_total(){
      return peso_total;
    }
    int get_peso_max(){
      return mochila.get_peso_max();
    }
    int get_peso_obj(int i){
      return objetos[i].get_peso();
    }
    int get_valor_obj(int i){
      return objetos[i].get_valor();
    }
    int get_valor_total(){
      return valor_total;
    }
    void set_peso_total(int x){
      peso_total = x;
    }
    void set_valor_total(int x) {
      valor_total = x;
    }
}

class Soluciones
{
  private:
    int cant_soluciones;
    Solucion total_soluciones[];
    int total_tipos_objetos;
    Objeto lista_obj[];
    Mochila mochila;
  public:
    void llenar_soluciones();
    Solucion tabu_search();
}

Soluciones::llenar_soluciones ()
{
  int peso = 0;
  int random = 0;
  for (int i = 0; i < cant_soluciones; i++){
    while (peso < mochila.get_peso_max()) {
      random = rand() % total_tipos_objetos;
      if(peso + lista_obj[random].get_peso() <= mochila.get_peso_max()){
        peso = peso + lista_obj[random].get_peso();
        total_soluciones[i].set_peso_total(peso);
        total_soluciones[i].set_valor_total(total_soluciones[i].get_valor_total() + lista_obj[random].get_valor());
      }
      else{
        break;
      }
    }
  }
}

soluciones::tabu_search(int N, Solucion *soluciones)
{
  Solucion tabu = total_soluciones[0];
  for(int i = 1; i < cant_soluciones; i++){
    if(tabu.get_valor_total() < total_soluciones[i].get_valor_total()){
      tabu = total_soluciones[i];
    }
  }
  return tabu;
}
