#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// System includes
#include <stm32f410rx.h>
#include <stm32f4xx.h>

// User includes
#include <user_types.h>
#include <user_functions.h>
#include <delay.h>
#include <adc.h>

/*********DEBUG ONLY*********/
#include <stdio.h>
#include <debug_functons.h>

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
pin_struct_TypeDef led_delay_control;

void clock_init()
{
  // Clock enable PORT A, B, C
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
  SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
  // APB2 clock enable for ADC
  SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);
}

void pin_init()
{
  // Set LED pins to general purpose output mode
  LED0 = pin_setup(GPIOC, PIN9, OUTPUT);
  LED1 = pin_setup(GPIOC, PIN8, OUTPUT);
  LED2 = pin_setup(GPIOB, PIN8, OUTPUT);
  LED3 = pin_setup(GPIOC, PIN6, OUTPUT);
  LED4 = pin_setup(GPIOB, PIN9, OUTPUT);
  LED5 = pin_setup(GPIOC, PIN5, OUTPUT);
  LED6 = pin_setup(GPIOA, PIN12, OUTPUT);
  LED7 = pin_setup(GPIOA, PIN6, OUTPUT);
  LED8 = pin_setup(GPIOA, PIN11, OUTPUT);
  // Set button input pin and pull mode
  BTN0 = pin_setup(GPIOB, PIN5, INPUT);
  set_input_pull_mode(BTN0, PULLDOWN);
  // Set analog pin
  led_delay_control = pin_setup(GPIOA, PIN1, ANALOG);
}

int main(void)
{
/*********DEBUG ONLY START*********/
/*********DEBUG ONLY END*********/

  bool continous_conversion = true;

  clock_init();
  pin_init();
  analog_init(continous_conversion);

  pin_struct_TypeDef LED_pins[9] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8};

  bool reverse_flag = false;
  int starting_position = 0;
  int delay;

  /* Loop forever */
  do
  {
    delay = linear_distribution_12_bit(continous_conversion_read_pa1(), 150);
    if (read_pin(BTN0, HIGH))
    {
      reverse_flag = !reverse_flag;
    }
    if (reverse_flag)
    {
      led_array_decrement(LED_pins, starting_position, delay);
    }
    else
    {
      led_array_increment(LED_pins, starting_position, delay);
    }

    printf("delay: ", delay);

  } while (true);
}
