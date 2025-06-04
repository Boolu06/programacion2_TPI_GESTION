#include <iostream>
#include "Detalle.h"
using namespace std;

Detalle::Detalle(){
    int _idFactura;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    bool _oculto;
}

void Detalle::setIdFactura(int idFactura){
    _idFactura = idFactura;
}
void Detalle::setIdProducto(int idProducto){
    _idProducto = idProducto;
}
void Detalle::setCantidad (int cantidad){
    _cantidad = cantidad;
}

void Detalle::setPrecioUnitario (float precioUnitario){
    _precioUnitario = precioUnitario;
}

void Detalle::setOculto( bool oculto){
    _oculto = oculto;
}


int Detalle::getIdFactura(){return _idFactura;}
int Detalle::getIdProducto(){return _idProducto;}
int Detalle::getCantidad(){return _cantidad;}
float Detalle::getPrecioUnitario(){return _precioUnitario;}
bool Detalle::getOculto(){return _oculto;}
