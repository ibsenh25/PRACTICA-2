
void setup() {
    Serial.begin(9600);
    Serial.println("Ingrese la cantidad de dinero en el monitor serial:");
}

void loop() {
    if (Serial.available() > 0) {

        long monto = Serial.parseInt();
        if (monto > 0) {
            Serial.print("Monto ingresado: ");
            Serial.println(monto);

            long resto = monto;
            long denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
            int cantidad[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int numDenominaciones = 10;
            long *ap;
            int i = 0;

            while(i < numDenominaciones) {
                ap = denominaciones;
                if(resto >= *(ap + i)) {
                    cantidad[i] = resto / (*(ap + i));
                    resto = resto % (*(ap + i));
                }
                i++;
            }

            for(int j = 0; j < numDenominaciones; j++) {
                Serial.print(*(ap + j));
                Serial.print(" : ");
                Serial.println(cantidad[j]);
            }

            if(resto > 0) {
                Serial.print("Faltante: ");
                Serial.println(resto);
            } else {
                Serial.println("Cantidad exacta");
            }

            Serial.println("\nIngrese otra cantidad para volver a calcular:");
        }
    }
}
