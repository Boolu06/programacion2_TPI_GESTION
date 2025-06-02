class DetalleArchivo{ ///Clase que crea el archivo de Detalle de venta

public:

    DetalleArchivo(std::string nombrearchivo="detalleDeVenta.dat");
    bool guardar(Detalle reg);
    bool modificar(Detalle &registro, int index);
    bool borrar(Detalle &registro, int index);
    int getCantidadRegistros();
    bool leerVector(Detalle vectorRegistros[], int cantidad);
    int buscarIndex(Detalle vectorRegistros[],int cantidad,int idFactura);
    std::string getNombreArchivo();
    int getNuevoId();

private:
    std::string _nombreArchivo;
};

