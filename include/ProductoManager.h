#pragma once
#include <cstring>
#include "ProductoArchivo.h"
#include "Producto.h"

class ProductoManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarProducto();
    void listarProductos();
    Producto buscarId(int idProducto);
    void mostrarUnProducto(int idProducto,float precioUnitario, std::string descripcion,std::string marca, std::string tipo, int stock);
    void modificarProducto();
    void borrarProducto();
private:
    ProductoArchivo _archivo;
};
