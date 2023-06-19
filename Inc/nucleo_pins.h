#if !defined(NUCLEO_PINS_H)
#define NUCLEO_PINS_H

//GPIO pin defines for the NUCLEO-F410Rx board.
#define LED0                        PC9
#define LED0_PIN_MODE_OUPUT         GPIO_MODER_MODER9_0     //PIN9 general purpose output mode
#define LED0_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOC->MODER, LED0_PIN_MODE_OUPUT)

#define LED1                        PC8 
#define LED1_PIN_MODE_OUPUT         GPIO_MODER_MODER8_0     //PIN8 general purpose output mode
#define LED1_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOC->MODER, LED1_PIN_MODE_OUPUT)

#define LED2                        PB8
#define LED2_PIN_MODE_OUPUT         GPIO_MODER_MODER8_0     //PIN8 general purpose output mode
#define LED2_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOB->MODER, LED2_PIN_MODE_OUPUT)

#define LED3                        PC6
#define LED3_PIN_MODE_OUPUT         GPIO_MODER_MODER6_0     //PIN6 general purpose output mode
#define LED3_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOC->MODER, LED3_PIN_MODE_OUPUT)

#define LED4                        PB9
#define LED4_PIN_MODE_OUPUT         GPIO_MODER_MODER9_0     //PIN9 general purpose output mode
#define LED4_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOB->MODER, LED4_PIN_MODE_OUPUT)

#define LED5                        PA5
#define LED5_PIN_MODE_OUPUT         GPIO_MODER_MODER5_0     //PIN5 general purpose output mode
#define LED5_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOA->MODER, LED5_PIN_MODE_OUPUT)

#define LED6                        PA12
#define LED6_PIN_MODE_OUPUT         GPIO_MODER_MODER12_0    //PIN12 general purpose output mode
#define LED6_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOA->MODER, LED6_PIN_MODE_OUPUT)

#define LED7                        PA6
#define LED7_PIN_MODE_OUPUT         GPIO_MODER_MODER6_0     //PIN6 general purpose output mode
#define LED7_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOA->MODER, LED7_PIN_MODE_OUPUT)

#define LED8                        PA11
#define LED8_PIN_MODE_OUPUT         GPIO_MODER_MODER11_0    //PIN11 general purpose output mode
#define LED8_SET_PIN_MODE_OUTPUT    SET_BIT(GPIOA->MODER, LED8_PIN_MODE_OUPUT)

#define BUTTON0                     PB2
#define BUTTON0_PIN_MODE_INPUT      GPIO_MODER_MODER2       //PIN2 MODER set to 11, which is used to clear bits.
#define BUTTON0_SET_PIN_MODE_INPUT  CLEAR_BIT(GPIOB->MODER, BUTTON0_PIN_MODE_INPUT)

#endif // NUCLEO_PINS_H


