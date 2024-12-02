#include <Arduino.h>
#include <src/kernel.h>
#include <src/Utils.h>
#include <src/modules.h>

const char* bootlog[] = {
  "[   0.000000] Booting Arduino...",
  "[   0.050000] Initializing system components...",
  "[   0.100000] CPU: ATmega328P @ 16 MHz",
  "[   0.150000] Memory: 2 KB SRAM, 32 KB Flash",
  "[   0.200000] I/O Ports: Initialized",
  "[   0.250000] UART: Serial communication started at 9600 baud",
  "[   0.300000] I2C: Bus initialized",
  "[   0.350000] SPI: Bus initialized",
  "[   0.400000] Timer: Configured for millis() and delay()",
  "[   0.450000] Watchdog: Disabled (default settings)",
  "[   0.500000] Analog pins: Initialized and ready",
  "[   0.550000] PWM: Pulse Width Modulation channels active",
  "[   0.600000] EEPROM: Read/Write initialized",
  "[   0.650000] LED: Blink test initiated",
  "[   0.700000] Sensors: Initialized (Analog/Digital)",
  "[   0.750000] External Interrupts: Enabled",
  "[   0.800000] External memory modules: Not detected",
  "[   0.850000] Configuration: Default settings loaded",
  "[   0.900000] Firmware Version: 1.0.0",
  "[   0.950000] Bootloader: Version 2.0.0",
  "[   1.000000] Setup complete. Entering user code...",
  "[   1.050000] [INFO] Main loop started. Waiting for events.",
  "[   1.100000] [INFO] System operational",
  "[   1.150000] [DEBUG] GPIO: Pin 13 set to HIGH",
  "[   1.200000] [DEBUG] Analog Read: A0 = 512",
  "[   1.250000] [DEBUG] Sensor Data: Temperature = 25°C",
  "[   1.300000] [DEBUG] Timer Status: Active",
  "[   1.350000] [DEBUG] PWM Output: 128",
  "[   1.400000] [DEBUG] EEPROM Status: No errors",
  "[   1.450000] [DEBUG] Watchdog Timer: Not active",
  "[   1.500000] [INFO] System running normally",
  "[   1.550000] [INFO] System uptime: 0 hours, 1 minutes, 30 seconds",
  "[   1.600000] [DEBUG] External Device Status: No errors",
  "[   1.650000] [INFO] Network: Not connected",
  "[   1.700000] [INFO] Power Supply: Voltage stable at 5V",
  "[   1.750000] [DEBUG] Boot sequence completed successfully",
  "[   1.800000] [INFO] Ready for user input or command execution"
};

const int numLines = sizeof(bootlog) / sizeof(bootlog[0]);

typedef void (*CommandFunction)();  // Определяем тип указателя на функцию

struct Command {
  const char* command;
  CommandFunction function;
};

// Определение команд и соответствующих функций
Command commands[] = {
  {"whoami", whoami},
  {"uname", uname},
  {"help", help},
  {"kill 0xff", panic}
};

const int numCommands = sizeof(commands) / sizeof(commands[0]);

void executeCommand(const String& command) {
  for (int i = 0; i < numCommands; i++) {
    if (command.equals(commands[i].command)) {
      commands[i].function();  // Вызов соответствующей функции
      return;
    }
  }
  Serial.println("Unknown command. Type 'help' for a list of commands.");
  Serial.print("#!/ ");
}

void setup() {
  // Инициализация серийного порта
  Serial.begin(SerialPort);
  pinMode(DefaultLed, OUTPUT);
  
  // Вывод логов с задержками
  for (int i = 0; i < numLines; i++) {
    Serial.println(bootlog[i]);
    delay(dlclock);  // Задержка между строками, параметр указан в kernel.h
  }
  Serial.println("");
  Serial.print("#!/ ");

}

void loop() {
  // Проверка, есть ли данные для чтения
  if (Serial.available() > 0) {
    // Чтение входящих данных
    String incomingMessage = Serial.readStringUntil('\n');
    incomingMessage.trim();  

    executeCommand(incomingMessage);
  }
  else {
    Serial.print("");
  }
}
