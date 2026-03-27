#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void suma_divisores(int n, int *resultado){
    *resultado = 0;
    if (n <= 1) return;

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
  lcd.begin(16, 2);
  
  Serial.println("Ingrese el limite en el monitor serial:");
  
  lcd.print("Ingrese limite");
  lcd.setCursor(0, 1);
  lcd.print("en el serial...");
}

void loop() {
  if (Serial.available() > 0) {
    int limite = Serial.parseInt();
    
    if (limite > 0) {
      Serial.print("\nLimite ingresado: ");
      Serial.println(limite);
      
      lcd.clear();
      lcd.print("Calculando...");

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
      
      lcd.clear();
      lcd.print("Suma amigables:");
      lcd.setCursor(0, 1); 
      lcd.print(*ap_suma);
      
      delay(5000); 
      
      lcd.clear();
      lcd.print("Ingrese limite");
      lcd.setCursor(0, 1);
      lcd.print("en el serial:");
      Serial.println("\nIngrese otro limite para volver a calcular:");
    }
  }
}
