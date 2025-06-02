#pragma once
#include "VentaArchivo.h"
#include "ProductoManager.h"
#include "ClienteManager.h"
#include "DetalleManager.h"

class VentaManager{
public:
    void cargarVenta();
    //void listarVentas();
   // void mostrarUnaVenta(int idFactura, int idCliente, Fecha fechaVenta, float importeTotal);
   // void modificarVenta();
   // void borrarVenta();
private:
    VentaArchivo _archivo;
    ProductoManager _producto;
    ClienteManager _cliente;
    DetalleManager _detalle;
};
