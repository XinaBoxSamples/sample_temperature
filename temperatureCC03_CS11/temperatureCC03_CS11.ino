#include <xCore.h>
#include <xSW01.h>
#include <xOD01.h>

#if defined(ESP8266)
#define RED   RED
#define GREEN GREEN
#define BLUE  BLUE
#include <ESP8266WiFi.h>
#define Serial Serial

#elif defined(ARDUINO_SAMD_ZERO)
#define RED   CC03_RED
#define GREEN CC03_GREEN
#define BLUE  CC03_BLUE
#define Serial SerialUSB

#elif defined(ARDUINO_AVR_PRO)
#define RED   CC01_RED
#define GREEN CC01_GREEN
#define BLUE  CC01_BLUE
#define Serial Serial

#elif defined(ESP32)
#define RED   CW02_RED
#define GREEN CW02_GREEN
#define BLUE  CW02_BLUE
#define Serial Serial
#endif


// Create a variable for the storage of data received from SW01  
  float Celsius_Temp;
  float Farenheit_Temp;

  
const int DELAY_TIME = 1000;

xSW01 SW01;

void setup() {

  #if defined(ESP8266)
  WiFi.forceSleepBegin();
  Wire.begin(2, 14);
  Wire.setClockStretchLimit(15000);

#elif defined(ARDUINO_SAMD_ZERO)
  Wire.begin();

#elif defined(ARDUINO_AVR_PRO)
  Wire.begin();

#elif defined(ESP32)
  Wire.begin();

#endif
  // Start the Serial Monitor
  Serial.begin(115200);
  
  // Start the SW01
  SW01.begin();

  OLED.begin();

  //Intialising variables
  Celsius_Temp = Farenheit_Temp = 0;
  
  OD01.println("Temperature Project        ");
  OD01.println("================================");
  
  //Delay for sensor to normalise
  delay(3000);
}

void loop() {
  
  // Read and calculate data from SW01 sensor
  SW01.poll();
  
  // Request the temperature measurement from SW01 and store in
  // the temperature variable   
  Celsius_Temp = SW01.getTempC(); // Temperature in Celcuis
   Farenheit_Temp = SW01.getTempF(); // Temperature in Farenheit
  
  // Show data over the Serial Monitor   
  OD01.print("Celsius_Temp: ");
  OD01.print(Celsius_Temp);
  OD01.println(" C");
  OD01.print("Farenheit_Temp: ");
  OD01.print(Farenheit_Temp);
  OD01.println(" F"); 

  // Small delay between sensor reads
  delay(DELAY_TIME);
}

