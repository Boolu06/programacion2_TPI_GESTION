#pragma once
#include <cstring>

class Fecha {
public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

    bool SetFecha(int dia, int mes,int anio);


private:
    int _dia;
    int _mes;
    int _anio;

};
