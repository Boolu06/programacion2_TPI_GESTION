#ifndef CLIENTEMANAGER_H_INCLUDED
#define CLIENTEMANAGER_H_INCLUDED
#include "ClienteArchivo.h"

class ClienteManager{ ///Clase que maneja la carga el archivo y muestra
public:
    void cargarCliente();
    void mostrarCliente();

    //TODO: void borrarCliente(); void modificarCliente();

private:
    ClienteArchivo _archivo;
};


#endif // CLIENTEMANAGER_H_INCLUDED
