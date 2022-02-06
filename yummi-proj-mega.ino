#include <Servo.h>

unsigned long currentMillis;

//each new timer requires similar three lines of code
unsigned long MillisServo1;
unsigned long MillisServo2;
unsigned long MillisServo3;
boolean       repeat13    = true; //repeat this sequence?
boolean       flag13      = true; //is this timer enabled?

Servo myservo1;
Servo myservo2;
Servo myservo3;

int servo1 = 11;
int servo2 = 10;
int servo3 = 9;

//myservo1.write(45);  // baseline
//myservo1.write(145); // 90
//myservo1.write(10);  // left
//myservo1.write(80);   // Right

void setup() {
  myservo1.attach(servo1);
  myservo2.attach(servo2);
  myservo3.attach(servo3);

  myservo1.write(45);
  myservo2.write(45);
  myservo3.write(45);

  
}

int randNumber = 0;

int randomgen(int min, int max)  // Pass in range
{
  srand(time(NULL));  // Changed from rand(). srand() seeds rand for you.
  int random = rand() % (max - min) + min;
  return random;
}


void loop() {
  if (flag13 == true && CheckTime(MillisServo1, 20000ul, repeat13))
  {
    ppHop();
  }

  if (flag13 == true && CheckTime(MillisServo2, 100000ul, repeat13))
  {
    skillPoints();
  }

  if (flag13 == true && CheckTime(MillisServo3, 240000ul, repeat13))
  {
    useSummoners();
  }

  heal();
  delay(10000);
}

void skillPoints() {
  myservo2.write(0);
  delay(500);
  myservo2.write(45);
  delay(500);
  myservo2.write(80);
  delay(500);
  myservo2.write(45);
  delay(500);
  myservo2.write(0);
  delay(500);
  myservo2.write(45);
  delay(500);
  myservo2.write(80);
  delay(500);
  myservo2.write(45);
  delay(500);
}

void useSummoners() {
  myservo3.write(10);
  delay(500);
  myservo3.write(45);
  delay(500);
  myservo3.write(80);
  delay(500);
  myservo3.write(45);
  delay(500);
}

void ppHop() {
  myservo1.write(0);
  delay(500);
  myservo1.write(45);
  delay(500);
  myservo1.write(0);
  delay(500);
  myservo1.write(45);
  delay(500);
}


void heal() {
  myservo1.write(80);
  delay(500);
  myservo1.write(45);
  delay(500);
}

//lastMillis = time we started, wait = delay in mS, restart = do we start again
boolean CheckTime(unsigned long &lastMillis, unsigned long wait, boolean restart)
{
  //is the time up for this task?
  if (millis() - lastMillis >= wait)
  {
    //should this start again?
    if (restart)
    {
      //get ready for the next iteration
      lastMillis = millis(); //get ready for the next iteration
    }
    return true;
  }
  return false;

}
