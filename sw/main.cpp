#include <Arduino.h>

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12
int step_number = 0;

void setup() {
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void OneStep(bool dir)
{
    if(dir)
    {
        switch(step_number)
        {
            case 0:
                digitalWrite(STEPPER_PIN_1, HIGH);
                digitalWrite(STEPPER_PIN_2, LOW);
                digitalWrite(STEPPER_PIN_3, LOW);
                digitalWrite(STEPPER_PIN_4, LOW);
                break;
            case 1:
                digitalWrite(STEPPER_PIN_1, LOW);
                digitalWrite(STEPPER_PIN_2, HIGH);
                digitalWrite(STEPPER_PIN_3, LOW);
                digitalWrite(STEPPER_PIN_4, LOW);
                break;
            case 2:
                digitalWrite(STEPPER_PIN_1, LOW);
                digitalWrite(STEPPER_PIN_2, LOW);
                digitalWrite(STEPPER_PIN_3, HIGH);
                digitalWrite(STEPPER_PIN_4, LOW);
                break;
            case 3:
                digitalWrite(STEPPER_PIN_1, LOW);
                digitalWrite(STEPPER_PIN_2, LOW);
                digitalWrite(STEPPER_PIN_3, LOW);
                digitalWrite(STEPPER_PIN_4, HIGH);
                break;
        } 
    }
    else
    {
        switch(step_number)
        {
            case 0:
                digitalWrite(STEPPER_PIN_1, LOW);
                digitalWrite(STEPPER_PIN_2, LOW);
                digitalWrite(STEPPER_PIN_3, LOW);
                digitalWrite(STEPPER_PIN_4, HIGH);
                break;
            case 1:
                digitalWrite(STEPPER_PIN_1, LOW);
                digitalWrite(STEPPER_PIN_2, LOW);
                digitalWrite(STEPPER_PIN_3, HIGH);
                digitalWrite(STEPPER_PIN_4, LOW);
                break;
            case 2:
                digitalWrite(STEPPER_PIN_1, LOW);
                digitalWrite(STEPPER_PIN_2, HIGH);
                digitalWrite(STEPPER_PIN_3, LOW);
                digitalWrite(STEPPER_PIN_4, LOW);
                break;
            case 3:
                digitalWrite(STEPPER_PIN_1, HIGH);
                digitalWrite(STEPPER_PIN_2, LOW);
                digitalWrite(STEPPER_PIN_3, LOW);
                digitalWrite(STEPPER_PIN_4, LOW);
                break;
        }
   }
  step_number++;
  if(step_number > 3)
    step_number = 0;
}

void step_angle (int angle)
{
  float ratio = 1000/180;
  int count = ratio*abs(angle);

  for (int i = 0; i < count; i++)
  {
    if (angle > 0)
      OneStep(false);
    else
      OneStep(true);
    
    delay(2);
  }
}

const int DIN_LEFT_PIN = 7;
const int DIN_RIGHT_PIN = 6;
void loop() 
{
  //step_angle(360);
  //delay(1000);
  //step_angle(-360);
  //delay(1000);

  int value;
  value = digitalRead(DIN_LEF7T_PIN);
  if (value)
    step_angle(-15);
  else
  {
    value = digitalRead(DIN_RIGHT_PIN);
    if (value)
      step_angle(15);
  }
}