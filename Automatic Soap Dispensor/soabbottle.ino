#include <NewPing.h>
#include <Servo.h>

#define trig 4
#define echo 5
#define servoPwm 3
#define max_distance 40

Servo sg90;
NewPing sonar(trig, echo, max_distance);

int getDistance();

void setup() {
  Serial.begin(9600);//to begin the serial communication
  sg90.attach(servoPwm);//just define the servo motor driver pin
  pinMode(trig, OUTPUT);//to trigger the sonar pulse
  pinMode(echo, INPUT); //this will give the distance

  sg90.write(180);//this is the default location for the servo motor
  digitalWrite(trig, LOW);

}

void loop() {


  int distance = getDistance();
  if (distance <= 20 )
  {
    sg90.write(90);
    delay(1000);
  }
  else
  {
    sg90.write(180);
  }

  delay(300);
}


int getDistance()
{
  int value = sonar.ping_cm();
  delay(70);
  if (value == 0)
  {
    return 250;
  }
  else
  {
    return value;
  }

}
