#pragma once
#include <iostream>
#include <cstring>

void menuClientes();
void menuProductos();
void menuVentas();
void menuBackUp();
void menuBackUpGuardar();
void menuBackUpRestaurar();
bool backUpGuardar(std::string nombreArchivo);
bool backupRestaurar(std::string nombreArchivo);
bool esSoloNumeros(std::string numero);
bool esSoloNumeros(float numero);
bool esSoloLetras(std::string palabra);
std::string aMinusculas(std::string palabra);



