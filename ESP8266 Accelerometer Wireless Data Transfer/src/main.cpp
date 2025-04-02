#include <Arduino.h>
#include <MPU6050.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#define WIFI_SSID "SpectrumSetup-71"
#define WIFI_PSWD "budgetagency975"
#define server_url "https://"

MPU6050 mpu; //Creating an instance of the MPU 6050 class


void setup();
void loop();

void setup(){
    Serial.begin(115200); //Setting the baud rate for serial transmission
    Wire.begin(); //Joins the I2C bus as a master
    mpu.initialize();

    mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_2); //Setting Accelerometer Range as +-2g (2 * Earth's Gravity)

    Serial.println("Initializing MPU6050...");
    if (mpu.testConnection()){ //If the MPU6050 connection is true
        Serial.println("Successfully Connected to MPU6050");
    }
    else{
        Serial.println("Connection to MPU6050 failed");
    }

    WiFi.begin(WIFI_SSID, WIFI_PSWD); //initializing wifi with Password and SSID
    while (WiFi.status() != WL_CONNECTED){
        delay (500);
        Serial.println("Connecting to Wifi..."); //Prints when trying to connect to wifi
    }

    Serial.println("Connected to Wifi!"); //Successfully connected to Wifi
    Serial.println(WiFi.localIP()); //Prints out the local IP address of the WiFi

}

void loop(){
    if (WiFi.status() == WL_CONNECTED){

        int16_t accx, accy, accz; //initializing variables that hold accelerometer data
        float accel_scale = 16384.0; //floating point value for accelerometer scale of +-2g (2 * Earth's Gravity)

        
        HTTPClient http; //Enabling http request to a server over Wifi
        WiFiClient client; //Declaring WifiClient objec5t 

        http.begin(client, server_url); //Connecting to the server url hosted on a Raspberry Pi
        http.addHeader("Content-Type", "application/json"); //Adds HTTP header to an http request, specifying JSON format

        mpu.getAcceleration(&accx, &accy, &accz); //reading the acceleration from all 3 axis (memory address of the variable using pointer is passed)

        JsonDocument doc; //creates a json document that is dynamic (you don't need to specify document size)
        //Raw Accelerometer Data
        doc["Raw"]["x"] = accx;
        doc["Raw"]["y"] = accy;
        doc["Raw"]["z"] = accz;
        //Normalized Accelerometer Data (divided by accelerometer scale)
        doc["Normalized"]["x"] = (accx / accel_scale);
        doc["Normalized"]["y"] = (accy / accel_scale);
        doc["Normalized"]["z"] = (accz / accel_scale);

        String payload; //Declaring an empty string type called payload
        serializeJson(doc, payload); //Serializing (encoding data in the JSON document into strings) JSON document into payload

        //Creating an HTTP Post Request (submitting data to be processed by the server)
        int responseCode = http.POST(payload); //sending data to the server and storing the HTTP response code as an integer value

        if(responseCode > 0){
            String response = http.getString(); //Stores the response body as a string 
            Serial.println(responseCode); //Printing out the response code and body
            Serial.println(response);
        }
        else{
            Serial.print("Error sending POST: "); //Prints out the error code for the POST request
            Serial.print(responseCode);
        }   

        http.end(); //This part is necessary for proper cleanup in subsequent requests
    }
    delay(100); //delaying the whole process (can make this value larger if there are a lot of values being shown at once)
}



