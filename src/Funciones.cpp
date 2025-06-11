#include<iostream>
#include "Funciones.h"
#include <cstring>
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "ClienteManager.h"
#include "Producto.h"
#include "ProductoArchivo.h"
#include "ProductoManager.h"
#include "Venta.h"
#include "VentaArchivo.h"
#include "VentaManager.h"

using namespace std;

void menuClientes(){
    ClienteManager _clManager;
    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== MENU CLIENTES ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. AGREGAR CLIENTE"<<endl;
        cout<<" 2. BORRAR CLIENTE"<<endl;
        cout<<" 3. MODIFICAR CLIENTE"<<endl;
        cout<<" 4. LISTAR CLIENTES"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            case 1: _clManager.cargarCliente(); break;
            case 2: _clManager.borrarCliente(); break;
            case 3: _clManager.modificarCliente(); break;
            case 4: _clManager.listarClientes(); break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

void menuProductos(){
    ProductoManager _pManager;
    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== MENU PRODUCTOS ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. AGREGAR PRODUCTO"<<endl;
        cout<<" 2. BORRAR PRODUCTO"<<endl;
        cout<<" 3. MODIFICAR PRODUCTO"<<endl;
        cout<<" 4. LISTAR PRODUCTOS"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            case 1: _pManager.cargarProducto(); break;
            case 2: _pManager.borrarProducto(); break;
            case 3: _pManager.modificarProducto(); break;
            case 4: _pManager.listarProductos(); break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

void menuVentas(){
    VentaManager _vManager;
    DetalleManager _dManager;

    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== MENU VENTAS ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. AGREGAR VENTA"<<endl;
        cout<<" 2. BORRAR VENTA"<<endl;
        cout<<" 3. MODIFICAR VENTA"<<endl;
        cout<<" 4. LISTAR VENTAS"<<endl;
        cout<<" 5. DETALLE DE VENTA"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            case 1: _vManager.cargarVenta(); break;
            // case 2: borrarVenta(); break;
            // case 3: modificarVenta(); break;
            case 4: _vManager.listarVentas(); break;
            case 5: _dManager.listarDetalles(); break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

string aMinusculas(string palabra){
    for(int i=0;i<palabra.length(); i++){
        palabra[i] = tolower(palabra[i]);
    }
    return palabra;
}
