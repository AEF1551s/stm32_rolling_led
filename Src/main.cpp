#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// System includes

// User includes
#include <user_types.h>
#include <user_functions.h>

// Define all used gpio pins
pin_struct_TypeDef LED0;
pin_struct_TypeDef LED1;
pin_struct_TypeDef LED2;
pin_struct_TypeDef LED3;
pin_struct_TypeDef LED4;
pin_struct_TypeDef LED5;
pin_struct_TypeDef LED6;
pin_struct_TypeDef LED7;
pin_struct_TypeDef LED8;
pin_struct_TypeDef BTN0;

void pin_init()
{
  // Set LED pins to general purpose output mode
  LED0 = pin_setup(GPIOC, PIN9, OUTPUT);
  LED1 = pin_setup(GPIOC, PIN8, OUTPUT);
  LED2 = pin_setup(GPIOB, PIN8, OUTPUT);
  LED3 = pin_setup(GPIOC, PIN6, OUTPUT);
  LED4 = pin_setup(GPIOB, PIN9, OUTPUT);
  LED5 = pin_setup(GPIOA, PIN5, OUTPUT);
  LED6 = pin_setup(GPIOA, PIN12, OUTPUT);
  LED7 = pin_setup(GPIOA, PIN6, OUTPUT);
  LED8 = pin_setup(GPIOA, PIN11, OUTPUT);
  BTN0 = pin_setup(GPIOB, PIN2, INPUT);
  // Set BUTTON pin to input mode (reset state)
}

int main(void)
{

  clock_init();
  pin_init();

  pin_struct_TypeDef LED_pins[9] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

  /* Loop forever */
  do
  {
    for (uint32_t i = 0; i < 9; i++)
    {
      uint32_t set_msk = 0x1U << LED_pins[i].pinx;
      uint32_t reset_pin = (31 - (0xF - LED_pins[i].pinx)); //(31- (15-pin)) This gives register adress for the same pin
      uint32_t reset_msk = 0x1U << reset_pin;

      SET_BIT(LED_pins[i].GPIOx->BSRR, set_msk); // set pin

      SET_BIT(LED_pins[i].GPIOx->BSRR, reset_msk); //reset pin
    }
  } while (SET);
}
