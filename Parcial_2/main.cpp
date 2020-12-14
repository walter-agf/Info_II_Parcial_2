#include "general.h"
#include "arma.h"
#include "bala.h"

//Definicion de variables globales de USO
bool ava = true;
int conti = 0;
double d = 0 , h = 0, v = 0, a = 0;
//_______________________________________



int main()
{
    cout << "\n\n\t\tPARCIAL_II" << endl;
    cout << "\n\tSimulador de ofensiva y defesiva de dos canones" << endl;
    cout << "\t(las cuales por facilidad llameremos - Armas - ) en conflicto" << endl;
    cout << "\tque se encuentran separados por una distancia [ d ] y una altura [ h ]" << endl;
    cout << "\t(Medidas las cuales por convencion se tomaran en metros)" << endl;
    cout << "\tSe trabaja con dos informantes para conocer los datos de tiro" << endl;
    cout << "\tdel oponente respectivo:" << endl;
    cout << "\n\t - Del lado defensivo retraso de 2 segundos" << endl;
    cout << "\n\t - Del lado ofensivo retraso de 1 segundo" << endl;
    cout << "\n\tAdemas se conoce los rangos de ataque para\n\ttres tipos diferentes de balas" << endl;
    cout << "\n\t * Disparo Defensivo = 0.025d" << endl;
    cout << "\n\t * Disparo Ofensivo = 0.05d" << endl;
    cout << "\n\t * Neutralizar Disparo Defenisvo = 0.005d" << endl;


    do{
        cout << "\n\n\tQue accion desea realizar" << endl;
        cout << "\n\t1) Generar disparos ofensivos" << endl;
        cout << "\n\t2) Generar disparos defensivos" << endl;
        cout << "\n\t3) Tacticas de defensa" << endl;
        cout << "\n\t4) Simulacion del Neutralizador ofensivo" << endl;
        cout << "\n\t5) Salir" << endl;

        cout << "\n\n ---> "; cin >> conti;

        switch (conti) {

        case 1:{
            cout << "\n\n\tDefina la ubicacion del arma defensiva, respecto al arma ofensiva" << endl;
            cout << "\n\tCual es su distancia horizontal (metros) \n ---> ";cin >> d;
            cout << "\n\tCual es su altura vertical (metros) \n ---> ";cin >> h;
            arma ofensivo(d,h);
            ofensivo.disparo_ofensivo();
            break;
        }

        case 2:{
            cout << "\n\n\tDefina la ubicacion del arma ofensiva, respecto al arma defensiva" << endl;
            cout << "\n\tCual es su distancia horizontal (metros) \n ---> ";cin >> d;
            cout << "\n\tCual es su altura vertical (metros) \n ---> ";cin >> h;
            arma defensivo(d,h);
            defensivo.disparo_defensivo();
            break;
        }

        case 3:{
            bool afecta = false;
            int def = 0;

            cout << "\n\n\tDefina la ubicacion del origen de la bala disparada" << endl;
            cout << "\n\tCual es su distancia horizontal (metros) \n ---> ";cin >> d;
            cout << "\n\tCual es su altura vertical (metros) \n ---> ";cin >> h;
            cout << "\n\n\tDefina datos de disaro" << endl;
            cout << "\n\tCual es la velocidad del tiro\n ---> ";cin >> v;
            cout << "\n\tCual es el angulo de tiro\n ---> ";cin >> a;

            bala defensa(d,h);
            afecta = defensa.validez(v,a);

            if (afecta == true){

                cout << "\n\n\tATAQUE COMPLETAMENTE EFECTIVO" << endl;

                cout << "\n\n\tBajo que parametro quiere defenderse" << endl;
                cout << "\n\t1) Con posible ataque colateral" << endl;
                cout << "\n\t2) Sin ataque colateral" << endl;
                cout << "\n\n ---> "; cin >> def;
                if (def == 1){
                    defensa.disparo_simple();
                }
                else if (def == 2){
                    defensa.disparo_sin_colateral();
                }
                else{
                    cout << "\n\n\nVALOR FUERA DE LOS RANGOS DEL PUNTO 3 -REINGRESE-" << endl;
                }

            }
            else if (afecta == false){
                cout << "\n\n\tATAQUE NO EFECTIVO CONTRA EL ARMA DEFENSIVA" << endl;
            }
            break;
        }


        case 4:{
            bool afecta = false;

            cout << "\n\n\tDefina la ubicacion del origen de la bala ofensiva" << endl;
            cout << "\n\tCual es su distancia horizontal (metros) \n ---> ";cin >> d;
            cout << "\n\tCual es su altura vertical (metros) \n ---> ";cin >> h;
            cout << "\n\n\tDefina datos de disaro de la bala OFENSIVA" << endl;
            cout << "\n\tCual es la velocidad del tiro\n ---> ";cin >> v;
            cout << "\n\tCual es el angulo de tiro\n ---> ";cin >> a;

            bala ofensiva(d,h);
            afecta = ofensiva.validez(v,a);

            if (afecta == true){

                cout << "\n\n\nDISPARO EFECTIVO\n\n\n" << endl;

                cout << "\n\n\tDefina datos de disaro de la bala DEFENSIVA" << endl;
                cout << "\n\tCual es la velocidad del tiro\n ---> ";cin >> v;
                cout << "\n\tCual es el angulo de tiro\n ---> ";cin >> a;

                afecta = ofensiva.cointento(v,a);

                if (afecta == true){

                    cout << "\n\n\nDISPARO DEFENSIVO EFECTIVO\n\n\n" << endl;
                    ofensiva.neutralizar();
                }
                else{
                    cout << "\n\nDISPARO DEFENSIVO NO RESULTANTE\n\n" << endl;
                }

            }
            else{
                cout << "\n\nDISPARO OFENSIVO NO RESULTANTE\n\n" << endl;
            }
            break;
        }


        case 5:{
            ava = false;
            break;
        }
        default:{
            cout << "\n\n\tValor fuera de rango de ingreso -REINTENTE-" << endl;
            break;
        }
        }
    }while (ava == true);
    cout << "\n\n____________________  GRACIAS :D ----- ADIOS :v  _________________\n\n" << endl;
    system("pause");
    return 0;
}
