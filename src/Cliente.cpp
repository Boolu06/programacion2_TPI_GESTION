#include<iostream>
#include <cstring>
#include "Funciones.h"
#include "Cliente.h"

using namespace std;

Cliente::Cliente(){
    _id = 0;
    _cuit[0] = '\0';
    _nombre[0] = '\0';
    _apellido[0] = '\0';
    _telefono[0] = '\0';
    _email[0] = '\0';
    _direccion[0] = '\0';
    _tipoCliente = 0;
    _oculto = false;
}

Cliente::Cliente(int id, std::string cuit,std::string nombre, std::string apellido, std::string telefono, std::string email, std::string direccion, int tipoCliente, bool oculto){
    setId(id);
    setCuit(cuit);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setDireccion(direccion);
    setTipoCliente(tipoCliente);
    setOculto(oculto);
}

//Getters
int Cliente::getId(){
    return _id;
}
std::string Cliente::getCuit(){
    return _cuit;
}
std::string Cliente::getNombre(){
    return _nombre;
}
std::string Cliente::getApellido(){
    return _apellido;
}
std::string Cliente::getTelefono(){
    return _telefono;
}
std::string Cliente::getEmail(){
    return _email;
}
std::string Cliente::getDireccion(){
    return _direccion;
}
int Cliente::getTipoCliente(){
    return _tipoCliente;
}
bool Cliente::getOculto(){
    return _oculto;
}


//Setters
int Cliente::setId(const int id){
    _id = id;
}

bool Cliente::setCuit(const std::string &cuit){
    if(cuit.size() == 11 && esSoloNumeros(cuit) == true){
        strcpy(_cuit, cuit.c_str()); // Conversion de string a char
        return true;
    }
    else{
        return false;
    }
}
bool Cliente::setNombre(const std::string &nombre){
    if(nombre.size() < 30 && nombre.size() > 0){
        if(esSoloLetras(nombre) == true){
            strcpy(_nombre, nombre.c_str());
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }

}
bool Cliente::setApellido(const std::string &apellido){
    if(apellido.size() < 30 && apellido.size() > 0){
        if(esSoloLetras(apellido) == true){
            strcpy(_apellido, apellido.c_str());
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool Cliente::setTelefono(const std::string &telefono){
    if(telefono.size() == 11 && esSoloNumeros(telefono) == true){
        strcpy(_telefono, telefono.c_str());
        return true;
    }
    else{
        return false;
    }

}
bool Cliente::setEmail(const std::string &email){
    if(email.size() < 50 && email.size() > 0){
        strcpy(_email, email.c_str());
        return true;
    }
    else{
        return false;
    }
}
bool Cliente::setDireccion(const std::string &direccion){
    if(direccion.size() < 50 && direccion.size() > 0 ){
        strcpy(_direccion, direccion.c_str());
        return true;
    }
    else{
        return false;
    }
}
bool Cliente::setTipoCliente(int tipoCliente){
    if( tipoCliente > 0 && tipoCliente < 3){
       _tipoCliente=tipoCliente;
        return true;
    }
    else{
        return false;
    }
}
bool Cliente::setOculto(bool oculto){

    _oculto = oculto;

    return true;
}






