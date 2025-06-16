#pragma once
#include <cstring>

class Fecha {
public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    int getDiasMes(int mes);

    bool SetFecha(int dia, int mes,int anio);


private:
    int _dia;
    int _mes;
    int _anio;
    int _diasMeses[12]={31,28,31,30,31,30,31,31,30,31,30,31};
};
