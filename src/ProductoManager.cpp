#include<iostream>
#include <cstring>
#include "Producto.h"
#include "ProductoManager.h"

using namespace std;

void ProductoManager::cargarProducto(){
    Producto nuevoProducto;
    int idProducto;
    string tipo;
    string descripcion;
    string marca;
    int stock;
    bool oculto;
    bool datoCorrecto = false;
    bool frenarCarga = false;
    cin.ignore();

    idProducto= _archivo.getNuevoId();

    nuevoProducto.setIdProducto(idProducto);
    nuevoProducto.setOculto(false);

    cout<< "Producto ID asignado: " <<  idProducto << endl;

    while(!datoCorrecto){
        cout<<"Ingrese el tipo de producto: "<<endl;
        getline(cin, tipo);
        datoCorrecto = nuevoProducto.setTipo(tipo);
    }

    datoCorrecto = false; // resetar el booleando para ingresar al proximo bucle

    while(!datoCorrecto){
        cout<<"Ingrese la descripcion: "<<endl;
        getline(cin, descripcion);
        datoCorrecto = nuevoProducto.setDescripcion(descripcion);
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese la marca: "<<endl;
        getline(cin, marca);
        datoCorrecto = nuevoProducto.setMarca(marca);
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el stock o disponibilidad (numero): "<<endl;
        cin>> stock;
        datoCorrecto = nuevoProducto.setStock(stock);
    }

    //dato correcto se deja en true para entrar al if:

    if(datoCorrecto){

        if(_archivo.guardar(nuevoProducto)){
            cout<<"Se ha registrado un nuevo producto."<<endl;
        }
        else{
            cout<<"No se pudo registrar el producto, intentelo de nuevo."<<endl;
        }
        system("pause");

    }

}

void ProductoManager::listarProductos(){
    int cantidad = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidad];

    _archivo.leerVector(vectorProductos, cantidad); // esta funcion mete en el vectorProductos los productos que consiga en el archivo.dat.

    for (int i=0; i < cantidad; i++ ){
        if(vectorProductos[i].getOculto()== false){
        mostrarUnProducto(vectorProductos[i].getIdProducto(),
                         vectorProductos[i].getDescripcion(),
                         vectorProductos[i].getMarca(),
                         vectorProductos[i].getTipo(),
                         vectorProductos[i].getStock()
                         );
        }
    }
    system("pause");

    delete[]vectorProductos;
}

Producto ProductoManager::buscarId(int idProducto){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidadRegistros];
    _archivo.leerVector(vectorProductos, cantidadRegistros);

    int index = _archivo.buscarIndex(vectorProductos,cantidadRegistros,idProducto);

    /*
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
    */

    if(index>-1){
        return(vectorProductos[index]);
    }
    else{
        Producto ProductoVacio;
        return ProductoVacio;
    }
}

void ProductoManager::modificarProducto(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidadRegistros];
    _archivo.leerVector(vectorProductos, cantidadRegistros);
    int idProductoModificar;

    cout<< "Ingrese el ID del producto que desea modificar: " <<endl;
    cin>> idProductoModificar;
    int index = _archivo.buscarIndex(vectorProductos,cantidadRegistros,idProductoModificar);
    bool huboModificaciones= false;

    if(index >= 0){
        system("cls");
        cout<< "Id de producto encontrado! "<< endl;
        mostrarUnProducto(vectorProductos[index].getIdProducto(),
                         vectorProductos[index].getDescripcion(),
                         vectorProductos[index].getMarca(),
                         vectorProductos[index].getTipo(),
                         vectorProductos[index].getStock()
                         );
        system("pause");

        bool flag = true;
        bool datoCorrecto = false;
        int opcion;
        while (flag == true){
            cout<< "Que dato deseas modificar ? " <<endl<<endl;
            cout<< "1. Descripcion del producto" <<endl;
            cout<< "2. Marca " <<endl;
            cout<< "3. Tipo " <<endl;
            cout<< "4. Stock " <<endl;
            cout<< "0. Terminar modificaciones"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion){
                case 1:{
                    string descripcion;
                    while(!datoCorrecto){
                        cout<<"Ingrese la descripcion"<<endl;
                        getline(cin, descripcion);
                        datoCorrecto = vectorProductos[index].setDescripcion(descripcion);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 2:{
                    string marca;
                    while(!datoCorrecto){
                        cout<<"Ingrese la marca"<<endl;
                        getline(cin, marca);
                        datoCorrecto = vectorProductos[index].setMarca(marca);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 3:{
                    string tipo;
                    while(!datoCorrecto){
                        cout<<"Ingrese el tipo"<<endl; //TODO: Se podrian ingresar validaciones o hacer un mini-menu para elegir el tipo (si es PC, notebook, impresora, periferico, etc)
                        getline(cin, tipo);
                        datoCorrecto = vectorProductos[index].setTipo(tipo);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 4:{
                    int stock;
                    while(!datoCorrecto){
                        cout<<"Ingrese el stock"<<endl;
                        cin>>stock;
                        datoCorrecto = vectorProductos[index].setStock(stock);
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
        cout << "Id de producto no encontrado chau" << endl;
        system("pause");
    }

    cout << " tamos mandando el indexxxxxxxxxxxx: " << index;
    if(huboModificaciones){
        _archivo.modificar(vectorProductos[index], index);
    }

    delete []vectorProductos;
}

void ProductoManager::mostrarUnProducto(int idProducto, std::string descripcion,std::string marca, std::string tipo, int stock){
    cout << "----------ID Producto: "<<idProducto<<" ------------" << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout<< "Marca: "<< marca <<endl;
        cout << "Tipo: " << tipo << endl;
        cout<< "Stock: "<< stock <<endl;
        cout << "-----------------------------" << endl;
}

void ProductoManager::borrarProducto(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidadRegistros];
    _archivo.leerVector(vectorProductos, cantidadRegistros);
    int idProductoBorrar;

    cout<< "Ingrese el ID del producto que desea borrar: " <<endl;
    cin>> idProductoBorrar;
    int index = _archivo.buscarIndex(vectorProductos,cantidadRegistros,idProductoBorrar);
    bool huboModificaciones = false;
    if(index >= 0){
        system("cls");
        cout<< "Este es el cliente que vas a borrar: "<< endl;
        mostrarUnProducto(vectorProductos[index].getIdProducto(),
                         vectorProductos[index].getDescripcion(),
                         vectorProductos[index].getMarca(),
                         vectorProductos[index].getTipo(),
                         vectorProductos[index].getStock()
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
                    vectorProductos[index].setOculto(true);
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
        _archivo.modificar(vectorProductos[index], index);
    }

    delete []vectorProductos;
}

