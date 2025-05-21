#pragma once
#include <cstring>
#include "ProductoArchivo.h"

class ProductoManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarProducto();
private:
    ProductoArchivo _archivo;
};
