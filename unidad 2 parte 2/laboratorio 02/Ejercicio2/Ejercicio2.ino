const int LED_PIN = 8;
const int BOTON_PULSACION = 2;   
const int BOTON_REINICIO = 3;    

int contador = 0;
int ultimoEstadoBoton1 = HIGH;
int ultimoEstadoBoton2 = HIGH;
unsigned long tiempoDebounce = 50;  

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BOTON_PULSACION, INPUT_PULLUP);
  pinMode(BOTON_REINICIO, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("=================================");
  Serial.println("Ejercicio 2 - CON DOS BOTONES");
  Serial.println("Botón 1 (pin 2): +1 contador y parpadea");
  Serial.println("Botón 2 (pin 3): REINICIAR contador");
  Serial.println("=================================");
}

void loop() {

  int estadoBoton1 = digitalRead(BOTON_PULSACION);
  int estadoBoton2 = digitalRead(BOTON_REINICIO);
  
  if (estadoBoton1 == LOW && ultimoEstadoBoton1 == HIGH) {
    delay(tiempoDebounce);
    if (digitalRead(BOTON_PULSACION) == LOW) {
      contador++;
      Serial.print("Pulsación #");
      Serial.print(contador);
      Serial.print(" - Parpadeando ");
      Serial.print(contador);
      Serial.println(" veces");
      
      for (int i = 0; i < contador; i++) {
        digitalWrite(LED_PIN, HIGH);
        delay(300);
        digitalWrite(LED_PIN, LOW);
        delay(300);
      }
      
      Serial.println("--- Parpadeo completado ---");
    }
  }
  
  if (estadoBoton2 == LOW && ultimoEstadoBoton2 == HIGH) {
    delay(tiempoDebounce);
    if (digitalRead(BOTON_REINICIO) == LOW) {
      contador = 0;
      Serial.println("!!! CONTADOR REINICIADO A CERO !!!");
      digitalWrite(LED_PIN, LOW); 
    }
  }
  
  ultimoEstadoBoton1 = estadoBoton1;
  ultimoEstadoBoton2 = estadoBoton2;
}
