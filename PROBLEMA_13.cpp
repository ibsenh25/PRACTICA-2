#include <iostream>
#include "PROBLEMA_13.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int contar_estrellas(int matriz[8][6]) {
    int estrellas = 0;

    for (int i = 1; i < 7; i++) {
        for (int j = 1; j < 5; j++) {
            int suma = *(*(matriz + i) + j)       +
                       *(*(matriz + i) + (j - 1)) +
                       *(*(matriz + i) + (j + 1)) +
                       *(*(matriz + (i - 1)) + j) +
                       *(*(matriz + (i + 1)) + j);

            if (suma > 30) {
                estrellas++;
            }
        }
    }

    return estrellas;
}


int imple_13() {
    int galaxia[8][6];

    srand(time(NULL));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            galaxia[i][j] = rand() % 16;

            // Imprimimos la matriz con formato para que se vea ordenada (opcional)
            if (galaxia[i][j] < 10) {
                cout << " "; // Espacio extra para números de un dígito
            }
            cout << galaxia[i][j] << " ";
        }
        cout << endl;
    }

    cout <<endl<<"Numero de estrellas encontradas en la imagen: " <<contar_estrellas(galaxia)<<"."<< endl;

    return 0;
}
