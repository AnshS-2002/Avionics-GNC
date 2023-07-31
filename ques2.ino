#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <MPU6050_tockn.h>

Adafruit_BMP085 bmp;
MPU60050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  // read BMP sensor
  float temp=bmp.readTeamperature();
  float pressure=bmp.readPressure();
  float alt=bmp.readaltitude(1013.25);
  //read MPU sensor
  float accelX=mpu6050.getAccX();
  float accelY=mpu6050.getAccY();
  float accelZ=mpu6050.getAccZ();
  float gyroX=mpu6050.getGyroX();
  float gyroY=mpu6050.getGyroY();
  float gyroZ=mpu6050.getGyroZ();
  float pitch=mpu6050.getPitch();
  float roll=mpu6050.getRoll();
  float yaw=mpu6050.getYaw();
  mpu6050.update();

  Serial.print("TEMPERATURE");
  Serial.println(temp);
  Serial.print("PRESSURE");
  Serial.println(pressure);
  Serial.print("ALTITUDE");
  Serial.println(alt);

  Serial.print("ACCELEROMETER(X,Y,Z): ");
  Serial.println(accelX);
  Serial.println(accelY);
  Serial.println(accelZ);
  Serial.print("GYROSCOPE(X,Y,Z): ");
  Serial.println(gyroX);
  Serial.println(gyroY);
  Serial.println(gyroZ);

  Serial.print("PITCH: ");
  Serial.println(pitch);
  Serial.print("ROLL: ");
  Serial.println(roll);
  Serial.print("YAW: ");
  Serial.println(yaw);

  delay(2000);
}
