#pragma once
#include <iostream>
#include <cstring>

void menuClientes();
void menuProductos();
void menuVentas();
void menuReportes();
void menuBackUp();
void menuBackUpGuardar();
void menuBackUpRestaurar();
void backUpGuardar(std::string nombreArchivo);
void backUpGuardarTodo();
bool backUpRestaurar(std::string nombreArchivo, bool flag);
bool backUpRestaurarTodo();
bool esSoloNumeros(std::string numero);
bool esSoloNumeros(float numero);
bool esSoloNumeros(int numero);
bool esSoloLetras(std::string palabra);
std::string aMinusculas(std::string palabra);
std::string llenarEspaciosString(std::string cadena,int espaciosTotales);
std::string llenarEspaciosInt(int cifra, int espaciosTotales);
std::string llenarEspaciosFloat(float cifra, int espaciosTotales);
std::string llenarEspaciosFecha(int dia, int mes, int anio, int espaciosTotales);
