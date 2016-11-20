// WaterVerstuiver aka Squirtalyzer by Pidgey.be

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 60;    // variable to store the servo position 
long interval= 10000; //squirt every 10sec 

unsigned long lastSpuit=0;

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(7, INPUT_PULLUP); //use a switch that connects pin 7 to ground to activate the squirter
  pinMode(A0, INPUT);
  
  //beginpositie
  myservo.write(pos);
  
  //voor debug:
  //Serial.begin(9600);    
} 
 
 
void loop() 
{ 
                          
    if(digitalRead(7)==LOW)
      {
        myservo.write(180);
        delay(1000);  
        myservo.write(pos);
        delay(1000); //wait
      }
      else 
      {
        
        interval = map(analogRead(0),0,700,10000,1200000); //potentiometer is connected to 3.3V, so analogread goes max to 700 (ipv 1023). 
                                                          // 10000 = 10 seconds min interval
                                                          // 1200000 = 20min max interval
         //Serial.println(analogRead(0));
         //Serial.println(interval); 
                                                         
         if(millis()>(lastSpuit+interval)) spuit();         
                                                          
      }

} 

void spuit()
{
        myservo.write(180);
        delay(800);                       // waits 800ms for the servo to reach the position 
        myservo.write(pos);
        delay(500); 
        lastSpuit = millis();
}
