#pragma once
#include <cstring>


class DetalleManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarDetalle();
    void listarDetalles();
    void mostrarUnDetalle(int idFactura, int idProducto,int cantidad, float precioUnitario);
    void modificarDetalle();
    void borrarDetalle();

private:
    DetalleArchivo _archivo;
};


