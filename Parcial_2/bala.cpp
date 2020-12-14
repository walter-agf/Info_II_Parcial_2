#include "bala.h"

bala::bala(double d, double h){
    distancia = d;
    altura = h;
}

bala::~bala(){};

bool bala::validez (double v, double a){
    val = false;
    ataque = distancia * 0.05;
    angulo = (a*PI)/180;
    velocidad = v;
    vx = cos(angulo) * velocidad;
    time = distancia / vx;

    vy = sin(angulo) * velocidad;
    momento = (vy * time) + (-g * pow(time,2))/2;

    if (altura - momento < ataque) val = true;

    return val;
}

void bala::disparo_simple (double v, double a){

}

void bala::disparo_sin_colateral (double v, double a){

}
