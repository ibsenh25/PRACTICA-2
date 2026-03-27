#include <iostream>
#include "PROBLEMA_1.h"
#include "PROBLEMA_3.h"
#include "PROBLEMA_5.h"
#include "PROBLEMA_7.h"
#include "PROBLEMA_9.h"
#include "PROBLEMA_11.h"
#include "PROBLEMA_13.h"
#include "PROBLEMA_15.h"
#include "PROBLEMA_17.h"



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
    case 11:
        imple_11();
        break;
    case 13:
        imple_13();
        break;
    case 15:
        imple_15();
        break;
    case 17:
        imple_17();
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }

    return 0;
}
