#ifndef Utils_h
#define Utils_h
 
#include <Arduino.h>

void whoami() {
    const char* whoLines[] = {
            "Root",
    };

    const int numLines = sizeof(whoLines) / sizeof(whoLines[0]);

    _DEV_NL_SERIAL_("");
    for (int i = 0; i < numLines; i++) {
        _DEV_NL_SERIAL_(whoLines[i]); // Вывод каждой строки через серийный порт
    }
    _USER_INPUT_SERIAL_;
}

void uname() {
    const char* infoLines[] = {
        "System: " _HW_NAME_,    // Имя платы
        "Version: 1.0.0",         // Версия прошивки
        "CPU Frequency: 16 MHz", // Частота процессора
        "Compile Date: " __DATE__, // Дата компиляции
        "Compile Time: " __TIME__  // Время компиляции
    };
    
    const int numLines = sizeof(infoLines) / sizeof(infoLines[0]);

    _DEV_NL_SERIAL_("");
    for (int i = 0; i < numLines; i++) {
        _DEV_NL_SERIAL_(infoLines[i]); // Вывод каждой строки через серийный порт
    }
    _USER_INPUT_SERIAL_;  
}



void help() {
    const char* helpLines[] = {
            "help",         // Версия прошивки
            "whoami", // Частота процессора
            "uname", // Дата компиляции
            "reboot"// Время компиляции
    };

    const int numLines = sizeof(helpLines) / sizeof(helpLines[0]);

    _DEV_NL_SERIAL_("");
    for (int i = 0; i < numLines; i++) {
        _DEV_NL_SERIAL_(helpLines[i]); // Вывод каждой строки через серийный порт
    }
    _USER_INPUT_SERIAL_;
}
 
#endif