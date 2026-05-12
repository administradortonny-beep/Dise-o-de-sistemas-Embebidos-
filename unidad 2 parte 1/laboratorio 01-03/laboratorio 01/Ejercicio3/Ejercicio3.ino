const int PIN_LED = 8;
const int TIEMPO_CORTO = 200;   
const int TIEMPO_LARGO = 600;    
const int PAUSA_LETRA = 400;     
const int PAUSA_REPETICION = 2000; 
int numeroDestello = 0;           

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Iniciando patrón SOS con tiempo...");
  Serial.println("S = ... (3 cortos)");
  Serial.println("O = --- (3 largos)");
  Serial.println("S = ... (3 cortos)");
  Serial.println("Pausa de 2 segundos entre repeticiones");
  Serial.println("==========================================");
}

void loop() {

  Serial.println("Letra S: ...");
  for(int i = 0; i < 3; i++) {
    numeroDestello++;
    
    digitalWrite(PIN_LED, HIGH);
    Serial.print("[#");
    Serial.print(numeroDestello);
    Serial.print("] t=");
    Serial.print(millis());  
    Serial.println(" ms LED -> ENCENDIDO");
    delay(TIEMPO_CORTO);
    
    digitalWrite(PIN_LED, LOW);
    Serial.print("[#");
    Serial.print(numeroDestello);
    Serial.print("] t=");
    Serial.print(millis());  
    Serial.println(" ms LED -> APAGADO");
    delay(TIEMPO_CORTO);
  }
  
  delay(PAUSA_LETRA);
  
  Serial.println("Letra O: ---");
  for(int i = 0; i < 3; i++) {
    numeroDestello++;
    
    digitalWrite(PIN_LED, HIGH);
    Serial.print("[#");
    Serial.print(numeroDestello);
    Serial.print("] t=");
    Serial.print(millis()); 
    Serial.println(" ms LED -> ENCENDIDO");
    delay(TIEMPO_LARGO);
    
    digitalWrite(PIN_LED, LOW);
    Serial.print("[#");
    Serial.print(numeroDestello);
    Serial.print("] t=");
    Serial.print(millis());  
    Serial.println(" ms LED -> APAGADO");
    delay(TIEMPO_CORTO);
  }
  
  delay(PAUSA_LETRA);
  
  Serial.println("Letra S: ...");
  for(int i = 0; i < 3; i++) {
    numeroDestello++;
    
    digitalWrite(PIN_LED, HIGH);
    Serial.print("[#");
    Serial.print(numeroDestello);
    Serial.print("] t=");
    Serial.print(millis()); 
    Serial.println(" ms LED -> ENCENDIDO");
    delay(TIEMPO_CORTO);
    
    digitalWrite(PIN_LED, LOW);
    Serial.print("[#");
    Serial.print(numeroDestello);
    Serial.print("] t=");
    Serial.print(millis());  
    Serial.println(" ms LED -> APAGADO");
    delay(TIEMPO_CORTO);
  }
  
  Serial.println("--- SOS completo ---");
  Serial.print("Tiempo total transcurrido: ");
  Serial.print(millis());  
  Serial.println(" ms");
  Serial.println("Esperando 2 segundos para repetir...");
  delay(PAUSA_REPETICION);
}
