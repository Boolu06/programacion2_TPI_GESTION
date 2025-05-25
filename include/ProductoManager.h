#pragma once
#include <cstring>
#include "ProductoArchivo.h"

class ProductoManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarProducto();
    void listarProductos();
    void mostrarUnProducto(int idProducto, std::string descripcion,std::string marca, std::string tipo, int stock);
    void modificarProducto();
    void borrarProducto();
private:
    ProductoArchivo _archivo;
};
