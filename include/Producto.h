#pragma once
#include <cstring>


class Producto {
public:
    // Constructores
    Producto();
    Producto(int id, std::string descripcion, std::string marca, std::string tipo, int stock, bool oculto);

    // Getters
    int getIdProducto();
    std::string getDescripcion();
    std::string getMarca();
    std::string getTipo();
    int getStock();
    bool getOculto();

    // Setters
    bool setIdProducto(int idProducto);
    bool setDescripcion(const std::string& descripcion);
    bool setMarca(const std::string& marca);
    bool setTipo(const std::string& tipo);
    bool setStock(int stock);
    bool setOculto(bool oculto);

private:
    int _idProducto;
    char _descripcion[50];
    char _marca[15];
    char _tipo[15];
    int _stock;
    bool _oculto;
};
