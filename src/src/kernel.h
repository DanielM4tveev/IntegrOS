#ifndef kernel_h
#define kernel_h
 
// Kernel Params
#define _DEV_SERIAL_ Serial
#define _DEV_SERIAL_BAUD_ 115200
#define _HW_LED_DEFAULT_ 13
#define _SYS_SLEEP_TICK_ 500

// System parameters
#define _SYS_CLK_FREQ_          16000000UL      // System clock frequency (16 MHz for AVR)
#define _SYS_MAX_PINS_          20              // Total available I/O pins
#define _SYS_MAX_TASKS_         10              // Maximum number of tasks for basic scheduler
#define _SYS_WD_TIMEOUT_MS_     1000            // Watchdog timeout (ms)
#define _SYS_DEBOUNCE_DELAY_    50              // Button debounce delay (ms)
#define _SYS_LOG_LEVEL_         3               // Log level for system (0-quiet, 3-verbose)
#define _HW_NAME_ "EmbSYS"

// Memory parameters
#define _MEM_EEPROM_SIZE_       1024            // EEPROM size in bytes
#define _MEM_FLASH_SIZE_        (32 * 1024)     // Flash memory size in bytes
#define _MEM_SRAM_SIZE_         2048            // SRAM size in bytes

// Hardware parameters
#define _HW_ADC_RES_            1024            // ADC resolution (10-bit)
#define _HW_ADC_PRESCALER_      128             // ADC prescaler
#define _HW_TIMER0_PRESCALER_   64              // Prescaler for Timer 0
#define _HW_TIMER1_PRESCALER_   256             // Prescaler for Timer 1
#define _HW_TIMER2_PRESCALER_   128             // Prescaler for Timer 2

// Peripheral support
#define _DEV_SUPPORT_UART_      1               // Enable UART (1 - yes, 0 - no)
#define _DEV_UART_BAUD_         9600            // UART baud rate
#define _DEV_SUPPORT_I2C_       1               // Enable I2C support
#define _DEV_I2C_FREQ_          100000          // I2C clock frequency (100 kHz)
#define _DEV_SUPPORT_SPI_       1               // Enable SPI support
#define _DEV_SPI_FREQ_          4000000         // SPI clock speed (4 MHz)
#define _DEV_MAX_I2C_DEV_       8               // Maximum number of I2C devices

// I/O and Pin configuration
#define _PIN_MAX_ANALOG_        6               // Max number of analog pins
#define _PIN_MAX_DIGITAL_       14              // Max number of digital pins
#define _PIN_MAX_PWM_           6               // Max number of PWM pins
#define _PIN_INTERRUPT_COUNT_   2               // Number of external interrupts supported (INT0, INT1)

// Power management
#define _PM_SUPPORT_SLEEP_      1               // Support for sleep modes (1 - yes, 0 - no)
#define _PM_SLEEP_MODE_         1               // Default sleep mode (1 - idle, 2 - ADC noise reduction)

// Kernel features
#define _KRN_USE_INTERRUPTS_    1               // Enable interrupts (1 - yes, 0 - no)
#define _KRN_SCHED_ALGO_        0               // Scheduler algorithm (0 - round-robin, 1 - FIFO)
#define _KRN_TICK_RATE_         1000            // System tick rate (in Hz)
#define _KRN_MAX_TIMERS_        3               // Maximum hardware timers available

// Debugging
#define _DBG_SERIAL_ENABLED_    1               // Enable serial debugging (1 - yes, 0 - no)
#define _DBG_SERIAL_BUFFER_     64              // Serial buffer size (in bytes)

// Hardware architecture
#define _ARCH_AVR_              1               // Architecture type (1 - AVR)
#define _ARCH_CPU_FREQ_         _SYS_CLK_FREQ_  // Alias for system clock frequency


#endif
