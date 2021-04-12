#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
int A=255;
int B=130;
 String readvoice;
void setup() {
 BT.begin(9600);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop() {
  while (BT.available()){  
  delay(10); 
  char c = BT.read(); 
  readvoice += c; 
  }  
  if (readvoice.length() > 0) {
    Serial.println(readvoice); 
   
    
   if(readvoice == "go") {
    analogWrite(6, A);
    analogWrite(4, A);
    analogWrite(3, 0);
    analogWrite(5,0);
    delay(100);
  } 
  else if(readvoice == "go back")  {
    analogWrite(6, 0);
    analogWrite(4, 0);
    analogWrite(3, A);
    analogWrite(5,A);
    delay(100);
  }
   else if (readvoice == "go right"){
    analogWrite (6,0);
    analogWrite (4,A);
    analogWrite (3,0);
    analogWrite (5,0);
    delay (1500);
    analogWrite(6, A);
    analogWrite (4, A);
    analogWrite(3,0);
    analogWrite(5,0);
  }

else if ( readvoice == "go left"){
   analogWrite (6, A);
   analogWrite (4, 0);
   analogWrite (3, 0);
   analogWrite (5, 0);
   delay (1500);
   analogWrite(6, A);
    analogWrite (4, A);
    analogWrite(3,0);
    analogWrite(5,0);
 }

else if (readvoice == "stop") {
   analogWrite (6, 0);
   analogWrite (4, 0);
   analogWrite (3, 0);
   analogWrite (5, 0);
   delay (100);
 }

 
readvoice="";
   }
}
