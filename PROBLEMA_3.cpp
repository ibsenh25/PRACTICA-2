#include <iostream>
#include "PROBLEMA_3.h"
using namespace std;

bool problema_3(char arr1[], char arr2[]) {
    char *ptr1 = arr1;
    char *ptr2 = arr2;


    while (*ptr1 != '\0' && *ptr2 != '\0') {
        if (*ptr1 != *ptr2) {
            return false;
        }
        ptr1++;
        ptr2++;
    }


    return (*ptr1 == '\0' && *ptr2 == '\0');
}




int imple_3() {
    char cadena1[100], cadena2[100];

    cout << "Ingrese la primera cadena: ";
    cin >> cadena1;
    cout << "Ingrese la segunda cadena: ";
    cin >> cadena2;

    if (problema_3(cadena1, cadena2)) {
        cout << "Las cadenas son iguales." << endl;
    } else {
        cout << "Las cadenas son diferentes." << endl;
    }

    return 0;
}

