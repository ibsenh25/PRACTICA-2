#include <iostream>
#include "PROBLEMA_9.h"
using namespace std;


void separar_numeros(char *origen, char *texto, char *numeros) {
    char *ptr_origen = origen;
    char *ptr_texto = texto;
    char *ptr_numeros = numeros;

    while (*ptr_origen != '\0') {
        if (*ptr_origen >= '0' && *ptr_origen <= '9') {
            *ptr_numeros = *ptr_origen;
            ptr_numeros++;
        } else {
            *ptr_texto = *ptr_origen;
            ptr_texto++;
        }
        ptr_origen++;
    }

    *ptr_texto = '\0';
    *ptr_numeros = '\0';
}


int imple_9() {
    char cadena[100];
    char texto[100];
    char numeros[100];

    cout << "Ingrese una cadena: ";
    cin >> cadena;

    separar_numeros(cadena, texto, numeros);

    cout << "Original: " << cadena << endl;
    cout << "Texto: " << texto << endl;
    cout << "Numeros: " << numeros << endl;

    return 0;
}
