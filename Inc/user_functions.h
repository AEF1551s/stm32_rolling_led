#if !defined(USER_FUNCTIONS_H)
#define USER_FUNCTIONS_H

#include <user_types.h>

void clock_init()
{
    // Clock enable PORT A, B, C
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
}

bool read_pin(pin_struct_TypeDef &pin, pin_state_TypeDef state_bit)
{
    uint32_t bit_mask = 0x1U << pin.pinx;
    if (state_bit == LOW)
        bit_mask = ~bit_mask;

    return READ_BIT(pin.GPIOx->IDR, bit_mask);
}

pin_struct_TypeDef pin_setup(GPIO_TypeDef *GPIOx, pin_TypeDef pinx, pin_mode_TypeDef mode)
{
    pin_struct_TypeDef pin_struct;
    pin_struct.GPIOx = GPIOx;
    pin_struct.pinx = pinx;
    pin_struct.mode = mode;

    uint32_t mode_pin = 2 * pinx;

    switch (mode)
    {
    case OUTPUT:
        SET_BIT(pin_struct.GPIOx->MODER, mode << mode_pin);
        break;
    case INPUT:
        CLEAR_BIT(pin_struct.GPIOx->MODER, ~mode << mode_pin);
        break;
    default:
        break;
    }

    return pin_struct;
}

void delay_ms()
{
    // TODO: Implement delay function
}
#endif // USER_FUNCTIONS_H
