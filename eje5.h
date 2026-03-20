#include <iostream>
using namespace std;

unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};


void eje3(){
    unsigned short *ap;

    ap = b[0];
    cout<<"Valor de b: "<<*ap+*(ap+1)<<endl;
    cout<<"Valor de b+2: "<<*(ap+4)<<endl;
    cout<<"Valor de *(b+2): "<<ap+4<<endl;
    cout<<"Valor de *(b+2)+1: "<<ap+5<<endl;
    cout<<"Valor de *(*(b+2)+1): "<<*(ap+5)<<endl;
    cout<<"Valor de b[3][1]: "<<*(ap+7)<<endl;
    cout<<"Valor de *b++: "<<*(ap++)<<endl;
}




