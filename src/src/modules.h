#ifndef modules_h
#define modules_h

#include <Arduino.h>
 
void panic() {
    Serial.println("\nKernel panic - not syncing: Fatal exception in interrupt\nCode: 00 FF FA 0F\n");
    while(1){}
}

#endif