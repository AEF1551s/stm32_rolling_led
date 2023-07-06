#if !defined(ADC_H)
#define ADC_H

#include <stm32f410rx.h>
#include <stm32f4xx.h>

void analog_init()
{
    // Set ADC channel count
    uint32_t channel_count = 0x0000U; // 1 channel to convert
    SET_BIT(ADC1->SQR1, channel_count << ADC_SQR1_L_Pos);

    // Set CH1 (PA1 pin) first in sequence.
    SET_BIT(ADC1->SQR3, 0x0001U << ADC_SQR3_SQ1_Pos);
}

uint32_t simple_analog_read_pa1() //TODO: Add universal analog_read for any supported pin
{

    // ADC ON
    SET_BIT(ADC1->CR2, ADC_CR2_ADON);

    // Start conversion
    SET_BIT(ADC1->CR2, ADC_CR2_SWSTART);

    // Set conversion not complete
    CLEAR_BIT(ADC1->SR, ADC_SR_EOC);

    // Wait to conversion to be completeS
    bool ready_to_read = false;
    do
    {
        ready_to_read = READ_BIT(ADC1->SR, ADC_SR_EOC) ? true : false;
    } while (!ready_to_read);

    // read result
    uint32_t read_value = ADC1->DR;

    // end conversion
    CLEAR_BIT(ADC1->CR2, ADC_CR2_SWSTART);

    return read_value;
}

#endif // ADC_H
