#include <iostream>
#include "Funciones.h"

using namespace std;

//TODO: Crear un cpp para menu. Utilizar una clase.

int main(){
    int opc;
    bool flag=true;

    while(flag==true){
        cout<<"===== MENU DE EMPRESA ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. GESTION DE CLIENTES"<<endl;
        cout<<" 2. GESTION DE PRODUCTOS"<<endl;
        cout<<" 3. GESTION DE VENTAS"<<endl;
        cout<<" 4. CONFIGURACION"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. FIN DEL PROGRAMA"<<endl;

        cin>>opc;

        switch(opc){
            case 1: menuClientes(); break;
            case 2: menuProductos(); break;
            case 3: menuVentas(); break;
            case 4: menuBackUp(); break;
            case 0: return 0; break;
            default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
        }
    }
}
