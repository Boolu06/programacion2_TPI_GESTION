#pragma once
#include "ClienteArchivo.h"
#include "Cliente.h"

class ClienteManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarCliente(const std::string &cuit = "");
    void listarClientes();
    void filtrarPorId(Cliente vectorClientes[], int cantidadRegistros);
    void filtrarPorCuit(Cliente vectorClientes[], int cantidadRegistros);
    void filtrarPorNombre(Cliente vectorClientes[], int cantidadRegistros);
    void filtrarPorApellido(Cliente vectorClientes[], int cantidadRegistros);
    void filtrarPorTipo(Cliente vectorClientes[], int cantidadRegistros);
    void mostrarUnCliente(int id, std::string cuit,std::string nombre, std::string apellido, std::string telefono, std::string email, std::string direccion, int tipoCliente);
    void modificarCliente();
    void borrarCliente();
    Cliente buscarCuit(std::string cuit);


private:
    ClienteArchivo _archivo;
};
