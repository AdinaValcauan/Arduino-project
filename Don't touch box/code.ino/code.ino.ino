#include <Servo.h>


Servo myservo;  // create servo object to control a servo

void setup() {
  
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);

  pinMode(12,INPUT_PULLUP);
  pinMode(13,OUTPUT);

}

void loop() {
  int now = digitalRead(12);
  static int currentState = 0;
  static int onStreak = 0, offStreak = 0;
  if(now == 1 && currentState == 0) {
    offStreak = 0;
    onStreak++;
  }
  if(now == 0 && currentState == 1) {
    onStreak = 0;
    offStreak++;
  }

  if(onStreak >= 500) {
    onStreak = 0;
    currentState = 1;
    // rising edge -> switch UP
    myservo.write(180);
    digitalWrite(13,HIGH);
    delay(1500);
    digitalWrite(13,LOW);
    myservo.write(0);
    delay(1500);
  } else if(offStreak >= 500) {
    offStreak = 0;
    currentState = 0;
    // falling edge -> switch DOWN
  }
}
