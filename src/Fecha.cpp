#include <iostream>
#include "Fecha.h"
using namespace std;


Fecha::Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 2000;
};

Fecha::Fecha(int dia, int mes, int anio){
    SetFecha(dia,mes,anio);
};

int Fecha::getDia() {return _dia};
int Fecha::getMes() {return _mes};
int Fecha::getAnio(){return _anio};

void Fecha::SetFecha(int dia, int mes,int anio){
    if (anio < 1900 || anio > 2100) return false;
    if (mes < 1 || mes > 12) return false;
    if (dia < 1 || dia > 31 return false;

    _dia = dia;
    _mes = mes;
    _anio = anio;
    return true;
};
