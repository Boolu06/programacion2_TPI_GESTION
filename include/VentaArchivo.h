#pragma once
#include <cstring>
#include "Venta.h"


class VentaArchivo{

public:
    VentaArchivo(std::string nombrearchivo="ventas.dat");
    bool guardar(Venta reg);
    int getCantidadRegistros();
    bool leerVector(Venta vectorRegistros[], int cantidad);
    int buscarIndex(Venta vectorRegistros[],int cantidad,int idFactura);
    std::string getNombreArchivo();
    int getNuevoId();
private:
    std::string _nombreArchivo;
};

