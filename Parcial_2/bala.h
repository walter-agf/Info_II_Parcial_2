#ifndef BALA_H
#define BALA_H
#include "general.h"

#endif // BALA_H

class bala{
    private:
        double radian = PI / 180;
        bool val = false;
        double distancia,altura,vx,vy;
        double angulo,velocidad,time,momento;
        double ataque;


    public:
        bala(double d, double h);

        bool validez (double v, double a);
        void disparo_simple (double v, double a);
        void disparo_sin_colateral (double v, double a);


        ~bala();

};
