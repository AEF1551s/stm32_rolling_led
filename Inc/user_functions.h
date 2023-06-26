#if !defined(USER_FUNCTIONS_H)
#define USER_FUNCTIONS_H

#include <stm32f410rx.h>
#include <stm32f4xx.h>

#include <user_types.h>
#include <delay.h>

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
        CLEAR_BIT(pin_struct.GPIOx->MODER, mode << mode_pin);
        break;
    default:
        break;
    }

    return pin_struct;
}

void set_input_pull_mode(pin_struct_TypeDef pin, pupd_mode_TypeDef input_mode)
{
    if (pin.mode != INPUT)
        return;
    switch (input_mode)
    {
    case NONE:
        CLEAR_BIT(pin.GPIOx->PUPDR, !NONE << 2 * pin.pinx);
        break;
    case PULLDOWN:
        SET_BIT(pin.GPIOx->PUPDR, PULLDOWN << 2 * pin.pinx);
        break;
    case PULLUP:
        SET_BIT(pin.GPIOx->PUPDR, PULLUP << 2 * pin.pinx);
        break;
    case RESERVED:
        SET_BIT(pin.GPIOx->PUPDR, RESERVED << 2 * pin.pinx);
        break;
    default:
        break;
    }
}

void digital_write(pin_struct_TypeDef pin, pin_state_TypeDef mode)
{
    if (mode == HIGH)
    {
        uint32_t set_msk = 0x1U << pin.pinx;
        WRITE_REG(pin.GPIOx->BSRR, set_msk); // set pin
        return;
    }
    uint32_t reset_pin = (0x1F - (0xF - pin.pinx));
    uint32_t reset_msk = 0x1U << reset_pin;
    WRITE_REG(pin.GPIOx->BSRR, reset_msk); // reset pin
}

void led_array_decrement(pin_struct_TypeDef LED_pins[9], int &starting_position, int &delay)
{
    int i = starting_position;

    digital_write(LED_pins[i], HIGH);
    delay_ms(delay);
    digital_write(LED_pins[i], LOW);

    starting_position--;

    if (starting_position == -1)
        starting_position = 8;
}

void led_array_increment(pin_struct_TypeDef LED_pins[9], int &starting_position, int &delay)
{
    int i = starting_position;

    digital_write(LED_pins[i], HIGH);
    delay_ms(delay);
    digital_write(LED_pins[i], LOW);

    starting_position++;

    if (starting_position == 9)
        starting_position = 0;
}

// TODO: Implement pin toogle function

#endif // USER_FUNCTIONS_H
