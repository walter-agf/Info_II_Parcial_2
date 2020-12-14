#include "arma.h"

arma::arma(double d, double h){
    distancia = d;
    altura = h;
}

arma::~arma(){};

void arma::disparo_ofensivo (){
    angulo = atan(altura/distancia);
    cad.push_back(angulo);
    while(angulo < 1){
        angulo += radian;
        cad.push_back(angulo);
    }
    num = cad.size();
    for (double i = 0.001; i < 60; i += 0.001){
        punto.push_back(((g*pow(i,2)/2)+altura)/i);
    }
    cout << "\nLANZAMIENTO EXITOSO CON:\n" << endl;
    cout << "_______________________________________________________________" << endl;
    cout << "|                   |                      |                  |" << endl;
    cout << "|   ANGULO          |      VELOCIDAD       |     TIEMPO       |" << endl;
    cout << "|_____________________________________________________________|" << endl;
    for (int i = 0; i < num; i++){
        salir = false;
        cont = 0;
        for (double a = 0.001; a < 60; a += 0.001){
            analizador = punto[cont]/tan(cad[i]);
            analizador *= a;
            if (analizador > distancia && analizador < distancia + 0.05){
                grados = cad[i] * 180 / PI;
                velocidad = sqrt(pow(analizador/a,2)+pow(punto[cont],2));
                cout << "| " << grados << " grados    |     " << velocidad << " m/s      | " << a << " segundos   |";
                cout << "\n|_____________________________________________________________|" << endl;
                salir = true;
            }
            if (salir == true) break;
            cont ++;
        }
    }
}
