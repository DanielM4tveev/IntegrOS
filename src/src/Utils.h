#ifndef Utils_h
#define Utils_h
 
#include <Arduino.h>

void whoami() {
    Serial.println("");
    Serial.println("root");
    Serial.print("#!/ ");
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

    Serial.println("");
    for (int i = 0; i < numLines; i++) {
        Serial.println(infoLines[i]); // Вывод каждой строки через серийный порт
    }
    Serial.print("#!/ ");  
}



void help() {
    Serial.println("");
    Serial.println("help");
    Serial.println("whoami");
    Serial.println("uname");
    Serial.print("#!/ "); 
}
 
#endif