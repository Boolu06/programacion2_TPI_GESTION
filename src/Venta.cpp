#include <iostream>
#include "Venta.h"
using namespace std;

Venta::Venta(){
    _idFactura = 0;
    _idCliente = 0;
    _importeTotal = 0.0;
    _oculto = false;
    // _fechaVenta se inicializa con su constructor por defecto
};
// No se crea un constructor parametrizado porque es muy probable que los parametros de la venta los ingresemos usando los setters.

void Venta::setIdFactura(int idFactura){
    _idFactura = idFactura;
};
void Venta::setIdCliente(int idCliente){
    _idCliente = idCliente;
};
void Venta::setImporteTotal (float importeTotal){
    _importeTotal = importeTotal;
};
void Venta::setOculto( bool oculto){
    _oculto = oculto;
};
int Venta::getIdFactura(){return _idFactura};
int Venta::getIdCliente(){return _idCliente};
float Venta::getImporteTotal(){return _importeTotal};
bool Venta::getOculto(){return _oculto};


