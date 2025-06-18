#pragma once
#include <iostream>
#include <cstring>
#include "VentaManager.h"
#include "Venta.h"

void reporteAnual();
void reporteAnualProductos();
void mostrarReporteAnual(int vectorMesesVenta[],float vectorMesesImporte[], int anioIngresado);
void mostrarReporteAnualProductos(Producto productoIterado, int vectorMeses[], int anioIngresado);
void mostrarEncabezadoReporteAnual(int anioIngresado);
