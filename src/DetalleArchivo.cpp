#include<iostream>
#include <cstring>
#include "Detalle.h"
#include "DetalleArchivo.h"

using namespace std;

DetalleArchivo::DetalleArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool DetalleArchivo::guardar(Detalle reg){
    bool resultado;

    FILE *pDetalle;
    pDetalle = fopen(_nombreArchivo.c_str(), "ab");

    if(pDetalle == NULL){
        return false;
    }

    resultado = fwrite(&reg, sizeof(reg), 1, pDetalle);

    fclose(pDetalle);

    return resultado;
}

bool DetalleArchivo::modificar(Detalle &registro, int index){
    bool resultado;
    int indexEnBytes = index * sizeof(Detalle);
    FILE *pDetalle;
    pDetalle = fopen(_nombreArchivo.c_str(), "rb+");

    if(pDetalle == NULL){
        return false;
    }
    fseek(pDetalle, indexEnBytes, SEEK_SET);

    resultado = fwrite(&registro, sizeof(Detalle), 1, pDetalle);

    fclose(pDetalle);

    return resultado;
}

bool DetalleArchivo::borrar(Detalle &registro, int index){
    // No implementation provided
    return false;
}

int DetalleArchivo::getCantidadRegistros(){
    FILE *pDetalle;
    pDetalle = fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;

    if(pDetalle == nullptr){
        return 0;
    }

    fseek(pDetalle, 0, SEEK_END);
    cantidad = ftell(pDetalle) / sizeof(Detalle);

    fclose(pDetalle);
    return cantidad;
}

bool DetalleArchivo::leerVector(Detalle vectorRegistros[], int cantidad){
    FILE *pDetalle;
    pDetalle = fopen(_nombreArchivo.c_str(), "rb");

    if(pDetalle == nullptr){
        return false;
    }

    fread(vectorRegistros, sizeof(Detalle), cantidad, pDetalle);

    fclose(pDetalle);

    return true;
}

int DetalleArchivo::buscarIndex(Detalle vectorRegistros[], int cantidad, int idFactura) {
    for (int i = 0; i < cantidad; i++) {
        if (vectorRegistros[i].getIdFactura() == idFactura) {
            return i;
        }
    }
    return -1;
}

std::string DetalleArchivo::getNombreArchivo(){
    return _nombreArchivo;
}

int DetalleArchivo::getNuevoId(){
    int id = getCantidadRegistros() + 1;
    return id;
}
