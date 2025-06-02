#pragma once
#include <cstring>
#include "Fecha.h"
class Venta {
public:
    Venta();
    // Setters
    void setIdFactura(int idFactura);
    void setIdCliente(int idCliente);
    void setFechaVenta(Fecha fechaVenta);
    void setImporteTotal(float importeTotal);
    void setOculto(bool oculto);

    // Getters
    int getIdFactura();
    int getIdCliente();
    Fecha getFechaVenta();
    float getImporteTotal();
    bool getOculto();

private:
    int _idFactura;
    int _idCliente;
    Fecha _fechaVenta;
    float _importeTotal;
    bool _oculto;

};
