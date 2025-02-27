/*
Electronics Studio
@file Read_all_data.ino
@date  25-02-2025
@url https:https: https://github.com/electronicsstudio
@url YouTube: https://www.youtube.com/@ElectronicsStudio-v7o/featured
*/

#include <DFRobot_BMX160.h>

DFRobot_BMX160 bmx160;
void setup(){
  Serial.begin(115200);
  delay(100);
  
  //init the hardware bmx160  
  if (bmx160.begin() != true){
    Serial.println("init false");
    while(1);
  }
  delay(100);
}

void loop(){
  sBmx160SensorData_t Omagn, Ogyro, Oaccel;

  /* Get a new sensor event */
  bmx160.getAllData(&Omagn, &Ogyro, &Oaccel);

  /* Display the magnetometer results (magn is magnetometer in uTesla) */
  Serial.print("$PMAG,");
  Serial.print(Omagn.x, 2); Serial.print(",");
  Serial.print(Omagn.y, 2); Serial.print(",");
  Serial.print(Omagn.z, 2);
  Serial.println("*");

  // Display gyroscope results
  Serial.print("$PGYR,");
  Serial.print(Ogyro.x, 2); Serial.print(",");
  Serial.print(Ogyro.y, 2); Serial.print(",");
  Serial.print(Ogyro.z, 2);
  Serial.println("*");

  // Display accelerometer results
  Serial.print("$ACC,");
  Serial.print(Oaccel.x, 2); Serial.print(",");
  Serial.print(Oaccel.y, 2); Serial.print(",");
  Serial.print(Oaccel.z, 2);
  Serial.println("*");

  Serial.println("");

  delay(500);
}










