#pragma once
#include <cstring>
#include "DetalleArchivo.h"

class DetalleManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarDetalle(int idFactura, int idProducto, int cantidad, float precioUnitario);
    void listarDetalles();
    void filtrarPorIdFactura(int idFactura=0);
    void mostrarUnDetalle(int idFactura, int idProducto,int cantidad, float precioUnitario);
    void modificarDetalle();
    void borrarDetalle();

private:
    DetalleArchivo _archivo;
};


