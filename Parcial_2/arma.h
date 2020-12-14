#ifndef ARMA_H
#define ARMA_H
#include "general.h"

#endif // ARMA_H

class arma{
    private:
        double radian = PI / 180;
        double distancia,altura,angulo,analizador;
        vector <double> cad;
        int num = 0, cont = 0;
        vector <double> punto;
        double grados, velocidad;


    public:
        arma(double distancia, double altura);
        void disparo_ofensivo ();


        ~arma();

};
