#include <xCore.h>
#include <xSW01.h>
#include <xOD01.h>


// Create a variable for the storage of data received from SW01  
  float Celsius_Temp;
  float Farenheit_Temp;

  
const int DELAY_TIME = 1000;

xSW01 SW01;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

  // START I2C COMMUNICATION
  Wire.begin(2, 14);
  
  // Start the SW01
  SW01.begin();

  OLED.begin();

  //Intialising variables
  Celsius_Temp = Farenheit_Temp = 0;
  
  OD01.println("Temperature Project");
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

