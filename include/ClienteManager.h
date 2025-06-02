#pragma once
#include "ClienteArchivo.h"

class ClienteManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarCliente();
    void listarClientes();
    void mostrarUnCliente(int id, std::string cuit,std::string nombre, std::string apellido, std::string telefono, std::string email, std::string direccion, int tipoCliente);
    void modificarCliente();
    void borrarCliente();
    void buscarCuit(std::string cuit);

private:
    ClienteArchivo _archivo;
};
