#pragma once
#include <cstring>

class Detalle {
public:
    Detalle();
    // Setters
    void setIdFactura(int idFactura);
    void setIdProducto(int idProducto);
    void setCantidad(int cantidad);
    void setPrecioUnitario(float precioUnitario);
    void setOculto(bool oculto);

    // Getters
    int getIdFactura();
    int getIdProducto();
    int getCantidad();
    float getPrecioUnitario();
    bool getOculto();

private:
    int _idFactura;
    int _idProducto;
    int _cantidad;
    float _precioUnitario;
    bool _oculto;

};
