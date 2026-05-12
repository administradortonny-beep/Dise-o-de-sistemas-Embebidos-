#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// --- CONFIGURACIÓN DE RED ---
const char* ssid = "UAM-ROBOTICA"; 
const char* password = "m4nt32024uat";

// --- CONFIGURACIÓN THINGSPEAK ---
unsigned long myChannelNumber = 3286429; // Reemplaza con tu ID de canal
const char * myWriteAPIKey = "MO6T3BQA3C5FMI9C"; // Reemplaza con tu API Key

// --- CONFIGURACIÓN DHT ---
#define DHTPIN 19          // Pin digital donde conectaste el sensor
#define DHTTYPE DHT11    // Cambia a DHT22 si es el que usas
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  
  Serial.print("Conectando a WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n¡Conectado!");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer el sensor DHT!");
  } else {
    Serial.print("Temp: "); Serial.print(t);
    Serial.print("°C | Hum: "); Serial.print(h); Serial.println("%");

    // Enviar datos a ThingSpeak
    ThingSpeak.setField(1, t);
    ThingSpeak.setField(2, h);
    
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if(x == 200) Serial.println("ThingSpeak actualizado correctamente.");
    else Serial.println("Error en ThingSpeak: " + String(x));
  }

  delay(20000); // Esperar 20 segundos para la siguiente lectura
}