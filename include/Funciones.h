#pragma once
#include <iostream>
#include <cstring>

void menuClientes();
void menuProductos();
void menuVentas();
void menuBackUp();
void menuBackUpGuardar();
void menuBackUpRestaurar();
void backUpGuardar(std::string nombreArchivo);
void backUpGuardarTodo();
bool backUpRestaurar(std::string nombreArchivo);
bool backUpRestaurarTodo();
bool esSoloNumeros(std::string numero);
bool esSoloNumeros(float numero);
bool esSoloLetras(std::string palabra);
std::string aMinusculas(std::string palabra);



