#include <iostream>
using namespace std;

void fun_a(int *px, int *py) {
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

void fun_b(int a[], int tam) {
    int f, l;
    for (f = 0, l = tam - 1; f < l; f++, l--) {
        fun_a(&a[f], &a[l]);
    }
}


void eje1(){
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "Arreglo inicial: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Direccion de array: " << array << endl;
    cout << "Cada elemento ocupa: " << sizeof(array[0]) << " bytes" << endl;
    cout<<endl;
    cout << "Direccion de array[3]: " << &array[3] << endl;
    cout << "Contenido de array[3]: " << array[3] << endl;


    fun_b(array, 10);
    cout<<endl;

    cout << "Arreglo despues de fun_b: ";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;


    cout << "Nueva direccion de array[3]: " << &array[3] << endl;
    cout << "Nuevo contenido de array[3]: " << array[3] << endl;

}
