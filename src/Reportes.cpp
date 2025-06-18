#include "Reportes.h"
#include "VentaArchivo.h"
#include "Venta.h"
#include "Funciones.h"
#include "rlutil.h"
#include<iostream>
#include<cstring>


using namespace std;

void reporteAnual(){
    VentaArchivo _archivo;
    int cantidad = _archivo.getCantidadRegistros();
    int anioBusqueda;
    Venta *vectorVentas;
    int vectorMesesCantVenta[12]={0};
    float vectorMesesImporteTotal[12]={0};
    vectorVentas = new Venta [cantidad];

    _archivo.leerVector(vectorVentas, cantidad); // esta funcion mete en el vectorProductos los productos que consiga en el archivo.dat.

    cout << "Ingrese el anio que necesita buscar: ";
    cin >> anioBusqueda;

    for(int i = 0 ; i < cantidad; i++){
        if(vectorVentas[i].getFechaVenta().getAnio()== anioBusqueda){

            vectorMesesCantVenta[vectorVentas[i].getFechaVenta().getMes()-1]++;
            vectorMesesImporteTotal[vectorVentas[i].getFechaVenta().getMes()-1]+= vectorVentas[i].getImporteTotal();
        }
    }

    mostrarReporteAnual(vectorMesesCantVenta,vectorMesesImporteTotal,anioBusqueda);

}

void reporteAnualProductos(){
    ProductoArchivo _archivoProd;
    VentaArchivo _archivoVenta;
    DetalleArchivo _archivoDetalle;
    int cantidadProductos = _archivoProd.getCantidadRegistros();
    int cantidadVentas = _archivoVenta.getCantidadRegistros();
    int cantidadDetalles = _archivoDetalle.getCantidadRegistros();
    Producto *vectorProductos;
    Venta *vectorVentas;
    Detalle *vectorDetalles;
    int anioBusqueda;

    int vectorMesesProdVendido[12] = {0};


    vectorProductos = new Producto [cantidadProductos];
    vectorVentas = new Venta [cantidadVentas];
    vectorDetalles = new Detalle [cantidadDetalles];

    _archivoProd.leerVector(vectorProductos,cantidadProductos);
    _archivoVenta.leerVector(vectorVentas,cantidadVentas);
    _archivoDetalle.leerVector(vectorDetalles,cantidadDetalles);

    cout << "Ingrese el anioo que necesita buscar: "<<endl;
    cin >> anioBusqueda;
    system("cls");
    mostrarEncabezadoReporteAnual(anioBusqueda);

    for(int iProducto = 0 ; iProducto < cantidadProductos; iProducto++){ // por cada producto recorre:
       for(int iVentas=0; iVentas < cantidadVentas; iVentas++){ //todas las vendas
            if(vectorVentas[iVentas].getFechaVenta().getAnio()== anioBusqueda){
                for( int iDetalles = 0; iDetalles < cantidadDetalles; iDetalles++){// y todos los detalles si coincide el año de busqueda
                    if(vectorDetalles[iDetalles].getIdFactura()== vectorVentas[iVentas].getIdFactura() && vectorDetalles[iDetalles].getIdProducto() == vectorProductos[iProducto].getIdProducto()){
                        vectorMesesProdVendido[vectorVentas[iVentas].getFechaVenta().getMes()-1]+=vectorDetalles[iDetalles].getCantidad();// suma la cantidad vendida
                    }
                }
            }
        }

        mostrarReporteAnualProductos(vectorProductos[iProducto], vectorMesesProdVendido,anioBusqueda);

        //este for limpia el vector del conteo por mes para pasar al siguiente producto.
        for(int x = 0 ; x < 12 ; x ++){
            vectorMesesProdVendido[x]= 0;
        }
    }

    system("pause");
}

void mostrarReporteAnual(int vectorMesesVenta[],float vectorMesesImporte[], int anioIngresado){
    int ancho1=6, ancho2= 12, ancho3 = 16;
    cout<< "--------------------------------------"<<endl;
    cout<< "------------------"<< anioIngresado<<"----------------"<<endl;
    cout<< "--------------------------------------"<<endl;
    cout<<"|"<< llenarEspaciosString("MES",ancho1)<<"|"<<llenarEspaciosString("Cant Ventas", ancho2)<<"|"<<llenarEspaciosString("Total Recaudado", ancho3) <<"|"<<endl;
    for(int i = 0 ; i < 12; i++){
        cout<<"|"<< llenarEspaciosInt( (i+1) ,ancho1)<<"|"<<llenarEspaciosInt(vectorMesesVenta[i], ancho2)<<"|"<<llenarEspaciosFloat(vectorMesesImporte[i], ancho3) <<"|"<<endl;
    }
    cout<< "--------------------------------------"<<endl;
    system("pause");
}

void mostrarReporteAnualProductos(Producto productoIterado, int vectorMeses[], int anioIngresado){
    int ancho1=3, ancho2= 50, ancho3 = 3;
    cout << llenarEspaciosInt(productoIterado.getIdProducto(),ancho1) << "|" <<  llenarEspaciosString(productoIterado.getDescripcion(),ancho2) << "|";
    for(int i = 0 ; i < 12; i++){
        if(vectorMeses[i]>0){
            rlutil::setColor(rlutil::LIGHTGREEN);
        }
        cout << llenarEspaciosInt(vectorMeses[i],ancho3);
        rlutil::setColor(rlutil::WHITE);
        cout << "|";
    }

    cout << endl;
}

void mostrarEncabezadoReporteAnual(int anioIngresado){
    string vectorMesesString [12] = {"ENE","FEB","MAR","ABR","MAY","JUN","JUL","AGO","SEP","OCT","NOV","DIC"};
    int ancho1=3, ancho2= 50, ancho3 = 3;
    for(int x = 0 ; x<103; x++){
       cout<<(char)205;
    }
    cout<<endl;
    rlutil::locate(50,2);cout<< anioIngresado<<endl;
    for(int x = 0 ; x<103; x++){
       cout<<(char)205;
    }
    cout<<endl;
    cout<< llenarEspaciosString("ID",ancho1)<<"|"<<llenarEspaciosString("DESCRIPCION", ancho2)<<"|";
    for(int i = 0 ; i < 12; i++){
        cout << llenarEspaciosString(vectorMesesString[i],ancho3) << "|";
    }
    cout << endl;
    for(int x = 0 ; x<103; x++){
       cout<<(char)205;
    }
    cout<<endl;
}
