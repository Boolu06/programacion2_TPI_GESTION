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

    ClienteEncontrado = Cliente_M.buscarCuit(cuitCliente); //Cliente_M.buscarCuit(cuitCliente) <- retorna un cliente, si fue encontrado su ID siempre sera mayor a 0
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
        int eleccion;

        while(true){
            cout<<"Desea registrar el cliente?"<<endl;
            cout<<"1. Si"<<endl;
            cout<<"2. No"<<endl;
            cin>>eleccion;
            if(cin.fail() || eleccion<=0 || eleccion>=3){
                cout<<"Numero invalido. Ingrese un tipo valido"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else if(eleccion==1){
                Cliente_M.cargarCliente(cuitCliente);
                break;
            }
            else{
                corteGeneral = true;
                break;
            }
        }
    }

    int idProducto;
    int eleccion;
    int cantidad;
    float importeTotal=0;
    bool flag = true;

    bool productosAgregados = false;

    if(!corteGeneral){
        while(true){
            cout<<"Ingrese el ID del producto a comprar"<<endl;
            cin>>idProducto;
            if(cin.fail() || idProducto <=0){
                cin.clear();
                cin.ignore(1000,'\n');
            }
            else{
                cin.ignore(1000,'\n');
            }

            Producto ProductoEncontrado;
            ProductoEncontrado = Producto_M.buscarId(idProducto);

            if(ProductoEncontrado.getIdProducto()!=0){
                Producto_M.mostrarUnProducto(ProductoEncontrado.getIdProducto(),
                                 ProductoEncontrado.getPrecioUnitario(),
                                 ProductoEncontrado.getDescripcion(),
                                 ProductoEncontrado.getMarca(),
                                 ProductoEncontrado.getTipo(),
                                 ProductoEncontrado.getStock());

                while(true){
                    cout<<"El producto mostrado es el correcto?"<<endl;
                    cout<<"1. Si"<<endl;
                    cout<<"2. No"<<endl;
                    cin>>eleccion;
                    if(cin.fail() || (eleccion <= 0 || eleccion >= 3)){
                        cout<<"Numero invalido. Ingrese un valor valido"<<endl;
                        cin.clear();
                        cin.ignore(1000,'\n');
                        system("pause");
                    }
                    else if (eleccion==1){
                        cin.ignore(1000,'\n');
                        while(true){
                            cout<<"Ingrese la cantidad a comprar"<<endl;
                            cin>>cantidad;
                            if(cin.fail() || cantidad <0){
                                cout<<"Numero invalido.Ingrese un valor valido"<<endl;
                                cin.clear();
                                cin.ignore(1000,'\n');
                            }
                            else{
                                cin.ignore(1000,'\n');
                                break;
                            }
                        }
                        if(Producto_M.descontarStock(ProductoEncontrado.getIdProducto(), cantidad)){
                            Detalle_M.cargarDetalle(idFactura, ProductoEncontrado.getIdProducto(), cantidad, ProductoEncontrado.getPrecioUnitario());
                            importeTotal=importeTotal+((float)cantidad*ProductoEncontrado.getPrecioUnitario());
                            flag = false;
                            productosAgregados = true;
                            break;
                        }
                        else{
                            cout<<"Cantidad supera stock, stock actual " << ProductoEncontrado.getStock()<<endl;
                            system("pause");
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                while(true){
                    cout<<"Desea ingresar otro producto?"<<endl;
                    cout<<"1. Si"<<endl;
                    cout<<"2. No"<<endl;
                    cin>>eleccion;
                    if(cin.fail() || (eleccion <=0 || eleccion >=3)){
                        cout<<"Numero invalido.Ingrese un valor valido"<<endl;
                        cin.clear();
                        cin.ignore(1000,'\n');
                    }
                    else{
                        cin.ignore(1000,'\n');
                        break;
                    }
                }
                if(eleccion==2){
                    break;
                }
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
                bool fechaCorrecta;
                while(!fechaCorrecta){
                    int dia, mes, anio;
                    cout<<"Ingrese el dia"<<endl;
                    cin>>dia;
                    cout<<"Ingrese el mes"<<endl;
                    cin>>mes;
                    cout<<"Ingrese el anio"<<endl;
                    cin>>anio;
                    fechaCorrecta = fechaFactura.SetFecha(dia,mes,anio);
                    if(!fechaCorrecta){
                        cout<<"El mes "<< mes << "solo tiene " << fechaFactura.getDiasMes(mes)<< " dias, ingrese nuevamente la fecha" << endl << endl;
                    }
                    else{
                       flag = false;
                    }
                }
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
            cout<<"==== COMPRA CONCRETADA ===="<<endl;
            system("pause");
        }
    }
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
        system("cls");
        switch(opc){
            case 1: filtrarPorIdFactura(vectorVentas, cantidad); break;
            case 2: filtrarPorIdCliente(vectorVentas, cantidad); break;
            case 3: filtrarPorCuit(vectorVentas,cantidad) ; break;
            case 4: filtrarPorFecha(vectorVentas,cantidad) ; break;
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

void VentaManager::filtrarPorIdFactura(Venta vectorVentas[], int cantidadRegistros){
    int id;
    bool ventaEncontrada=false;

    system("cls");
    while(true){
        cout<<"Ingrese el ID de factura"<<endl;
        cin>>id;
        if(cin.fail() || id <= 0){
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
        cout << " ------------------------------------------- " << endl;
        cout << "| No se pudo encontrar una venta con ese ID |" << endl;
        cout << " ------------------------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}

void VentaManager::filtrarPorIdCliente(Venta vectorVentas[], int cantidadRegistros){
    int idCliente=0;
    bool ventaEncontrada=false;

    system("cls");

    while(true){
        cout<<"Ingrese el ID del cliente que desea buscar: "<<endl;
        cin >> idCliente;
        if(cin.fail() || idCliente <= 0){
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

    if(idCliente>0){
        for(int i=0; i < cantidadRegistros; i++ ){
            if(vectorVentas[i].getIdCliente()==idCliente && vectorVentas[i].getOculto()== false){
                mostrarUnaVenta(vectorVentas[i].getIdFactura(),
                                     vectorVentas[i].getIdCliente(),
                                     vectorVentas[i].getFechaVenta(),
                                     vectorVentas[i].getImporteTotal()
                                     );
                ventaEncontrada=true;
            }
        }
    }
    if(!ventaEncontrada){
        cout << " ---------------------------------------- " << endl;
        cout << "| No se encontro ninguna venta con ese ID |" << endl;
        cout << " ---------------------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}

void VentaManager::filtrarPorCuit(Venta vectorVentas[], int cantidadRegistros){
    ClienteManager Cliente_M;
    Cliente clienteEncontrado;
    string cuitCliente;
    cout<<"Ingrese el CUIT del cliente que desea buscar: "<<endl;
    cin.ignore();
    getline(cin,cuitCliente);

    if(esSoloNumeros(cuitCliente)){
        clienteEncontrado = Cliente_M.buscarCuit(cuitCliente);
        if(clienteEncontrado.getId()==0){
            cout<<"No hay clientes registrados con el CUIT "<< cuitCliente << endl;
        }
        else{
            for (int i=0; i < cantidadRegistros; i++ ){
                if(vectorVentas[i].getIdCliente()==clienteEncontrado.getId() && vectorVentas[i].getOculto()== false){
                    mostrarUnaVenta(vectorVentas[i].getIdFactura(),
                                     vectorVentas[i].getIdCliente(),
                                     vectorVentas[i].getFechaVenta(),
                                     vectorVentas[i].getImporteTotal()
                                     );
                }
            }
        }
    }
    else{
        cout << " ---------------------------------------- " << endl;
        cout << "| No se encontro ninguna venta con ese ID |" << endl;
        cout << " ---------------------------------------- " << endl << endl;
    }
    system("pause");
    system("cls");
}

void VentaManager::filtrarPorFecha(Venta vectorVentas[], int cantidadRegistros){
    bool datoCorrecto = false;
    bool fechaEncontrada = false;
    int diaIngresado, mesIngresado, anioIngresado;
    cout<<"Ingrese la fecha que desea buscar en ventas : "<<endl;


    while(!datoCorrecto){
        cout<<"Dia: ";
        cin >> diaIngresado;
        cout<<endl;
        if(cin.fail() || (diaIngresado <= 0 || diaIngresado >= 32)){
            cout << " --------------------- " << endl;
            cout << "|Ingrese un dia valido|" << endl;
            cout << " --------------------- "  << endl << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
        }
        else{
            cin.ignore(1000,'\n');
            datoCorrecto = true;
        }
    }
    datoCorrecto=false;
    while(!datoCorrecto){
        cout<<"Mes: ";
        cin >> mesIngresado;
        cout<<endl;
        if(cin.fail() || (mesIngresado <= 0 || mesIngresado >= 13)){
            cout << " --------------------- " << endl;
            cout << "|Ingrese un mes valido|" << endl;
            cout << " --------------------- "  << endl << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
        }
        else{
            cin.ignore(1000,'\n');
            datoCorrecto = true;
        }
    }
    datoCorrecto=false;
    while(!datoCorrecto){
        cout<<"Anio: ";
        cin >> anioIngresado;
        cout<<endl;

        if(cin.fail() || (anioIngresado <= 1900 || anioIngresado >= 3000)){
            cout << " --------------------- " << endl;
            cout << "|Ingrese un anio valido|" << endl;
            cout << " --------------------- "  << endl << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            system("pause");
        }
        else{
            cin.ignore(1000,'\n');
            datoCorrecto = true;
        }
    }

    for(int i=0; i < cantidadRegistros; i++ ){
        if(vectorVentas[i].getFechaVenta().getDia() == diaIngresado && vectorVentas[i].getFechaVenta().getMes()== mesIngresado && vectorVentas[i].getFechaVenta().getAnio()== anioIngresado){
            mostrarUnaVenta(vectorVentas[i].getIdFactura(),
                                 vectorVentas[i].getIdCliente(),
                                 vectorVentas[i].getFechaVenta(),
                                 vectorVentas[i].getImporteTotal()
                                 );
            fechaEncontrada = true;
        }
    }

    if(!fechaEncontrada){
        cout << "Fecha no encontrada"<< endl;
    }
    system("pause");
    system("cls");
}

void VentaManager::mostrarUnaVenta(int idFactura, int idCliente, Fecha fechaVenta, float importeTotal){
    int ancho1=16,ancho2=50;
    cout <<"----------------------------------------------------------------------"<< endl;
    cout <<"|"<< llenarEspaciosString("ID Factura",ancho1)<< "| "<<llenarEspaciosInt(idFactura,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("ID Cliente",ancho1)<< "| "<<llenarEspaciosInt(idCliente,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Fecha Venta",ancho1)<< "| "<< llenarEspaciosFecha(fechaVenta.getDia(),fechaVenta.getMes(),fechaVenta.getAnio(),ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Importe Total",ancho1)<< "| "<< llenarEspaciosFloat(importeTotal,ancho2)<< "|"<< endl;
    cout <<"----------------------------------------------------------------------"<< endl;

}


