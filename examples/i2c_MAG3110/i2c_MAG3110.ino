#include <Wire.h>
#include "i2c.h"

#include "i2c_MAG3110.h"
MAG3110 mag3110 = MAG3110();


void setup()
{
    Serial.begin(115200);
    Serial.println("READ MAG3310");

    if (mag3110.initialize())  Serial.println("Sensor found!");
    else
    {
        Serial.println("Sensor missing");
        while(1) {};
    }
}

void loop()
{
    float xyz_uT[3];

    mag3110.getMeasurement(xyz_uT);

    Serial.print(" X: ");
    Serial.print(xyz_uT[0],2);
    Serial.print(" \tY: ");
    Serial.print(xyz_uT[1],2);
    Serial.print(" \tZ: ");
    Serial.print(xyz_uT[2],2);
    Serial.println("");
    delay(20);

}


