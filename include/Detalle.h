#pragma once
#include <cstring>

class Detalle {
    Detalle();
    // Setters
    void setIdFactura(int idFactura);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
    void setOculto(bool oculto);

    // Getters
    int getIdFactura() const;
    int getIdProducto() const;
    int getCantidad() const;
    float getPrecioUnitario() const;
    bool getOculto() const;

private:
    int _idFactura;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    bool _oculto;

};
