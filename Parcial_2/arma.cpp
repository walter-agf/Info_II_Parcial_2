#include "arma.h"

arma::arma(double d, double h){
    distancia = d;
    altura = h;
}

arma::~arma(){};

void arma::disparo_defensivo (){
    ataque = distancia * 0.025;
    angulo = atan(altura/distancia);
    cad.push_back(angulo);
    while(angulo < PI/2){
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
    cont = 0;
    time = 0.001;
    for (int i = 0; i < num; i++){
        salir = false;
        for (; time < 60; time += 0.001){
            analizador = punto[cont]/tan(cad[i]);
            analizador *= time;
            if (analizador > distancia - ataque && analizador < distancia + ataque){
                grados = cad[i] * 180 / PI;
                velocidad = sqrt(pow(analizador/time,2)+pow(punto[cont],2));
                cout << "| " << grados << " grados    |     " << velocidad << " m/s      | " << time << " segundos   |";
                cout << "\n|_____________________________________________________________|" << endl;
                salir = true;
            }
            if (salir == true) break;
            cont ++;
        }
    }
}

void arma::disparo_ofensivo (){
    ataque = distancia * 0.05;
    angulo = atan(altura/distancia);
    cad.push_back(angulo);
    while(angulo < PI/2){
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
    cont = 0;
    time = 0.001;
    for (int i = 0; i < num; i++){
        salir = false;
        for (; time < 60; time += 0.001){
            analizador = punto[cont]/tan(cad[i]);
            analizador *= time;
            if (analizador > distancia - ataque && analizador < distancia + ataque){
                grados = cad[i] * 180 / PI;
                velocidad = sqrt(pow(analizador/time,2)+pow(punto[cont],2));
                cout << "| " << grados << " grados    |     " << velocidad << " m/s      | " << time << " segundos   |";
                cout << "\n|_____________________________________________________________|" << endl;
                salir = true;
            }
            if (salir == true) break;
            cont ++;
        }
    }
}
