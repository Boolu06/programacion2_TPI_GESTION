#include <iostream>
#include <ctime>
#include "Funciones.h"

using namespace std;

int main(){
    srand(time(0));
    int opc;
    bool flag=true;

    while(flag==true){
        cout<<"===== MENU DE EMPRESA ====="<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 1. GESTION DE CLIENTES"<<endl;
        cout<<" 2. GESTION DE PRODUCTOS"<<endl;
        cout<<" 3. GESTION DE VENTAS"<<endl;
        cout<<" 4. GESTION DE REPORTES"<<endl;
        cout<<" 5. CONFIGURACION"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<" 0. FIN DEL PROGRAMA"<<endl;
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
                case 1: menuClientes(); break;
                case 2: menuProductos(); break;
                case 3: menuVentas(); break;
                case 4: menuReportes();break;
                case 5: menuBackUp(); break;
                case 0: return 0; break;
                default: cout<<"INGRESE UNA OPCION CORRECTA"<<endl; system("pause"); system("cls");
            }
        }
    }
}
