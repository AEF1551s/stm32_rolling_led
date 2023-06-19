#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// System includes
#include <stm32f4xx.h>
#include <stm32f410rx.h>

// User includes
#include <nucleo_pins.h>

void clock_init()
{
  // Clock enable PORT A, B, C
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
}

void pin_init()
{
  //Set LED pins to general purpose output mode
  LED0_SET_PIN_MODE_OUTPUT;
  LED1_SET_PIN_MODE_OUTPUT;
  LED2_SET_PIN_MODE_OUTPUT;
  LED3_SET_PIN_MODE_OUTPUT;
  LED4_SET_PIN_MODE_OUTPUT;
  LED5_SET_PIN_MODE_OUTPUT;
  LED6_SET_PIN_MODE_OUTPUT;
  LED7_SET_PIN_MODE_OUTPUT;
  LED8_SET_PIN_MODE_OUTPUT;
  
}

int main(void)
{
  clock_init();
  pin_init();
  /* Loop forever */
  for (;;)
    ;
}
