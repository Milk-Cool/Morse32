#include <Arduino.h>
#include <WiFi.h>
#include <WebSocketsServer.h>
#include "config.h"

WebSocketsServer wss(8080);

void setup() {
    Serial.begin(UART_BAUD);
    pinMode(INPUT_PIN, INPUT_PULLUP);

    WiFi.softAP(WIFI_SSID, WIFI_PASS);
    wss.begin();
}

uint64_t last_pressed = 0;
int last_state = 0; // 0 = not transmitted, 1 = transmitted
int last_btn_state = LOW;
int cur_btn_state = LOW;
void loop() {
    wss.loop();
    if(digitalRead(INPUT_PIN) == LOW){
        wss.broadcastTXT("pressed");
    }
    delay(100);
}