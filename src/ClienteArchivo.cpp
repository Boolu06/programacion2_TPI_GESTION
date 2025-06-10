#include<iostream>
#include <cstring>
#include "Cliente.h"
#include "ClienteArchivo.h"

using namespace std;


ClienteArchivo::ClienteArchivo(std::string nombreArchivo){
    _nombreArchivo=nombreArchivo;
}

bool ClienteArchivo::guardar(Cliente reg){
    bool resultado;

    FILE *pCliente;
    pCliente = fopen(_nombreArchivo.c_str(), "ab");

    if(pCliente == NULL){
        return false;
    }

    resultado=fwrite(&reg, sizeof(reg), 1, pCliente);

    fclose(pCliente);

    return resultado;
}

bool ClienteArchivo::modificar(Cliente &registro, int index){
    bool resultado;
    int indexEnBytes = index * sizeof(Cliente);
    FILE *pCliente;
    pCliente = fopen(_nombreArchivo.c_str(), "rb+");

    if(pCliente == NULL){
        return false;
    }
    fseek(pCliente,indexEnBytes, SEEK_SET);

    resultado = fwrite(&registro, sizeof(Cliente), 1, pCliente);

    fclose(pCliente);
}

int ClienteArchivo::getCantidadRegistros(){
    FILE *pCliente;
    pCliente= fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;


    if(pCliente == nullptr){ //validacion de apertura exitosa
        return 0;
    }

    fseek(pCliente,0, SEEK_END); // posicionamiento del puntero al final del archivo

    cantidad = ftell(pCliente) / sizeof(Cliente); // ftell da la cantidad total de bytes del archivo aprovechando la posicion del puntero
                                                 // luego, divide esa cantidad de bytes entre la cantidad de bytes que pesa el objeto solo para obtener el total de ellos.

    fclose(pCliente);
    return cantidad;
}

bool ClienteArchivo::leerVector(Cliente vectorRegistros[], int cantidad){
    FILE *pCliente;
    pCliente= fopen(_nombreArchivo.c_str(), "rb");

    if(pCliente == nullptr){ //validacion de apertura exitosa
        return false;
    }

    fread(vectorRegistros,sizeof(Cliente),cantidad,pCliente);

    fclose(pCliente);

    return true;
}

int ClienteArchivo::buscarIndex(Cliente vectorRegistros[], int cantidad, int idCliente) {
    for (int i = 0; i < cantidad; i++) {
        if (vectorRegistros[i].getId() == idCliente) {
            return i; // Retorna el índice si encuentra el ID
        }
    }
    return -1; // Retorna -1 si no lo encuentra
}

int ClienteArchivo::buscarIndexCuit(Cliente vectorRegistros[], int cantidad, std::string cuit) {
    for (int i = 0; i < cantidad; i++) {
        if (vectorRegistros[i].getCuit() == cuit) {
            return i; // Retorna el índice si encuentra el cuit
        }
    }
    return -1; // Retorna -1 si no lo encuentra
}

std::string ClienteArchivo::getNombreArchivo(){ return _nombreArchivo;}

int ClienteArchivo::getNuevoId(){
    int id = getCantidadRegistros() + 1 ;
    return id;
}


/////////////////////////////////////------------------------------------------------------


