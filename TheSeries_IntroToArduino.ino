#define ledPin 3
#define photoPin A0
#define servoControlPin A1
#define servoPin 10
#include <Servo.h>
int bright;
int photoVal;
int servoVal;

Servo myServo;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(photoPin,INPUT);
  myServo.attach(servoPin);
}

void loop()
{
  //blinkLED(ledPin);
  ledControl(ledPin);
  //photoValRead(photoPin);
  //controlServo();
  delay(100);
}

void blinkLED(int lp)
{
  digitalWrite(lp, HIGH);
  delay(500);
  digitalWrite(lp, LOW);
  delay(400);
}

void ledControl(int lp)
{ 
 Serial.println("Please enter a value ( 0 - 255)");
 Serial.println();
 
 while(true)
 {
  while(Serial.available() > 0)
  {
   bright = Serial.parseInt();
   bright = constrain(bright, 0, 255);
   
   Serial.print("The LED has been set to ");
   Serial.println(bright);
   Serial.println();
   analogWrite(lp, bright);
  }
 }  
}

int photoValRead(int pn)
{
  photoVal = analogRead(pn);
  Serial.print(photoVal);
  photoVal = photoVal - 700;
  Serial.print("\t");
  Serial.print(photoVal);
  photoVal = photoVal * 5;
  Serial.print("\t");
  Serial.println(photoVal);
  return(photoVal);
}

void controlServo()
{
  servoVal = analogRead(servoControlPin);
  //servoVal = map(servoVal, 0, 1023, 0, 180);
  servoVal = map(photoVal, 0, 1023, 0, 180);
  myServo.write(servoVal);
  delay(15);
}
