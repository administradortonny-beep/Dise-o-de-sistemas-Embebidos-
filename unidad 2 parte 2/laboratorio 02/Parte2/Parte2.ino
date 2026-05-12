const int LED_PIN = 8;     
const int BOTON_PIN = 2;    

int contador = 0;            
int ultimoEstadoBoton = HIGH; 

void setup() {

  pinMode(LED_PIN, OUTPUT);
  
  pinMode(BOTON_PIN, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.println("=== Laboratorio 02 - Iniciado ===");
  Serial.println("Configuración: Pull-up interno");
  Serial.println("Botón: PIN 2 | LED: PIN 8");
  Serial.println("=================================");
}

void loop() {

  int estadoActual = digitalRead(BOTON_PIN);
  
  if (estadoActual == LOW) {   
    digitalWrite(LED_PIN, HIGH);  
  } else {                        
    digitalWrite(LED_PIN, LOW);   
  }
  

  if (estadoActual != ultimoEstadoBoton) {
    if (estadoActual == LOW) {

      contador++;
      Serial.print("Botón PRESIONADO - #");
      Serial.print(contador);
      Serial.println(" - LED ENCENDIDO");
    } else {

      Serial.print("Botón LIBERADO - #");
      Serial.print(contador);
      Serial.println(" - LED APAGADO");
    }
    
    delay(50);
  }
  
  ultimoEstadoBoton = estadoActual;
}