#include<iostream>
#include <cstring>
#include "Detalle.h"
#include "DetalleManager.h"

using namespace std;

void DetalleManager::cargarDetalle(){
    Detalle nuevoDetalle;
    int idFactura;
    int idProducto;
    int cantidad;
    float precioUnitario;
    bool oculto;
    bool datoCorrecto = false;
    bool frenarCarga = false;
    cin.ignore();

    idFactura= _archivo.getNuevoId();

    nuevoDetalle.setIdFactura(idFactura);
    nuevoDetalle.setOculto(false);
}

/*
void DetalleManager::listarDetalles(){
    int cantidad = _archivo.getCantidadRegistros();
    Detalle *vectorDetalles;
    vectorDetalles = new Detalle[cantidad];

    _archivo.leerVector(vectorDetalles, cantidad);

    for (int i=0; i < cantidad; i++ ){
        if(vectorDetalles[i].getOculto()== false){
            mostrarUnDetalle(vectorDetalles[i].getIdDetalle(),
                             vectorDetalles[i].getDescripcion(),
                             vectorDetalles[i].getMarca(),
                             vectorDetalles[i].getTipo(),
                             vectorDetalles[i].getStock()
                             );
        }
    }
    system("pause");
    delete[]vectorDetalles;
}

void DetalleManager::modificarDetalle(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Detalle *vectorDetalles;
    vectorDetalles = new Detalle[cantidadRegistros];
    _archivo.leerVector(vectorDetalles, cantidadRegistros);
    int idDetalleModificar;

    cout<< "Ingrese el ID del detalle que desea modificar: " <<endl;
    cin>> idDetalleModificar;
    int index = _archivo.buscarIndex(vectorDetalles,cantidadRegistros,idDetalleModificar);
    bool huboModificaciones= false;

    if(index >= 0){
        system("cls");
        cout<< "Id de detalle encontrado! "<< endl;
        mostrarUnDetalle(vectorDetalles[index].getIdDetalle(),
                         vectorDetalles[index].getDescripcion(),
                         vectorDetalles[index].getMarca(),
                         vectorDetalles[index].getTipo(),
                         vectorDetalles[index].getStock()
                         );
        system("pause");

        bool flag = true;
        bool datoCorrecto = false;
        int opcion;
        while (flag == true){
            cout<< "Que dato deseas modificar ? " <<endl<<endl;
            cout<< "1. Descripcion del detalle" <<endl;
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
                        datoCorrecto = vectorDetalles[index].setDescripcion(descripcion);
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
                        datoCorrecto = vectorDetalles[index].setMarca(marca);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 3:{
                    string tipo;
                    while(!datoCorrecto){
                        cout<<"Ingrese el tipo"<<endl;
                        getline(cin, tipo);
                        datoCorrecto = vectorDetalles[index].setTipo(tipo);
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
                        datoCorrecto = vectorDetalles[index].setStock(stock);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 0: flag=false; system("cls"); break;
            }
        }

    } else {
        cout << "resultado de busqueda index: " << index << endl;
        cout << "Id de detalle no encontrado chau" << endl;
        system("pause");
    }

    if(huboModificaciones){
        _archivo.modificar(vectorDetalles[index], index);
    }

    delete []vectorDetalles;
}
*/

void DetalleManager::mostrarUnDetalle(int idFactura, int idProducto, int cantidad, float precioUnitario){
    cout << "----------ID Factura: "<<idFactura<<" ------------" << endl;
    cout << "ID Producto: " << idProducto << endl;
    cout<< "Cantidad: "<< cantidad <<endl;
    cout << "Precio Unitario: " << precioUnitario << endl;
    cout << "-----------------------------" << endl;
}

/*
void DetalleManager::borrarDetalle(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Detalle *vectorDetalles;
    vectorDetalles = new Detalle[cantidadRegistros];
    _archivo.leerVector(vectorDetalles, cantidadRegistros);
    int idDetalleBorrar;

    cout<< "Ingrese el ID del detalle que desea borrar: " <<endl;
    cin>> idDetalleBorrar;
    int index = _archivo.buscarIndex(vectorDetalles,cantidadRegistros,idDetalleBorrar);
    bool huboModificaciones = false;
    if(index >= 0){
        system("cls");
        cout<< "Este es el detalle que vas a borrar: "<< endl;
        mostrarUnDetalle(vectorDetalles[index].getIdDetalle(),
                         vectorDetalles[index].getDescripcion(),
                         vectorDetalles[index].getMarca(),
                         vectorDetalles[index].getTipo(),
                         vectorDetalles[index].getStock()
                         );
        system("pause");

        bool flag = true;
        int opcion;

        while (flag == true){
            cout<< "Estas seguro que lo quieres borrar ? " <<endl<<endl;
            cout<< "1. Si" <<endl;
            cout<< "0. Cancelar borrado"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion){
                case 1:
                    vectorDetalles[index].setOculto(true);
                    flag = false;
                    huboModificaciones = true;
                    break;
                case 0:
                    flag=false; system("cls"); break;
            }
        }
    } else {
        cout << "resultado de busqueda index: " << index << endl;
        cout << "Id de detalle no encontrado chau" << endl;
        system("pause");
    }
    if(huboModificaciones){
        _archivo.modificar(vectorDetalles[index], index);
    }

    delete []vectorDetalles;
}
*/
