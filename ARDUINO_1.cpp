#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2); 
  
  Serial.println("Ingrese la cantidad en el monitor serial:");
  
  lcd.print("Ingrese cantidad");
  lcd.setCursor(0, 1); 
  lcd.print("en el Serial...");
}

void loop() {
  if (Serial.available() > 0) {
    long monto = Serial.parseInt(); 
    
    if (monto > 0) {
      Serial.print("\nMonto ingresado: ");
      Serial.println(monto);
      
      lcd.clear();
      lcd.print("Calculando...");

      long resto = monto;
      long denominaciones[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
      int cantidad[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int numDenominaciones = 10;
      long *ap = denominaciones;


      for(int i = 0; i < numDenominaciones; i++) {
          if(resto >= *(ap + i)) {
              cantidad[i] = resto / (*(ap + i));
              resto = resto % (*(ap + i));
          }
      }

      for(int j = 0; j < numDenominaciones; j++) {
          Serial.print(*(ap + j)); 
          Serial.print(" : ");
          Serial.println(cantidad[j]);
          
       
          if (cantidad[j] > 0) {
              lcd.clear();
              lcd.print("Valor: ");
              lcd.print(*(ap + j));
              lcd.setCursor(0, 1);
              lcd.print("Cantidad: ");
              lcd.print(cantidad[j]);
              delay(2000); 
          }
      }

      lcd.clear();
      if(resto > 0) {
          Serial.print("Faltante: ");
          Serial.println(resto);
          lcd.print("Faltante: ");
          lcd.print(resto);
      } else {
          Serial.println("Cantidad exacta");
          lcd.print("Cantidad exacta");
      }
      
      delay(4000); 
      
    
      lcd.clear();
      lcd.print("Ingrese cantidad");
      lcd.setCursor(0, 1);
      lcd.print("en el Serial...");
      Serial.println("\nIngrese otra cantidad para volver a calcular:");
    }
  }
}
