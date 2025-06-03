#include<iostream>
#include <cstring>
#include "VentaManager.h"
#include "Venta.h"

using namespace std;

void VentaManager::cargarVenta(){
    Venta Factura;
    ClienteManager Cliente_M;
    ProductoManager Producto_M;
    DetalleManager Detalle_M;

    string cuitCliente;

    cout<<"Por favor ingrese el numero de CUIT del cliente";
    cin.ignore();

    getline(cin,cuitCliente);

    Cliente_M.buscarCuit(cuitCliente);

    //Venta.setIdFactura(idFactura); ///setea el idFactura autoincremental al momento de concretar la venta en detalleventa
    //Venta.setIdCliente(idCliente); ///asignar el idCliente encontrado con el CUIT
    ///Funcion que me traiga la fecha actual y asignarlo a fechaVenta
   // Venta.setFechaVenta(fechaVenta);
   // Venta.setImporteTotal(importeTotal) ///Importe total traido de detalleVenta
}

/*
void VentaManager::listarVentas();
void VentaManager::mostrarUnaVenta(int idFactura, int idCliente, Fecha fechaVenta, float importeTotal);
void VentaManager::modificarVenta();
void VentaManager::borrarVenta();
*/


