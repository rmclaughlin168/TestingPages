#include <Arduino.h>
#include "stat_tracker.h"

void setup() {
    
    // initialize serial
    Serial.begin(115200);
    delay(5000);

    // create an object of the class StatTracker
    StatTracker myCalculator;
    
    
uint32_t array_32u[] = {3441,1178,2978,2840,618,1478};
int32_t array_32s[] = {31813,-25694,8423,42675,-10053,7592};
float array_float[] = {-2087.0,-3242.0,-2230.0,1578.0,-2590.0,888.0,2223.0,-2081.0};


    uint8_t length_u = sizeof(array_32u)/sizeof(array_32u[0]);
    uint8_t length_s = sizeof(array_32s)/sizeof(array_32s[0]);
    uint8_t length_f = sizeof(array_float)/sizeof(array_float[0]);

    uint32_t* unsignedPointer  = array_32u;
    int32_t*  signedPointer    = array_32s;
    float*    floatPointer     = array_float;

    // add unsigned ints
    for (uint8_t index = 0; index < length_u; index++)
    {
        myCalculator.add_data(*unsignedPointer);
        unsignedPointer++;  
    }

    // add signed ints
    for (uint8_t index = 0; index < length_s; index++)
    {
        myCalculator.add_data(*signedPointer);
        signedPointer++;  
    }

    // add floats
    for (uint8_t index = 0; index < length_f; index++)
    {
        myCalculator.add_data(*floatPointer);
        floatPointer++;  
    }

    uint32_t myNumPoints = myCalculator.num_points();
    float myAverage = myCalculator.average();
    float myStdDev = myCalculator.std_dev();
    delay(1000);
    Serial.println("--Statistics for this data set--");
    delay(1000);
    Serial.printf("Number of points in the data set: %u \n", myNumPoints);
    delay(1000);
    Serial.println(myAverage);
    Serial.println(myStdDev);
    // Serial.printf("Average of the data set: %f \n", myAverage);
    // delay(1000);
    // Serial.printf("Standard deviation of the data set: %f \n", myStdDev);
    // delay(1000);


}

void loop() 
{

}