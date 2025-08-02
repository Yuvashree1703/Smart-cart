
#include <HTTPClient.h>
#include <WiFi.h>
#include <ArduinoJson.h> 
#include <LiquidCrystal.h>
const int rs = 5, en = 18, d4 = 19, d5 = 21, d6 = 22, d7 = 23; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include "SoftwareSerial.h" 
#include "DFRobotDFPlayerMini.h"
int A, z, IR1, t;
String a;


DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

int Z1, Z2, Z3, Z4;


String sensor1_status;
String sensor2_status; 
String sensor3_status; 
String sensor4_status;

void setup() { 
    Serial.begin(9600); 
    lcd.begin(16, 2);

    Serial2.begin(9600);

    WiFi.begin("iotbegin047", "iotbegin047"); 
    while (WiFi.status() != WL_CONNECTED) {
 
    lcd.setCursor(0, 0); 

    lcd.print("Connecting to "); 
    lcd.setCursor(0, 1); l
    cd.print(" iotbegin047");
    Serial.println(F("CONNECTING TO WIFI"));
}
// Display a message on LCD 
lcd.setCursor(0, 0);
lcd.print("IOT BASED	"); 
lcd.setCursor(0, 1);
lcd.print(" SMART TROLLEY "); 
delay(4000);

Serial.println(F("DFRobot DFPlayer Mini Demo")); 
Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
if (!myDFPlayer.begin(Serial2)) { //Use softwareSerial to communicate with mp3. 
   Serial.println(F("Unable to begin:"));
   Serial.println(F("1.Please recheck the connection!")); 
   Serial.println(F("2.Please insert the SD card!"));
}
Serial.println(F("DFPlayer Mini online.")); 
myDFPlayer.volume(30); //Set volume value. From 0 to 30 lcd.clear();
}

void loop() {



    if (Serial.available()) { 
        a = Serial.readString(); 
        delay(5); 
        Serial.println((a));
        if ((a == "53002620D98C") && (Z1 == 0)) {

            lcd.setCursor(0, 0); 
            lcd.print(" RICE RS 60	"); 
            lcd.setCursor(0, 1); 
            lcd.print("	");
            Z1 = 1;
            myDFPlayer.play(1); 
            delay(4000);
            a = "*******************";
        }
        if ((a == "530026685D40") && (Z2 == 0)) {

            lcd.setCursor(0, 0);
            lcd.print(" DETTOL RS 70 "); 
            lcd.setCursor(0, 1);
            lcd.print("	"); 
            Z2 = 1;
            myDFPlayer.play(2); 
            delay(4000);
            a = "*******************";
        }
        if ((a == "530026571230") && (Z3 == 0)) {


            lcd.setCursor(0, 0); 
            lcd.print(" MILK RS 25	"); 
            lcd.setCursor(0, 1); 
            lcd.print("	");
            Z3 = 1;
            myDFPlayer.play(3); 
            delay(4000);
            a = "*******************";
        }
        if ((a == "5300263B2769") && (Z4 == 0)) {

            lcd.setCursor(0, 0);
            lcd.print(" HIDE&SEEK RS 25 "); lcd.setCursor(0, 1);
            lcd.print("1 Kg	RS 40 "); Z4 = 1;
            myDFPlayer.play(4); delay(4000);
            a = "*******************";
        }
        if ((a == "53002620D98C") && (Z1 == 1)) {
            
            
            sensor1_status = " RICE "; sensor2_status = " RS 60 ";
            
            t = t + 60;
            sensor3_status = String(t); Z1 = 0;
            iot();
        }
        if ((a == "530026685D40") && (Z2 == 1)) {
            
            
            sensor1_status = " DETTOL "; sensor2_status = " RS 70 ";
            
            t = t + 70;
            sensor3_status = String(t); Z2 = 0;
            iot();
             
        }
        if ((a == "530026571230") && (Z3 == 1)) {
            
            sensor1_status = " MILK "; sensor2_status = " RS 25 "; t = t + 25;
            sensor3_status = String(t); Z3 = 0;
            iot();
        }
        if ((a == "5300263B2769") && (Z4 == 1)) {
            
            
            sensor1_status = " HIDE AND SEEK "; sensor2_status = " RS 25 ";
            
            t = t + 25;
            sensor3_status = String(t); Z4 = 0;
            iot();
        }
    }lcd.clear();
}
void iot() {
    DynamicJsonDocument jsonBuffer(JSON_OBJECT_SIZE(3) + 300); 
    JsonObject root = jsonBuffer.to<JsonObject>();
    root["sensor1"] = sensor1_status; 
    root["sensor2"] = sensor2_status; 
    root["sensor3"] = sensor3_status; 
    root["sensor4"] = sensor4_status;
    /* root["sensor5"] = sensor5_status; 
    root["sensor6"] = sensor6_status; 
    root["sensor7"] = sensor7_status;
    root["sensor8"] = sensor8_status; 
    root["sms"] = sms_status;*/ 
    String json; 
    serializeJson(jsonBuffer, json);
    HTTPClient http;	// Declare object of class HTTPClient 
    http.begin("http://iotbegineer.com/api/sensors"); // Specify request destination 
    http.addHeader("username", "iotbegin047");	
    Specify content-type header http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(json);	// Send the request
    String payload = http.getString(); // Get the response payload http.end();
    a = "*******************";
}

    
            


            

            
            
    