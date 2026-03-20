#include <iostream>
#include "PROBLEMA_7.h"
using namespace std;


void eliminar_repetidos(char *cadena) {
    if (*cadena == '\0'){
        return;  // cadena vacía
    }

    char *actual = cadena;
    char *resultado = cadena;

    while (*actual != '\0') {

        char *verificar = cadena;
        bool repetido = false;


        while (verificar < resultado) {
            if (*verificar == *actual) {
                repetido = true;
                break;
            }
            verificar++;
        }


        if (!repetido) {
            *resultado = *actual;
            resultado++;
        }

        actual++;
    }

    *resultado = '\0';
}


int imple_7() {
    char texto[100];

    cout << "Ingrese una cadena: ";
    cin >> texto;

    cout << "Original: " << texto << endl;
    eliminar_repetidos(texto);
    cout << "Sin repetidos: " << texto << endl;

    return 0;
}
