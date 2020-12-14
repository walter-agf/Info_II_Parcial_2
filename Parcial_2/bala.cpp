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

    time -= 0.1;

    vy = sin(angulo) * velocidad;
    momento = (vy * time) + (-g * pow(time,2))/2;

    momento = altura - momento;

    if (momento < 0 ) momento *= -1;

    if (momento < 4*ataque) val = true; //SE COLOCA UN RANGO DE CERTEZA EL DOBLE DEL RANGO DE ATAQUE

    //cout << "\n\nMOMENTO: " << momento;

    return val;
}

void bala::disparo_sin_colateral (){
    posibilidad = false;
    ataque = distancia * 0.025;
    angulo = atan(-altura/distancia);
    cad.push_back(angulo);
    while(angulo < PI/2){
        angulo += radian;
        cad.push_back(angulo);
    }
    num = cad.size();
    for (double i = 2.001; i < time; i += 0.001){
        punto.push_back(((vy*i)+((-g*pow(i,2))/2))-altura);
    }
    cout << "\nLANZAMIENTO EXITOSO CON:\n" << endl;
    cout << "______________________________________________________________________" << endl;
    cout << "|                      |                          |                  |" << endl;
    cout << "|      ANGULO          |         VELOCIDAD        |     TIEMPO       |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cont = 0;
    pass = 0;
    i = 0;
    momento = 0.001;

    for (; momento < time-2; momento += 0.001){

        val = false;

        llegada = (((g*pow(momento,2)/2)+punto[cont])/momento);

        analizador = distancia - (vx * (momento + 2));

        if (analizador > distancia * 0.05){
            vel_x = analizador / momento;

            lejania = distancia / vel_x;

            for (; i < num; i += 1){

                cercania = tan(cad[i])*vel_x;

                if (cercania > llegada - ataque && cercania < llegada + ataque){

                    lejania = ((cercania * lejania) + (-g*pow(lejania,2))/2);

                    lejania = -altura - lejania;

                    if (lejania > -0.025 && lejania < 0.025){
                        val = true;
                    }
                    else{

                        grados = cad[i] * 180 / PI;
                        velocidad = sqrt(pow(vel_x,2)+pow(cad[i]*vel_x,2));
                        cout << setprecision(8)<< "| " << grados << " grados    |     ";
                        cout << setprecision(10) << velocidad << " m/s      | ";
                        cout << setprecision(5) << momento << " segundos   |";
                        cout << "\n|___________________________________________________________________|" << endl;
                        val = true;
                        posibilidad = true;
                    }
                }
                if (val == true) {
                    i += 1;
                    pass = i;
                    break;
                }
            }

        }
        if (val == false) i = pass;
        cont ++;
    }
    if (posibilidad == false ){
        cout << "\n\n--ARMA DESTRUIDA NO EXISTIO TIEMPO DE REACCION--\n\n" << endl ;
    }
}

void bala::disparo_simple (){

    posibilidad =false;
    ataque = distancia * 0.025;
    angulo = atan(-altura/distancia);
    cad.push_back(angulo);
    while(angulo < PI/2){
        angulo += radian;
        cad.push_back(angulo);
    }
    num = cad.size();
    for (double i = 2.001; i < time; i += 0.001){
        punto.push_back(((vy*i)+((-g*pow(i,2))/2))-altura);
    }
    cout << "\nLANZAMIENTO EXITOSO CON:\n" << endl;
    cout << "______________________________________________________________________" << endl;
    cout << "|                      |                          |                  |" << endl;
    cout << "|      ANGULO          |         VELOCIDAD        |     TIEMPO       |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cont = 0;
    pass = 0;
    i = 0;
    momento = 0.001;

    for (; momento < time-2; momento += 0.001){

        val = false;

        llegada = (((g*pow(momento,2)/2)+punto[cont])/momento);

        analizador = distancia - (vx * (momento + 2));

        if (analizador > distancia * 0.05){
            vel_x = analizador / momento;
            for (; i < num; i += 1){
                if (tan(cad[i])*vel_x > llegada - ataque && tan(cad[i])*vel_x < llegada + ataque){
                    grados = cad[i] * 180 / PI;
                    velocidad = sqrt(pow(vel_x,2)+pow(cad[i]*vel_x,2));
                    cout << setprecision(8)<< "| " << grados << " grados    |     ";
                    cout << setprecision(10) << velocidad << " m/s      | ";
                    cout << setprecision(5) << momento << " segundos   |";
                    cout << "\n|___________________________________________________________________|" << endl;
                    val = true;
                    posibilidad = true;
                }
                if (val == true) {
                    i += 1;
                    pass = i;
                    break;
                }
            }

        }
        if (val == false) i = pass;
        cont ++;
    }

    if (posibilidad == false ){
        cout << "\n\n--ARMA DESTRUIDA NO EXISTIO TIEMPO DE REACCION--\n\n" << endl ;
    }

}
