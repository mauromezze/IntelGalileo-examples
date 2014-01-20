/*
 Set static IP address using Intel Galileo Linux system calls

 created 20 Jan. 2014
 by Mauro Mezzenzana

 This example code is in the public domain.
 */


void setup() {
  //script to 
  system("ifconfig eth0 192.168.1.6 netmask 255.255.255.0");

}

void loop() {
  // put your main code here, to run repeatedly: 
 delay(10000); 
}
