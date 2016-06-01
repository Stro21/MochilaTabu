#include <iostream>
#include "mochila.h"
#include "archivo.h"
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main(int argc, char* argv[])
{
    clock_t t_ini;
    Archivo lectura_escritura();
    for(int i = 1; i <= 8; i++){
        t_ini = clock();
        lectura_escritura.Elegir_Test(i);
        lectura_escritura.Ejecutar_Test(t_ini);
    }    
    return 0;
}
