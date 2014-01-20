/*
 Read values from the T000090 LDR Analog Sensor connected to I1, 
 then uses the result to set the brightness on a T010111 LED 
 Module connected on O1. 
 Read temperature from the T00020 Thermistor Module connected to I0.
 Prints the values on the serial monitor.
 Save the values in a log file using Intel Galileo Linux system calls
 
 created 20 Jan. 2014
 by Mauro Mezzenzana 

 Created using code from Tinkerkit library example LightSensor
 created 29 Dec. 2008
 Modified 4 Sep 2010
 by Tom Igoe
 modified 7 dec 2010
 by Davide Gomba
 modified on Ded 2011
 by Federico Vanzati
 modified Jun 2013
 by Matteo Loglio<http://matlo.me>

 This example code is in the public domain.
 */

#include <TinkerKit.h>

TKLightSensor ldr(I1);	//create the "ldr" object on port I1
TKThermistor therm(I0); //create the "therm" object on port I0

TKLed led(O1);		//create the "led" object on port O1

float C;

int bright;

void setup() {
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
}

void loop() {
  
  // store the therm values into a variable called C
  C = therm.readCelsius();
  
  // store the ldr values into a variable called brightnessVal
  int brightnessVal = ldr.read();            

  // set the led brightness, led is ON while it is dark
  bright = 500 - brightnessVal;
  if (bright < 0) bright = 0;
  led.brightness(bright);       

  // print the results to the serial monitor:
  Serial.print("brightness = " );                      
  Serial.print(bright); 
  Serial.print(" | ");
  Serial.print("temp = " );                      
  Serial.println(C); 

  //compose status string for logging (variables will be converted to String)
  String stringOne = "echo 'LED brightness = ";
  stringOne += bright;
  stringOne +="' >> mylog.txt";
   
  //convert the status string to const char* to be used as system command  
  char charBuf[stringOne.length()+1];
  stringOne.toCharArray(charBuf, 500);
  
  //execute the system command
  system(charBuf);

  // wait 10 milliseconds before the next loop
  delay(100);                    
}

