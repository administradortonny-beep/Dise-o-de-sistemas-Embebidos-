// Lab06_Stepper_Motor.ino

const int STEP_PIN = 9;    
const int DIR_PIN = 8;    
const int ENABLE_PIN = 10; 

int delayMicrosegundos = 1000; 

void setup() {
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(ENABLE_PIN, OUTPUT);
    
    digitalWrite(ENABLE_PIN, LOW);  
    digitalWrite(DIR_PIN, HIGH);    
    
    Serial.begin(9600);
    Serial.println("Lab 06 - Control Motor a Pasos");
}

void loop() {
    Serial.println("Adelante: 200 pasos");
    digitalWrite(DIR_PIN, HIGH);
    for (int i = 0; i < 200; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(delayMicrosegundos);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(delayMicrosegundos);
    }
    
    delay(1000);
    
    Serial.println("Atras: 200 pasos");
    digitalWrite(DIR_PIN, LOW);
    for (int i = 0; i < 200; i++) {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(delayMicrosegundos);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(delayMicrosegundos);
    }
    
    delay(1000);
}