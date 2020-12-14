#ifndef BALA_H
#define BALA_H
#include "general.h"

#endif // BALA_H

class bala{
    private:
        double radian = PI / 180;
        bool val = false , posibilidad;
        double distancia,altura,vx,vy;
        double angulo,velocidad,time,momento;
        double ataque,analizador,grados;
        int num, cont;
        vector <double> cad;
        vector <double> punto;

        double llegada, vel_x,i,pass;

        double lejania, cercania;


    public:
        bala(double d, double h);

        bool validez (double v, double a);
        void disparo_simple ();
        void disparo_sin_colateral ();


        ~bala();

};
