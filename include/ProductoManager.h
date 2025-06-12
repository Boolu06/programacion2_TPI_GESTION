#pragma once
#include <cstring>
#include "ProductoArchivo.h"
#include "Producto.h"

class ProductoManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarProducto();
    void listarProductos();
    void filtrarPorMarca(Producto vectorProductos[], int cantidadRegistros);
    void filtrarPorTipo(Producto vectorProductos[], int cantidadRegistros);
    Producto buscarId(int idProducto);
    void mostrarUnProducto(int idProducto,float precioUnitario, std::string descripcion,std::string marca, std::string tipo, int stock);
    bool descontarStock(int idProductoModificar, int cantidadStockVendido);
    void modificarProducto();
    void borrarProducto();
private:
    ProductoArchivo _archivo;
};
