#include<iostream>
#include <cstring>
#include "Detalle.h"
#include "DetalleManager.h"
#include "Funciones.h"

using namespace std;

void DetalleManager::cargarDetalle(int idFactura, int idProducto, int cantidad, float precioUnitario){
    Detalle nuevoDetalle(idFactura,idProducto, cantidad, precioUnitario, false);

    _archivo.guardar(nuevoDetalle);
}

void DetalleManager::listarDetalles(){
    int cantidad = _archivo.getCantidadRegistros();
    Detalle *vectorDetalles;
    vectorDetalles = new Detalle[cantidad];

    _archivo.leerVector(vectorDetalles, cantidad);

    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== MENU DETALLE VENTA ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. Filtrar por ID FACTURA"<<endl;
        cout<<" 2. Listar todos los detalles de ventas"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;
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
                case 1: filtrarPorIdFactura(vectorDetalles, cantidad); break;
                case 2:
                    system("cls");
                    for (int i=0; i < cantidad; i++ ){
                        if(vectorDetalles[i].getOculto()== false){
                            mostrarUnDetalle(vectorDetalles[i].getIdFactura(),
                                             vectorDetalles[i].getIdProducto(),
                                             vectorDetalles[i].getCantidad(),
                                             vectorDetalles[i].getPrecioUnitario()
                                             );
                        }
                    }
                    system("pause");
                break;
                case 0: flag=false; system("cls"); break;
                default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
            }
        }
    }
    system("pause");
    delete[]vectorDetalles;
}

void DetalleManager::mostrarUnDetalle(int idFactura, int idProducto, int cantidad, float precioUnitario){
    int ancho1=16,ancho2=50;
    cout <<"----------------------------------------------------------------------"<< endl;
    cout <<"|"<< llenarEspaciosString("ID Factura",ancho1)<< "| "<<llenarEspaciosInt(idFactura,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("ID Producto",ancho1)<< "| "<<llenarEspaciosInt(idProducto,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Cantidad",ancho1)<< "| "<< llenarEspaciosInt(cantidad,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Precio Unitario",ancho1)<< "| "<< llenarEspaciosFloat(precioUnitario,ancho2)<< "|"<< endl;
    cout <<"----------------------------------------------------------------------"<< endl;
}

void DetalleManager::filtrarPorIdFactura(Detalle vectorDetalles[], int cantidadRegistros){
    int id;
    bool detalleEncontrado=false;

    system("cls");
    while(true){
        cout<<"Ingrese el ID de factura"<<endl;
        cin>>id;
        if(cin.fail() || id<0){
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

    for(int i=0; i<cantidadRegistros; i++){
        if(vectorDetalles[i].getIdFactura() == id && id>0){
            mostrarUnDetalle(vectorDetalles[i].getIdFactura(),
                             vectorDetalles[i].getIdProducto(),
                             vectorDetalles[i].getCantidad(),
                             vectorDetalles[i].getPrecioUnitario()
                            );
            detalleEncontrado=true;
        }
    }

    if(!detalleEncontrado){
        cout << " --------------------------------------- " << endl;
        cout << "| No se encontro una factura con ese ID |" << endl;
        cout << " --------------------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}
