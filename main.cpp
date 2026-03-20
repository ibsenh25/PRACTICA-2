#include <iostream>
#include "PROBLEMA_1.h"
#include "PROBLEMA_3.h"
#include "PROBLEMA_5.h"
#include "PROBLEMA_7.h"
#include "PROBLEMA_9.h"

using namespace std;

int main() {
    int n;

    cout << "Elija el numero del problema: " << endl;
    cin >> n;

    switch (n) {
    case 1:
        problema_1();
        break;
    case 3:
        imple_3();
        break;
    case 5:
        imple_5();
        break;
    case 7:
        imple_7();
        break;
    case 9:
        imple_9();
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }

    return 0;
}
