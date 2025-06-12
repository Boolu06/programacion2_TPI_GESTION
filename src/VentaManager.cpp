#include<iostream>
#include <cstring>
#include "Funciones.h"
#include "VentaManager.h"
#include "Venta.h"

using namespace std;

void VentaManager::cargarVenta(){
    Venta nuevaFactura;
    ClienteManager Cliente_M;
    ProductoManager Producto_M;
    DetalleManager Detalle_M;
    VentaManager Venta_M;
    Fecha fechaFactura;

    int idFactura;
    string cuitCliente;

    idFactura = _archivo.getNuevoId();
    nuevaFactura.setIdFactura(idFactura);

    cin.ignore();
    do{
        cout<<"Por favor ingrese el numero de CUIT del cliente"<<endl;
        getline(cin,cuitCliente);
        if(!esSoloNumeros(cuitCliente)){
            cout << " ------------------------------------------ " << endl;
            cout << "|El cuit debe tener 11 caracteres numericos|" << endl;
            cout << " ------------------------------------------ " << endl << endl;
        }
    }while(!esSoloNumeros(cuitCliente));

    Cliente ClienteEncontrado;

    ClienteEncontrado = Cliente_M.buscarCuit(cuitCliente); //Cliente_M.buscarCuit(cuitCliente) <- retorna un cliente, si fue encontrado su ID siempre será mayor a 0
    // Si no existe el CUIT en la tabla de Clientes, informarle al usuario y crear un nuevo cliente.

    bool corteGeneral = false;

    if(ClienteEncontrado.getId() != 0 && ClienteEncontrado.getOculto() == false){
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
    else if(ClienteEncontrado.getId()!=0 && ClienteEncontrado.getOculto()== true){
        cout<<"El cliente fue borrado anteriormente, desea recuperarlo?"<<endl;
        cout<<"Para recuperar ir a modificar clientes con el ID de cliente: " << ClienteEncontrado.getId()<< endl;
        system("pause");
        corteGeneral = true;
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
                Cliente_M.cargarCliente(cuitCliente); //TODO: Que no me vuelva a pedir el CUIT
                flag=true;
            }
            else{
                flag=true;
                corteGeneral = true;
            }
        }
        system("pause");
    }


    //Al usuario le voy a pedir que seleccione un producto a comprar. Esto va a ser un menú en el cual esta constantemente mostrandome los productos disponibles con
    //su precio unitario. Por ahora en el codigo en su estado basico solo se le pide el ingreso del ID del producto.
    int idProducto;
    int eleccion;
    int cantidad;
    float importeTotal=0;
    bool flag = true;
    bool flag2 = true;
    bool flag3 = true;

    bool productosAgregados = false;

    if(!corteGeneral){
        while(flag3){
            cout<<"Ingrese el ID del producto a comprar"<<endl;
            cin>>idProducto;

            Producto ProductoEncontrado;
            ProductoEncontrado = Producto_M.buscarId(idProducto);

            if(ProductoEncontrado.getIdProducto()!=0){
                Producto_M.mostrarUnProducto(ProductoEncontrado.getIdProducto(),
                                 ProductoEncontrado.getPrecioUnitario(),
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

                        if(Producto_M.descontarStock(ProductoEncontrado.getIdProducto(), cantidad)){
                            Detalle_M.cargarDetalle(idFactura, ProductoEncontrado.getIdProducto(), cantidad, ProductoEncontrado.getPrecioUnitario());
                            flag2 = false;
                            flag = false;
                            productosAgregados = true;
                            importeTotal=importeTotal+((float)cantidad*ProductoEncontrado.getPrecioUnitario());
                        }
                        else{
                            cout<<"Cantidad supera stock, stock actual " << ProductoEncontrado.getStock()<<endl;
                             system("pause");
                        }

                    }
                    else{
                        flag2 = false;
                    }
                }

                cout<<"Desea ingresar otro producto?"<<endl;
                cout<<"1. Si"<<endl;
                cout<<"2. No"<<endl;
                cin>>eleccion;

                if(eleccion==1){
                    flag3 = true;
                }
                else{

                    flag3 = false;
                }
                system("pause");
            }
            else{
                cout<<"El producto no existe, vuelva a ingresarlo"<<endl;
                system("pause");
            }
        }

        if(productosAgregados){
            cout<<"Como desea ingresar la fecha?"<<endl;
            cout<<"1. Manual"<<endl;
            cout<<"2. Automatico"<<endl;
            cin>>eleccion;

            if(eleccion==1){
                int dia, mes, anio;
                cout<<"Ingrese el dia"<<endl;
                cin>>dia;
                cout<<"Ingrese el mes"<<endl;
                cin>>mes;
                cout<<"Ingrese el anio"<<endl;
                cin>>anio;
                fechaFactura = Fecha(dia, mes, anio);
                flag = false;
            }
            else{
                fechaFactura = Fecha();
                flag = false;
            }
            cout<<fechaFactura.getDia()<<"/"<<fechaFactura.getMes()<<"/"<<fechaFactura.getAnio()<<endl;
            cout<<"El importe total es: "<< to_string(importeTotal)<<endl;

            nuevaFactura.setIdCliente(ClienteEncontrado.getId());
            nuevaFactura.setFechaVenta(fechaFactura);
            nuevaFactura.setImporteTotal(importeTotal);
            _archivo.guardar(nuevaFactura);

            system("pause");
        }
    }

    //Venta.setIdFactura(idFactura); ///setea el idFactura autoincremental al momento de concretar la venta en detalleventa
    //Venta.setIdCliente(idCliente); ///asignar el idCliente encontrado con el CUIT
    ///Funcion que me traiga la fecha actual y asignarlo a fechaVenta
   // Venta.setFechaVenta(fechaVenta);
   // Venta.setImporteTotal(importeTotal) ///Importe total traido de detalleVenta
}

void VentaManager::listarVentas(){
    int cantidad = _archivo.getCantidadRegistros();
    Venta *vectorVentas;
    vectorVentas = new Venta [cantidad];

    _archivo.leerVector(vectorVentas, cantidad); // esta funcion mete en el vectorProductos los productos que consiga en el archivo.dat.

    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== MENU VENTAS ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. Filtrar por ID de factura"<<endl;
        cout<<" 2. Filtrar por ID de cliente"<<endl;
        cout<<" 3. Filtrar por CUIT de cliente"<<endl;
        cout<<" 4. Filtrar por fecha de venta"<<endl;
        cout<<" 5. Filtrar por importe"<<endl;
        cout<<" 6. Listar todas las ventas"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. VOLVER AL MENU PRINCIPAL"<<endl;

        cin>>opc;

        switch(opc){
            case 1: filtrarPorIDFactura(vectorVentas, cantidad); break;
            //case 2: filtrarPorIDCliente(vectorVentas, cantidad); break;
            case 6:
                system("cls");
                for (int i=0; i < cantidad; i++ ){
                    if(vectorVentas[i].getOculto()== false){
                        mostrarUnaVenta(vectorVentas[i].getIdFactura(),
                                         vectorVentas[i].getIdCliente(),
                                         vectorVentas[i].getFechaVenta(),
                                         vectorVentas[i].getImporteTotal()
                                         );
                    }
                }
                system("pause");
            break;
            case 0: flag=false; system("cls"); break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
    delete[]vectorVentas;
}

void VentaManager::mostrarUnaVenta(int idFactura, int idCliente, Fecha fechaVenta, float importeTotal){
    cout << "----------ID Factura: "<<idFactura<<" ------------" << endl;
        cout << "ID Cliente: " << idCliente << endl;
        cout << "Fecha : " << fechaVenta.getDia() << "/" << fechaVenta.getMes()<<"/"<< fechaVenta.getAnio() << endl;
        cout << "Importe Total: "<< to_string(importeTotal)<< "$" <<endl;
        cout << "-----------------------------" << endl;
}

void VentaManager::filtrarPorIDFactura(Venta vectorVentas[], int cantidadRegistros){
    int id;
    bool ventaEncontrada=false;

    system("cls");
    cout<<"Ingrese el ID de factura"<<endl;
    cin>>id;

    for(int i=0; i<cantidadRegistros; i++){
        if(vectorVentas[i].getIdFactura() == id && id>0){
            mostrarUnaVenta(vectorVentas[i].getIdFactura(),
                             vectorVentas[i].getIdCliente(),
                             vectorVentas[i].getFechaVenta(),
                             vectorVentas[i].getImporteTotal()
                            );
            ventaEncontrada=true;
        }
    }
    if(!ventaEncontrada){
        cout<<"Venta no encontrada"<<endl;
        system("pause");
    }
    else{
        system("pause");
    }
}
//Metodo para filtrar por idCliente
//Metodo para filtrar por cuit de cliente
//Metodo para filtrar por fecha
//Metodo para filtrar por importe <- a revisar

/*
void VentaManager::listarVentas();
void VentaManager::mostrarUnaVenta(int idFactura, int idCliente, Fecha fechaVenta, float importeTotal);
void VentaManager::modificarVenta();
void VentaManager::borrarVenta();
*/


