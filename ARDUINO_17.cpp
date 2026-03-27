void suma_divisores(int n, int *resultado){
    *resultado = 0;
    if (n <= 1){
        return;
    }

    *resultado = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            *resultado += i;

            if (i * i != n) {
                *resultado += (n / i);
            }
        }
    }
}

void setup() {
    Serial.begin(9600);
    Serial.println("Ingrese el numero limite en el monitor serial:");
}

void loop() {
    if (Serial.available() > 0) {
        int limite = Serial.parseInt();

        if (limite > 0) {
            Serial.print("Limite ingresado: ");
            Serial.println(limite);

            int suma_total = 0;
            int *ap_suma = &suma_total;

            for (int a = 2; a < limite; a++) {
                int b = 0;
                suma_divisores(a, &b);

                if (b != a) {
                    int suma_b = 0;
                    suma_divisores(b, &suma_b);

                    if (suma_b == a) {
                        *ap_suma += a;
                    }
                }
            }

            Serial.print("El resultado de la suma es: ");
            Serial.print(*ap_suma);
            Serial.println(".");
            Serial.println("\nIngrese otro limite para volver a calcular:");
        }
    }
}
