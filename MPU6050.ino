#include <MPU6050.h>   

MPU6050 mpu;
Vector normAccel;
float xOrigin = 0;
float yOrigin = 0;

float high_thresh = 6;
float low_thresh = -6;

void setup() {
  
  Serial.begin(9600);

  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    delay(100);
  }
  normAccel = mpu.readNormalizeAccel();
  xOrigin = normAccel.XAxis;
  yOrigin = normAccel.YAxis;
  delay(100);
}

void loop() {
  
  normAccel = mpu.readNormalizeAccel();
  delay(50);

  if((normAccel.XAxis - xOrigin) > high_thresh) {

    Serial.println("L");
    delay(500); 
  }
  
  else if((normAccel.XAxis - xOrigin) < low_thresh) {

    Serial.println("R");
    delay(500);
  }
 
  else if((normAccel.YAxis - yOrigin) < low_thresh) {

    Serial.println("U");
    delay(500);
  }
  
  else if((normAccel.YAxis - yOrigin) > high_thresh) {

    Serial.println("D");
    delay(500);
  }
}
