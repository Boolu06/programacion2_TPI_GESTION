#include<iostream>
#include <cstring>
#include "Producto.h"
#include "ProductoArchivo.h"

using namespace std;


ProductoArchivo::ProductoArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}

bool ProductoArchivo::guardar(Producto reg){
    bool resultado;

    FILE *pProducto;
    pProducto = fopen(_nombreArchivo.c_str(), "ab");

    if(pProducto == NULL){
        return false;
    }

    resultado=fwrite(&reg, sizeof(reg), 1, pProducto);

    fclose(pProducto);

    return resultado;
}

bool ProductoArchivo::modificar(Producto &registro, int index){
    bool resultado;
    int indexEnBytes = index * sizeof(Producto);
    FILE *pProducto;
    pProducto = fopen(_nombreArchivo.c_str(), "rb+");

    if(pProducto == NULL){
        return false;
    }
    fseek(pProducto,indexEnBytes, SEEK_SET);

    resultado = fwrite(&registro, sizeof(Producto), 1, pProducto);

    fclose(pProducto);
}

int ProductoArchivo::getCantidadRegistros(){
    FILE *pProducto;
    pProducto= fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;


    if(pProducto == nullptr){ //validacion de apertura exitosa
        return 0;
    }

    fseek(pProducto,0, SEEK_END); // posicionamiento del puntero al final del archivo

    cantidad = ftell(pProducto) / sizeof(Producto); // ftell da la cantidad total de bytes del archivo aprovechando la posicion del puntero
                                                 // luego, divide esa cantidad de bytes entre la cantidad de bytes que pesa el objeto solo para obtener el total de ellos.

    fclose(pProducto);
    return cantidad;
}

bool ProductoArchivo::leerVector(Producto vectorRegistros[], int cantidad){
    FILE *pProducto;
    pProducto= fopen(_nombreArchivo.c_str(), "rb");

    if(pProducto == nullptr){ //validacion de apertura exitosa
        return false;
    }

    fread(vectorRegistros,sizeof(Producto),cantidad,pProducto);

    fclose(pProducto);

    return true;
}

int ProductoArchivo::buscarIndex(Producto vectorRegistros[], int cantidad, int idProducto) {
    for (int i = 0; i < cantidad; i++) {
        if (vectorRegistros[i].getIdProducto() == idProducto) {
            return i; // Retorna el índice si encuentra el ID
        }
    }
    return -1; // Retorna -1 si no lo encuentra
}

std::string ProductoArchivo::getNombreArchivo(){
    return _nombreArchivo;
}

int ProductoArchivo::getNuevoId(){
    int id = getCantidadRegistros() + 1 ;
    return id;
}
