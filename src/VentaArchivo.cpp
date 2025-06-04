#include<iostream>
#include "Venta.h"
#include "VentaArchivo.h"

using namespace std;

VentaArchivo::VentaArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool VentaArchivo::guardar(Venta reg){
    bool resultado;

    FILE *pVenta;
    pVenta = fopen(_nombreArchivo.c_str(), "ab");

    if(pVenta == NULL){
        return false;
    }

    resultado=fwrite(&reg, sizeof(reg), 1, pVenta);

    fclose(pVenta);

    return resultado;
}


int VentaArchivo::getCantidadRegistros(){
    FILE *pVenta;
    pVenta= fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;


    if(pVenta == nullptr){ //validacion de apertura exitosa
        return 0;
    }

    fseek(pVenta,0, SEEK_END); // posicionamiento del puntero al final del archivo

    cantidad = ftell(pVenta) / sizeof(Venta); // ftell da la cantidad total de bytes del archivo aprovechando la posicion del puntero
                                                 // luego, divide esa cantidad de bytes entre la cantidad de bytes que pesa el objeto solo para obtener el total de ellos.

    fclose(pVenta);
    return cantidad;
}

bool VentaArchivo::leerVector(Venta vectorRegistros[], int cantidad){
    FILE *pVenta;
    pVenta= fopen(_nombreArchivo.c_str(), "rb");

    if(pVenta == nullptr){ //validacion de apertura exitosa
        return false;
    }

    fread(vectorRegistros,sizeof(Venta),cantidad,pVenta);

    fclose(pVenta);

    return true;
}

int VentaArchivo::buscarIndex(Venta vectorRegistros[], int cantidad, int idFactura) {
    for (int i = 0; i < cantidad; i++) {
        if (vectorRegistros[i].getIdFactura() == idFactura) {
            return i; // Retorna el �ndice si encuentra el ID
        }
    }
    return -1; // Retorna -1 si no lo encuentra
}

std::string VentaArchivo::getNombreArchivo(){
    return _nombreArchivo;
}

int VentaArchivo::getNuevoId(){
    int id = getCantidadRegistros() + 1 ;
    return id;
}

/*

#include<iostream>
#include <cstring>
#include "VentaManager.h"
#include "Venta.h"

using namespace std;

void VentaManager::cargarVenta(){
    Venta Factura;
    ClienteManager ClienteX;
    ProductoManager ProductoX;
    DetalleManager DetalleX;

    string cuitCliente;

    cout<<"Por favor ingrese el numero de CUIT del cliente";
    getline(cin,cuitCliente);
    ClienteX.buscarCuit(cuitCliente); // Si no existe el CUIT en la tabla de Clientes, informarle al usuario y crear un nuevo cliente.
    // Llamar a _clManager.cargarCliente() ??





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
