#include <iostream>
#include "PROBLEMA_11.h"
using namespace std;


void inicializar_asientos(char asientos[15][20]){
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 20; j++) {
            asientos[i][j] = '-';
        }
    }
}


void imprimir_asientos(char asientos[15][20]){
    int j = 0;

    for(j=0; j<=40;j++){
        cout<<"_";
    }

    cout<<endl;

    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 20; j++) {
            cout << "|" << asientos[i][j];
        }

        cout << "|" << endl;
    }

    for(j = 0; j<=40;j++){
        cout<<"-";
    }
    cout<<endl;

}



void reservar_asientos(char x, char asientos[15][20]){
    int i, j;
    char *pocision=NULL;

    if(x=='a'|| x=='A'){
        while (true){
            cout<<"Ingrese el numero de la fila a reservar: "<<endl;
            cin>>i;
            if(i>=1 && i<=15){
                break;
            }
            else{
                cout<<"Parametro invalido. Ingreselo nuevamente."<<endl;
            }
        }
        while (true){
            cout<<"Ingrese el asiento de la fila que desea reservar: "<<endl;
            cin>>j;
            if(j>=1 && j<=20){
                break;
            }
            else{
                cout<<"Parametro invalido. Ingreselo nuevamente."<<endl;
            }
        }

        pocision = &asientos[i-1][j-1];

        if(*(pocision)=='-'){
            *pocision = '+';
            cout<<"Su reservacion se ha hecho exitosamente. "<<endl;
        }
        else{
            cout<<"Reservacion denegada. Este asiento ya esta ocupado. "<<endl;
        }
    }

    else{
        while (true){
            cout<<"Ingrese el numero de la fila: "<<endl;
            cin>>i;
            if(i>=1 && i<=15){
                break;
            }
            else{
                cout<<"Parametro invalido. Ingreselo nuevamente."<<endl;
            }
        }
        while (true){
            cout<<"Ingrese el asiento correspondiente: "<<endl;
            cin>>j;
            if(j>=1 && j<=20){
                break;
            }
            else{
                cout<<"Parametro invalido. Ingreselo nuevamente."<<endl;
            }
        }

        pocision = &asientos[i-1][j-1];

        if(*(pocision)=='+'){
            *pocision = '-';
            cout<<"Su cancelacion de reserva se ha hecho exitosamente. "<<endl;
        }
        else{
            cout<<"Cancelacion denegada. Este asiento no se encuentra ocupado. "<<endl;
        }

    }

}


int imple_11(){
    char n;
    char sala_cine[15][20];
    inicializar_asientos(sala_cine);

    while(true){
        cout<<"Ingrese A para reservar y O para cancelar. Para finalizar pulse q."<<endl;
        cin>>n;


        if(n!='q'){
            reservar_asientos(n, sala_cine);
            imprimir_asientos(sala_cine);
        }
        else{
            break;
        }
    }


    return 0;
}
