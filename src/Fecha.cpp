#include <iostream>
#include <ctime>
#include "Fecha.h"
using namespace std;


Fecha::Fecha(){
    // Obtener la hora actual del sistema
    time_t ahora = time(nullptr);

    // Convertir a estructura tm (tiempo local)
    tm* fecha_local = localtime(&ahora);

    _dia = fecha_local->tm_mday;
    _mes = fecha_local->tm_mon + 1;
    _anio = fecha_local->tm_year + 1900;
}

Fecha::Fecha(int dia, int mes, int anio){
    SetFecha(dia,mes,anio);
}

int Fecha::getDia() {return _dia;}
int Fecha::getMes() {return _mes;}
int Fecha::getAnio(){return _anio;}
int Fecha::getDiasMes(int mes){
    return _diasMeses[mes-1];
}


bool Fecha::SetFecha(int dia, int mes,int anio){
    if (anio < 1900 || anio > 2100) return false;
    if (mes < 1 || mes > 12) return false;

    // Mover esto despu�s de validar el mes
    if (dia < 1 || dia > _diasMeses[mes - 1]) return false;

    _dia = dia;
    _mes = mes;
    _anio = anio;

    return true;
}
