#include "general.h"
#include "arma.h"

//Definicion de variables globales de USO
bool ava = true;
int conti = 0;
double d = 0 , h = 0;
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
            break;
        }


        case 3:{
            cout << "\n\n\tTRES" << endl;
            break;
        }


        case 4:{
            cout << "\n\n\tCUATRO" << endl;
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
