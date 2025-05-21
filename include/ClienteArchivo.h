#pragma once
#include <cstring>
#include "Cliente.h"

class ClienteArchivo{ ///Clase que crea el archivo de clientes

public:
    ClienteArchivo(std::string nombrearchivo="clientes.dat");
    bool guardar(Cliente reg);
    int getCantidadRegistros();
    bool leerVector(Cliente vectorRegistros[], int cantidad);
    std::string getNombreArchivo();
    int getNuevoId();
private:
    std::string _nombreArchivo;
};


