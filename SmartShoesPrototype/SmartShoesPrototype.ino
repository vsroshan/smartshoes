//First define the libraries and the shields we will use
#define CUSTOM_SETTINGS
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_TERMINAL_SHIELD  //this Terminal shield is just to check if everything is going alright as planned 
/* Include 1Sheeld library. */
#include <OneSheeld.h>
//Now define the ultrasonic echo and trig pins
const int righttrig = 9; //trig on pin 9 
const int rightecho = 10; //echo on pin 10
const int fronttrig = 11; //trig on pin 9 
const int frontecho = 12;
//define variables that will memorize the distance 
long rightduration;
int rightdistance;
long frontduration;
int frontdistance; 
void setup() {
  //Start communication with smartphone
    OneSheeld.begin();
  // Ultrasonic pins setting up modes trigs are OUTPUTs and echos are INPUT
pinMode(righttrig,OUTPUT);
pinMode(rightecho,INPUT);
pinMode(fronttrig,OUTPUT);
pinMode(frontecho,INPUT);
}
void loop() {
  // This block is for ultrasonic distance detection
 digitalWrite( righttrig, LOW); 
  delayMicroseconds(2); 
  digitalWrite( righttrig, HIGH);//send ultrasonic wave 
  delayMicroseconds(10);
    digitalWrite( righttrig, LOW);  
rightduration=pulseIn(rightecho,HIGH);
rightdistance=rightduration*0.034/2; //to turn the distance into cm unit
digitalWrite( fronttrig, LOW); 
  delayMicroseconds(2); 
  digitalWrite( fronttrig, HIGH);//send ultrasonic wave 
  delayMicroseconds(10);
 digitalWrite( fronttrig, LOW);  
frontduration=pulseIn(frontecho,HIGH);
frontdistance=frontduration*0.034/2;
Terminal.println(frontdistance);
Terminal.println(rightdistance);
//Now the comparison and communication with smartphone part 
if(frontdistance<15 && rightdistance<15) //I set it as 15 cm, you can change it if you want to.
{       
      Terminal.println("Go Left");//Just to check you can remove this line if you don't like it 
  TextToSpeech.say("Go Left");
  delay(1000); //This delay is for the "Go Left" to be read out slowly completely 
}
if(frontdistance<15 && rightdistance>15)
{     Terminal.println("Go right");
      
  TextToSpeech.say("Go right");
  delay(1000);
}
if(frontdistance>15 && rightdistance<15)
{
    Terminal.println("on your right");
    TextToSpeech.say("move forward");
    delay(1000);
}
delay(1000);
}

