#pragma once
#include <cstring>


class Producto {
public:
    // Constructores
    Producto();
    Producto(int id,float precioUnitario, std::string descripcion, std::string marca, std::string tipo, int stock, bool oculto);

    // Getters
    int getIdProducto();
    float getPrecioUnitario();
    std::string getDescripcion();
    std::string getMarca();
    std::string getTipo();
    int getStock();
    bool getOculto();

    // Setters
    bool setIdProducto(int idProducto);
    bool setPrecioUnitario(float precioUnitario);
    bool setDescripcion(const std::string& descripcion);
    bool setMarca(const std::string& marca);
    bool setTipo(const std::string& tipo);
    bool setStock(int stock);
    bool setOculto(bool oculto);

private:
    int _idProducto;
    float _precioUnitario;
    char _descripcion[50];
    char _marca[15];
    char _tipo[15];
    int _stock;
    bool _oculto;
};
