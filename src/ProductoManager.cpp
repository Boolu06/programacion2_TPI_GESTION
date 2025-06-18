#include<iostream>
#include <cstring>
#include "Producto.h"
#include "ProductoManager.h"
#include "Funciones.h"

using namespace std;

void ProductoManager::cargarProducto(){
    Producto nuevoProducto;
    int idProducto;
    float precioUnitario;
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
        if(!datoCorrecto){
            cout << " ----------------------------------------------- " << endl;
            cout << "| El tipo debe tener entre 1 y 14 caracteres     |" << endl;
            cout << " ----------------------------------------------- " << endl << endl;
        }
    }

    datoCorrecto = false; // resetar el booleando para ingresar al proximo bucle

    while(!datoCorrecto){
        cout<<"Ingrese el precio: "<<endl;
        cin>>precioUnitario; // El cin simple si le agrego letras van a quedar en el buffer
        if(cin.fail() || precioUnitario<0){
            cout << " ------------------------------- " << endl;
            cout << "| El precio unitario debe ser un numero mayor que 0 |" << endl;
            cout << " ------------------------------- " << endl << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
        else{
            cin.ignore(1000,'\n');
            datoCorrecto = nuevoProducto.setPrecioUnitario(precioUnitario);
        }
    }

    datoCorrecto = false; // resetar el booleando para ingresar al proximo bucle

    while(!datoCorrecto){
        cout<<"Ingrese la descripcion: "<<endl;
        getline(cin, descripcion);
        datoCorrecto = nuevoProducto.setDescripcion(descripcion);

        if(!datoCorrecto){
            cout << " -------------------------------------------------- " << endl;
            cout << "| La descripcion debe tener entre 1 y 49 caracteres |" << endl;
            cout << " -------------------------------------------------- " << endl << endl;
        }
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese la marca: "<<endl;
        getline(cin, marca);
        datoCorrecto = nuevoProducto.setMarca(marca);

        if(!datoCorrecto){
            cout << " ----------------------------------------------- " << endl;
            cout << "| La marca debe tener entre 1 y 14 caracteres    |" << endl;
            cout << " ----------------------------------------------- " << endl << endl;
        }
    }

    datoCorrecto = false;

    while(!datoCorrecto){
        cout<<"Ingrese el stock o disponibilidad (numero): "<<endl;
        cin>> stock;

        if(cin.fail() || stock < 0){
            cout << " ---------------------------------- " << endl;
            cout << "| El numero ingresado no es valido |" << endl;
            cout << " ---------------------------------- " << endl << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
        else{
            cin.ignore(1000,'\n');
            datoCorrecto = nuevoProducto.setStock(stock);
        }
    }

    //dato correcto se deja en true para entrar al if:

    if(datoCorrecto){

        if(_archivo.guardar(nuevoProducto)){
            cout<<"Producto registrado correctamente."<<endl;
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

    bool flag=true;
    int opc;

    while(flag==true){
        system("cls");
        cout<<"===== MENU PRODUCTOS ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. Filtrar por marca"<<endl;
        cout<<" 2. Filtrar por tipo de producto"<<endl;
        cout<<" 3. Listar todos los productos"<<endl;
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
                case 1: filtrarPorMarca(vectorProductos, cantidad); break;
                case 2: filtrarPorTipo(vectorProductos, cantidad); break;
                case 3:
                    system("cls");
                    for (int i=0; i<cantidad; i++ ){
                        if(vectorProductos[i].getOculto()== false){
                            mostrarUnProducto(vectorProductos[i].getIdProducto(),
                                             vectorProductos[i].getPrecioUnitario(),
                                             vectorProductos[i].getDescripcion(),
                                             vectorProductos[i].getMarca(),
                                             vectorProductos[i].getTipo(),
                                             vectorProductos[i].getStock()
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
    delete[]vectorProductos;
}

void ProductoManager::filtrarPorMarca(Producto vectorProductos[], int cantidadRegistros){
    string marca;
    bool productoEncontrado=false;

    system("cls");
    cout<<"Ingrese la marca"<<endl;
    cin.ignore();
    getline(cin,marca);

    for(int i=0; i<cantidadRegistros; i++){
        if(aMinusculas(vectorProductos[i].getMarca()) == aMinusculas(marca) && vectorProductos[i].getOculto() == false){
            mostrarUnProducto(vectorProductos[i].getIdProducto(),
                             vectorProductos[i].getPrecioUnitario(),
                             vectorProductos[i].getDescripcion(),
                             vectorProductos[i].getMarca(),
                             vectorProductos[i].getTipo(),
                             vectorProductos[i].getStock()
                             );
            productoEncontrado=true;
        }
    }
    if(!productoEncontrado){
        cout<<"Marca no encontrada"<<endl;
    }
    system("pause");
}

void ProductoManager::filtrarPorTipo(Producto vectorProductos[], int cantidadRegistros){
    string tipo;
    bool productoEncontrado=false;
    system("cls");
    cout<<"Ingrese el tipo de producto"<<endl;
    cin.ignore();
    getline(cin,tipo);

    for(int i=0; i<cantidadRegistros; i++){
        if(vectorProductos[i].getTipo() == tipo && vectorProductos[i].getOculto() == false){
            mostrarUnProducto(vectorProductos[i].getIdProducto(),
                             vectorProductos[i].getPrecioUnitario(),
                             vectorProductos[i].getDescripcion(),
                             vectorProductos[i].getMarca(),
                             vectorProductos[i].getTipo(),
                             vectorProductos[i].getStock()
                             );
            productoEncontrado=true;
        }
    }
    if(!productoEncontrado){
        cout<<"Tipo de producto no encontrado"<<endl;
    }
    system("pause");
}

Producto ProductoManager::buscarId(int idProducto){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidadRegistros];
    _archivo.leerVector(vectorProductos, cantidadRegistros);

    int index = _archivo.buscarIndex(vectorProductos,cantidadRegistros,idProducto);


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
        bool flag = true;
        bool datoCorrecto = false;
        int opcion;

        while (flag == true){
        system("cls");
            cout<<"=== ID de producto encontrado! ==="<< endl;
            mostrarUnProducto(vectorProductos[index].getIdProducto(),
                             vectorProductos[index].getPrecioUnitario(),
                             vectorProductos[index].getDescripcion(),
                             vectorProductos[index].getMarca(),
                             vectorProductos[index].getTipo(),
                             vectorProductos[index].getStock()
                             );
            cout<< "Que dato deseas modificar ? " <<endl<<endl;
            cout<< "1. Precio" <<endl;
            cout<< "2. Descripcion del producto" <<endl;
            cout<< "3. Marca " <<endl;
            cout<< "4. Tipo " <<endl;
            cout<< "5. Stock " <<endl;
            cout<< "0. Terminar modificaciones"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            if(cin.fail()){
                cout<<"INGRESE UNA OPCION CORRECTA"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                system("pause");
            }
            else{
                cin.ignore(1000,'\n');
                switch (opcion){
                    case 1:{
                        float precioUnitario;
                        while(!datoCorrecto){
                            cout<<"Ingrese el precio unitario del producto"<<endl;
                            cin>>precioUnitario;

                            if(cin.fail() || precioUnitario<0){
                                cout << " ------------------------------- " << endl;
                                cout << "| El precio unitario debe ser un numero mayor que 0 |" << endl;
                                cout << " ------------------------------- " << endl << endl;
                                cin.clear();
                                cin.ignore(1000,'\n');
                            }
                            else{
                                cin.ignore(1000,'\n');
                                datoCorrecto = vectorProductos[index].setPrecioUnitario(precioUnitario);
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 2:{
                        string descripcion;
                        while(!datoCorrecto){
                            cout<<"Ingrese la descripcion"<<endl;
                            getline(cin, descripcion);
                            datoCorrecto = vectorProductos[index].setDescripcion(descripcion);
                            if(!datoCorrecto){
                                cout << " -------------------------------------------------- " << endl;
                                cout << "| La descripcion debe tener entre 1 y 49 caracteres |" << endl;
                                cout << " -------------------------------------------------- " << endl << endl;
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 3:{
                        string marca;
                        while(!datoCorrecto){
                            cout<<"Ingrese la marca"<<endl;
                            getline(cin, marca);
                            datoCorrecto = vectorProductos[index].setMarca(marca);
                            if(!datoCorrecto){
                                cout << " ----------------------------------------------- " << endl;
                                cout << "| La marca debe tener entre 1 y 14 caracteres    |" << endl;
                                cout << " ----------------------------------------------- " << endl << endl;
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 4:{
                        string tipo;
                        while(!datoCorrecto){
                            cout<<"Ingrese el tipo"<<endl; //TODO: Se podrian ingresar validaciones o hacer un mini-menu para elegir el tipo (si es PC, notebook, impresora, periferico, etc)
                            getline(cin, tipo);
                            datoCorrecto = vectorProductos[index].setTipo(tipo);
                            if(!datoCorrecto){
                                cout << " ----------------------------------------------- " << endl;
                                cout << "| El tipo debe tener entre 1 y 14 caracteres     |" << endl;
                                cout << " ----------------------------------------------- " << endl << endl;
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 5:{
                        int stock;
                        while(!datoCorrecto){
                            cout<<"Ingrese el stock"<<endl;
                            cin>>stock;
                            if(cin.fail() || stock<0){
                                cout << " ---------------------------------- " << endl;
                                cout << "| El numero ingresado no es valido |" << endl;
                                cout << " ---------------------------------- " << endl << endl;
                                cin.clear();
                                cin.ignore(1000,'\n');
                            }
                            else{
                                cin.ignore(1000,'\n');
                                datoCorrecto = vectorProductos[index].setStock(stock);
                            }
                        }
                        datoCorrecto = false;
                        huboModificaciones= true;
                        cout<<"Dato modificado correctamente"<<endl;
                        system("pause");
                        break;
                    }
                    case 0: flag=false; system("cls"); break;
                    default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause");
                }
            }
        }
    }
    else{
        cout << " ------------------------------ " << endl;
        cout << "| ID de producto no encontrado |" << endl;
        cout << " ------------------------------ " << endl << endl;
    }

    if(huboModificaciones){
        _archivo.modificar(vectorProductos[index], index);
    }
    system("pause");
    delete []vectorProductos;
}

bool ProductoManager::descontarStock(int idProductoModificar, int cantidadStockVendido){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidadRegistros];
    _archivo.leerVector(vectorProductos, cantidadRegistros);

    int index = _archivo.buscarIndex(vectorProductos,cantidadRegistros,idProductoModificar);

    bool datoCorrecto  = false;

    if(index >= 0){
        int stockFinal  = (vectorProductos[index].getStock()) - cantidadStockVendido;
        datoCorrecto = (vectorProductos[index].setStock(stockFinal));
    }

    if(datoCorrecto){
        _archivo.modificar(vectorProductos[index], index);
    }
    else{
        return datoCorrecto;
    }

    delete []vectorProductos;
}

void ProductoManager::mostrarUnProducto(int idProducto, float precioUnitario, std::string descripcion,std::string marca, std::string tipo, int stock){
    int ancho1=16,ancho2=50;
    cout <<"----------------------------------------------------------------------"<< endl;
    cout <<"|"<< llenarEspaciosString("ID",ancho1)<< "| "<<llenarEspaciosInt(idProducto,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Precio Unitario",ancho1)<< "| "<<llenarEspaciosFloat(precioUnitario,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Descripcion",ancho1)<< "| "<< llenarEspaciosString(descripcion,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Marca",ancho1)<< "| "<< llenarEspaciosString(marca,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Tipo",ancho1)<< "| "<< llenarEspaciosString(tipo,ancho2)<< "|"<< endl;
    cout <<"|"<< llenarEspaciosString("Stock",ancho1)<< "| "<< llenarEspaciosInt(stock,ancho2)<< "|"<< endl;
    cout <<"----------------------------------------------------------------------"<< endl;
}

void ProductoManager::borrarProducto(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidadRegistros];
    _archivo.leerVector(vectorProductos, cantidadRegistros);
    int idProductoBorrar;

    system("cls");
    while(true){
        cout<< "Ingrese el ID del producto que desea borrar: " <<endl;
        cin>> idProductoBorrar;
        if(cin.fail() || idProductoBorrar<0){
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

    int index = _archivo.buscarIndex(vectorProductos,cantidadRegistros,idProductoBorrar);
    bool huboModificaciones = false;
    if(index >= 0){
        system("cls");
        cout<< "Este es el cliente que vas a borrar: "<< endl;
        mostrarUnProducto(vectorProductos[index].getIdProducto(),
                         vectorProductos[index].getPrecioUnitario(),
                         vectorProductos[index].getDescripcion(),
                         vectorProductos[index].getMarca(),
                         vectorProductos[index].getTipo(),
                         vectorProductos[index].getStock()
                         );
        system("pause");

        int opcion;
        while(true){
            cout<< "Confirme si desea eliminarlo" <<endl<<endl;
            cout<< "1. Si" <<endl;
            cout<< "0. Cancelar borrado"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            if(cin.fail() || (opcion <0 || opcion >1)){
                cout<<"Numero invalido. Ingrese un tipo valido"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
                system("pause");
            }
            else{
                cin.ignore(1000,'\n');
                switch(opcion){
                    case 1:
                        vectorProductos[index].setOculto(true);
                        huboModificaciones = true;
                        break;
                    case 0:
                        break;
                }
                break;
            }
        }
    }
    else{
        cout << " ------------------------------ " << endl;
        cout << "| ID de producto no encontrado |" << endl;
        cout << " ------------------------------ " << endl << endl;
        system("pause");
    }
    if(huboModificaciones){
        _archivo.modificar(vectorProductos[index], index);
        cout<<"Cliente eliminado satisfactoriamente"<<endl;
        system("pause");
    }

    delete []vectorProductos;
}

