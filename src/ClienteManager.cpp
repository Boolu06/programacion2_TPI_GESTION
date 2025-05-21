#include<iostream>
#include <cstring>
#include "Cliente.h"
#include "ClienteManager.h"

using namespace std;

void ClienteManager::cargarCliente(){
    Cliente nuevoCliente;
    int id;
    string cuit;
    string nombre;
    string apellido;
    string telefono;
    string email;
    string direccion;
    int tipo;
    bool datoCorrecto = false;
    bool frenarCarga = false;
    cin.ignore();

    id = _archivo.getNuevoId();
    nuevoCliente.setId(id);
    cout<< "Cliente ID signado: " <<  id << endl;


    while(!datoCorrecto){
        cout<<"Ingrese el CUIT"<<endl;
        getline(cin, cuit);
        datoCorrecto = nuevoCliente.setCuit(cuit);
    }

    datoCorrecto = false; // resetar el booleando para ingresar al proximo bucle

    while(!datoCorrecto){
        cout<<"Ingrese el nombre"<<endl;
        getline(cin, nombre);
        datoCorrecto = nuevoCliente.setNombre(nombre);
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el apellido"<<endl;
        getline(cin, apellido);
        datoCorrecto = nuevoCliente.setApellido(apellido);
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el telefono"<<endl;
        getline(cin, telefono);
        datoCorrecto = nuevoCliente.setTelefono(telefono);
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el email"<<endl;
        getline(cin, email);
        datoCorrecto = nuevoCliente.setEmail(email);
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese la direccion"<<endl;
        getline(cin, direccion);
        datoCorrecto = nuevoCliente.setDireccion(direccion);
    }

    datoCorrecto = false;
    while(!datoCorrecto){
        cout<<"Ingrese el tipo de cliente"<<endl;
        cout<<"1. Particular"<<endl;
        cout<<"2. Empresa"<<endl;
        cin>>tipo;
        datoCorrecto = nuevoCliente.setTipoCliente(tipo);
    }

    if(datoCorrecto){

        if(_archivo.guardar(nuevoCliente)){
            cout<<"Cliente registrado correctamente."<<endl;
        }
        else{
            cout<<"No se pudo registrar cliente, intentelo de nuevo."<<endl;
        }
        system("pause");

    }
}


void ClienteManager::mostrarCliente(){
    int cantidad = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidad];

    _archivo.leerVector(vectorClientes, cantidad); // esta funcion mete en el vectorClientes los clientes que consiga en el archivo.dat.

    for (int i=0; i < cantidad; i++ ){
        cout << "----------ID Cliente: "<<vectorClientes[i].getId()<<" ------------" << endl;
        cout << "Nombre: " << vectorClientes[i].getNombre() << endl;
        cout<< "Apellido: "<< vectorClientes[i].getApellido()<<endl;
        cout << "CUIT: " << vectorClientes[i].getCuit() << endl;
        cout<< "Telefono: "<< vectorClientes[i].getTelefono()<<endl;
        cout<< "Email: "<< vectorClientes[i].getEmail()<<endl;
        cout<< "Direccion: "<< vectorClientes[i].getDireccion()<<endl;
        cout<< "Tipo de cliente: "<< vectorClientes[i].getTipoCliente()<<endl;
        cout << "-----------------------------" << endl;
    }
    system("pause");

    delete[]vectorClientes;
}
