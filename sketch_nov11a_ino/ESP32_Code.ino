#include <WiFi.h>
#include <HTTPClient.h>

const int sensor = 36; 
const float alpha = 0.06;
float previous = 1940.0;

// ESP32 SoftAP credentials
const char* SSID = "ESPtars";
const char* password = "12tarsss";

// Set the Server URL to your laptop's IP in the ESP32 SoftAP network
// Usually, when your laptop connects to ESP32 SoftAP, ESP32 IP is 192.168.4.1
// Check your laptop IP in this network (ipconfig/ifconfig) and replace below
String ServerURL = "http://192.168.4.2:5000"; 

unsigned long previousMillis = 0;
const long interval = 1000; // 1 second interval

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);

  // Start SoftAP
  bool apStarted = WiFi.softAP(SSID, password);
  if (apStarted) {
    Serial.println("Soft access point created SUCCESSFULLY");
  } else {
    Serial.println("FAILED to create soft access point");
  }

  Serial.print("SoftAP SSID: ");
  Serial.println(WiFi.softAPSSID());
  Serial.print("SoftAP Password: ");
  Serial.println(password);
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  Serial.println();

  Serial.println("Connect your laptop to this WiFi and check its IP in this network");
}

void sendpulse(float input) {
  String tosend = "{\"Sensor-Data\":" + String(input, 2) + "}";
  
  HTTPClient http;
  http.begin(ServerURL + "/pulse");
  http.addHeader("Content-Type", "application/json");
  
  int result = http.POST(tosend);
  if (result > 0) {
    Serial.println("Data sent successfully: " + http.getString());
  } else {
    Serial.println("\t\tERROR DURING SENDING DATA TO API");
  }
  http.end();
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    int input = analogRead(sensor);
    float soundwave = (alpha * input) + ((1 - alpha) * previous);
    previous = soundwave;
    
    sendpulse(soundwave);
  }
}

