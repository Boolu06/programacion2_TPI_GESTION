#pragma once
#include <cstring>
#include "Cliente.h"

class ClienteArchivo{ ///Clase que crea el archivo de clientes

public:
    ClienteArchivo(std::string nombrearchivo="clientes.dat");
    bool guardar(Cliente reg);
    bool modificar(Cliente &registro, int index);
    bool borrar(Cliente &registro, int index);
    int getCantidadRegistros();
    bool leerVector(Cliente vectorRegistros[], int cantidad);
    int buscarIndex(Cliente vectorRegistros[],int cantidad,int idCliente);
    std::string getNombreArchivo();
    int getNuevoId();
private:
    std::string _nombreArchivo;
};


