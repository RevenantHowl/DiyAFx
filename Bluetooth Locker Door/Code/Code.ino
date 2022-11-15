#include <SoftwareSerial.h>
SoftwareSerial BT(3,2); // 
 
char data = 0;                //Variable for storing received data
void setup() 
{
BT.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
pinMode(5, OUTPUT);        //Sets digital pin 13 as output pin
pinMode(6, OUTPUT);
}
void loop()
{
if(BT.available() > 0)  // Send data only when you receive data:
{
data = BT.read();      //Read the incoming data and store it into variable data
switch(data){
  case '1':
  digitalWrite(5, HIGH);  //If value is 1 then LED turns ON
  delay(3000);      
  digitalWrite(5, LOW);
  break;
  case '2':
  digitalWrite(6, HIGH);  //If value is 1 then LED turns ON
  delay(3000);       
  digitalWrite(6, LOW);
  break;
  default:
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  break;
}
}                            
}
