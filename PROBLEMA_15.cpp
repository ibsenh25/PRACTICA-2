#include <iostream>
#include "PROBLEMA_15.h"
using namespace std;

int obtener_max(int a, int b){
    return (a > b) ? a : b;
}

int obtener_min(int a, int b){
    return (a < b) ? a : b;
}

void interseccion_rectangulos(int *A, int *B, int *C){
    int izq_A = 0;
    izq_A = *A;
    int der_A = *A + *(A + 2);
    int arr_A = *(A + 1);
    int abj_A = *(A + 1) + *(A + 3);

    int izq_B = *B;
    int der_B = *B + *(B + 2);
    int arr_B = *(B + 1);
    int abj_B = *(B + 1) + *(B + 3);

    int inter_izq = obtener_max(izq_A, izq_B);
    int inter_der = obtener_min(der_A, der_B);
    int inter_arr = obtener_max(arr_A, arr_B);
    int inter_abj = obtener_min(abj_A, abj_B);

    int ancho_C = inter_der - inter_izq;
    int alto_C = inter_abj - inter_arr;

    if (ancho_C > 0 && alto_C > 0) {
        *C = inter_izq;
        *(C + 1) = inter_arr;
        *(C + 2) = ancho_C;
        *(C + 3) = alto_C;
    } else {
        *C = 0;
        *(C + 1) = 0;
        *(C + 2) = 0;
        *(C + 3) = 0;
    }
}

int imple_15(){
    int rectangulo_A[4];
    int rectangulo_B[4];
    int rectangulo_C[4];

    cout << "Datos del Rectangulo A" << endl;
    cout << "Ingrese la coordenada X (esquina superior izquierda): ";
    cin >> rectangulo_A[0];
    cout << "Ingrese la coordenada Y (esquina superior izquierda): ";
    cin >> rectangulo_A[1];
    cout << "Ingrese el ancho: ";
    cin >> rectangulo_A[2];
    cout << "Ingrese el alto: ";
    cin >> rectangulo_A[3];

    cout << endl;

    cout << "Datos del Rectangulo B" << endl;
    cout << "Ingrese la coordenada X (esquina superior izquierda): ";
    cin >> rectangulo_B[0];
    cout << "Ingrese la coordenada Y (esquina superior izquierda): ";
    cin >> rectangulo_B[1];
    cout << "Ingrese el ancho: ";
    cin >> rectangulo_B[2];
    cout << "Ingrese el alto: ";
    cin >> rectangulo_B[3];

    cout << endl;

    interseccion_rectangulos(rectangulo_A, rectangulo_B, rectangulo_C);

    cout << "Datos del rectangulo resultante:" << endl;

    if (rectangulo_C[2] > 0 && rectangulo_C[3] > 0) {
        cout << "Coordenada X: " << rectangulo_C[0] << endl;
        cout << "Coordenada Y: " << rectangulo_C[1] << endl;
        cout << "Ancho: " << rectangulo_C[2] << endl;
        cout << "Alto: " << rectangulo_C[3] << endl;
    } else {
        cout << "Los rectangulos no se intersectan." << endl;
    }

    return 0;
}
