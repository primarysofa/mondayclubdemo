/**
 * DHT11 Sensor Reader
 * This sketch reads temperature and humidity data from the DHT11 sensor and prints the values to the serial port.
 * It also handles potential error states that might occur during reading.
 *
 * Author: Dhruba Saha
 * Version: 2.1.0
 * License: MIT
 */

// Include local secrets
#include "arduino_secrets.h"

// Include the DHT11 library for interfacing with the sensor.
#include <DHT11.h>

// Include WiFi and ThingSpeak libraries
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// Create an instance of the DHT11 class.
// - For Arduino: Connect the sensor to Digital I/O Pin 2.
// - For ESP32: Connect the sensor to pin GPIO2 or P2.
// - For ESP8266: Connect the sensor to GPIO2 or D4.
DHT11 dht11(2);
 
// Wifi config
const char* ssid = SECRET_SSID;
const char* password = SECRET_PASSWORD;

// ThingSpeak config
WiFiClient client;
unsigned long myChannelNumber = SECRET_CHANNEL_NUMBER;
const char * myWriteAPIKey = SECRET_API_WRITE_KEY;

void setup() {
    // Initialize serial communication to allow debugging and data readout.
    // Using a baud rate of 9600 bps.
    Serial.begin(9600);
    
    // Uncomment the line below to set a custom delay between sensor readings (in milliseconds).
    dht11.setDelay(20000); // Set this to the desired delay. Default is 500ms.

    // Setup wifi and thingspeak
    WiFi.mode(WIFI_STA);   
    ThingSpeak.begin(client);  // Initialize ThingSpeak

}

void loop() {
    int temperature = 0;
    int humidity = 0;

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
    int result = dht11.readTemperatureHumidity(temperature, humidity);

    // Check the results of the readings.
    // If the reading is successful, print the temperature and humidity values.
    // If there are errors, print the appropriate error messages.
    if (result == 0) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" °C\tHumidity: ");
        Serial.print(humidity);
        Serial.println(" %");
        postToThingspeak(temperature, humidity);
    } else {
        // Print error message based on the error code.
        Serial.println(DHT11::getErrorString(result));
    }
}

void postToThingspeak(int temperature, int humidity) {
  connect();
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
}

// Connect to WiFi
void connect() {
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect");
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, password); 
      delay(5000);     
    }
    Serial.println("\nConnected.");
  }
}