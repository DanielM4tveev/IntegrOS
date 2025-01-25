#include <Arduino.h>
#include <src/kernel.h>
#include <src/Utils.h>
#include <src/modules.h>
#include <src/screenmsg.h>

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
  {"kill 0xff", panic},
  {"reboot", reboot}
};

const int numCommands = sizeof(commands) / sizeof(commands[0]);

void executeCommand(const String& command) {
  for (int i = 0; i < numCommands; i++) {
    if (command.equals(commands[i].command)) {
      commands[i].function();  // Вызов соответствующей функции
      return;
    }
  }
  _DEV_NL_SERIAL_("Unknown command. Type 'help' for a list of commands.");
  _USER_INPUT_SERIAL_;
}

void setup() {
  // Инициализация серийного порта
  _DEV_SERIAL_INIT_(_DEV_SERIAL_BAUD_);
  _PIN_MODE_(_HW_LED_DEFAULT_, OUTPUT);
  
  screenmessage();
  _USER_INPUT_SERIAL_;

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
    _DEV_SERIAL_("");
  }
}
