#include <iostream>
#include "PROBLEMA_17.h"
using namespace std;


void suma_divisores(int n, int *resultado){
    *resultado = 0;
    if (n <= 1){
        return;
    }

    *resultado = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            *resultado += i;

            if (i * i != n) {
                *resultado += (n / i);
            }
        }
    }
}


int imple_17(){
    int limite;
    int suma_total = 0;


    int *ap_suma = &suma_total;

    cout << "Ingrese el numero limite: ";
    cin >> limite;

    for (int a = 2; a < limite; a++) {
        int b = 0;

        suma_divisores(a, &b);

        if (b != a) {
            int suma_b = 0;

            suma_divisores(b, &suma_b);

            if (suma_b == a) {
                *ap_suma += a;
            }
        }
    }

    cout << "El resultado de la suma es: " << *ap_suma << "." << endl;

    return 0;
}
