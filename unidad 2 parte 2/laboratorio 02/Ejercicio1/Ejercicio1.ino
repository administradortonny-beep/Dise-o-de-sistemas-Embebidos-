const int LED_PIN = 8;     
const int BOTON1_PIN = 2;   
const int BOTON2_PIN = 3;   

int contador = 0;

int estadoBoton1 = HIGH;
int ultimoEstadoBoton1 = HIGH;
unsigned long ultimoTiempoRebote1 = 0;
const unsigned long tiempoRebote = 50;

int estadoBoton2 = HIGH;
int ultimoEstadoBoton2 = HIGH;
unsigned long ultimoTiempoRebote2 = 0;

void setup() {

  Serial.begin(9600);
  
  pinMode(LED_PIN, OUTPUT);
  
  pinMode(BOTON1_PIN, INPUT_PULLUP);
  pinMode(BOTON2_PIN, INPUT_PULLUP);
  
  digitalWrite(LED_PIN, LOW);
  
  Serial.println("Sistema iniciado. Contador: 0");
}

void loop() {

  int lecturaBoton1 = digitalRead(BOTON1_PIN);
  int lecturaBoton2 = digitalRead(BOTON2_PIN);
  
  if (lecturaBoton1 != ultimoEstadoBoton1) {
    ultimoTiempoRebote1 = millis();
  }
  
  if ((millis() - ultimoTiempoRebote1) > tiempoRebote) {
    if (lecturaBoton1 != estadoBoton1) {
      estadoBoton1 = lecturaBoton1;
      
      if (estadoBoton1 == LOW) {
        contador++;
        if (contador > 2) {
          contador = 0; 
        }
        
        Serial.print("Botón 1 presionado. Contador: ");
        Serial.println(contador);
        
        if (contador == 1) {
          digitalWrite(LED_PIN, HIGH); 
        } else if (contador == 2) {
          digitalWrite(LED_PIN, HIGH);
        } else {
          digitalWrite(LED_PIN, LOW);  
        }
      }
    }
  }
  ultimoEstadoBoton1 = lecturaBoton1;
  
  if (lecturaBoton2 != ultimoEstadoBoton2) {
    ultimoTiempoRebote2 = millis();
  }
  
  if ((millis() - ultimoTiempoRebote2) > tiempoRebote) {
    if (lecturaBoton2 != estadoBoton2) {
      estadoBoton2 = lecturaBoton2;
      
      if (estadoBoton2 == LOW) {
        contador = 0;
        digitalWrite(LED_PIN, LOW); 
        
        Serial.println("Botón 2 presionado. Contador reiniciado a 0");
      }
    }
  }
  ultimoEstadoBoton2 = lecturaBoton2;
}
