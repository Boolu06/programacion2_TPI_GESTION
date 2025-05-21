#pragma once
#include <cstring>

class Cliente{
public:
    //Constructores
    Cliente();
    Cliente(int id, std::string cuit,std::string nombre, std::string apellido, std::string telefono, std::string email, std::string direccion, int tipoCliente);

    //Getters
    int getId();
    std::string getCuit();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getEmail();
    std::string getDireccion();
    int getTipoCliente();

    //Setters
    int setId(int nuevoId);
    bool setCuit(const std::string &cuit);
    bool setNombre(const std::string &nombre);
    bool setApellido(const std::string &apellido);
    bool setTelefono(const std::string &telefono);
    bool setEmail(const std::string &email);
    bool setDireccion(const std::string &direccion);
    bool setTipoCliente(int tipoCliente);

private:
    int _id;
    char _cuit[12];
    char _nombre[30];
    char _apellido[30];
    char _telefono[16];
    char _email[50];
    char _direccion[50];
    int _tipoCliente;
};
