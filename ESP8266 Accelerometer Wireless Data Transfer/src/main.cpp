#include <Arduino.h>
#include <MPU6050.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <ESP8266WiFi.h> //ESP8266 Wifi Library

#define WIFI_SSID "SpectrumSetup-71"
#define WIFI_PSWD "budgetagency975"


void setup();
void DataTransfer();

const int MPU = 0x68;
int16_t AccX, AccY, AccZ;

void setup(){
    Serial.begin(115200); //initializing serial port
    Wire.begin(); //initializing wire
    Serial.println(" ");
    WiFi.begin(WIFI_SSID, WIFI_PSWD); //initializing Wifi w/ Password and SSID

    while (WiFi.status() != WL_CONNECTED){
        delay(500); //Delay for 500
        Serial.println("Connecting to Wifi...");
    }

    Serial.println("Connected!");
    Serial.println(WiFi.localIP());
}

void DataTransfer(int16_t AccX, int16_t AccY, int16_t AccZ){

}