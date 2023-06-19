#if !defined(NUCLEO_PINS_H)
#define NUCLEO_PINS_H

#define PIN_PORT(port)                  GPIO##port
#define PIN_MODE_OUTPUT(pin)            GPIO_MODER_MODER##pin##_0
#define PIN_MODE_INPUT(pin)             GPIO_MODER_MODER##pin
#define SET_PIN_MODE_OUTPUT(port, pin)  SET_BIT(PIN_PORT(port)->MODER, PIN_MODE_OUTPUT(pin)) 
#define SET_PIN_MODE_INPUT(port, pin)   CLEAR_BIT(PIN_PORT(port)->MODER, PIN_MODE_INPUT(pin))

// GPIO pin defines for the NUCLEO-F410Rx board.
#define LED0                            PC9
#define LED0_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(C, 9)

#define LED1                            PC8
#define LED1_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(C, 8)

#define LED2                            PB8
#define LED2_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(B, 8)

#define LED3                            PC6
#define LED3_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(C, 6)

#define LED4                            PB9
#define LED4_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(B, 9)

#define LED5                            PA5
#define LED5_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(A, 5)

#define LED6                            PA12
#define LED6_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(A, 12)

#define LED7                            PA6
#define LED7_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(A, 6)

#define LED8                            PA11
#define LED8_SET_PIN_MODE_OUTPUT        SET_PIN_MODE_OUTPUT(A, 11)

#define BUTTON0                         PB2
#define BUTTON0_SET_PIN_MODE_INPUT      SET_PIN_MODE_INPUT(B, 2)

#endif // NUCLEO_PINS_H