#include <iostream>
#include "PROBLEMA_1.h"
using namespace std;


void problema_1() {
    int monto, resto;

    int denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cantidad[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int numDenominaciones = 10;
    int *ap;
    int i = 0;

    cout << "Ingrese la cantidad de dinero: ";
    cin >> monto;

    resto = monto;

    while(i < numDenominaciones) {
        ap = denominaciones;
        if(resto >= *(ap + i)) {
            cantidad[i] = resto / (*(ap + i));
            resto = resto % (*(ap + i));
        }
        i++;
    }

    for(int i = 0; i < numDenominaciones; i++) {
        cout << denominaciones[i] << " : " << cantidad[i] << endl;
    }

    if(resto > 0) {
        cout << endl << "Faltante: " << resto << endl;
    } else {
        cout << endl << "Cantidad exacta" << endl;
    }
}
