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
const int NUM_SERVOS = 7;

int servoErrors[NUM_SERVOS] = {0,-200,-100,-100,-100,100,-100};
int servoValues[NUM_SERVOS] = {900,2100,1300,1700,2100,900,1500};

int lAnkleVal = 900;
int rAnkleVal = 2100;
int lKneeVal = 1300;
int rKneeVal = 1700;
int lHipVal = 2100;
int rHipVal = 900;
int middleVal= 1500;

int poseTime = 250;
#include <ServoEx.h>
ServoEx    gerwalkServo[7];

unsigned long lastUpdateTime;
int updateInterval = 1000;
void setup() {
Serial.begin(38400);
  pinMode(2, OUTPUT);
  
  gerwalkServo[L_LEG_ANKLE_INDEX].attach(L_LEG_ANKLE_PIN);
  gerwalkServo[R_LEG_ANKLE_INDEX].attach(R_LEG_ANKLE_PIN);
  gerwalkServo[L_LEG_KNEE_INDEX].attach(L_LEG_KNEE_PIN);
  gerwalkServo[R_LEG_KNEE_INDEX].attach(R_LEG_KNEE_PIN);
  gerwalkServo[L_LEG_HIP_INDEX].attach(L_LEG_HIP_PIN);
  gerwalkServo[R_LEG_HIP_INDEX].attach(R_LEG_HIP_PIN);
  gerwalkServo[MIDDLE_SERVO_INDEX].attach(MIDDLE_SERVO_PIN);

  
  SetServo(2000);
  // put your setup code here, to run once:

  setservoArray(709,2229,1180,1926,2058,916,1500);//neutral
  SetServo(3000);
  
  


  
}

void loop() {
  // put your main code here, to run repeatedly:

  setservoArray(709,2229,1180,1926,2058,936,920); // head tilt left
  SetServo(poseTime + 150);

  setservoArray(709,2400,1180,2357,2058,934,920);//right leg up
  SetServo(poseTime);
  
  setservoArray(709,2400,1180,1917,2058,1108,920);//right down

  SetServo(poseTime);
  
  setservoArray(707,2400,1180,1917,2056,1108,2070); // head right
  SetServo(poseTime + 150);

  setservoArray(600,2222,731,1831,2042,1108,2070); // left leg up
  SetServo(poseTime);


  setservoArray(600,2222,1321,1831,1724,1108,2070);// left leg down
  SetServo(poseTime);

  setservoArray(709,2229,1180,1926,2058,916,1500);//neutral
  SetServo(poseTime);

}

//===================================================================================================
// SetServo: Writes Servo Position Solutions
//===================================================================================================
void SetServo(unsigned int DeltaTime)
{
  ServoGroupMove.start();
  for(int i = 0; i < NUM_SERVOS; i++)
    {
      gerwalkServo[i].writeMicroseconds(servoValues[i] + servoErrors[i]);
    }

  ServoGroupMove.commit(DeltaTime);
  delay(DeltaTime);
}

void setServoAnalog()
{
  for(int i = 0; i < NUM_SERVOS; i++)
    {
      gerwalkServo[i].writeMicroseconds(servoValues[i] + servoErrors[i]);
    }
}

void readAnalogs()
{
  for(int i = 0; i< NUM_SERVOS; i++)
  {
    servoValues[i] =  map(analogRead(i), 0, 1023, 600, 2400);
  }
}
void setservoArray(int s0, int s1, int s2, int s3, int s4, int s5, int s6)
{
   servoValues[0] = s0;
   servoValues[1] = s1;
   servoValues[2] = s2;
   servoValues[3] = s3;
   servoValues[4] = s4;
   servoValues[5] = s5;
   servoValues[6] = s6;
}

void reportValues()
{
  if(millis() - lastUpdateTime> updateInterval)
  {
    Serial.print("setservoArray(");
    for(int i = 0; i < NUM_SERVOS; i++)
    {
      
     Serial.print(servoValues[i]);
     Serial.print(",");
    }
    
    Serial.println(")");
      lastUpdateTime = millis();
  }

}

