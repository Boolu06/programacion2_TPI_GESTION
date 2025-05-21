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
