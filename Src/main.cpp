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
  
  /* Loop forever */
  do
  {
  } while (SET);
}
