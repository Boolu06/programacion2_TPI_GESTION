#include<iostream>
#include <cstring>
#include "Cliente.h"
#include "ClienteManager.h"
#include "Funciones.h"
using namespace std;

void ClienteManager::cargarCliente(const std::string &cuit){
    Cliente nuevoCliente;
    int id;
    string cuitFinal = cuit;
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
        if(cuit == ""){
            cout<<"Ingrese el CUIT"<<endl;
            getline(cin, cuitFinal);
        }
        datoCorrecto = nuevoCliente.setCuit(cuitFinal);
        if(!datoCorrecto){
            cout << " ------------------------------------------ " << endl;
            cout << "|El cuit debe tener 11 caracteres numericos|" << endl;
            cout << " ------------------------------------------ " << endl << endl;
        }
    }

    datoCorrecto = false; // resetar el booleando para ingresar al proximo bucle

    while(!datoCorrecto){
        cout<<"Ingrese el nombre"<<endl;
        getline(cin, nombre);
        datoCorrecto = nuevoCliente.setNombre(nombre);

        if(!datoCorrecto){
            cout << " ----------------------------------------------------------------------------------- " << endl;
            cout << "|El nombre debe tener al menos 1 caracter, menos de 30 y no tiene que tener espacios|" << endl;
            cout << " ------------------------------------------------------ ---------------------------- "  << endl << endl;
        }
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el apellido"<<endl;
        getline(cin, apellido);
        datoCorrecto = nuevoCliente.setApellido(apellido);

        if(!datoCorrecto){
            cout << " -------------------------------------------------------- " << endl;
            cout << "|El apellido debe tener al menos 1 caracter y menos de 30|" << endl;
            cout << " -------------------------------------------------------- " << endl<< endl;
        }
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el telefono"<<endl;
        getline(cin, telefono);
        datoCorrecto = nuevoCliente.setTelefono(telefono);

        if(!datoCorrecto){
            cout << " ---------------------------------------------- " << endl;
            cout << "|El telefono debe tener 11 caracteres numericos|" << endl;
            cout << " ---------------------------------------------- " << endl << endl;
        }
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el email"<<endl;
        getline(cin, email);
        datoCorrecto = nuevoCliente.setEmail(email);

        if(!datoCorrecto){
            cout << " ------------------------------------ " << endl;
            cout << "| El email no es valido              |" << endl;
            cout << " ------------------------------------ " << endl << endl;
        }
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese la direccion"<<endl;
        getline(cin, direccion);
        datoCorrecto = nuevoCliente.setDireccion(direccion);

        if(!datoCorrecto){
            cout << " --------------------------------------------- " << endl;
            cout << "| Direccion no puede ser mas de 50 caracteres |" << endl;
            cout << " --------------------------------------------- " << endl << endl;
        }
    }

    datoCorrecto = false;
    while(!datoCorrecto){
        cout<<"Ingrese el tipo de cliente"<<endl;
        cout<<"1. Particular"<<endl;
        cout<<"2. Empresa"<<endl;
        cin>>tipo;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << " ------------------------------ " << endl;
            cout << "| Selecciona una opcion valida |" << endl;
            cout << " ------------------------------ " << endl << endl;
        }
        datoCorrecto = nuevoCliente.setTipoCliente(tipo);

        if(!datoCorrecto){
            cout << " ------------------------------ " << endl;
            cout << "| Selecciona una opcion valida |" << endl;
            cout << " ------------------------------ " << endl << endl;
        }
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

    int opc;
    bool flag = true;
    while(flag==true){
        cout<<"---------------------------"<<endl;
        cout<<" 1. Filtrar por ID de cliente"<<endl;
        cout<<" 2. Filtrar por CUIT"<<endl;
        cout<<" 3. Filtrar por Nombre"<<endl;
        cout<<" 4. Filtrar por Apellido"<<endl;
        cout<<" 5. Filtrar por tipo de cliente"<<endl;
        cout<<" 6. Listar todos los clientes"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. Volver al menu principal"<<endl<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: filtrarPorId(vectorClientes,cantidad); break;
            case 2: filtrarPorCuit(vectorClientes,cantidad); break;
            case 3: filtrarPorNombre(vectorClientes,cantidad); break;
            case 4: filtrarPorApellido(vectorClientes,cantidad); break;
            case 5: filtrarPorTipo(vectorClientes,cantidad); break;

            case 6:{
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
                }

            case 0: flag=false; system("cls"); break;

            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }

    system("pause");




    delete[]vectorClientes;
}

void ClienteManager::filtrarPorId(Cliente vectorClientes[], int cantidadRegistros){
    int idCliente=0;
    cout<<"Ingrese el ID del cliente que desea buscar: "<<endl;
    cin >> idCliente;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << " --------------------------- " << endl;
        cout << "| Ingrese una opcion valida |" << endl;
        cout << " --------------------------- " << endl << endl;
    }
    if(idCliente>0){
        for(int i=0; i < cantidadRegistros; i++ ){
            if(vectorClientes[i].getId()==idCliente && vectorClientes[i].getOculto()== false){
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
    }
    else{
        cout<<"ID invalido"<<endl;
        system("pause");
    }

}

void ClienteManager::filtrarPorCuit(Cliente vectorClientes[], int cantidadRegistros){
    string cuitCliente;
    cout<<"Ingrese el CUIT del cliente que desea buscar: "<<endl;
    cin.ignore();
    getline(cin,cuitCliente);

    if(!cuitCliente.empty()){
        for (int i=0; i < cantidadRegistros; i++ ){
            if(vectorClientes[i].getCuit()==cuitCliente && vectorClientes[i].getOculto()== false){
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

    }
    else{
        cout<<"ID invalido"<<endl;
        system("pause");
    }
}

void ClienteManager::filtrarPorNombre(Cliente vectorClientes[], int cantidadRegistros){
    string nombreCliente;
    cout<<"Ingrese el nombre del cliente que desea buscar: "<<endl;
    cin.ignore();
    getline(cin,nombreCliente);

    if(!nombreCliente.empty()){
        for (int i=0; i < cantidadRegistros; i++ ){
            if(aMinusculas(vectorClientes[i].getNombre())== aMinusculas(nombreCliente) && vectorClientes[i].getOculto()== false){
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

    }
    else{
        cout<<"nombre invalido"<<endl;
        system("pause");
    }
}

void ClienteManager::filtrarPorApellido(Cliente vectorClientes[], int cantidadRegistros){
    string apellidoCliente;
    cout<<"Ingrese el apellido del cliente que desea buscar: "<<endl;
    cin.ignore();
    getline(cin,apellidoCliente);

    if(!apellidoCliente.empty()){
        for (int i=0; i < cantidadRegistros; i++ ){
            if(aMinusculas(vectorClientes[i].getApellido())== aMinusculas(apellidoCliente) && vectorClientes[i].getOculto()== false){
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

    }
    else{
        cout<<"apellido invalido"<<endl;
        system("pause");
    }
}

void ClienteManager::filtrarPorTipo(Cliente vectorClientes[], int cantidadRegistros){
    int tipoCliente;
    cout<<"Ingrese el tipo de cliente que desea buscar"<<endl;
        cout<<"1. Particular"<<endl;
        cout<<"2. Empresa"<<endl;
        cin>>tipoCliente;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << " ------------------------------ " << endl;
            cout << "| Selecciona una opcion valida |" << endl;
            cout << " ------------------------------ " << endl << endl;
        }

    if(tipoCliente > 0 && tipoCliente < 3){
        for (int i=0; i < cantidadRegistros; i++ ){
            if(vectorClientes[i].getTipoCliente()== tipoCliente && vectorClientes[i].getOculto()== false){
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

    }
    else{
        cout<<"Tipo invalido"<<endl;
        system("pause");
    }
}

Cliente ClienteManager::buscarCuit(std::string cuit){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidadRegistros];
    _archivo.leerVector(vectorClientes, cantidadRegistros);

    int index = _archivo.buscarIndexCuit(vectorClientes,cantidadRegistros,cuit);


    if(index>-1){
        return(vectorClientes[index]);
    }
    else{
        Cliente ClienteVacio;
        return ClienteVacio;
    }
}

void ClienteManager::modificarCliente(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidadRegistros];
     _archivo.leerVector(vectorClientes, cantidadRegistros);
    int idClienteModificar;

    cout<< "Ingrese el ID del cliente que desea modificar: " <<endl;
    cin>> idClienteModificar;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << " ------------------------------ " << endl;
        cout << "| Selecciona una opcion valida |" << endl;
        cout << " ------------------------------ " << endl << endl;
    }
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
            cout<< "8. Estado (oculto/visible)" << endl;
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
                        if(!datoCorrecto){
                            cout << " ------------------------------------------ " << endl;
                            cout << "|El cuit debe tener 11 caracteres numericos|" << endl;
                            cout << " ------------------------------------------ " << endl << endl;
                        }
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
                        if(!datoCorrecto){
                            cout << " ----------------------------------------------------------------------------------- " << endl;
                            cout << "|El nombre debe tener al menos 1 caracter, menos de 30 y no tiene que tener espacios|" << endl;
                            cout << " ------------------------------------------------------ ---------------------------- "  << endl << endl;
                        }
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
                        if(!datoCorrecto){
                            cout << " -------------------------------------------------------- " << endl;
                            cout << "|El apellido debe tener al menos 1 caracter y menos de 30|" << endl;
                            cout << " -------------------------------------------------------- " << endl<< endl;
                        }
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
                        if(!datoCorrecto){
                            cout << " ---------------------------------------------- " << endl;
                            cout << "|El telefono debe tener 11 caracteres numericos|" << endl;
                            cout << " ---------------------------------------------- " << endl << endl;
                        }
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
                        if(!datoCorrecto){
                            cout << " ------------------------------------ " << endl;
                            cout << "| El email no es valido              |" << endl;
                            cout << " ------------------------------------ " << endl << endl;
                        }
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
                        if(!datoCorrecto){
                            cout << " --------------------------------------------- " << endl;
                            cout << "| Direccion no puede ser mas de 50 caracteres |" << endl;
                            cout << " --------------------------------------------- " << endl << endl;
                        }
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
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << " ------------------------------ " << endl;
                            cout << "| Selecciona una opcion valida |" << endl;
                            cout << " ------------------------------ " << endl << endl;
                        }
                        if(!datoCorrecto){
                            cout << " ------------------------------ " << endl;
                            cout << "| Selecciona una opcion valida |" << endl;
                            cout << " ------------------------------ " << endl << endl;
                        }
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 8:{
                    bool estado;
                    int opcion;
                    while(!datoCorrecto){
                        cout<<"Seleccione una opcion: "<<endl;
                        cout<<"1. Oculto"<<endl;
                        cout<<"2. Visible"<<endl;
                        cin>>opcion;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << " ------------------------------ " << endl;
                            cout << "| Selecciona una opcion valida |" << endl;
                            cout << " ------------------------------ " << endl << endl;
                        }
                        if(opcion == 1){
                            estado = true;
                            datoCorrecto = vectorClientes[index].setOculto(estado);
                        }
                        else if(opcion == 2){
                            estado = false;
                            datoCorrecto = vectorClientes[index].setOculto(estado);
                        }
                        else{
                            system("cls");
                            cout << " ------------------------------ " << endl;
                            cout << "| Selecciona una opcion valida |" << endl;
                            cout << " ------------------------------ " << endl << endl;

                        }

                    }
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
    int ancho1=12,ancho2=50;
    cout <<"---------------------------------------------------------------"<< endl;
    cout <<"|"<< llenarEspaciosString("ID",ancho1)<< "| "<<llenarEspaciosInt(id,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("CUIT",ancho1)<< "| "<<llenarEspaciosString(cuit,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Nombre",ancho1)<< "| "<< llenarEspaciosString(nombre,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Apellido",ancho1)<< "| "<< llenarEspaciosString(apellido,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Telefono",ancho1)<< "| "<< llenarEspaciosString(telefono,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Email",ancho1)<< "| "<< llenarEspaciosString(email,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Direccion",ancho1)<< "| "<< llenarEspaciosString(direccion,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("T.Cliente",ancho1)<< "| "<< llenarEspaciosInt(tipoCliente,ancho2)<< "|"<< endl;
    cout <<"---------------------------------------------------------------"<< endl;

}

void ClienteManager::borrarCliente(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidadRegistros];
    _archivo.leerVector(vectorClientes, cantidadRegistros);
    int idClienteBorrar;

    cout<< "Ingrese el ID del cliente que desea borrar: " <<endl;
    cin>> idClienteBorrar;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << " ------------------------------ " << endl;
        cout << "| Selecciona una opcion valida |" << endl;
        cout << " ------------------------------ " << endl << endl;
    }

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
            cout<< "1. Si" <<endl;
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
