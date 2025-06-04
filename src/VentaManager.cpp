#include<iostream>
#include <cstring>
#include "VentaManager.h"
#include "Venta.h"

using namespace std;

void VentaManager::cargarVenta(){
    Venta Factura;
    ClienteManager Cliente_M;
    ProductoManager Producto_M;
    DetalleManager Detalle_M;

    string cuitCliente;

    cout<<"Por favor ingrese el numero de CUIT del cliente"<<endl;
    cin.ignore();
    getline(cin,cuitCliente);

    Cliente ClienteEncontrado;
    ClienteEncontrado = Cliente_M.buscarCuit(cuitCliente); //Cliente_M.buscarCuit(cuitCliente) <- retorna un cliente, si fue encontrado su ID siempre será mayor a 0
    // Si no existe el CUIT en la tabla de Clientes, informarle al usuario y crear un nuevo cliente.
    if(ClienteEncontrado.getId()!=0){
        Cliente_M.mostrarUnCliente(ClienteEncontrado.getId(),
                         ClienteEncontrado.getCuit(),
                         ClienteEncontrado.getNombre(),
                         ClienteEncontrado.getApellido(),
                         ClienteEncontrado.getTelefono(),
                         ClienteEncontrado.getEmail(),
                         ClienteEncontrado.getDireccion(),
                         ClienteEncontrado.getTipoCliente());
        system("pause");
    }
    else{
        cout<<"El cliente no esta registrado"<<endl;
        bool flag = false;
        int eleccion;

        while(!flag){
            cout<<"Desea registrar el cliente?"<<endl;
            cout<<"1. Si"<<endl;
            cout<<"2. No"<<endl;
            cin>>eleccion;

            if(eleccion==1){
                Cliente_M.cargarCliente(); //TODO: Que no me vuelva a pedir el CUIT
                flag=true;
            }
            else{
                flag=true;
            }
        }
        system("pause");
    }

    //Al usuario le voy a pedir que seleccione un producto a comprar. Esto va a ser un menú en el cual esta constantemente mostrandome los productos disponibles con
    //su precio unitario. Por ahora en el codigo en su estado basico solo se le pide el ingreso del ID del producto.
    int idProducto;
    bool flag = true;
    bool flag2 = true;
    int eleccion;
    int cantidad;

    while(flag){
        cout<<"Ingrese el ID del producto a comprar"<<endl;
        cin>>idProducto;

        Producto ProductoEncontrado;
        ProductoEncontrado = Producto_M.buscarId(idProducto);

        if(ProductoEncontrado.getIdProducto()!=0){
            Producto_M.mostrarUnProducto(ProductoEncontrado.getIdProducto(),
                             ProductoEncontrado.getDescripcion(),
                             ProductoEncontrado.getMarca(),
                             ProductoEncontrado.getTipo(),
                             ProductoEncontrado.getStock());
                flag2 = true;
                while(flag2){
                    cout<<"El producto mostrado es el correcto?"<<endl;
                    cout<<"1. Si"<<endl;
                    cout<<"2. No"<<endl;
                    cin>>eleccion;

                    if(eleccion==1){
                        cout<<"Ingrese la cantidad a comprar"<<endl;
                        cin>>cantidad;
                        flag2 = false;
                        flag = false;
                    }
                    else{
                        flag2 = false;
                    }
                }
            system("pause");
        }
        else{
            cout<<"El producto no existe, vuelva a ingresarlo"<<endl;
            system("pause");
        }
    }

    //Venta.setIdFactura(idFactura); ///setea el idFactura autoincremental al momento de concretar la venta en detalleventa
    //Venta.setIdCliente(idCliente); ///asignar el idCliente encontrado con el CUIT
    ///Funcion que me traiga la fecha actual y asignarlo a fechaVenta
   // Venta.setFechaVenta(fechaVenta);
   // Venta.setImporteTotal(importeTotal) ///Importe total traido de detalleVenta
}

/*
void VentaManager::listarVentas();
void VentaManager::mostrarUnaVenta(int idFactura, int idCliente, Fecha fechaVenta, float importeTotal);
void VentaManager::modificarVenta();
void VentaManager::borrarVenta();
*/


