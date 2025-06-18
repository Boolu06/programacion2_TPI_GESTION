#include<iostream>
#include <cstring>
#include "Cliente.h"
#include "ClienteManager.h"
#include "Funciones.h"
using namespace std;

void ClienteManager::cargarCliente(const std::string &cuit){
    Cliente nuevoCliente;
    ClienteManager Cliente_M;
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

        nuevoCliente = Cliente_M.buscarCuit(cuitFinal);

        if(nuevoCliente.getId() == 0){
            datoCorrecto = nuevoCliente.setCuit(cuitFinal);
        }
        else{
            cout << " ----------------- " << endl;
            cout << "|El cuit ya existe|" << endl;
            cout << " ----------------- " << endl << endl;
        }

        if(!datoCorrecto && nuevoCliente.getId() == 0){
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
            cout << " ---------------------------------------------------------------------- " << endl;
            cout << "|El apellido debe ser numerico, tener al menos 1 caracter y menos de 30|" << endl;
            cout << " ---------------------------------------------------------------------- " << endl<< endl;
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
        if(cin.fail() || (tipo <= 0 || tipo >= 3)){
            cout << " ------------------------------ " << endl;
            cout << "| Selecciona una opcion valida |" << endl;
            cout << " ------------------------------ " << endl << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
        }
        else{
            cin.ignore(1000,'\n');
            datoCorrecto = nuevoCliente.setTipoCliente(tipo);
        }
    }

    if(datoCorrecto){

        if(_archivo.guardar(nuevoCliente)){
            cout<<"Cliente registrado correctamente."<<endl;
        }
        else{
            cout<<"No se pudo registrar el cliente, intentelo de nuevo."<<endl;
        }
        system("pause");

    }
}

void ClienteManager::listarClientes(){
    system("cls");
    int cantidad = _archivo.getCantidadRegistros();
    Cliente *vectorClientes;
    vectorClientes = new Cliente[cantidad];

    _archivo.leerVector(vectorClientes, cantidad); // esta funcion mete en el vectorClientes los clientes que consiga en el archivo.dat.

    int opc;
    bool flag = true;
    while(flag==true){
        cout<<"===== MENU CLIENTES ====="<<endl;
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
        if(cin.fail()){
            cout<<"INGRESE UNA OPCION CORRECTA"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
            system("cls");
        }
        else{
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
    }
    delete[]vectorClientes;
}

void ClienteManager::filtrarPorId(Cliente vectorClientes[], int cantidadRegistros){
    int idCliente;
    bool clienteEncontrado=false;

    system("cls");
    while(true){
        cout<<"Ingrese el ID del cliente que desea buscar: "<<endl;
        cin>>idCliente;
        if(cin.fail() || idCliente<0){
            cout<<"ID Invalido"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
            system("cls");
        }
        else{
            cin.ignore(1000,'\n');
            break;
        }
    }

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
            clienteEncontrado=true;
        }
    }

    if(!clienteEncontrado){
        cout << " --------------------------- " << endl;
        cout << "| No se encontro el cliente |" << endl;
        cout << " --------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}

void ClienteManager::filtrarPorCuit(Cliente vectorClientes[], int cantidadRegistros){
    string cuitCliente;
    bool clienteEncontrado=false;

    system("cls");
    cout<<"Ingrese el CUIT del cliente que desea buscar: "<<endl;
    cin.ignore();
    getline(cin,cuitCliente);

    for(int i=0; i < cantidadRegistros; i++ ){
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
            clienteEncontrado=true;
        }
    }
    if(!clienteEncontrado){
        cout << " --------------------------- " << endl;
        cout << "| No se encontro el cliente |" << endl;
        cout << " --------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}

void ClienteManager::filtrarPorNombre(Cliente vectorClientes[], int cantidadRegistros){
    string nombreCliente;
    bool clienteEncontrado=false;

    system("cls");
    cout<<"Ingrese el nombre del cliente que desea buscar: "<<endl;
    cin.ignore();
    getline(cin,nombreCliente);

    for(int i=0; i < cantidadRegistros; i++ ){
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
            clienteEncontrado=true;
        }
    }
    if(!clienteEncontrado){
        cout << " --------------------------- " << endl;
        cout << "| No se encontro un cliente |" << endl;
        cout << " --------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}

void ClienteManager::filtrarPorApellido(Cliente vectorClientes[], int cantidadRegistros){
    string apellidoCliente;
    bool clienteEncontrado=false;

    system("cls");
    cout<<"Ingrese el apellido del cliente que desea buscar: "<<endl;
    cin.ignore();
    getline(cin,apellidoCliente);

    for(int i=0; i < cantidadRegistros; i++ ){
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
            clienteEncontrado=true;
        }
    }
    if(!clienteEncontrado){
        cout << " --------------------------- " << endl;
        cout << "| No se encontro un cliente |" << endl;
        cout << " --------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}

void ClienteManager::filtrarPorTipo(Cliente vectorClientes[], int cantidadRegistros){
    int tipoCliente;
    bool clienteEncontrado=false;

    system("cls");
    while(true){
        cout<<"Ingrese el tipo de cliente que desea buscar"<<endl;
        cout<<"1. Particular"<<endl;
        cout<<"2. Empresa"<<endl;
        cin>>tipoCliente;
        if(cin.fail() || (tipoCliente <= 0 || tipoCliente >= 3)){
            cout<<"Numero invalido. Ingrese un tipo valido"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
            system("cls");
        }
        else{
            cin.ignore(1000,'\n');
            break;
        }
    }

    for(int i=0; i < cantidadRegistros; i++ ){
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
            clienteEncontrado=true;
        }
    }

    if(!clienteEncontrado){
        cout << " ---------------------------------------- " << endl;
        cout << "| No se encontro un cliente con ese tipo |" << endl;
        cout << " ---------------------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
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

    system("cls");

    while(true){
        cout<< "Ingrese el ID del cliente que desea modificar: " <<endl;
        cin>> idClienteModificar;
        if(cin.fail() || idClienteModificar<0){
            cout<<"ID Invalido"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
            system("cls");
        }
        else{
            cin.ignore(1000,'\n');
            break;
        }
    }

    int index = _archivo.buscarIndex(vectorClientes,cantidadRegistros,idClienteModificar);

    bool huboModificaciones= false;

    if(index >= 0){
        bool flag = true;
        bool datoCorrecto = false;
        int opcion;
        Cliente nuevoCliente;
        ClienteManager Cliente_M;

        while(flag == true){
            system("cls");
            cout<<"=== ID de cliente encontrado! ==="<< endl;
            mostrarUnCliente(vectorClientes[index].getId(),
                             vectorClientes[index].getCuit(),
                             vectorClientes[index].getNombre(),
                             vectorClientes[index].getApellido(),
                             vectorClientes[index].getTelefono(),
                             vectorClientes[index].getEmail(),
                             vectorClientes[index].getDireccion(),
                             vectorClientes[index].getTipoCliente()
                             );

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
            if(cin.fail()){
                cout<<"INGRESE UNA OPCION CORRECTA"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                system("pause");
            }
            else{
                cin.ignore(1000,'\n');
                switch (opcion){
                    case 1:{
                        string cuit;
                        while(!datoCorrecto){
                            cout<<"Ingrese el CUIT"<<endl;
                            getline(cin, cuit);
                            nuevoCliente = Cliente_M.buscarCuit(cuit);

                            if(nuevoCliente.getId() == 0){
                                datoCorrecto = vectorClientes[index].setCuit(cuit);
                            }
                            else{
                                cout << " ----------------- " << endl;
                                cout << "|El cuit ya existe|" << endl;
                                cout << " ----------------- " << endl << endl;
                            }

                            if(!datoCorrecto && nuevoCliente.getId() == 0){
                                cout << " ------------------------------------------ " << endl;
                                cout << "|El cuit debe tener 11 caracteres numericos|" << endl;
                                cout << " ------------------------------------------ " << endl << endl;
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
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
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 3:{
                        string apellido;
                        while(!datoCorrecto){
                            cout<<"Ingrese el apellido"<<endl;
                            getline(cin, apellido);
                            datoCorrecto = vectorClientes[index].setApellido(apellido);
                            if(!datoCorrecto){
                                cout << " ---------------------------------------------------------------------- " << endl;
                                cout << "|El apellido debe ser numerico, tener al menos 1 caracter y menos de 30|" << endl;
                                cout << " ---------------------------------------------------------------------- " << endl<< endl;
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
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
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
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
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
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
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 7:{
                        int tipo;
                        while(!datoCorrecto){
                            cout<<"Ingrese el tipo de cliente"<<endl;
                            cout<<"1. Particular"<<endl;
                            cout<<"2. Empresa"<<endl;
                            cin>>tipo;

                            if(cin.fail() || (tipo <= 0 || tipo >= 3)){
                                cout << " ------------------------------------ " << endl;
                                cout << "| No se encontro ese tipo de cliente |" << endl;
                                cout << " ------------------------------------ " << endl << endl;
                                system("pause");
                                cin.clear();
                                cin.ignore(1000,'\n');
                            }
                            else{
                                cin.ignore(1000,'\n');
                                datoCorrecto = vectorClientes[index].setTipoCliente(tipo);
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
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
                            if(cin.fail() || (opcion <= 0 || opcion >= 3)){
                                cin.clear();
                                cin.ignore(1000,'\n');
                            }
                            else if(opcion == 1){
                                cin.ignore(1000,'\n');
                                estado = true;
                                datoCorrecto = vectorClientes[index].setOculto(estado);
                            }
                            else if(opcion == 2){
                                cin.ignore(1000,'\n');
                                estado = false;
                                datoCorrecto = vectorClientes[index].setOculto(estado);
                            }
                            if(!datoCorrecto){
                                cout << " ------------------------------ " << endl;
                                cout << "| Selecciona una opcion valida |" << endl;
                                cout << " ------------------------------ " << endl << endl;
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones = true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 0: flag=false; system("cls"); break;
                    default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause");
                }
            }
        }
    }
    else{
        cout << " ------------------------------ " << endl;
        cout << "| ID de cliente no encontrado |" << endl;
        cout << " ------------------------------ " << endl << endl;
    }

    if(huboModificaciones){
        _archivo.modificar(vectorClientes[index], index);
    }
    system("pause");
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

    system("cls");
    while(true){
        cout<< "Ingrese el ID del cliente que desea borrar: " <<endl;
        cin>> idClienteBorrar;
        if(cin.fail() || idClienteBorrar<0){
            cout<<"ID Invalido"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
            system("cls");
        }
        else{
            cin.ignore(1000,'\n');
            break;
        }
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

        int opcion;

        while(true){
            cout<< "Confirme si desea eliminarlo" <<endl<<endl;
            cout<< "1. Si" <<endl;
            cout<< "0. Cancelar borrado"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            if(cin.fail() || (opcion <0 || opcion >1)){
                cout<<"Numero invalido. Ingrese un tipo valido"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                system("pause");
            }
            else{
                cin.ignore(1000,'\n');
                switch(opcion){
                    case 1:
                        vectorClientes[index].setOculto(true);
                        huboModificaciones = true;
                        break;
                    case 0:
                        break;
                }
                break;
            }
        }
    }
    else{
        cout << " ------------------------------ " << endl;
        cout << "| ID de cliente no encontrado |" << endl;
        cout << " ------------------------------ " << endl << endl;
        system("pause");
    }
    if(huboModificaciones){
        _archivo.modificar(vectorClientes[index], index);
        cout<<"Cliente eliminado satisfactoriamente"<<endl;
        system("pause");
    }

    delete []vectorClientes;
}
