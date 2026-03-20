#include <iostream>
#include "PROBLEMA_5.h"
using namespace std;


void convertir_a_cadena(int numero, char *cadena) {
    if (numero == 0) {
        *cadena = '0';
        *(cadena + 1) = '\0';
        return;
    }

    bool es_negativo = false;
    if (numero < 0) {
        es_negativo = true;
        numero = -numero;
    }


    int temp = numero;
    int num_digitos = 0;
    while (temp > 0) {
        temp /= 10;
        num_digitos++;
    }

    char *ptr = cadena;
    if (es_negativo) {
        *ptr = '-';
        ptr++;
    }


    char *fin = ptr + num_digitos;
    *fin = '\0';
    fin--;

    int num = numero;
    while (num > 0) {
        int digito = num % 10;
        *fin = '0' + digito;
        num /= 10;
        fin--;
    }
}


int imple_5() {
    char resultado[100];
    int n;
    cout << "Ingrese el numero a convertir a una cadena de caracteres: ";
    cin >> n;

    convertir_a_cadena(n, resultado);
    cout <<n<<" ----> " << resultado << endl;


    return 0;
}
