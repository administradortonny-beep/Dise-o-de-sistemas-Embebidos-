// Lab07_BMP180_OLED_Plotter.ino
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_W   128
#define OLED_H   64
#define OLED_ADDR  0x3C

Adafruit_BMP085 bmp;
Adafruit_SSD1306 display(OLED_W, OLED_H, &Wire, -1);

const float PRESION_MAR = 1013.25;

void setup() {
    Serial.begin(9600);

    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("ERROR: OLED no encontrada");
        while (true);
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(20, 28);
    display.println("Iniciando BMP180...");
    display.display();

    if (!bmp.begin()) {
        Serial.println("ERROR: BMP180 no encontrado");
        while (true);
    }

    Serial.println("Temperatura\tPresion"); 
}

void loop() {
    float temp = bmp.readTemperature();
    float presion = bmp.readPressure() / 100.0;

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(30, 0);
    display.println("--- BMP180 ---");
    display.setTextSize(2);
    display.setCursor(0, 14);
    display.print(temp, 1);
    display.println(" C");
    display.setTextSize(1);
    display.setCursor(0, 38);
    display.print("P: ");
    display.print(presion, 1);
    display.println(" hPa");
    display.display();

    Serial.print(temp, 1);
    Serial.print("\t");  
    Serial.println(presion, 1);

    delay(1000);
}