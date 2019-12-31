// This code was burned in Arduino mega for this project
#include <Wire.h>
#include <SoftwareSerial.h>

#define sensor1  A0
#define sensor2  A1
#define sensor3  A2
#define sensor4  A3
#define sensor5  A4
#define sensor6  A5
float sensorVal[] = {0,0,0,0,0,0};


long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;

long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  setupMPU();
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  pinMode(sensor5,INPUT);
  pinMode(sensor6,INPUT);
  Serial.print("Thumb1");
  Serial.print(",");
  Serial.print("Index1");
  Serial.print(",");
  Serial.print("Middle1");
  Serial.print(",");
  Serial.print("Ring1");
  Serial.print(",");
  Serial.print("Pinky1");
  Serial.print(",");
  Serial.print("Palm1");
  Serial.print(",");
  Serial.print("AX1");
  Serial.print(",");
  Serial.print("AY1");
  Serial.print(",");
  Serial.print("AZ1");
  Serial.print(",");
  Serial.print("GX1");
  Serial.print(",");
  Serial.print(" GY1");
  Serial.print(",");
  Serial.print("GZ1");
  Serial.print(",");
  
  Serial.print("Thumb2");
  Serial.print(",");
  Serial.print("Index2");
  Serial.print(",");
  Serial.print("Middle2");
  Serial.print(",");
  Serial.print("Ring2");
  Serial.print(",");
  Serial.print("Pinky2");
  Serial.print(",");
  Serial.print("Palm2");
  Serial.print(",");
  Serial.print("AX2");
  Serial.print(",");
  Serial.print("AY2");
  Serial.print(",");
  Serial.print("AZ2");
  Serial.print(",");
  Serial.print("GX2");
  Serial.print(",");
  Serial.print(" GY2");
  Serial.print(",");
  Serial.println("GZ2");
}


void loop() {
  recordAccelRegisters();
  recordGyroRegisters();
  
  sensorVal[0] = analogRead(sensor1);
  sensorVal[1] = analogRead(sensor2);
  sensorVal[2] = analogRead(sensor3);
  sensorVal[3] = analogRead(sensor4);
  sensorVal[4] = analogRead(sensor5);
  sensorVal[5] = analogRead(sensor6);
  printData1();
  delay(500);
  recordAccelRegisters();
  recordGyroRegisters();
  sensorVal[0] = analogRead(sensor1);
  sensorVal[1] = analogRead(sensor2);
  sensorVal[2] = analogRead(sensor3);
  sensorVal[3] = analogRead(sensor4);
  sensorVal[4] = analogRead(sensor5);
  sensorVal[5] = analogRead(sensor6);
  printData2();
  delay(500);
  Serial.flush();
}

void setupMPU(){
  Wire.beginTransmission(0b1101000); //This is the I2C address of the MPU (b1101000/b1101001 for AC0 low/high datasheet sec. 9.2)
  Wire.write(0x6B); //Accessing the register 6B - Power Management (Sec. 4.28)
  Wire.write(0b00000000); //Setting SLEEP register to 0. (Required; see Note on p. 9)
  Wire.endTransmission();  
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1B); //Accessing the register 1B - Gyroscope Configuration (Sec. 4.4) 
  Wire.write(0x00000000); //Setting the gyro to full scale +/- 250deg./s 
  Wire.endTransmission(); 
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x1C); //Accessing the register 1C - Acccelerometer Configuration (Sec. 4.5) 
  Wire.write(0b00000000); //Setting the accel to +/- 2g
  Wire.endTransmission(); 
}

void recordAccelRegisters() {
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x3B); //Starting register for Accel Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Accel Registers (3B - 40)
  while(Wire.available() < 6);
  accelX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  accelY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  accelZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  processAccelData();
}

void processAccelData(){
  gForceX = accelX / 16384.0;
  gForceY = accelY / 16384.0; 
  gForceZ = accelZ / 16384.0;
}

void recordGyroRegisters() {
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x43); //Starting register for Gyro Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Gyro Registers (43 - 48)
  while(Wire.available() < 6);
  gyroX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  gyroY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  gyroZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  processGyroData();
}

void processGyroData() {
  rotX = gyroX / 131.0;
  rotY = gyroY / 131.0; 
  rotZ = gyroZ / 131.0;
}

void printData1() {
  Serial.print(String(sensorVal[0]));
  Serial.print(",");
  Serial.print(String(sensorVal[1]));
  Serial.print(",");
  Serial.print(String(sensorVal[2]));
  Serial.print(",");
  Serial.print(String(sensorVal[3]));
  Serial.print(",");
  Serial.print(String(sensorVal[4]));
  Serial.print(",");
  Serial.print(String(sensorVal[5]));
  Serial.print(",");
  Serial.print(rotX);
  Serial.print(",");
  Serial.print(rotY);
  Serial.print(",");
  Serial.print(rotZ);
  Serial.print(",");
  Serial.print(gForceX);
  Serial.print(",");
  Serial.print(gForceY);
  Serial.print(",");
  Serial.print(gForceZ);
  Serial.print(",");
}
void printData2() {
  Serial.print(String(sensorVal[0]));
  Serial.print(",");
  Serial.print(String(sensorVal[1]));
  Serial.print(",");
  Serial.print(String(sensorVal[2]));
  Serial.print(",");
  Serial.print(String(sensorVal[3]));
  Serial.print(",");
  Serial.print(String(sensorVal[4]));
  Serial.print(",");
  Serial.print(String(sensorVal[5]));
  Serial.print(",");
  Serial.print(rotX);
  Serial.print(",");
  Serial.print(rotY);
  Serial.print(",");
  Serial.print(rotZ);
  Serial.print(",");
  Serial.print(gForceX);
  Serial.print(",");
  Serial.print(gForceY);
  Serial.print(",");
  Serial.print(gForceZ); 
  Serial.print("\n");
}
