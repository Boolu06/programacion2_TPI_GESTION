#include<iostream>
#include<cstring>
#include<ctime>
#include "Funciones.h"
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

bool esSoloNumeros(std::string numero){
    bool flag = true;
    int i=0;

    while(flag){
        if(numero[i]>='0' && numero[i]<='9'){ // Con que alguno de estos caracteres no corresponda a un numero, devuelve falso.
            i++;
            if(i==11){
                return true;
            }
        }
        else{
            flag = false;
        }
    }
    if(flag == false){
        return false;
    }
}

bool esSoloNumeros(float numero){
    string numeroCadena = to_string(numero);
    bool flag = true;
    int i=0;

    while(flag){
        if((numeroCadena[i]>='0' && numeroCadena[i]<='9') || (numeroCadena[i]=='.')){ //Con que alguno de estos caracteres no corresponda a un numero, devuelve falso.
            i++;
            if(i==numeroCadena.length()){
                return true;
            }
        }
        else{
            flag = false;
        }
    }
    if(flag == false){
        return false;
    }
}

bool esSoloLetras(std::string palabra){
    bool flag = true;
    int i=0;

    while(flag){
        if(palabra[i]>='A' && palabra[i]<='z'){ // Con que alguno de estos caracteres no corresponda a un numero, devuelve falso.
            i++;
            if(i==palabra.length()){
                return true;
            }
        }
        else{
            flag = false;
        }
    }
    if(flag == false){
        return false;
    }
}

void menuBackUp(){
    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== MENU CONFIGURACION ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. REALIZAR COPIA DE SEGURIDAD"<<endl;
        cout<<" 2. RESTAURAR COPIA DE SEGURIDAD"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            case 1: menuBackUpGuardar(); break;
            case 2: menuBackUpRestaurar(); break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

void menuBackUpGuardar(){
    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== REALIZAR COPIA DE SEGURIDAD ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. Clientes"<<endl;
        cout<<" 2. Productos"<<endl;
        cout<<" 3. Ventas"<<endl;
        cout<<" 4. Detalle de Ventas"<<endl;
        cout<<" 5. Todos los archivos"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            case 1:
                backUpGuardar("clientes.dat");
                break;
            case 2:
                backUpGuardar("productos.dat");
                break;
            case 3:
                backUpGuardar("ventas.dat");
                break;
            case 4:
                backUpGuardar("detalleDeVenta.dat");
            case 5:
                backUpGuardarTodo();
                break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

void menuBackUpRestaurar(){
    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== RESTAURAR COPIA DE SEGURIDAD ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. Clientes"<<endl;
        cout<<" 2. Productos"<<endl;
        cout<<" 3. Ventas"<<endl;
        cout<<" 4. Detalle de Ventas"<<endl;
        cout<<" 5. Todos los archivos"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            case 1:
                backUpRestaurar("clientes.dat");
                break;
            case 2:
                backUpRestaurar("productos.dat");
                break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}

void backUpGuardar(std::string nombreArchivo){
    int cantidadBytes;
    char vdatos[1];
    char ruta[30]="backups/";

    //Necesito guardar el archivo que contiene X cantidad de bytes, no hace falta trabajar con el objeto.
    strcat(ruta,nombreArchivo.c_str());
    //Copiar el archivo entero del .dat segun la opcion
    //Guardarlo en la carpeta backups

    FILE *pArchivoOrigen;
    FILE *pArchivoCopia;

    pArchivoOrigen = fopen(nombreArchivo.c_str(), "rb");
    pArchivoCopia = fopen(ruta, "wb");

    if(pArchivoOrigen == nullptr){
        cout<<"Error al buscar el archivo de origen."<<endl;
    }
    else{
        int resultado;
        while((resultado = fread(&vdatos, 1, sizeof(vdatos), pArchivoOrigen)) > 0) {
            fwrite(&vdatos, 1, 1, pArchivoCopia);
        }

        fseek(pArchivoOrigen,0,SEEK_END);
        fseek(pArchivoCopia,0,SEEK_END);

        if(ftell(pArchivoCopia) == ftell(pArchivoOrigen)){
            fclose(pArchivoOrigen);
            fclose(pArchivoCopia);
            cout<<"====ARCHIVO "<<nombreArchivo<<" GUARDADO CORRECTAMENTE===="<<endl;
            system("pause");
        }
        else{
            fclose(pArchivoOrigen);
            fclose(pArchivoCopia);
            cout<<"====HUBO ERRORES AL MOMENTO DE GUARDAR===="<<endl;
            system("pause");
        }
    }
}

void backUpGuardarTodo(){
    backUpGuardar("clientes.dat");
    backUpGuardar("productos.dat");
    backUpGuardar("detalleDeVenta.dat");
    backUpGuardar("ventas.dat");
}

bool backUpRestaurar(std::string nombreArchivo){
    int cantidadBytes;
    char vdatos[1];
    char ruta[30]="backups/";

    //Necesito guardar el archivo que contiene X cantidad de bytes, no hace falta trabajar con el objeto.
    strcat(ruta,nombreArchivo.c_str());
    //Copiar el archivo entero del .dat segun la opcion
    //Guardarlo en la carpeta backups

    FILE *pArchivoOrigen;
    FILE *pArchivoBackup;

    int randCodSeguridad=rand() % 99999+1000;
    string codigoConfirmacion;
    string codigoSeguridad = to_string(randCodSeguridad);


    cout<<"Restaurando "<<nombreArchivo<<"..."<<endl;
    cout<<"Ingrese el siguiente codigo de seguridad para continuar: "<<codigoSeguridad<<endl;
    cout<<""<<endl;
    cout<<"CODIGO DE CONFIRMACION: ";
    cin.ignore();
    getline(cin, codigoConfirmacion);

    while(codigoConfirmacion!=codigoSeguridad){
        cout<<"Codigo incorrecto, vuelva a intentarlo."<<endl;

        cout<<"CODIGO DE CONFIRMACION: ";
        getline(cin, codigoConfirmacion);
    }

    pArchivoOrigen = fopen(nombreArchivo.c_str(), "wb");
    pArchivoBackup = fopen(ruta, "rb");

    if(pArchivoOrigen == nullptr){
        cout<<"Error al buscar el archivo de origen."<<endl;
    }
    else{
        int resultado;
        while((resultado = fread(&vdatos, 1, sizeof(vdatos), pArchivoBackup)) > 0) {
            fwrite(&vdatos, 1, 1, pArchivoOrigen);
        }

        fseek(pArchivoOrigen,0,SEEK_END);
        fseek(pArchivoBackup,0,SEEK_END);

        if(ftell(pArchivoBackup) == ftell(pArchivoOrigen)){
            fclose(pArchivoOrigen);
            fclose(pArchivoBackup);
            cout<<"====ARCHIVO "<<nombreArchivo<<" RESTAURADO CORRECTAMENTE===="<<endl;
            system("pause");
        }
        else{
            fclose(pArchivoOrigen);
            fclose(pArchivoBackup);
            cout<<"====HUBO ERRORES AL MOMENTO DE RESTAURAR===="<<endl;
            system("pause");
        }
    }

    system("pause");

    //Ingresar codigo de seguridad al restaurar
    /*char CodigoSeguridad[4];

    for(int i=0; i<4 ; i++){
        CodigoSeguridad[i]=rand() % 10;
    }
    */


}
