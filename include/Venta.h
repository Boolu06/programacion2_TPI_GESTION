#pragma once
#include <cstring>
#include "Fecha.h"
class Venta {

    Venta();
    // Setters
    void setIdFactura(int idFactura);
    void setIdCliente(int idCliente);
    void setFechaVenta(Fecha fechaVenta);
    void setImporteTotal(float importeTotal);
    void setOculto(bool oculto);

    // Getters
    int getIdFactura() const;
    int getIdCliente() const;
    Fecha getFechaVenta() const;
    float getImporteTotal() const;
    bool getOculto() const;

private:
    int _idFactura;
    int _idCliente;
    Fecha _fechaVenta;
    float _importeTotal;
    bool _oculto;

};
