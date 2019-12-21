#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
const int Nosepoke = A0;
const int PumpPin = 6; 
const int LED = 7;
int out;
int DataArray[4];
int LastPump;
bool PumpOn;

void setup()                    
{
Serial.begin(9600);
pinMode(A0,INPUT); 
pinMode(6,OUTPUT);
pinMode(7, OUTPUT);
digitalWrite(PumpPin, HIGH);


LastPump = 0;
PumpOn = false;
}
void loop()
{  
int total1=  cs_2_3.capacitiveSensor(30); 
int total2 =  cs_2_4.capacitiveSensor(30);
int total3 =  cs_2_5.capacitiveSensor(30);
int total4 = analogRead(Nosepoke);
    
    String DataString = String(total1) + ',' + String(total2) + ',' + String(total3) + ',' + String(total4) + ',' ;
   Serial.println(DataString);                // print sensor output 1
    out = Serial.read();
    if (out == '1'){
    digitalWrite(LED, HIGH);
    }
    else if (out == '2') {
    digitalWrite(LED, LOW);
    }
    else if (out =='3') {
    digitalWrite(PumpPin,LOW);
    }
    else if (out =='4')  {
    digitalWrite(PumpPin,HIGH);
    }
    else if (out =='5'){
    digitalWrite(PumpPin,LOW);
    }
}
//    delay(10);                             // arbitrary delay to limit data to serial port 

