/*
Water flow rate sensor 

Measure the water flow rate using this code. 
Connect Vcc and Gnd of sensor to ESP32, and the 
signal line to ESP32 digital pin 13.
 
 */
#include <myLib.h>
#define statusLed     21

#define sensorInterrupt  0  // INT0
#define sensorPin        13

// F = 7.5 * Q -- 1l <=> 1*7.5*60 = 450 pulse per second
#define calibrationFactor  7.5

myLib sensor(statusLed, sensorInterrupt, sensorPin, calibrationFactor);
long temp = -1;
void setup()
{
  
  // Initialize a serial connection for reporting values to the host
  Serial.begin(9600);
  sensor.init();
}

/**
 * Main program loop
 */
void loop()
{
   sensor.count();
   if( sensor.getTotalWaterFlow() != temp)
   {
     temp = sensor.getTotalWaterFlow();
    Serial.println(temp);
   }
}

