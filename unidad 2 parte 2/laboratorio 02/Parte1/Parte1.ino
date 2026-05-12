const int PIN_BOTON = 2;   
const int PIN_LED = 8;     

void setup() {
    pinMode(PIN_BOTON, INPUT);      
    pinMode(PIN_LED, OUTPUT);       
    Serial.begin(9600);               
    Serial.println("Laboratorio 02 - Parte 1");
    Serial.println("Presiona el botón para encender el LED");
    Serial.println("================================");
}

void loop() {
    int estadoBoton = digitalRead(PIN_BOTON);
    
    if (estadoBoton == HIGH) {
        digitalWrite(PIN_LED, HIGH); 
        Serial.println("Botón: PRESIONADO - LED ON");
    } else {
        digitalWrite(PIN_LED, LOW);  
        Serial.println("Botón: LIBERADO - LED OFF");
    }
    
    delay(0); 
}
