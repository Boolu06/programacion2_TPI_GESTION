#pragma once
#include <cstring>

class Fecha {

    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

    void SetFecha(int dia, int mes,int anio);


private:
    int _dia;
    int _mes;
    int _anio;

};
