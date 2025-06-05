#pragma once
#include <cstring>
#include "Producto.h"

class ProductoArchivo{ ///Clase que crea el archivo de productos

public:
    ProductoArchivo(std::string nombrearchivo="productos.dat");
    bool guardar(Producto reg);
    bool modificar(Producto &registro, int index);
    int getCantidadRegistros();
    bool leerVector(Producto vectorRegistros[], int cantidad);
    int buscarIndex(Producto vectorRegistros[],int cantidad,int idProducto);
    std::string getNombreArchivo();
    int getNuevoId();
private:
    std::string _nombreArchivo;
};
