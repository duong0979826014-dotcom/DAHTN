#include <Arduino.h>
#include "GPS.h"

// GPS dùng UART2
GPS gps(Serial2);

unsigned long t_print = 0;

void setup() {
    Serial.begin(9600);          // PC
    delay(1000);

    Serial.println("=== GPS LOCATION TEST ===");

    gps.begin(115200);           // GPS baud
}

void loop() {
    GPS::Data data = gps.read();

    if (data.valid) {
        Serial.print("GPS OK: ");
        Serial.print(data.lat_deg);
        Serial.print("°");
        Serial.print(data.lat_min);
        Serial.print("'");
        Serial.print(data.lat_sec, 1);
        Serial.print("\"");
        Serial.print(data.lat_dir);
        Serial.print("  ");

        Serial.print(data.lon_deg);
        Serial.print("°");
        Serial.print(data.lon_min);
        Serial.print("'");
        Serial.print(data.lon_sec, 1);
        Serial.print("\"");
        Serial.println(data.lon_dir);

        delay(1000);
    }
    else {
        if (millis() - t_print > 2000) {
            Serial.println("Dang TIM kiem GPS...");
            t_print = millis();
        }
    }
}
