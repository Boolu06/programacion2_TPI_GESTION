#ifndef CLIENTEMANAGER_H_INCLUDED
#define CLIENTEMANAGER_H_INCLUDED
#include "ClienteArchivo.h"

class ClienteManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarCliente();
    void listarClientes();
    void mostrarUnCliente(int id, std::string cuit,std::string nombre, std::string apellido, std::string telefono, std::string email, std::string direccion, int tipoCliente);
    void modificarCliente();
    void borrarCliente();

private:
    ClienteArchivo _archivo;
};


#endif // CLIENTEMANAGER_H_INCLUDED
