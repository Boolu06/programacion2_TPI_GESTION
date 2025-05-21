#include <iostream>
#include <cstring>
#include "Cliente.h"
#include "ClienteArchivo.h"

using namespace std;

//TODO: Crear un cpp para menu. Utilizar una clase.

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
            // case 2: borrarCliente(); break;
            // case 3: modificarCliente(); break;
            case 4: _clManager.mostrarCliente(); break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

void menuProductos(){
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
            //case 1: agregarProducto(); break;
            // case 2: borrarProducto(); break;
            // case 3: modificarProducto(); break;
            // case 4: listarProductos(); break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

void menuVentas(){
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
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            //case 1: agregarVenta(); break;
            // case 2: borrarVenta(); break;
            // case 3: modificarVenta(); break;
            // case 4: listarVentas(); break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

int main(){
    int opc;
    bool flag=true;

    while(flag==true){
        cout<<"===== MENU DE EMPRESA ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. GESTION DE CLIENTES"<<endl;
        cout<<" 2. GESTION DE PRODUCTOS"<<endl;
        cout<<" 3. GESTION DE VENTAS"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. FIN DEL PROGRAMA"<<endl;

        cin>>opc;

        switch(opc){
            case 1: menuClientes(); break;
            case 2: menuProductos(); break;
            case 3: menuVentas(); break;
            case 0: return 0; break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}
