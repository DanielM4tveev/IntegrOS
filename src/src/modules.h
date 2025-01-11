#ifndef modules_h
#define modules_h

#include <Arduino.h>
#include <avr/wdt.h>

void reboot() {
    Serial.print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    wdt_disable();
    wdt_enable(WDTO_15MS);
    while (1) {}
}

void panic() {
    Serial.println("\nKernel panic - not syncing: Fatal exception in interrupt\nCode: 00 FF FA 0F\n");
    while(1){
        for(int i = 5; i > 0; i--) {
            delay(_SYS_SLEEP_TICK_ * 2);
        }
        reboot();
    }
}

#endif