#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Duplicamos el mensaje para lograr desplazamiento continuo
String base = "    microcontroladores    ";  
String mensaje = base + base;  // Doble para transición suave

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  static int i = 0;  // Índice que guarda la posición de desplazamiento

  lcd.setCursor(0, 0);
  lcd.print(mensaje.substring(i, i + 16));  // Muestra los 16 caracteres actuales

  delay(200);  // Controla la velocidad del desplazamiento

  i++;  // Incrementa el índice

  // Cuando llega al final, vuelve al inicio sin cortes
  if (i >= mensaje.length() - 16) {
    i = 0;  // Reinicia el índice
  }
}
