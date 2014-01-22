/*
 This example uses Linux system calls to create a node.js script.

 created 21 Jan. 2014
 by Mauro Mezzenzana
 
 This example code is in the public domain.
*/


void setup() {
  //set static ip address
  system("ifconfig eth0 192.168.1.6 netmask 255.255.255.0");
  
  //clean up previous script
  system("rm myScript.js");
  //create new script
  system("echo 'var sys = require(\"sys\"),' > myScript.js");
  system("echo 'my_http = require(\"http\");' >> myScript.js");
  system("echo 'my_http.createServer(function(request,response){' >> myScript.js");
  system("echo sys.puts(\"Galileo server start\"); >> myScript.js");
  system("echo 'response.writeHeader(200, {\"Content-Type\": \"text/plain\"});' >> myScript.js");
  system("echo 'response.write(\"Hello Galileo\");' >> myScript.js");
  system("echo 'response.end();' >> myScript.js");
  system("echo '}).listen(8080);' >> myScript.js");
  system("echo sys.puts(\"Galileo Server Running on 8080\"); >> myScript.js");
  //system("chmod a+x myScript.js");
  system("node myScript.js &");    
}

void loop() {
  
  delay(100000);
  
}
