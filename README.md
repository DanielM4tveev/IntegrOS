![logo2](https://github.com/user-attachments/assets/62908f39-682e-4fd9-aa8b-3dbd5aab33dc)
# IntegrOS: Unix-подобная операционная система для микроконтроллеров

**IntegrOS** — это легковесная Unix-подобная операционная система, разработанная для работы на микроконтроллерах таких платформ, как Arduino, Raspberry Pi Pico, ESP32 и STM32. Система обеспечивает базовый функционал для управления устройством через Serial Monitor, предоставляя минималистичный интерфейс командной строки и поддержку ключевых функций для встраиваемых систем.

## Основные возможности

- **Поддержка платформ**:
  - Arduino
  - Raspberry Pi Pico
  - ESP32
  - STM32
- **Интерфейс**: работа через Serial Monitor с помощью текстовых команд.
- **Командная строка**: базовые Unix-команды для навигации по файловой системе, управления файлами и выполнения задач.
- **Минимальные требования**: система оптимизирована для работы в ограниченной среде с минимальным количеством ресурсов.
- **Модульность**: возможность расширения за счет добавления новых функций через модули.

## Установка

1. Клонируйте репозиторий на локальный компьютер:
    ```bash
    git clone https://github.com/DanielM4tveev/IntegrOS.git
    ```

2. Откройте проект в Arduino IDE (или другой среде разработки для вашей платформы).

3. Выберите подходящую плату:
   - Arduino: `Tools -> Board -> Arduino Uno` (или другой тип Arduino)
   - Raspberry Pi Pico: `Tools -> Board -> Raspberry Pi Pico`
   - ESP32: `Tools -> Board -> ESP32`
   - STM32: `Tools -> Board -> STM32`

4. Загрузите проект на вашу плату.

## Начало работы

1. Подключите ваше устройство к компьютеру через USB.
2. Откройте Serial Monitor в Arduino IDE или другом терминальном приложении (например, PuTTY).
3. Установите скорость обмена данных (baud rate) на **9600** (или другую, указанную в настройках).
4. После загрузки устройства в Serial Monitor появится приглашение командной строки:
    ```bash
    IntegrOS>
    ```
5. Введите команды для выполнения различных операций.

## Примеры команд

- **ls** — Показать список файлов и папок в текущем каталоге.
- **cd [путь]** — Перейти в указанный каталог.
- **cat [файл]** — Показать содержимое файла.
- **rm [файл]** — Удалить файл.
- **touch [файл]** — Создать новый файл.
- **echo [текст] > [файл]** — Записать текст в файл.
- **reboot** — Перезагрузить устройство.

## Поддерживаемые команды

| Команда                  | Описание                                              |
|--------------------------|-------------------------------------------------------|
| `ls`                     | Список файлов и папок в текущем каталоге              |
| `cd [путь]`              | Перейти в указанный каталог                           |
| `cat [файл]`             | Показать содержимое файла                             |
| `touch [файл]`           | Создать пустой файл                                   |
| `rm [файл]`              | Удалить файл                                          |
| `echo [текст] > [файл]`  | Записать текст в файл                                 |
| `reboot`                 | Перезагрузить систему                                 |
| `help`                   | Показать список доступных команд                      |

## Расширение функционала

IntegrOS разработана с учетом возможности расширения. Вы можете добавлять собственные модули и команды, чтобы адаптировать систему под конкретные задачи. Для этого:

1. Создайте новый файл в папке `/modules`.
2. Определите функции обработки команд в новом модуле.
3. Зарегистрируйте команду в основном скетче, чтобы она стала доступна в интерфейсе командной строки.

## Поддержка

Если у вас возникли вопросы или предложения по улучшению системы, создайте [issue](https://github.com/DanielM4tveev/IntegrOS/issues) в репозитории на GitHub или свяжитесь с разработчиками через email.

## Лицензия

Этот проект распространяется под лицензией MIT. Подробности см. в файле [LICENSE](LICENSE).
