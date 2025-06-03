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
    nuevoCliente.setOculto(false);

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


void ClienteManager::listarClientes(){
    int cantidad = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidad];

    _archivo.leerVector(vectorClientes, cantidad); // esta funcion mete en el vectorClientes los clientes que consiga en el archivo.dat.

    for (int i=0; i < cantidad; i++ ){
        if(vectorClientes[i].getOculto()== false){
        mostrarUnCliente(vectorClientes[i].getId(),
                         vectorClientes[i].getCuit(),
                         vectorClientes[i].getNombre(),
                         vectorClientes[i].getApellido(),
                         vectorClientes[i].getTelefono(),
                         vectorClientes[i].getEmail(),
                         vectorClientes[i].getDireccion(),
                         vectorClientes[i].getTipoCliente()
                         );
        }
    }
    system("pause");

    delete[]vectorClientes;
}

void ClienteManager::buscarCuit(std::string cuit){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidadRegistros];
    _archivo.leerVector(vectorClientes, cantidadRegistros);

    int index = _archivo.buscarIndexCuit(vectorClientes,cantidadRegistros,cuit);


    mostrarUnCliente(vectorClientes[index].getId(),
                         vectorClientes[index].getCuit(),
                         vectorClientes[index].getNombre(),
                         vectorClientes[index].getApellido(),
                         vectorClientes[index].getTelefono(),
                         vectorClientes[index].getEmail(),
                         vectorClientes[index].getDireccion(),
                         vectorClientes[index].getTipoCliente()
                         );
    system("pause");
}

void ClienteManager::modificarCliente(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidadRegistros];
     _archivo.leerVector(vectorClientes, cantidadRegistros);
    int idClienteModificar;

    cout<< "Ingrese el ID del cliente que desea modificar: " <<endl;
    cin>> idClienteModificar;
    int index = _archivo.buscarIndex(vectorClientes,cantidadRegistros,idClienteModificar);
    bool huboModificaciones= false;

    if(index >= 0){
        system("cls");
        cout<< "Id de cliente encontrado! "<< endl;
        mostrarUnCliente(vectorClientes[index].getId(),
                         vectorClientes[index].getCuit(),
                         vectorClientes[index].getNombre(),
                         vectorClientes[index].getApellido(),
                         vectorClientes[index].getTelefono(),
                         vectorClientes[index].getEmail(),
                         vectorClientes[index].getDireccion(),
                         vectorClientes[index].getTipoCliente()
                         );
        system("pause");

        bool flag = true;
        bool datoCorrecto = false;
        int opcion;
        while (flag == true){
            cout<< "Que dato deseas modificar ? " <<endl<<endl;
            cout<< "1. Numero de Cuit" <<endl;
            cout<< "2. Nombre " <<endl;
            cout<< "3. Apellido " <<endl;
            cout<< "4. Telefono " <<endl;
            cout<< "5. Email " <<endl;
            cout<< "6. Direccion " <<endl;
            cout<< "7. Tipo de cliente " <<endl;
            cout<< "0. Terminar modificaciones"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion){
                case 1:{
                    string cuit;
                    while(!datoCorrecto){
                        cout<<"Ingrese el CUIT"<<endl;
                        getline(cin, cuit);
                        datoCorrecto = vectorClientes[index].setCuit(cuit);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 2:{
                    string nombre;
                    while(!datoCorrecto){
                        cout<<"Ingrese el nombre"<<endl;
                        getline(cin, nombre);
                        datoCorrecto = vectorClientes[index].setNombre(nombre);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 3:{
                    string apellido;
                    while(!datoCorrecto){
                        cout<<"Ingrese el apellido"<<endl;
                        getline(cin, apellido);
                        datoCorrecto = vectorClientes[index].setApellido(apellido);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 4:{
                    string telefono;
                    while(!datoCorrecto){
                        cout<<"Ingrese el telefono"<<endl;
                        getline(cin, telefono);
                        datoCorrecto = vectorClientes[index].setTelefono(telefono);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 5:{
                    string email;
                    while(!datoCorrecto){
                        cout<<"Ingrese el email"<<endl;
                        getline(cin, email);
                        datoCorrecto = vectorClientes[index].setEmail(email);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 6:{
                    string direccion;
                    while(!datoCorrecto){
                        cout<<"Ingrese la direccion"<<endl;
                        getline(cin, direccion);
                        datoCorrecto = vectorClientes[index].setDireccion(direccion);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 7:{
                    int tipo;
                    while(!datoCorrecto){
                        cout<<"Ingrese el tipo de cliente"<<endl;
                        cout<<"1. Particular"<<endl;
                        cout<<"2. Empresa"<<endl;
                        cin>>tipo;
                        datoCorrecto = vectorClientes[index].setTipoCliente(tipo);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 0: flag=false; system("cls"); break;
            }
        }

    }
    else{
        cout << "resultado de busqueda index: " << index << endl;
        cout << "Id de cliente no encontrado chau" << endl;
        system("pause");
    }

    cout << " tamos mandando el indexxxxxxxxxxxx: " << index;
    if(huboModificaciones){
        _archivo.modificar(vectorClientes[index], index);
    }

    delete []vectorClientes;
}

void ClienteManager::mostrarUnCliente(int id, std::string cuit,std::string nombre, std::string apellido, std::string telefono, std::string email, std::string direccion, int tipoCliente){
    cout << "----------ID Cliente: "<<id<<" ------------" << endl;
        cout << "Nombre: " << nombre << endl;
        cout<< "Apellido: "<< apellido <<endl;
        cout << "CUIT: " << cuit << endl;
        cout<< "Telefono: "<< telefono <<endl;
        cout<< "Email: "<< email <<endl;
        cout<< "Direccion: "<< direccion <<endl;
        cout<< "Tipo de cliente: "<< tipoCliente <<endl;
        cout << "-----------------------------" << endl;
}

void ClienteManager::borrarCliente(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidadRegistros];
    _archivo.leerVector(vectorClientes, cantidadRegistros);
    int idClienteBorrar;

    cout<< "Ingrese el ID del cliente que desea borrar: " <<endl;
    cin>> idClienteBorrar;
    int index = _archivo.buscarIndex(vectorClientes,cantidadRegistros,idClienteBorrar);
    bool huboModificaciones = false;
    if(index >= 0){
        system("cls");
        cout<< "Este es el cliente que vas a borrar: "<< endl;
        mostrarUnCliente(vectorClientes[index].getId(),
                         vectorClientes[index].getCuit(),
                         vectorClientes[index].getNombre(),
                         vectorClientes[index].getApellido(),
                         vectorClientes[index].getTelefono(),
                         vectorClientes[index].getEmail(),
                         vectorClientes[index].getDireccion(),
                         vectorClientes[index].getTipoCliente()
                         );
        system("pause");

        bool flag = true;

        int opcion;

        while (flag == true){
            cout<< "Que estas seguro que lo quieres borrar ? " <<endl<<endl;
            cout<< "1. S1" <<endl;
            cout<< "0. Cancelar borrado"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion){
                case 1:
                    vectorClientes[index].setOculto(true);
                    flag = false;
                    huboModificaciones = true;
                    break;
                case 0:
                    flag=false; system("cls"); break;
            }
        }
    }
    else{
        cout << "resultado de busqueda index: " << index << endl;
        cout << "Id de cliente no encontrado chau" << endl;
        system("pause");
    }
    if(huboModificaciones){
        _archivo.modificar(vectorClientes[index], index);
    }

    delete []vectorClientes;
}
