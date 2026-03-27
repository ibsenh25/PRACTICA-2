#include <iostream>
#include "PROBLEMA_9.h"
using namespace std;

int obtener_longitud(const char *cadena) {
    int len = 0;
    while (*cadena != '\0') {
        len++;
        cadena++;
    }
    return len;
}

int sumar_cadena(int n, const char *cadena) {
    int len = obtener_longitud(cadena);
    int suma_total = 0;
    int valor_actual = 0;
    int multiplicador = 1;
    int cifras_contadas = 0;

    const char *ptr = cadena + (len - 1);

    while (ptr >= cadena) {
       
        int digito = *ptr - '0';
       
        valor_actual = valor_actual + (digito * multiplicador);
        multiplicador *= 10;
        cifras_contadas++;

        if (cifras_contadas == n) {
            suma_total += valor_actual;
           
            valor_actual = 0;
            multiplicador = 1;
            cifras_contadas = 0;
        }
       
        ptr--;
    }

 
    if (cifras_contadas > 0) {
        suma_total += valor_actual;
    }

    return suma_total;
}

int imple_9() {
    int n;
    char cadena[100];// Arreglo estático clásico
   
    cout << "Ingrese la cadena: ";
    cin >> cadena;
   
    cout << "Ingrese un numero para dividir la cadena: ";
    cin >> n;
   
    cout << "Original: " << cadena << "." << endl;
    cout << "Suma: " << sumar_cadena(n, cadena) << "." << endl;

    return 0;
}    cout << "Numeros: " << numeros << endl;

    return 0;
}
