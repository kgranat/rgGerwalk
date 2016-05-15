const int L_LEG_ANKLE_INDEX = 0;
const int R_LEG_ANKLE_INDEX = 1;
const int L_LEG_KNEE_INDEX = 2;
const int R_LEG_KNEE_INDEX = 3;
const int L_LEG_HIP_INDEX = 4;
const int R_LEG_HIP_INDEX = 5;
const int MIDDLE_SERVO_INDEX = 6;

const int L_LEG_ANKLE_PIN = 6;
const int R_LEG_ANKLE_PIN = 11;
const int L_LEG_KNEE_PIN = 5;
const int R_LEG_KNEE_PIN = 10;
const int L_LEG_HIP_PIN = 3;
const int R_LEG_HIP_PIN = 9;
const int MIDDLE_SERVO_PIN = 12;



const int L_ANKLE_ERROR = 00;
const int R_ANKLE_ERROR = -200;
const int L_KNEE_ERROR = -100;
const int R_KNEE_ERROR = -100;
const int L_HIP_ERROR = -100;
const int R_HIP_ERROR = 100;
const int MIDDLE_ERROR = -100;

const int BUZZER_PIN = 2;


int lAnkleVal = 900;
int rAnkleVal = 2100;
int lKneeVal = 1300;
int rKneeVal = 1700;
int lHipVal = 2100;
int rHipVal = 900;
int middleVal= 1500;

#include <ServoEx.h>
ServoEx    gerwalkServo[7];

void setup() {

  pinMode(2, OUTPUT);
  
  gerwalkServo[L_LEG_ANKLE_INDEX].attach(L_LEG_ANKLE_PIN);
  gerwalkServo[R_LEG_ANKLE_INDEX].attach(R_LEG_ANKLE_PIN);
  gerwalkServo[L_LEG_KNEE_INDEX].attach(L_LEG_KNEE_PIN);
  gerwalkServo[R_LEG_KNEE_INDEX].attach(R_LEG_KNEE_PIN);
  gerwalkServo[L_LEG_HIP_INDEX].attach(L_LEG_HIP_PIN);
  gerwalkServo[R_LEG_HIP_INDEX].attach(R_LEG_HIP_PIN);
  gerwalkServo[MIDDLE_SERVO_INDEX].attach(MIDDLE_SERVO_PIN);

  
  SetServo(1000);
  // put your setup code here, to run once:


  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
  
   //rHipVal = 900//pick up knee
   rKneeVal = 2000;
  middleVal = 600;
   
  SetServo(1000);
  
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
  //level ankle
  rAnkleVal = 2400;
  SetServo(1000);
  
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);

  rHipVal = rHipVal + 300;
  rKneeVal = rKneeVal - 300;

  SetServo(1000);


  middleVal = 2400;
  SetServo(1000);

  
   //rHipVal = 900//pick up knee
   lKneeVal = lKneeVal - 600;
   rKneeVal = rKneeVal + 500;
   lAnkleVal  = lAnkleVal - 150;

  SetServo(1000);

   
   rKneeVal = rKneeVal - 300;
   rAnkleVal = rAnkleVal - 450;
   rHipVal = 600;
  SetServo(1000);
   

}

void loop() {
  // put your main code here, to run repeatedly:

}

//===================================================================================================
// SetServo: Writes Servo Position Solutions
//===================================================================================================
void SetServo(unsigned int DeltaTime)
{
  ServoGroupMove.start();
  gerwalkServo[L_LEG_ANKLE_INDEX].writeMicroseconds(lAnkleVal + L_ANKLE_ERROR);
  gerwalkServo[R_LEG_ANKLE_INDEX].writeMicroseconds(rAnkleVal + R_ANKLE_ERROR);
  gerwalkServo[L_LEG_KNEE_INDEX].writeMicroseconds(lKneeVal + L_KNEE_ERROR);
  gerwalkServo[R_LEG_KNEE_INDEX].writeMicroseconds(rKneeVal + R_KNEE_ERROR);
  gerwalkServo[L_LEG_HIP_INDEX].writeMicroseconds(lHipVal + L_HIP_ERROR);
  gerwalkServo[R_LEG_HIP_INDEX].writeMicroseconds(rHipVal + R_HIP_ERROR);
  gerwalkServo[MIDDLE_SERVO_INDEX].writeMicroseconds(middleVal + MIDDLE_ERROR);
  ServoGroupMove.commit(DeltaTime);
  delay(DeltaTime);
}

