#include<iostream>
#include "Venta.h"
#include "VentaArchivo.h"

using namespace std;

VentaArchivo::VentaArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
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
            return i; // Retorna el índice si encuentra el ID
        }
    }
    return -1; // Retorna -1 si no lo encuentra
}

std::string VentaArchivo::getNombreArchivo(){ return _nombreArchivo;}

int VentaArchivo::getNuevoId(){
    int id = getCantidadRegistros() + 1 ;
    return id;
}
