#include <Arduino.h>
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;
int ena = 6;
int enb = 9;

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  Serial.begin(9600);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
//void back(int speeRB , int speeLB)
//{
//  //turn on right motor
//  digitalWrite (in1,HIGH);
//  digitalWrite (in2,LOW);
//  analogWrite (ena,speeRB);
//  //turn on left motor
//  digitalWrite (in3,HIGH);
//  digitalWrite (in4,LOW);
//  analogWrite (enb,speeLB);
//  delay(0);
//  delay(0);
// }
//
//void front (int speeRF ,int speeLF)
//{
//  //--turn on right motor
//  digitalWrite (in1,LOW);
//  digitalWrite (in2,HIGH);
//  analogWrite (ena,speeRF);
//  //--turn on left motor
//  digitalWrite (in3,LOW);
//  digitalWrite (in4,HIGH);
//  analogWrite (enb,speeLF);
//  delay(0);
//  delay(0);
// }

void Left_if(int speeL)
{
  Serial.println("L");
  if (speeL >= 0 && speeL <= 255)
  { // left motor front
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("left motor front = ON --- speeL = ");
    Serial.println(speeL);
    analogWrite(enb, speeL);
    delay(0);
    delay(0);
  }
  else if (speeL >= -255 && speeL < 0)
  { // left motor back
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enb,-speeL);
    Serial.println("left motor back = ON --- speeL = ");
    Serial.println(speeL);

    delay(0);
    delay(0);
  }
  else
  {
    speeL == 0;
    Serial.println("no match left value");
  }
}
void Right_if(int speeR)
{
  Serial.println("R");
  //right motor if
  if (speeR >= 0 && speeR <= 255)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.println("right motor front = ON --- speeR = ");
    Serial.println(speeR);
    analogWrite(ena, speeR);
    delay(0);
    delay(0);
  }
  else if (speeR >= -255 && speeR < 0)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.println("right motor back = ON --- speeR = ");
    Serial.println(-speeR);
    analogWrite(ena, -speeR);
    delay(0);
    delay(0);
  }
  else
  {
    speeR == 0;
    Serial.println("no match right value");
  }
}
void motocontrol(int speeRR, int speeLL)
{
  Serial.println("-------------------------");
  Serial.println(speeRR);
  Serial.println(speeLL);
  Serial.println("-------------------------");
  Right_if(speeRR);
  Serial.println("<<<<<<>>>>>>");
  Left_if(speeLL);
  delay(200);
}
void loop()
{
  motocontrol(0, -50);
  delay(1000);
}
