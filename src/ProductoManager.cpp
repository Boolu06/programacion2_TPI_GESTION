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

        datoCorrecto = nuevoProducto.setPrecioUnitario(precioUnitario);

        if(!datoCorrecto){
            cout << " ------------------------------- " << endl;
            cout << "| El precio unitario debe ser un numero mayor que 0 |" << endl;
            cout << " ------------------------------- " << endl << endl;
        }
    }
    cin.ignore();
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
        datoCorrecto = nuevoProducto.setStock(stock);

        if(!datoCorrecto){
            cout << " -------------------------------- " << endl;
            cout << "| El stock no puede ser negativo |" << endl;
            cout << " -------------------------------- " << endl << endl;
        }
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
        system("pause");
    }
    else{
        system("pause");
    }
}

void ProductoManager::filtrarPorTipo(Producto vectorProductos[], int cantidadRegistros){
    string tipo;
    cout<<"Ingrese el tipo de producto"<<endl;
    cin>>tipo;

    for(int i=0; i<cantidadRegistros; i++){
        if(vectorProductos[i].getTipo() == tipo && vectorProductos[i].getOculto() == false){
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
        system("cls");
        cout<< "Id de producto encontrado! "<< endl;
        mostrarUnProducto(vectorProductos[index].getIdProducto(),
                         vectorProductos[index].getPrecioUnitario(),
                         vectorProductos[index].getDescripcion(),
                         vectorProductos[index].getMarca(),
                         vectorProductos[index].getTipo(),
                         vectorProductos[index].getStock()
                         );
        system("pause");

        bool flag = true;
        bool datoCorrecto = false;
        int opcion;
        while (flag == true){
            cout<< "Que dato deseas modificar ? " <<endl<<endl;
            cout<< "1. Precio" <<endl;
            cout<< "2. Descripcion del producto" <<endl;
            cout<< "3. Marca " <<endl;
            cout<< "4. Tipo " <<endl;
            cout<< "5. Stock " <<endl;
            cout<< "0. Terminar modificaciones"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion){
                case 1:{
                    float precioUnitario;
                    while(!datoCorrecto){
                        cout<<"Ingrese el precio unitario del producto"<<endl;
                        cin>>precioUnitario;
                        datoCorrecto = vectorProductos[index].setPrecioUnitario(precioUnitario);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 2:{
                    string descripcion;
                    while(!datoCorrecto){
                        cout<<"Ingrese la descripcion"<<endl;
                        getline(cin, descripcion);
                        datoCorrecto = vectorProductos[index].setDescripcion(descripcion);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 3:{
                    string marca;
                    while(!datoCorrecto){
                        cout<<"Ingrese la marca"<<endl;
                        getline(cin, marca);
                        datoCorrecto = vectorProductos[index].setMarca(marca);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 4:{
                    string tipo;
                    while(!datoCorrecto){
                        cout<<"Ingrese el tipo"<<endl; //TODO: Se podrian ingresar validaciones o hacer un mini-menu para elegir el tipo (si es PC, notebook, impresora, periferico, etc)
                        getline(cin, tipo);
                        datoCorrecto = vectorProductos[index].setTipo(tipo);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 5:{
                    int stock;
                    while(!datoCorrecto){
                        cout<<"Ingrese el stock"<<endl;
                        cin>>stock;
                        datoCorrecto = vectorProductos[index].setStock(stock);
                    }
                    datoCorrecto = false;
                    huboModificaciones= true;
                    break;
                }
                case 0: flag=false; system("cls"); break;
            }
        }

    }
    else{
        cout << "resultado de busqueda index: " << index << endl;
        cout << "Id de producto no encontrado chau" << endl;
        system("pause");
    }

    cout << " tamos mandando el indexxxxxxxxxxxx: " << index;
    if(huboModificaciones){
        _archivo.modificar(vectorProductos[index], index);
    }

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
    else{

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
    cout << "----------ID Producto: "<<idProducto<<" ------------" << endl;
        cout << "Precio Unitario: " << precioUnitario << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Marca: "<< marca <<endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Stock: "<< stock <<endl;
        cout << "-----------------------------" << endl;
}

void ProductoManager::borrarProducto(){
    int cantidadRegistros = _archivo.getCantidadRegistros();
    Producto *vectorProductos;
    vectorProductos = new Producto[cantidadRegistros];
    _archivo.leerVector(vectorProductos, cantidadRegistros);
    int idProductoBorrar;

    cout<< "Ingrese el ID del producto que desea borrar: " <<endl;
    cin>> idProductoBorrar;
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

        bool flag = true;

        int opcion;

        while (flag == true){
            cout<< "Que estas seguro que lo quieres borrar ? " <<endl<<endl;
            cout<< "1. S1" <<endl;
            cout<< "0. Cancelar borrado"<<endl<<endl;
            cout<< "Opcion: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion){
                case 1:
                    vectorProductos[index].setOculto(true);
                    flag = false;
                    huboModificaciones = true;
                    break;
                case 0:
                    flag=false; system("cls"); break;
            }
        }
    }
    else{
        cout << "resultado de busqueda index: " << index << endl;
        cout << "Id de cliente no encontrado chau" << endl;
        system("pause");
    }
    if(huboModificaciones){
        _archivo.modificar(vectorProductos[index], index);
    }

    delete []vectorProductos;
}

