#include <SoftwareSerial.h>
#define gas_Pin 7
SoftwareSerial SIM900(2,3);
int gas_value;

void setup()
{
  Serial.begin(9600);
  SIM900.begin(19200);
   
  delay(20000);  // give time to log on to network.
}





  


void loop()
{

     
    gas_value = digitalRead(gas_Pin); 
     int sensorValue = analogRead(A0);
      
     if( sensorValue==850)
    {
      SIM900.print("AT+CMGF=1\r");// AT command to send SMS message
      Serial.print("AT+CMGF=1\r" );
      delay(100);
      SIM900.println("AT + CMGS = \"+919609022562\"");// recipient's mobile number, in international format
      Serial.print("AT + CMGS = \"+919609022562\"" );
  
      delay(100);
      SIM900.println("food is going to empty.");        // message to send
      Serial.print("food is going to empty." );
      delay(100);
      SIM900.println((char)26);// End AT command with a ^Z, ASCII code 26
      Serial.print((char)26);
      delay(100);
      SIM900.println();
      delay(5000);                                     // give module time to send SMS
     
      //do {} while (1);
      
    }
   
    if(gas_value==1)
  {
      SIM900.print("AT+CMGF=1\r");// AT command to send SMS message
      Serial.print("AT+CMGF=1\r" );
      delay(100);
      SIM900.println("AT + CMGS = \"+919609022562\"");// recipient's mobile number, in international format
      Serial.print("AT + CMGS = \"+919609022562\"" );
  
      delay(100);
      SIM900.println("food is going to be spoiled.");        // message to send
      Serial.print("food is going to be spoiled." );
      delay(100);
      SIM900.println((char)26);// End AT command with a ^Z, ASCII code 26
      Serial.print((char)26);
      delay(100);
      SIM900.println();
      delay(5000);                                     // give module time to send SMS
     
      //do {} while (1);
  }
    
   
}
