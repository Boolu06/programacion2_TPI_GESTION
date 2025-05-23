#include<iostream>
#include <cstring>
#include "Producto.h"

using namespace std;

Producto::Producto() {
    _idProducto = 0;
    _descripcion[0] = '\0';
    _marca[0] = '\0';
    _tipo[0] = '\0';
    _stock = 0;
    _oculto = false;
}

Producto::Producto(int id, std::string descripcion, std::string marca, std::string tipo, int stock, bool oculto) {
    setIdProducto(id);
    setDescripcion(descripcion);
    setMarca(marca);
    setTipo(tipo);
    setStock(stock);
    setOculto(oculto);
}


// Getters
int Producto::getIdProducto() { return _idProducto; }
std::string Producto::getDescripcion() { return std::string(_descripcion); }
std::string Producto::getMarca() { return std::string(_marca); }
std::string Producto::getTipo() { return std::string(_tipo); }
int Producto::getStock() { return _stock; }
bool Producto::getOculto() { return _oculto; }

// Setters
bool Producto::setIdProducto(int idProducto) {
    if (idProducto > 0) {
        _idProducto = idProducto;
        return true;
    } else {
        system("cls");
        cout << " ------------------------------- " << endl;
        cout << "| El ID debe ser un n�mero mayor que 0 |" << endl;
        cout << " ------------------------------- " << endl << endl;
        return false;
    }
}

bool Producto::setDescripcion(const std::string& descripcion) {
    if (descripcion.size() > 0 && descripcion.size() < 50) {
        strncpy(_descripcion, descripcion.c_str(), 49);
        _descripcion[49] = '\0';
        return true;
    } else {
        system("cls");
        cout << " -------------------------------------------------- " << endl;
        cout << "| La descripci�n debe tener entre 1 y 49 caracteres |" << endl;
        cout << " -------------------------------------------------- " << endl << endl;
        return false;
    }
}

bool Producto::setMarca(const std::string& marca) {
    if (marca.size() > 0 && marca.size() < 15) {
        strncpy(_marca, marca.c_str(), 14);
        _marca[14] = '\0';
        return true;
    } else {
        system("cls");
        cout << " ----------------------------------------------- " << endl;
        cout << "| La marca debe tener entre 1 y 14 caracteres    |" << endl;
        cout << " ----------------------------------------------- " << endl << endl;
        return false;
    }
}

bool Producto::setTipo(const std::string& tipo) {
    if (tipo.size() > 0 && tipo.size() < 15) {
        strncpy(_tipo, tipo.c_str(), 14);
        _tipo[14] = '\0';
        return true;
    } else {
        system("cls");
        cout << " ----------------------------------------------- " << endl;
        cout << "| El tipo debe tener entre 1 y 14 caracteres     |" << endl;
        cout << " ----------------------------------------------- " << endl << endl;
        return false;
    }
}

bool Producto::setStock(int stock) {
    if (stock >= 0) {
        _stock = stock;
        return true;
    } else {
        system("cls");
        cout << " -------------------------------- " << endl;
        cout << "| El stock no puede ser negativo |" << endl;
        cout << " -------------------------------- " << endl << endl;
        return false;
    }
}

bool Producto::setOculto(bool oculto) {
    _oculto = oculto;
    return true;
}
